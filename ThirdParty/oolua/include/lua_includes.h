///////////////////////////////////////////////////////////////////////////////
///  @file lua_includes.h
///  Prevents name mangling and compatabilty for new Lua versions
///  @author Liam Devine
///////////////////////////////////////////////////////////////////////////////
#ifndef LUA_INCLUDES_H_
#	define LUA_INCLUDES_H_
//Prevent name mangling
extern "C"
{
#if defined _MSC_VER
#	include "lua.h"
#	include "lauxlib.h"
#	include "lualib.h"
#elif defined __MINGW32__ //you may need to change this
#	include "lua.h"
#	include "lauxlib.h"
#	include "lualib.h"
#elif defined __GNUC__
	
#	include "lua.h"
#	include "lauxlib.h"
#	include "lualib.h"

/*	
#	include "lua.h"
#	include "lauxlib.h"
#	include "lualib.h"
*/
#endif

}

#endif //LUA_INCLUDES_H_
