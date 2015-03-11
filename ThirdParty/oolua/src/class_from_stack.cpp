#include "class_from_stack.h"
#include "lua_includes.h"
#include "lvd_types.h"


namespace OOLUA
{
	namespace INTERNAL
	{

#if OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA == 1 
#	if OOLUA_USERDATA_OPTIMISATION == 1
		bool index_is_userdata(lua_State* l,int index,Lua_ud*& ud)
		{
#if defined LUA_VERSION_NUM && LUA_VERSION_NUM == 502
/*lua_objlen may or may not be a macro for lua_rawlen in luaconfig.h;
 so lets just work regardless of the configuration used*/
#	define _oolua_len_ lua_rawlen 
#else 
#	define _oolua_len_ lua_objlen
#endif
			ud = static_cast<Lua_ud *>(lua_touserdata(l,index));
			return ud && _oolua_len_(l,index) == sizeof(Lua_ud) && OOLUA_CHECK_COOKIE(ud->flags) ;
#undef _oolua_len_
		}
#	else
		
		bool index_is_userdata(lua_State* l,int index,Lua_ud*& ud)
		{	
			ud = static_cast<Lua_ud *>(lua_touserdata(l,index));
			if(!ud || !lua_getmetatable(l, index)) return false;
			lua_pushlightuserdata(l,(void*)lua_topointer(l, LUA_REGISTRYINDEX));
			lua_rawget(l,-2);
			bool result = lua_isnil(l,-1) == 0;
			lua_pop(l,2);
			return result;	
		}
		 	
#	endif

#endif


		bool is_requested_type_a_base(lua_State* l,Lua_ud const* stack_ud,Lua_ud* requested_ud,int const& userdata_index)
		{
			return stack_ud->base_checker(l,requested_ud,userdata_index);
		}
		
		void report_error_userdata_is_constant(lua_State* const l, char const* pulling_class_type)
		{
			luaL_error (l, "%s \"%s\" %s", "Tried to pull a none constant"
						,pulling_class_type
						,"pointer from a const pointer"
						);
		}

	}
}