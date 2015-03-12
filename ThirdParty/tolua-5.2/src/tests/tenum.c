#include "lualib.h"
#include "lauxlib.h"

#include "tenum.h"

Status checkenum (Order o)
{
	if (o == FIRST)
		return TRUE;
	else
		return FALSE;
}

int main (void)
{
	int  tolua_tenum_open (lua_State*);
	lua_State* L = luaL_newstate();

	luaL_openlibs(L);
	tolua_tenum_open(L);

	luaL_dofile(L,"tenum.lua");

	lua_close(L);
	return 0;
}
