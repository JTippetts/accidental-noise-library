#include "anl_bindings.h"

int  tolua_Noise_open (lua_State* tolua_S);
int  tolua_RGBA_open (lua_State* tolua_S);
int  tolua_Imaging_open (lua_State* tolua_S);

void loadANLBindings(lua_State *l)
{
    tolua_Noise_open(l);
    tolua_RGBA_open(l);
	tolua_Imaging_open(l);
}
