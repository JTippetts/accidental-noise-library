#ifndef EXPOSE_OUT_PARAMS_H_
#	define EXPOSE_OUT_PARAMS_H_

#include "oolua.h"
#include "cpp_out_params.h"
#include "expose_stub_classes.h"

OOLUA_CLASS_NO_BASES(OutParamsTest)
	OOLUA_TYPEDEFS Abstract OOLUA_END_TYPES
	OOLUA_MEM_FUNC_1(void,int_ref,OOLUA::in_out_p<int&>)
	OOLUA_MEM_FUNC_2(void,two_int_refs,OOLUA::in_out_p<int&>,OOLUA::in_out_p<int&>)
	OOLUA_MEM_FUNC_1_RENAME(int_ptr_in_out,void,int_ptr,OOLUA::in_out_p<int*>)
	OOLUA_MEM_FUNC_1_RENAME(int_ref_out,void,int_ref,OOLUA::out_p<int&>)
	OOLUA_MEM_FUNC_1(void,int_ref_change,OOLUA::out_p<int&>)
	OOLUA_MEM_FUNC_1_RENAME(int_ptr_out,void,int_ptr,OOLUA::out_p<int*>)
	OOLUA_MEM_FUNC_1(void,int_ptr_change_pointee,OOLUA::out_p<int*>)
	OOLUA_MEM_FUNC_2(int,return_int_and_2_int_refs,OOLUA::in_out_p<int&>,OOLUA::in_out_p<int&>)
	OOLUA_MEM_FUNC_1(void,int_ptr,int*)
OOLUA_CLASS_END


OOLUA_PROXY_CLASS(MockParamWithStringMember)
	OOLUA_NO_TYPEDEFS
	OOLUA_ONLY_DEFAULT_CONSTRUCTOR
OOLUA_CLASS_END

OOLUA_PROXY_CLASS(OutParamsUserData)
	OOLUA_TYPEDEFS Abstract OOLUA_END_TYPES
	OOLUA_MEM_FUNC(void, ref,out_p<Stub1&>)
	OOLUA_MEM_FUNC(void,ptr,out_p<Stub1*>)
	OOLUA_MEM_FUNC(void,ref_param,out_p<MockParamWithStringMember&>)
	/*when enabled should give a compile time error*/
	//OOLUA_MEM_FUNC(void,by_value,out_p<Stub1>)
OOLUA_CLASS_END

#endif
