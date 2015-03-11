
#	include "lua_function.h"
#   include "oolua_check_result.h"
#	include "oolua_config.h"
#	include "oolua_error.h"

namespace 
{
	const int LEVELS1 = 10;
	const int LEVELS2 = 20;
	
	lua_State *getthread (lua_State *L, int *arg) {
		if (lua_isthread(L, 1)) {
			*arg = 1;
			return lua_tothread(L, 1);
		}
		else {
			*arg = 0;
			return L;
		}
	}
	
	int stack_trace (lua_State *L) {
		int level;
		int firstpart = 1;  /* still before eventual `...' */
		int arg;
		lua_State *L1 = getthread(L, &arg);
		lua_Debug ar;
		if (lua_isnumber(L, arg+2)) {
			level = (int)lua_tointeger(L, arg+2);
			lua_pop(L, 1);
		}
		else
			level = (L == L1) ? 1 : 0;  /* level 0 may be this own function */
		if (lua_gettop(L) == arg)
			lua_pushliteral(L, "");
		else if (!lua_isstring(L, arg+1)) return 1;  /* message is not a string */
		else lua_pushliteral(L, "\n");
		lua_pushliteral(L, "stack traceback:");
		while (lua_getstack(L1, level++, &ar)) {
			if (level > LEVELS1 && firstpart) {
				/* no more than `LEVELS2' more levels? */
				if (!lua_getstack(L1, level+LEVELS2, &ar))
					level--;  /* keep going */
				else {
					lua_pushliteral(L, "\n\t...");  /* too many levels */
					while (lua_getstack(L1, level+LEVELS2, &ar))  /* find last levels */
						level++;
				}
				firstpart = 0;
				continue;
			}
			lua_pushliteral(L, "\n\t");
			lua_getinfo(L1, "Snl", &ar);
			lua_pushfstring(L, "%s:", ar.short_src);
			if (ar.currentline > 0)
				lua_pushfstring(L, "%d:", ar.currentline);
			if (*ar.namewhat != '\0')  /* is there a name? */
				lua_pushfstring(L, " in function " LUA_QS, ar.name);
			else {
				if (*ar.what == 'm')  /* main? */
					lua_pushfstring(L, " in main chunk");
				else if (*ar.what == 'C' || *ar.what == 't')
					lua_pushliteral(L, " ?");  /* C function or tail call */
				else
					lua_pushfstring(L, " in function <%s:%d>",
									ar.short_src, ar.linedefined);
			}
			lua_concat(L, lua_gettop(L) - arg);
		}
		lua_concat(L, lua_gettop(L) - arg);
		return 1;
	}
	
	int set_error_callback(lua_State* l, lua_CFunction func)
	{
#if OOLUA_DEBUG_CHECKS == 1
		lua_pushcfunction(l, func);
		return lua_gettop(l);
#else
		(void)l;
		(void)func;
		return 0;
#endif
	}
	
}

namespace OOLUA
{
	void Lua_function::bind_script(lua_State* const lua)
	{
#if OOLUA_DEBUG_CHECKS == 1
		assert(lua);
#endif
		m_lua = lua;
	}
	
	Lua_function::Lua_function()
		:m_lua(0)
	{}
	Lua_function::Lua_function(lua_State* l)
	{
		bind_script(l);
	}
	bool Lua_function::call(int const nparams,int const error_index)
	{
		int result = lua_pcall(m_lua,nparams,LUA_MULTRET,error_index);
		if (error_index != 0)lua_remove(m_lua, error_index);
		return INTERNAL::protected_call_check_result(m_lua,result);
	}
	
	
#if OOLUA_RUNTIME_CHECKS_ENABLED == 1 
#	if OOLUA_USE_EXCEPTIONS == 1
#		define OOLUA_CHECK_STACK_IF_ENABLED(lvm,count) \
		if( ! lua_checkstack(lvm, (count)) )throw OOLUA::Runtime_error("unable to grow the stack")
#	elif OOLUA_STORE_LAST_ERROR == 1
#		define OOLUA_CHECK_STACK_IF_ENABLED(lvm,count) \
		MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA \
		if( ! lua_checkstack(lvm, (count)) ) \
		do \
		{ \
			if( lua_checkstack(lvm, 3) ) \
			{ \
				lua_pushliteral(lvm,"unable to grow the stack"); \
				OOLUA::INTERNAL::set_error_from_top_of_stack_and_pop_the_error(lvm); \
			} \
			/*else cant even grow the stack to add the error*/ \
			return false; \
		}while(0) \
		MSC_POP_COMPILER_WARNING_OOLUA
#	endif
#elif OOLUA_DEBUG_CHECKS == 1
#	define OOLUA_CHECK_STACK_IF_ENABLED(lvm,count) \
	if( ! lua_checkstack(lvm, (count)) ) assert(0 && "Unable to grow the stack")
#else
#	define OOLUA_CHECK_STACK_IF_ENABLED(lvm,count)(void)lvm
#endif	
	
	
	/*
	 prep_function
	 If the given function is not actually a function (and the following exception does not apply)
	 then pcall will tell us this and it will be handled as specified by the configration in use.
	 Exception : If it is a function reference it can fail when the states are not related and this 
	 error is given not the pcall error, otherwise it would be confusing as to why there was
	 an error.
	 */
	
	bool Lua_function::prep_function(Lua_func_ref const& func,int const nparams,int& error_index)
	{
		OOLUA_CHECK_STACK_IF_ENABLED(m_lua,nparams+2);
		error_index = set_error_callback(m_lua,stack_trace);
		return func.push(m_lua);
	}

	bool Lua_function::prep_function(std::string const& func,int const nparams,int& error_index)
	{
		OOLUA_CHECK_STACK_IF_ENABLED(m_lua,nparams+2);
		error_index = set_error_callback(m_lua,stack_trace);
		lua_getglobal(m_lua,func.c_str() );
		return true;
	}
	
	bool Lua_function::prep_function(int const func_index,int const nparams, int& error_index)
	{
		int const top = lua_gettop(m_lua);
#if OOLUA_DEBUG_CHECKS == 1
		assert( !( top == 0 || func_index == 0|| func_index > top || -func_index > top )  && "Out of bounds index");
#endif
		OOLUA_CHECK_STACK_IF_ENABLED(m_lua,nparams+2);
		error_index = set_error_callback(m_lua,stack_trace);
		lua_pushvalue(m_lua,  func_index > 0 ? func_index : top + 1 + func_index);
		
		return true;
	}
	
#undef OOLUA_CHECK_STACK_IF_ENABLED	
	
	int Lua_function::get_top()
	{
#if OOLUA_DEBUG_CHECKS == 1
		assert(m_lua && "No valid script is bound for the Lua_function caller");
#endif
		return lua_gettop(m_lua);
	}


}

