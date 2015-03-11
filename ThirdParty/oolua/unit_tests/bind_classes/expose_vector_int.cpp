#include "expose_vector_int.h"


EXPORT_OOLUA_FUNCTIONS_2_NON_CONST(vector_int,
								   push_back,
								   pop_back)

EXPORT_OOLUA_FUNCTIONS_1_CONST(vector_int,size)

