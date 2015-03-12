extern "C"
{
#include "lualib.h"
#include "lauxlib.h"
}

#include "tfunction.h"


int main (void)
{
	int  tolua_tfunction_open (lua_State*);
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	tolua_tfunction_open(L);

	luaL_dofile(L,"tfunction.lua");

	lua_close(L);
	return 0;
}

