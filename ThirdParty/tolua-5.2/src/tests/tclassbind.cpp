/*
** Lua binding: tclass
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
TOLUA_API int tolua_tclass_open (lua_State* tolua_S);
LUALIB_API int luaopen_tclass (lua_State* tolua_S);

#include "tclass.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Tst_A_Tst_BB (lua_State* tolua_S)
{
 Tst_A::Tst_BB* self = (Tst_A::Tst_BB*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_Tst_C (lua_State* tolua_S)
{
 Tst_C* self = (Tst_C*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_Tst_A_Tst_AA (lua_State* tolua_S)
{
 Tst_A::Tst_AA* self = (Tst_A::Tst_AA*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Tst_A");
 tolua_usertype(tolua_S,"D");
 tolua_usertype(tolua_S,"Tst_B");
 tolua_usertype(tolua_S,"Tst_C");
 tolua_usertype(tolua_S,"Tst_A::Tst_BB");
 tolua_usertype(tolua_S,"Tst_Dummy");
 tolua_usertype(tolua_S,"Tst_A::Tst_AA");
}

/* get function: last of class  Tst_A */
static int tolua_get_Tst_A_Tst_A_last_ptr(lua_State* tolua_S)
{
 tolua_pushusertype(tolua_S,(void*)Tst_A::last,"Tst_A");
 return 1;
}

/* set function: last of class  Tst_A */
static int tolua_set_Tst_A_Tst_A_last_ptr(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isusertype(tolua_S,2,"Tst_A",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Tst_A::last = ((Tst_A*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: new of class  Tst_A */
static int tolua_tclass_A_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Tst_A",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Tst_A* tolua_ret = (Tst_A*)  new Tst_A();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Tst_A");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: a of class  Tst_A */
static int tolua_tclass_A_a00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Tst_A",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Tst_A* self = (Tst_A*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'a'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->a();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'a'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Tst_AA */
static int tolua_tclass_A_AA_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Tst_A::Tst_AA",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Tst_A::Tst_AA* tolua_ret = (Tst_A::Tst_AA*)  new Tst_A::Tst_AA();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Tst_A::Tst_AA");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Tst_AA */
static int tolua_tclass_A_AA_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Tst_A::Tst_AA",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Tst_A::Tst_AA* self = (Tst_A::Tst_AA*)  tolua_tousertype(tolua_S,1,0);
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

/* method: aa of class  Tst_AA */
static int tolua_tclass_A_AA_aa00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Tst_A::Tst_AA",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Tst_A::Tst_AA* self = (Tst_A::Tst_AA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'aa'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->aa();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'aa'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Tst_BB */
static int tolua_tclass_A_BB_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Tst_A::Tst_BB",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Tst_A::Tst_BB* tolua_ret = (Tst_A::Tst_BB*)  new Tst_A::Tst_BB();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Tst_A::Tst_BB");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Tst_BB */
static int tolua_tclass_A_BB_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Tst_A::Tst_BB",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Tst_A::Tst_BB* self = (Tst_A::Tst_BB*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Base of class  Tst_BB */
static int tolua_tclass_A_BB_Base00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Tst_A::Tst_BB",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Tst_A::Tst_BB* self = (Tst_A::Tst_BB*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Base'",NULL);
#endif
 {
  Tst_A::Tst_AA* tolua_ret = (Tst_A::Tst_AA*)  self->Base();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Tst_A::Tst_AA");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Base'.",&tolua_err);
 return 0;
#endif
}

/* method: classname of class  Tst_BB */
static int tolua_tclass_A_BB_classname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Tst_A::Tst_BB",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Tst_A::Tst_BB* self = (const Tst_A::Tst_BB*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'classname'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->classname();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'classname'.",&tolua_err);
 return 0;
#endif
}

/* get function: last of class  Tst_B */
static int tolua_get_Tst_B_Tst_B_last_ptr(lua_State* tolua_S)
{
 tolua_pushusertype(tolua_S,(void*)Tst_B::last,"Tst_B");
 return 1;
}

