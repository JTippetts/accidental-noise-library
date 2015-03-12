extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int main ()
{
	int  tolua_tinheritance_open (lua_State*);

	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	tolua_tinheritance_open(L);

	luaL_dofile(L,"tinheritance.lua");

	lua_close(L);

	return 0;
}

