#ifndef EXPOSE_PULLS_STUB_PARAM_H_
#	define EXPOSE_PULLS_STUB_PARAM_H_

#	include "oolua.h"
#	include "cpp_pulls_stub_param.h"
#	include "expose_stub_classes.h"

OOLUA_CLASS_NO_BASES(Pulls_stub)
	OOLUA_TYPEDEFS Abstract OOLUA_END_TYPES
	OOLUA_MEM_FUNC_1(void,ref,Stub1&)
	OOLUA_MEM_FUNC_1(void,ref_const,Stub1 const &)
	OOLUA_MEM_FUNC_1(void,ptr,Stub1*)
	OOLUA_MEM_FUNC_1(void,ptr_const,Stub1 const *)
	OOLUA_MEM_FUNC_1(void,const_ptr_const,Stub1  const* const)
	OOLUA_MEM_FUNC_1(void,ref_ptr_const,Stub1 const *&)
	OOLUA_MEM_FUNC_1(void,ref_const_ptr_const,Stub1 const* const &)
OOLUA_CLASS_END

#endif

