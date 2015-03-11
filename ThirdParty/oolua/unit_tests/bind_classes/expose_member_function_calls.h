#ifndef EXPOSE_MEMBER_FUNCTION_CALLS_H_
#	define EXPOSE_MEMBER_FUNCTION_CALLS_H_

#	include "oolua.h"
#	include "cpp_member_function_calls.h"

OOLUA_CLASS_NO_BASES(Function_calls)
	OOLUA_TYPEDEFS Abstract OOLUA_END_TYPES
	OOLUA_MEM_FUNC_0(void,func)
	OOLUA_MEM_FUNC_0(void,abstract_func_0)
	OOLUA_MEM_FUNC_1(void,abstract_func_1,int)
	OOLUA_MEM_FUNC_3(int,abstract_func_3,in_p<int const&> ,in_p<int&> ,in_p<int> )
	OOLUA_MEM_FUNC_1(void,ptr_to_char,char * )
	OOLUA_MEM_FUNC_1(void,ptr_to_const_char,char const* )
	OOLUA_MEM_FUNC_0(char*,returns_char_ptr)
	OOLUA_MEM_FUNC_0(char const*,returns_const_char_ptr)
	OOLUA_MEM_FUNC_RENAME(renamedUsingVaArgs,void,abstract_func_1,int);
	OOLUA_MEM_FUNC_CONST(void,lua_state,calling_lua_state)
OOLUA_CLASS_END


#endif

