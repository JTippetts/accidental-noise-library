#ifndef EXPOSE_INTEGRAL_FUNCTION_PARAMS_H_
#	define EXPOSE_INTEGRAL_FUNCTION_PARAMS_H_

#include "oolua.h"
#include "cpp_integral_function_params.h"

OOLUA_CLASS_NO_BASES(Int_params)
	OOLUA_TYPEDEFS Abstract OOLUA_END_TYPES
	OOLUA_MEM_FUNC_1(void, int_,int)
	OOLUA_MEM_FUNC_1(void, int_ref,int& )
	OOLUA_MEM_FUNC_1(void, int_ptr,int* )
	OOLUA_MEM_FUNC_1(void, int_const,int const)
	OOLUA_MEM_FUNC_1(void, int_const_ref,int const& )
	OOLUA_MEM_FUNC_1(void, int_const_ptr,int const*  )
	OOLUA_MEM_FUNC_1(void, int_const_ptr_const,int const * const )
	OOLUA_MEM_FUNC_1(void, bool_,bool)
OOLUA_CLASS_END


#endif
