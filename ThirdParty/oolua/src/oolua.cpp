///////////////////////////////////////////////////////////////////////////////
///  @file oolua.cpp
///  @author Liam Devine
///  @email
///  See http://www.liamdevine.co.uk for contact details.
///  @licence
///  See licence.txt for more details.
///////////////////////////////////////////////////////////////////////////////
#	include "oolua.h"
#   include "oolua_storage.h"
#   include "oolua_check_result.h"
#	include "oolua_error.h"
#	include "oolua_char_arrays.h"
namespace
{
	void add_weaklookup_table(lua_State* l)
	{
		lua_newtable(l);//tb
		int weakTable = lua_gettop(l);
		luaL_newmetatable(l, "weak_mt");
		int weak_mt = lua_gettop(l);

		lua_pushstring(l,"__mode");//tb mt key
		lua_pushstring(l,"v");//tb mt key value
		lua_settable(l,weak_mt);//tb mt
		//weak_mt["__mode"]="v"

		lua_setmetatable(l, weakTable);//tb
		//weakTable["__mt"]=weak_mt

		OOLUA::INTERNAL::Weak_table::setWeakTable(l,-2);
		//registry[weak_lookup_name]=weakTable
		
		lua_pop(l,1);//empty
	}
	void add_ownership_globals(lua_State* l)
	{
		lua_pushinteger(l,OOLUA::Cpp);//int
		lua_setglobal(l,OOLUA::INTERNAL::cpp_owns_str);//globals[string]=int
		
		
		lua_pushinteger(l,OOLUA::Lua);//int
		lua_setglobal(l,OOLUA::INTERNAL::lua_owns_str);//globals[string]=int

		OOLUA::INTERNAL::get_oolua_module(l);
		lua_pushinteger(l,OOLUA::Cpp);//int
		push_char_carray(l,OOLUA::INTERNAL::cpp_owns_str);
		lua_rawset(l, -3);
		
		lua_pushinteger(l,OOLUA::Lua);//int
		push_char_carray(l,OOLUA::INTERNAL::lua_owns_str);
		lua_rawset(l, -3);

		lua_pop(l,1);
	}

	void get_preload_table(lua_State* L)
	{
#if LUA_VERSION_NUM < 502
		lua_getglobal(L,"package");
		lua_getfield(L, -1, "preload");
#else
		lua_getfield(L, LUA_REGISTRYINDEX, "_PRELOAD");
#endif
		if (lua_type(L,-1) != LUA_TTABLE )
			luaL_error(L, "Lua %d get_preload_table failed to retrieve the preload table. Stack top is %s\n"
					   ,LUA_VERSION_NUM,lua_typename(L,-1));
	}
	
	void register_oolua_module(lua_State *L)
	{
		int const top = lua_gettop(L);
		get_preload_table(L);

		push_char_carray(L,OOLUA::INTERNAL::oolua_str);
		lua_pushcclosure(L, OOLUA::INTERNAL::get_oolua_module, 0);
		lua_settable(L, -3);

		push_char_carray(L,OOLUA::INTERNAL::oolua_str);
		lua_createtable(L, 0, 2);//starts with two entries cpp_own and lua_owns
		lua_rawset(L, LUA_REGISTRYINDEX);
		
		lua_settop(L, top);
	}
}

namespace OOLUA
{
	void setup_user_lua_state(lua_State* l)
	{
		add_weaklookup_table(l);
		register_oolua_module(l);
		add_ownership_globals(l);
	}

	Script::Script(): call(),m_lua(0)
	{
		m_lua = luaL_newstate();
		luaL_openlibs(m_lua);
		call.bind_script(m_lua);//bind the lua state to the function caller
		setup_user_lua_state(m_lua);
	}

	Script::~Script()
	{
		close_down();
	}

	void Script::gc()
	{
		lua_gc(m_lua,LUA_GCCOLLECT,0);
	}

	void Script::close_down()
	{
		if(m_lua)
		{
			lua_gc(m_lua,LUA_GCCOLLECT,0);
			lua_close(m_lua); m_lua = 0;
		}
	}

	bool Script::load_chunk(std::string const& chunk)
	{
		return OOLUA::load_chunk(m_lua,chunk);
	}
	
	bool Script::run_chunk(std::string const& chunk)
	{
		return OOLUA::run_chunk(m_lua,chunk);
	}
	
	bool Script::run_file(std::string const & filename)
	{
		return OOLUA::run_file(m_lua,filename);
	}
	
	bool Script::load_file(std::string const & filename)
	{
		return OOLUA::load_file(m_lua,filename);
	}
	
	void set_global_to_nil(lua_State*l, char const * name)
	{
		lua_pushnil(l);
		lua_setglobal(l, name);
	}
	
	/*
	This function uses the Lua public API to indicated if it is defined as 
	per the manual, that a call to lua_xmove is valid. 
	
	lua_xmove returns without doing anywork if the two pointers are the same
	and fails when using LUA_USE_APICHECK and the states do not share the same 
	global_State.
	
	It may be fine to move numbers between different unrelated states when Lua
	was not compiled with LUA_USE_APICHECK but this function would still return
	false for that scenario.
	*/
	bool can_xmove(lua_State* vm0,lua_State* vm1)
	{
		if(!vm0 || !vm1 || vm0 == vm1) return false;		

		/*
		Threads that are related share the same registry
		G(vm0)->l_registry == G(vm1)->l_registry
		*/
		return lua_topointer(vm0, LUA_REGISTRYINDEX) == lua_topointer(vm1, LUA_REGISTRYINDEX);
	}

	
	
	bool load_chunk(lua_State* lua, std::string const& chunk)
	{
		int res = luaL_loadbuffer(lua,chunk.c_str(),chunk.size(),"userChunk");
		return INTERNAL::load_buffer_check_result(lua,res);
	}
	
	bool run_chunk(lua_State* lua, std::string const& chunk)
	{
		if(! load_chunk(lua, chunk ) ) return false;
		int result = lua_pcall(lua,0,LUA_MULTRET,0);
		return INTERNAL::protected_call_check_result(lua,result);
	}
	
	bool run_file(lua_State* lua, std::string const & filename)
	{
		bool status = load_file(lua,filename);
		if( !status )return false;
		int result = lua_pcall(lua,0,LUA_MULTRET,0);
		return INTERNAL::protected_call_check_result(lua,result);
	}
	
	bool load_file(lua_State* lua, std::string const & filename)
	{
		int result = luaL_loadfile(lua, filename.c_str() );
		return INTERNAL::load_buffer_check_result(lua,result);;
	}
	
}

