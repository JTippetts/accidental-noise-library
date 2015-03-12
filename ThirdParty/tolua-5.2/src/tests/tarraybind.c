/*
** Lua binding: tarray
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
TOLUA_API int tolua_tarray_open (lua_State* tolua_S);
LUALIB_API int luaopen_tarray (lua_State* tolua_S);

#include "tarray.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Point (lua_State* tolua_S)
{
 Point* self = (Point*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Point");
 tolua_usertype(tolua_S,"Array");
}

/* get function: x of class  Point */
static int tolua_get_Point_Point_x(lua_State* tolua_S)
{
  Point* self = (Point*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}

/* set function: x of class  Point */
static int tolua_set_Point_Point_x(lua_State* tolua_S)
{
  Point* self = (Point*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: y of class  Point */
static int tolua_get_Point_Point_y(lua_State* tolua_S)
{
  Point* self = (Point*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}

/* set function: y of class  Point */
static int tolua_set_Point_Point_y(lua_State* tolua_S)
{
  Point* self = (Point*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: a */
static int tolua_get_tarray_a(lua_State* tolua_S)
{
 int tolua_index;
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)a[tolua_index]);
 return 1;
}

/* set function: a */
static int tolua_set_tarray_a(lua_State* tolua_S)
{
 int tolua_index;
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  a[tolua_index] = ((int)  tolua_tonumber(tolua_S,3,0));
 return 0;
}

/* get function: p */
static int tolua_get_tarray_p(lua_State* tolua_S)
{
 int tolua_index;
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushusertype(tolua_S,(void*)&p[tolua_index],"const Point");
 return 1;
}

/* get function: pp */
static int tolua_get_tarray_pp(lua_State* tolua_S)
{
 int tolua_index;
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushusertype(tolua_S,(void*)pp[tolua_index],"Point");
 return 1;
}

/* set function: pp */
static int tolua_set_tarray_pp(lua_State* tolua_S)
{
 int tolua_index;
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  pp[tolua_index] = ((Point*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}

/* get function: ma */
static int tolua_get_tarray_M_a(lua_State* tolua_S)
{
 int tolua_index;
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)ma[tolua_index]);
 return 1;
}

/* set function: ma */
static int tolua_set_tarray_M_a(lua_State* tolua_S)
{
 int tolua_index;
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  ma[tolua_index] = ((int)  tolua_tonumber(tolua_S,3,0));
 return 0;
}

/* get function: mp */
static int tolua_get_tarray_M_p(lua_State* tolua_S)
{
 int tolua_index;
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushusertype(tolua_S,(void*)&mp[tolua_index],"const Point");
 return 1;
}

/* get function: mpp */
static int tolua_get_tarray_M_pp(lua_State* tolua_S)
{
 int tolua_index;
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushusertype(tolua_S,(void*)mpp[tolua_index],"Point");
 return 1;
}

/* set function: mpp */
static int tolua_set_tarray_M_pp(lua_State* tolua_S)
{
 int tolua_index;
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  mpp[tolua_index] = ((Point*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}

/* get function: a of class  Array */
static int tolua_get_tarray_Array_a(lua_State* tolua_S)
{
 int tolua_index;
  Array* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (Array*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->a[tolua_index]);
 return 1;
}

/* set function: a of class  Array */
static int tolua_set_tarray_Array_a(lua_State* tolua_S)
{
 int tolua_index;
  Array* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (Array*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->a[tolua_index] = ((int)  tolua_tonumber(tolua_S,3,0));
 return 0;
}

/* get function: p of class  Array */
static int tolua_get_tarray_Array_p(lua_State* tolua_S)
{
 int tolua_index;
  Array* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (Array*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushusertype(tolua_S,(void*)&self->p[tolua_index],"Point");
 return 1;
}

/* set function: p of class  Array */
static int tolua_set_tarray_Array_p(lua_State* tolua_S)
{
 int tolua_index;
  Array* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (Array*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->p[tolua_index] = *((Point*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}

/* get function: pp of class  Array */
static int tolua_get_tarray_Array_pp(lua_State* tolua_S)
{
 int tolua_index;
  Array* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (Array*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushusertype(tolua_S,(void*)self->pp[tolua_index],"Point");
 return 1;
}

/* set function: pp of class  Array */
static int tolua_set_tarray_Array_pp(lua_State* tolua_S)
{
 int tolua_index;
  Array* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (Array*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=10)
 tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->pp[tolua_index] = ((Point*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}

/* get function: array */
static int tolua_get_array(lua_State* tolua_S)
{
 tolua_pushusertype(tolua_S,(void*)&array,"Array");
 return 1;
}

/* set function: array */
static int tolua_set_array(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isusertype(tolua_S,2,"Array",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  array = *((Array*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: parray */
static int tolua_get_parray_ptr(lua_State* tolua_S)
{
 tolua_pushusertype(tolua_S,(void*)parray,"Array");
 return 1;
}

/* set function: parray */
static int tolua_set_parray_ptr(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isusertype(tolua_S,2,"Array",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  parray = ((Array*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* Open lib function */
LUALIB_API int luaopen_tarray (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Point","Point","",tolua_collect_Point);
#else
 tolua_cclass(tolua_S,"Point","Point","",NULL);
#endif
 tolua_beginmodule(tolua_S,"Point");
 tolua_variable(tolua_S,"x",tolua_get_Point_Point_x,tolua_set_Point_Point_x);
 tolua_variable(tolua_S,"y",tolua_get_Point_Point_y,tolua_set_Point_Point_y);
 tolua_endmodule(tolua_S);
 tolua_array(tolua_S,"a",tolua_get_tarray_a,tolua_set_tarray_a);
 tolua_array(tolua_S,"p",tolua_get_tarray_p,NULL);
 tolua_array(tolua_S,"pp",tolua_get_tarray_pp,tolua_set_tarray_pp);
 tolua_module(tolua_S,"M",1);
 tolua_beginmodule(tolua_S,"M");
 tolua_array(tolua_S,"a",tolua_get_tarray_M_a,tolua_set_tarray_M_a);
 tolua_array(tolua_S,"p",tolua_get_tarray_M_p,NULL);
 tolua_array(tolua_S,"pp",tolua_get_tarray_M_pp,tolua_set_tarray_M_pp);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Array","Array","",NULL);
 tolua_beginmodule(tolua_S,"Array");
 tolua_array(tolua_S,"a",tolua_get_tarray_Array_a,tolua_set_tarray_Array_a);
 tolua_array(tolua_S,"p",tolua_get_tarray_Array_p,tolua_set_tarray_Array_p);
 tolua_array(tolua_S,"pp",tolua_get_tarray_Array_pp,tolua_set_tarray_Array_pp);
 tolua_endmodule(tolua_S);
 tolua_variable(tolua_S,"array",tolua_get_array,tolua_set_array);
 tolua_variable(tolua_S,"parray",tolua_get_parray_ptr,tolua_set_parray_ptr);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_tarray_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_tarray);
 lua_pushstring(tolua_S, "tarray");
 lua_call(tolua_S, 1, 0);
 return 1;
}