/* set function: last of class  Tst_B */
static int tolua_set_Tst_B_Tst_B_last_ptr(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isusertype(tolua_S,2,"Tst_B",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Tst_B::last = ((Tst_B*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: new of class  Tst_B */
static int tolua_tclass_B_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Tst_B",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Tst_B* tolua_ret = (Tst_B*)  new Tst_B();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Tst_B");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: b of class  Tst_B */
static int tolua_tclass_B_b00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Tst_B",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Tst_B* self = (Tst_B*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'b'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->b();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'b'.",&tolua_err);
 return 0;
#endif
}

/* get function: last of class  Tst_C */
static int tolua_get_Tst_C_Tst_C_last_ptr(lua_State* tolua_S)
{
 tolua_pushusertype(tolua_S,(void*)Tst_C::last,"Tst_C");
 return 1;
}

/* set function: last of class  Tst_C */
static int tolua_set_Tst_C_Tst_C_last_ptr(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isusertype(tolua_S,2,"Tst_C",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Tst_C::last = ((Tst_C*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: new of class  Tst_C */
static int tolua_tclass_luaC_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Tst_C",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int n = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  Tst_C* tolua_ret = (Tst_C*)  new Tst_C(n);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Tst_C");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Tst_C */
static int tolua_tclass_luaC_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Tst_C",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Tst_C* self = (Tst_C*)  tolua_tousertype(tolua_S,1,0);
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

/* method: c of class  Tst_C */
static int tolua_tclass_luaC_c00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Tst_C",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Tst_C* self = (Tst_C*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'c'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->c();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'c'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  D */
static int tolua_tclass_D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"D",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  D* tolua_ret = (D*)  new D();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* function: Tst_create_aa */
static int tolua_tclass_create_aa00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Tst_A::Tst_AA* tolua_ret = (Tst_A::Tst_AA*)  Tst_create_aa();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Tst_A::Tst_AA");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_aa'.",&tolua_err);
 return 0;
#endif
}

/* function: Tst_is_aa */
static int tolua_tclass_is_aa00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Tst_A::Tst_AA",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Tst_A::Tst_AA* obj = ((Tst_A::Tst_AA*)  tolua_tousertype(tolua_S,1,0));
 {
  bool tolua_ret = (bool)  Tst_is_aa(obj);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_aa'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_tclass (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"Dummy","Tst_Dummy","",NULL);
 tolua_beginmodule(tolua_S,"Dummy");
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"A","Tst_A","",NULL);
 tolua_beginmodule(tolua_S,"A");
 tolua_variable(tolua_S,"last",tolua_get_Tst_A_Tst_A_last_ptr,tolua_set_Tst_A_Tst_A_last_ptr);
 tolua_function(tolua_S,"new",tolua_tclass_A_new00);
 tolua_function(tolua_S,"a",tolua_tclass_A_a00);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"AA","Tst_A::Tst_AA","",tolua_collect_Tst_A_Tst_AA);
#else
 tolua_cclass(tolua_S,"AA","Tst_A::Tst_AA","",NULL);
#endif
 tolua_beginmodule(tolua_S,"AA");
 tolua_function(tolua_S,"new",tolua_tclass_A_AA_new00);
 tolua_function(tolua_S,"delete",tolua_tclass_A_AA_delete00);
 tolua_function(tolua_S,"aa",tolua_tclass_A_AA_aa00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"BB","Tst_A::Tst_BB","Tst_A::Tst_AA",tolua_collect_Tst_A_Tst_BB);
#else
 tolua_cclass(tolua_S,"BB","Tst_A::Tst_BB","Tst_A::Tst_AA",NULL);
#endif
 tolua_beginmodule(tolua_S,"BB");
 tolua_function(tolua_S,"new",tolua_tclass_A_BB_new00);
 tolua_function(tolua_S,"delete",tolua_tclass_A_BB_delete00);
 tolua_function(tolua_S,"Base",tolua_tclass_A_BB_Base00);
 tolua_function(tolua_S,"classname",tolua_tclass_A_BB_classname00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"B","Tst_B","Tst_A",NULL);
 tolua_beginmodule(tolua_S,"B");
 tolua_variable(tolua_S,"last",tolua_get_Tst_B_Tst_B_last_ptr,tolua_set_Tst_B_Tst_B_last_ptr);
 tolua_function(tolua_S,"new",tolua_tclass_B_new00);
 tolua_function(tolua_S,"b",tolua_tclass_B_b00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"luaC","Tst_C","Tst_B",tolua_collect_Tst_C);
#else
 tolua_cclass(tolua_S,"luaC","Tst_C","Tst_B",NULL);
#endif
 tolua_beginmodule(tolua_S,"luaC");
 tolua_variable(tolua_S,"last",tolua_get_Tst_C_Tst_C_last_ptr,tolua_set_Tst_C_Tst_C_last_ptr);
 tolua_function(tolua_S,"new",tolua_tclass_luaC_new00);
 tolua_function(tolua_S,"delete",tolua_tclass_luaC_delete00);
 tolua_function(tolua_S,"c",tolua_tclass_luaC_c00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"D","D","",NULL);
 tolua_beginmodule(tolua_S,"D");
 tolua_function(tolua_S,"new",tolua_tclass_D_new00);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"create_aa",tolua_tclass_create_aa00);
 tolua_function(tolua_S,"is_aa",tolua_tclass_is_aa00);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_tclass_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_tclass);
 lua_pushstring(tolua_S, "tclass");
 lua_call(tolua_S, 1, 0);
 return 1;
}
