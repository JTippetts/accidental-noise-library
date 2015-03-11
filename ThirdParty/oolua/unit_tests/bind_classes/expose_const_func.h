#ifndef EXPOSE_CONST_FUNCS_H_
#	define EXPOSE_CONST_FUNCS_H_

#	include "cpp_const_funcs.h"
#	include "oolua.h"

OOLUA_CLASS_NO_BASES(Constant)
	OOLUA_TYPEDEFS Abstract OOLUA_END_TYPES
	OOLUA_MEM_FUNC_0_CONST(int,cpp_func_const)
	OOLUA_MEM_FUNC_0(void,cpp_func)
	OOLUA_MEM_FUNC_CONST_RENAME(renamedUsingVaArgs,int,function_to_test_rename_using_varags,int)
OOLUA_CLASS_END



#endif
