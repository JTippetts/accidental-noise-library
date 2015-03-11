#include "expose_functions_with_ref_params.h"


EXPORT_OOLUA_FUNCTIONS_5_NON_CONST(Function_refs
								   ,lua_function
								   ,returns_ref
								   ,takes_and_returns_ref
								   ,takes_ref_to_Lua_func_ref
								   ,takes_ref_to_const_Lua_func_ref)

EXPORT_OOLUA_FUNCTIONS_0_CONST(Function_refs)


EXPORT_OOLUA_FUNCTIONS_2_NON_CONST(TableMemberFunction
								   ,function_which_takes_a_table
								   ,function_takes_table_returns_result_of_valid)
EXPORT_OOLUA_FUNCTIONS_0_CONST(TableMemberFunction)