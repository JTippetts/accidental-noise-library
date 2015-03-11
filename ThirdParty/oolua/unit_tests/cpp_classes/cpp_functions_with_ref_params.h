#ifndef CPP_FUNCTIONS_WITH_REF_PARAMS_H_
#	define CPP_FUNCTIONS_WITH_REF_PARAMS_H_

#include "oolua.h"

class Function_refs
{
public:
	void lua_function(OOLUA::Lua_func_ref /*ref*/)
	{
	}
	OOLUA::Lua_func_ref returns_ref()
	{
		OOLUA::Lua_func_ref f;
		return f;
	}
	OOLUA::Lua_func_ref takes_and_returns_ref(OOLUA::Lua_func_ref ref)
	{
		return ref;
	}
	void takes_ref_to_Lua_func_ref(OOLUA::Lua_func_ref& /*ref*/)
	{
	}
	void takes_ref_to_const_Lua_func_ref(OOLUA::Lua_func_ref const& /*ref*/)
	{
	}
};


struct TableMemberFunction
{
	void function_which_takes_a_table(OOLUA::Lua_table t)
	{
		t.set_value(1,2);
	}
	bool function_takes_table_returns_result_of_valid(OOLUA::Lua_table t)
	{
		return t.valid();
	}
};


#endif


