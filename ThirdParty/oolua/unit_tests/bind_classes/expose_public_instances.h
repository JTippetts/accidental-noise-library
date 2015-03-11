#ifndef EXPOSE_PUBLIC_INSTANCES_OOLUA_H_
#	define EXPOSE_PUBLIC_INSTANCES_OOLUA_H_

#include "oolua.h"
#include "cpp_public_instances.h"
#include "cpp_stub_classes.h"

OOLUA_CLASS_NO_BASES(Public_variables)
	OOLUA_NO_TYPEDEFS
	OOLUA_ONLY_DEFAULT_CONSTRUCTOR
	OOLUA_PUBLIC_MEMBER_GET_SET(an_int)
	OOLUA_PUBLIC_MEMBER_GET_SET(int_ptr)
	OOLUA_PUBLIC_MEMBER_GET_SET(dummy_instance)
	OOLUA_PUBLIC_MEMBER_GET(dummy_ref)
	OOLUA_PUBLIC_MEMBER_GET(dummy_instance_none_ptr)
OOLUA_CLASS_END

#endif
