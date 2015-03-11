#include "expose_max_params.h"



/*
TEST_EXPORT_OOLUA_FUNCTIONS_NON_CONST(VoidReturnIntParam,
								   one,
								   two,
								   three,
								   four,
								   five,
								   six,
								   seven,
								   eight)


*/

EXPORT_OOLUA_FUNCTIONS_8_NON_CONST(VoidReturnIntParam,
								   one,
								   two,
								   three,
								   four,
								   five,
								   six,
								   seven,
								   eight)

EXPORT_OOLUA_FUNCTIONS_0_CONST(VoidReturnIntParam)


