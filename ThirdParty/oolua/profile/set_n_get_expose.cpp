#include "set_n_get_expose.h"


#ifdef OOLUA_LUABIND_COMPARE
#	include "luabind/luabind.hpp"
#	include "luabind/operator.hpp"
#endif

EXPORT_OOLUA_FUNCTIONS_1_NON_CONST(Set_get,set)
EXPORT_OOLUA_FUNCTIONS_1_CONST(Set_get,get)



void open_Luabind_set_n_get(lua_State *l)
{
#ifdef OOLUA_LUABIND_COMPARE
	luabind::open(l);
	luabind::module(l)
		[
			luabind::class_<Set_get>("Set_get")
			.def(luabind::constructor<>())
			.def("set",&Set_get::set)
			.def("get",&Set_get::get)
		];
#else
	(void)l;
#endif
}


#ifdef OOLUA_LUABRIDGE_COMPARE
#	include "LuaBridge.h"
#endif

void open_LuaBridge_set_n_get(lua_State* l)
{
#ifdef OOLUA_LUABRIDGE_COMPARE
	typedef void (*default_constructor) (void);
	//.addConstructor<default_constructor>()
	using namespace luabridge;
	getGlobalNamespace(l)
		.beginClass <Set_get>("Set_get")
			.addConstructor<void(*)(void)>()
			.addFunction("set",&Set_get::set)
			.addFunction("get",&Set_get::get)
		.endClass ();
#else
	(void)l;
#endif
}

