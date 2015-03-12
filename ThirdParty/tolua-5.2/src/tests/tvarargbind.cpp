/*
** Lua binding: tvararg
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
TOLUA_API int tolua_tvararg_open (lua_State* tolua_S);
LUALIB_API int luaopen_tvararg (lua_State* tolua_S);

#include "tvararg.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_B (lua_State* tolua_S)
{
 B* self = (B*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"A");
 tolua_usertype(tolua_S,"B");
}

/* get function: n of class  B */
static int tolua_get_B_B_n(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)B::n);
 return 1;
}

/* set function: n of class  B */
static int tolua_set_B_B_n(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  B::n = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  B */
static int tolua_tvararg_B_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"B",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  B* tolua_ret = (B*)  new B();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"B");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  B */
static int tolua_tvararg_B_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"B",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  B* self = (B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  A */
static int tolua_tvararg_A_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"A",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  A* tolua_ret = (A*)  new A();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"A");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: get of class  A */
static int tolua_tvararg_A_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"A",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  A* self = (A*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  double tolua_ret = (double)  self->get(i);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}

/* method: bounce of class  A */
static int tolua_tvararg_A_bounce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"A",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,1,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  A* self = (A*)  tolua_tousertype(tolua_S,1,0);
  tolua_index i = ((tolua_index)  tolua_tonumber(tolua_S,2,0)-1);
  tolua_index j = ((tolua_index)  tolua_tonumber(tolua_S,3,0)-1);
  tolua_index k = ((tolua_index)  tolua_tonumber(tolua_S,4,0)-1);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bounce'",NULL);
#endif
 {
  tolua_index tolua_ret = (tolua_index)  self->bounce(i,&j,&k);
 if (tolua_ret < 0) lua_pushnil(tolua_S);
 else tolua_pushnumber(tolua_S,(lua_Number)tolua_ret+1);
 tolua_pushnumber(tolua_S,(lua_Number)j+1);
 tolua_pushnumber(tolua_S,(lua_Number)k+1);
 }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bounce'.",&tolua_err);
 return 0;
#endif
}

/* method: add of class  A */
static int tolua_tvararg_A_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"A",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  A* self = (A*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
 {
  double tolua_ret = (double)  self->add(L);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}

/* method: GetB of class  A */
static int tolua_tvararg_A_GetB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"A",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  A* self = (A*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetB'",NULL);
#endif
 {
  tolua_own B* tolua_ret = (tolua_own B*)  self->GetB();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"B");
 lua_pushcfunction(tolua_S, tolua_bnd_takeownership);
 lua_pushvalue(tolua_S, -2);
 lua_call(tolua_S, 1, 0);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetB'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_tvararg (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"B","B","",tolua_collect_B);
#else
 tolua_cclass(tolua_S,"B","B","",NULL);
#endif
 tolua_beginmodule(tolua_S,"B");
 tolua_variable(tolua_S,"n",tolua_get_B_B_n,tolua_set_B_B_n);
 tolua_function(tolua_S,"new",tolua_tvararg_B_new00);
 tolua_function(tolua_S,"delete",tolua_tvararg_B_delete00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"A","A","",NULL);
 tolua_beginmodule(tolua_S,"A");
 tolua_function(tolua_S,"new",tolua_tvararg_A_new00);
 tolua_function(tolua_S,"get",tolua_tvararg_A_get00);
 tolua_function(tolua_S,"bounce",tolua_tvararg_A_bounce00);
 tolua_function(tolua_S,"add",tolua_tvararg_A_add00);
 tolua_function(tolua_S,"GetB",tolua_tvararg_A_GetB00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_tvararg_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_tvararg);
 lua_pushstring(tolua_S, "tvararg");
 lua_call(tolua_S, 1, 0);
 return 1;
}
