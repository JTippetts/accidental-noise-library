
#include "oolua.h"
#include "set_n_get_expose.h"
#include "hierarachy_expose.h"
#include <iostream>



#ifdef OOLUA_SWIG_COMPARE
extern "C"
{
	extern int luaopen_swig_profile(lua_State* L);
	extern void OOLUA_SWIG_pass_pointer_to_lua(lua_State* L,void* ptr,char* type,int own);
}
#endif
#ifdef OOLUA_LUABIND_COMPARE
#	include "luabind/luabind.hpp"
#endif

#ifdef OOLUA_LUABRIDGE_COMPARE
#	include "LuaBridge.h"
#endif

int main()
{
	{
		OOLUA::Script L;
		L.register_class<Set_get>();
		if (! L.run_file("./oolua_set_and_get.lua") )
		{
			std::cout <<OOLUA::get_last_error(L);
		}
	}
	{
		OOLUA::Script L;
		L.register_class<ProfileDerived>();
		OOLUA::register_class_and_bases<ProfileMultiBases>(L);
		if (! L.run_file("./oolua_derived.lua") )
		{
			std::cout <<OOLUA::get_last_error(L);
		}
		ProfileMultiBases derived;
		ProfileBase* base = &derived;
		L.call("func",base);
		double time;
		OOLUA::pull2cpp(L,time);
		std::cout <<"OOLua - Lua function which takes a base and calls a virtual function (average elapsed time): " 
			<<time <<std::endl; 
	}

#ifdef OOLUA_SWIG_COMPARE
	{
		OOLUA::Script L;
		luaopen_swig_profile(L);
		if (! L.run_file("./swig_set_and_get.lua") )
		{
			std::cout <<OOLUA::get_last_error(L);
		}
	}
	{
		OOLUA::Script L;
		luaopen_swig_profile(L);
		if (! L.run_file("./swig_derived.lua") )
		{
			std::cout <<OOLUA::get_last_error(L);
		}

		ProfileMultiBases derived;
		ProfileBase* base = &derived;
//		lua_getfield(L, LUA_GLOBALSINDEX, "func");
		lua_getglobal(L,"func");
		OOLUA_SWIG_pass_pointer_to_lua(L,base,"ProfileBase *",0);
		if( lua_pcall(L,1,LUA_MULTRET,0) != 0)
		{
			std::cout <<lua_tostring(L,-1) <<std::endl;
		}
		else
		{
			double time;
			OOLUA::pull2cpp(L,time);
			std::cout <<"Swig - Lua function which takes a base and calls a virtual function (average elapsed time): " 
				<<time <<std::endl; 
		}

	}
#endif

#ifdef OOLUA_LUABIND_COMPARE
	{
		OOLUA::Script L;
		open_Luabind_set_n_get(L);
		if (! L.run_file("./luabind_set_and_get.lua") )
		{
			std::cout <<OOLUA::get_last_error(L);
		}
	}
	{
		OOLUA::Script L;
		open_Luabind_hierarchy(L);
		if (! L.run_file("./luabind_derived.lua") )
		{
			std::cout <<OOLUA::get_last_error(L);
		}

		ProfileMultiBases derived;
		ProfileBase* base = &derived;
		double time = luabind::call_function<double>(L,"func",base);
		std::cout <<"Luabind - Lua function which takes a base and calls a virtual function (average elapsed time): " 
			<<time <<std::endl; 
	}
#endif

#ifdef OOLUA_LUABRIDGE_COMPARE
	{
		OOLUA::Script L;
		open_LuaBridge_set_n_get(L);
		if (! L.run_file("./luabind_set_and_get.lua") )
		{
			std::cout <<OOLUA::get_last_error(L);
		}
	}
	{
		OOLUA::Script L;
		open_LuaBridge_hierarchy(L);
		if (! L.run_file("./luabridge_derived.lua") )
		{
			std::cout <<OOLUA::get_last_error(L);
		}
		
		ProfileMultiBases derived;
		ProfileBase* base = &derived;
		//		lua_getfield(L, LUA_GLOBALSINDEX, "func");
		lua_getglobal(L,"func");
		luabridge::push(L, base);
		if( lua_pcall(L,1,LUA_MULTRET,0) != 0)
		{
			std::cout <<lua_tostring(L,-1) <<std::endl;
		}
		else
		{
			double time;
			OOLUA::pull2cpp(L,time);
			std::cout <<"LuaBridge - Lua function which takes a base and calls a virtual function (average elapsed time): " 
			<<time <<std::endl; 
		}
	}
	
	
#endif	
}