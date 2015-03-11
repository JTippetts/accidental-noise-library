#ifndef EXPOSE_STATIC_AND_C_FUNCTIONS_H_
#	define EXPOSE_STATIC_AND_C_FUNCTIONS_H_

#include "oolua.h"
#include "cpp_static_and_c_functions.h"

OOLUA_CLASS_NO_BASES(ClassHasStaticFunction)
	OOLUA_TYPEDEFS No_public_constructors OOLUA_END_TYPES
	static int returns_input(lua_State* l)
	{
		OOLUA_C_FUNCTION_1(int,::ClassHasStaticFunction::returns_input,int)
	}
OOLUA_CLASS_END


int oolua_ClassHasStaticFunction_static_function(lua_State* l);
int oolua_ClassHasStaticFunction_static_function_int(lua_State* l);

#endif
