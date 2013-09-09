#include <stdio.h>
extern "C" {
	#include "lua.h"
	#include "lauxlib.h"
}
#define PROJECT_TABLENAME "libanl"
#ifdef WIN32
#define L_API __declspec(dllexport)
#else
#define L_API
#endif

#include "anl_bindings.h"

extern "C" {
	int L_API luaopen_libanl (lua_State *L);
}

int L_API luaopen_libanl (lua_State *L) {
	loadANLBindings(L);
	return 1;
}