#ifndef EXPOSE_CLASS_ENUMS_H_
#	define EXPOSE_CLASS_ENUMS_H_

#	include "oolua.h"
#	include "cpp_class_enums.h"


/*
Register_class_enums : tag for hey there are enums in this class that need registering when 
the class type is registered
*/
OOLUA_PROXY_CLASS(ClassWithEnums)
	OOLUA_TYPEDEFS No_public_constructors, Register_class_enums OOLUA_END_TYPES
	OOLUA_ENUMS
		OOLUA_ENUM_ENTRY(UNNAMED_ENUM_0)
		OOLUA_ENUM_ENTRY(UNNAMED_ENUM_1)
		OOLUA_ENUM_ENTRY(ENUM_0)
		OOLUA_ENUM_ENTRY(ENUM_1)
	OOLUA_ENUMS_END
OOLUA_CLASS_END

#endif

