#include "expose_member_function_calls.h"

EXPORT_OOLUA_FUNCTIONS_8_NON_CONST(Function_calls
								   ,func
								   ,abstract_func_0
								   ,abstract_func_1
								   ,abstract_func_3
								   ,ptr_to_char
								   ,ptr_to_const_char
								   ,returns_char_ptr
								   ,returns_const_char_ptr)

EXPORT_OOLUA_FUNCTIONS_1_CONST(Function_calls,lua_state)