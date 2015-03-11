#include "lua_ownership.h"

EXPORT_OOLUA_FUNCTIONS_NON_CONST(OwnershipParamsAndReturns
								,lua_takes_ownership_of_ref_2_ptr
								,lua_takes_ownership_of_ref_2_ptr_const
													   
								,cpp_takes_ownership_of_ptr_param
								,cpp_takes_ownership_of_ref_to_ptr_param
								 
								,cpp_takes_ownership_of_const_ptr_param
								,cpp_takes_ownership_of_ref_2_const_ptr_param
								 
								,cpp_takes_ownership_of_ptr_to_const_param
								,cpp_takes_ownership_of_ref_to_ptr_to_const_param
								 
								,cpp_takes_ownership_of_const_ptr_to_const_param
								,cpp_takes_ownership_of_ref_to_const_ptr_to_const_param		
								
								)
								 
EXPORT_OOLUA_FUNCTIONS_CONST(OwnershipParamsAndReturns)