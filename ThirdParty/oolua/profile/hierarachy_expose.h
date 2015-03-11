#ifndef HIERARACHY_OOLUA_H_
#	define HIERARACHY_OOLUA_H_

#include "hierarchy.h"
#include "oolua.h"

OOLUA_CLASS_NO_BASES(ProfileBase)
	OOLUA_TYPEDEFS Abstract OOLUA_END_TYPES
	OOLUA_MEM_FUNC_1(void,increment_a_base,ProfileBase*)
	OOLUA_MEM_FUNC_0(void, virtual_func)
	OOLUA_MEM_FUNC_0(void, pure_virtual_func)
OOLUA_CLASS_END

OOLUA_CLASS_NO_BASES(ProfileAnotherBase)
	OOLUA_NO_TYPEDEFS
	OOLUA_ONLY_DEFAULT_CONSTRUCTOR
OOLUA_CLASS_END


OOLUA_CLASS(ProfileDerived) : public Proxy_class<ProfileBase>
	OOLUA_BASIC
	OOLUA_NO_TYPEDEFS
	OOLUA_BASES_START ProfileBase OOLUA_BASES_END
	OOLUA_ONLY_DEFAULT_CONSTRUCTOR
OOLUA_CLASS_END

OOLUA_CLASS(ProfileMultiBases) :public Proxy_class<ProfileDerived>, public Proxy_class<ProfileAnotherBase>
	OOLUA_BASIC
	OOLUA_NO_TYPEDEFS
	OOLUA_BASES_START ProfileDerived,ProfileAnotherBase OOLUA_BASES_END
	OOLUA_ONLY_DEFAULT_CONSTRUCTOR
OOLUA_CLASS_END

void open_Luabind_hierarchy(lua_State* l);

void open_LuaBridge_hierarchy(lua_State* l);

#endif
