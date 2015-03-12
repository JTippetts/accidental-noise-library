/*
** Lua binding: tdirective
*/

#include "tolua.h"

#ifndef __cplusplus
#include <stdlib.h>
#endif
#ifdef __cplusplus
 extern "C" int tolua_bnd_takeownership (lua_State* L); // from tolua_map.c
#else
 int tolua_bnd_takeownership (lua_State* L); /* from tolua_map.c */
#endif
#include <string.h>

/* Exported function */
TOLUA_API int tolua_tdirective_open (lua_State* tolua_S);
LUALIB_API int luaopen_tdirective (lua_State* tolua_S);

#include "lualib.h"
#include "lauxlib.h"
int a;
extern int a;
int main (void)
{
 lua_State* L = luaL_newstate();
	luaopen_base(L);
 tolua_tdirective_open(L);
	luaL_dofile(L,"tdirective.lua");
	lua_close(L);
 return 0;
}

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* get function: a */
static int tolua_get_a(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)a);
 return 1;
}

/* set function: a */
static int tolua_set_a(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  a = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* Open lib function */
LUALIB_API int luaopen_tdirective (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 tolua_variable(tolua_S,"a",tolua_get_a,tolua_set_a);
{
 a = 3;
}

 { /* begin embedded lua code */
 static unsigned char B[] = {
  10, 65, 32, 61, 32, 52,32
 };
 if (luaL_loadbuffer(tolua_S,(char*)B,sizeof(B),"tolua: embedded Lua code") == LUA_OK)
 lua_pcall(tolua_S,0,LUA_MULTRET,0);
 } /* end of embedded lua code */


 { /* begin embedded lua code */
 static unsigned char B[] = {
  10,100,111,102,105,108,101, 40, 34,109,121, 97,115,115,101,
 114,116, 46,108,117, 97, 34, 41, 10,102,117,110, 99,116,105,
 111,110, 32,102,117,110, 99, 32, 40, 41, 10,114,101,116,117,
 114,110, 32, 53, 10,101,110,100,32
 };
 if (luaL_loadbuffer(tolua_S,(char*)B,sizeof(B),"tolua: embedded Lua code") == LUA_OK)
 lua_pcall(tolua_S,0,LUA_MULTRET,0);
 } /* end of embedded lua code */

 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_tdirective_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_tdirective);
 lua_pushstring(tolua_S, "tdirective");
 lua_call(tolua_S, 1, 0);
 return 1;
}
