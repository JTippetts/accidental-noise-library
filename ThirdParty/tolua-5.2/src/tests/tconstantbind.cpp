/*
** Lua binding: tconstant
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
TOLUA_API int tolua_tconstant_open (lua_State* tolua_S);
LUALIB_API int luaopen_tconstant (lua_State* tolua_S);

#include "tconstant.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"A");
}

/* Open lib function */
LUALIB_API int luaopen_tconstant (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_constant(tolua_S,"FIRST",FIRST);
 tolua_constant(tolua_S,"SECOND",SECOND);
 tolua_constant(tolua_S,"ONE",ONE);
 tolua_constant(tolua_S,"TWO",TWO);
 tolua_module(tolua_S,"M",0);
 tolua_beginmodule(tolua_S,"M");
 tolua_constant(tolua_S,"FIRST",M_FIRST);
 tolua_constant(tolua_S,"SECOND",M_SECOND);
 tolua_constant(tolua_S,"ONE",M_ONE);
 tolua_constant(tolua_S,"TWO",M_TWO);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"A","A","",NULL);
 tolua_beginmodule(tolua_S,"A");
 tolua_constant(tolua_S,"FIRST",FIRST);
 tolua_constant(tolua_S,"SECOND",SECOND);
 tolua_constant(tolua_S,"ONE",A::ONE);
 tolua_constant(tolua_S,"TWO",A::TWO);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_tconstant_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_tconstant);
 lua_pushstring(tolua_S, "tconstant");
 lua_call(tolua_S, 1, 0);
 return 1;
}
