#ifndef PROFILE_SET_N_GET_EXPOSE_H_
#	define PROFILE_SET_N_GET_EXPOSE_H_

#include "set_and_get.h"
#include "oolua.h"

OOLUA_CLASS_NO_BASES(Set_get)
	OOLUA_NO_TYPEDEFS
	OOLUA_MEM_FUNC_1(void,set,double)
	OOLUA_MEM_FUNC_0_CONST(double,get)
	OOLUA_ONLY_DEFAULT_CONSTRUCTOR
OOLUA_CLASS_END

void open_Luabind_set_n_get(lua_State* l);

void open_LuaBridge_set_n_get(lua_State* l);

#endif

