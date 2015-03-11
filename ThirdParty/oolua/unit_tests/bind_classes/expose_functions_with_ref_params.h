#ifndef EXPOSE_FUNCTIONS_WITH_REF_PARAMS
#	define EXPOSE_FUNCTIONS_WITH_REF_PARAMS

#include "cpp_functions_with_ref_params.h"
#include "oolua.h"

OOLUA_CLASS_NO_BASES(Function_refs)
	OOLUA_TYPEDEFS No_public_constructors OOLUA_END_TYPES
	OOLUA_MEM_FUNC_1(void,lua_function,OOLUA::Lua_func_ref)
	OOLUA_MEM_FUNC_0(OOLUA::Lua_func_ref,returns_ref)
	OOLUA_MEM_FUNC_1(OOLUA::Lua_func_ref,takes_and_returns_ref,OOLUA::Lua_func_ref)
	OOLUA_MEM_FUNC_1(void,takes_ref_to_Lua_func_ref,OOLUA::Lua_func_ref&)
	OOLUA_MEM_FUNC_1(void,takes_ref_to_const_Lua_func_ref,OOLUA::Lua_func_ref const&)
OOLUA_CLASS_END


OOLUA_CLASS_NO_BASES(TableMemberFunction)
	OOLUA_TYPEDEFS No_public_constructors OOLUA_END_TYPES
	OOLUA_MEM_FUNC_1(void,function_which_takes_a_table,OOLUA::Lua_table)
	OOLUA_MEM_FUNC_1(bool,function_takes_table_returns_result_of_valid,OOLUA::Lua_table)
OOLUA_CLASS_END


#endif