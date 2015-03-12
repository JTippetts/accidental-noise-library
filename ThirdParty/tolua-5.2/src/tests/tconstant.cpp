extern "C"
{
#include "lualib.h"
#include "lauxlib.h"
}

#include "tconstant.h"


int main (void)
{
	int  tolua_tconstant_open (lua_State*);
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	tolua_tconstant_open(L);

	luaL_dofile(L,"tconstant.lua");

	lua_close(L);
	return 0;
}

