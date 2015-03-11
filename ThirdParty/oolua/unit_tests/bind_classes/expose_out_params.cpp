#include "expose_out_params.h"

EXPORT_OOLUA_FUNCTIONS_9_NON_CONST(OutParamsTest
								   ,int_ref
								   ,two_int_refs
								   ,int_ptr_in_out
								   ,int_ref_out
								   ,int_ref_change
								   ,int_ptr
								   ,int_ptr_out
								   ,int_ptr_change_pointee
								   ,return_int_and_2_int_refs
								   )
EXPORT_OOLUA_FUNCTIONS_0_CONST(OutParamsTest)


EXPORT_OOLUA_FUNCTIONS_NON_CONST(OutParamsUserData
								   ,ref
									,ptr
									,ref_param
									)

EXPORT_OOLUA_FUNCTIONS_CONST(OutParamsUserData)

EXPORT_OOLUA_NO_FUNCTIONS(MockParamWithStringMember)