extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "tvararg.h"


#include <assert.h>
#include <stdlib.h>

int B::n = 0;

static void check (void)
{
  assert(B::n == 0);
}

int main ()
{
  int  tolua_tvararg_open (lua_State*);

  atexit(check);

  lua_State* L = luaL_newstate();
  luaL_openlibs(L);
  tolua_tvararg_open(L);

  lua_pushstring(L, "tolua_ubox");
  lua_rawget(L, LUA_REGISTRYINDEX);
  lua_setglobal(L, "ubox");

  if (luaL_dofile(L,"tvararg.lua")) {
    printf("Error: %s\n",lua_tostring(L,-1));
  }

  lua_close(L);

  return 0;
}

