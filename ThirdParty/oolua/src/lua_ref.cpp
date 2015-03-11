#include "lua_ref.h"

#include "oolua_config.h"
#include "oolua_error.h"

namespace OOLUA
{
	bool can_xmove(lua_State* vm0,lua_State* vm1);
	namespace INTERNAL 
	{
		bool handle_unrelated_states(lua_State* const from,lua_State* const to)
		{
#if OOLUA_RUNTIME_CHECKS_ENABLED == 1
#	if OOLUA_USE_EXCEPTIONS ==1
			lua_pushfstring(to,"Can not push a valid Lua reference from lua_State(%p) to an unrelated lua_State(%p)",from,to);
			throw OOLUA::Runtime_error(to,(OOLUA::ERROR::PopTheStack*)0);
#	endif
#	if OOLUA_STORE_LAST_ERROR ==1
			lua_pushfstring(to,"Can not push a valid Lua reference from lua_State(%p) to an unrelated lua_State(%p)",from,to); 
			OOLUA::INTERNAL::set_error_from_top_of_stack_and_pop_the_error(to);
#	endif
#	if OOLUA_DEBUG_CHECKS == 1
			//assert(0 && "Can not push a valid Lua reference from one lua_State to a different state");
#	endif
#	if OOLUA_USE_EXCEPTIONS == 0
			return false;
#	endif
#else
			(void)from;
			(void)to;
			return true;
#endif
		}
		
		
		void pull_handle_invalid(lua_State* const lua,int id)
		{
#if OOLUA_STORE_LAST_ERROR == 1 || 	OOLUA_USE_EXCEPTIONS ==1
			lua_pushfstring(lua,
							"pulling incorrect type from stack. This is a Lua registry reference to id%d, stack contains %s"
							,id
							,lua_gettop(lua) ? lua_typename(lua,lua_type(lua, -1)): "empty stack");	
#	if OOLUA_USE_EXCEPTIONS ==1
			throw OOLUA::Runtime_error(lua,(OOLUA::ERROR::PopTheStack*)0);
#	else // OOLUA_STORE_LAST_ERROR ==1								
			OOLUA::INTERNAL::set_error_from_top_of_stack_and_pop_the_error(lua);
#	endif
#elif OOLUA_DEBUG_CHECKS == 1
			assert(0 && "pulling incorrect type from stack");
#endif
		}
		
		bool push_reference_if_possible(int const ref, lua_State* const from,lua_State* const to)
		{
			if (from == to || OOLUA::can_xmove(from, to) )  
			{
				lua_rawgeti(to, LUA_REGISTRYINDEX, ref );
				return true;
			}
			return handle_unrelated_states(from,to);
		}
	}
}