#include "lualib.h"
#include "lauxlib.h"

#include "tmodule.h"

int a = 1;
int b = 2;
int c = 3;
int d = 4;

int main ()
{
	int  tolua_tmodule_open (lua_State*);

	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	tolua_tmodule_open(L);

	luaL_dofile(L,"tmodule.lua");

	lua_close(L);
	return 0;
}

