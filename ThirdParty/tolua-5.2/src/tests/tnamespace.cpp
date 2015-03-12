extern "C" {
#include "lualib.h"
#include "lauxlib.h"
}

#include "tnamespace.h"

int A::a = 1;
int A::B::b = 2;
int A::B::C::c = 3;

int main ()
{
	int  tolua_tnamespace_open (lua_State*);

	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	tolua_tnamespace_open(L);

	luaL_dofile(L,"tnamespace.lua");

	lua_close(L);
	return 0;
}

