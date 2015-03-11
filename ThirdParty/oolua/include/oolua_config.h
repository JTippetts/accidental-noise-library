#ifndef OOLUA_CONFIG_H_
#	define OOLUA_CONFIG_H_

///def OOLUA_RUNTIME_CHECKS_ENABLED
///Checks that a type being pulled off the stack is of the correct type
///If this is a proxy type, it also checks the userdata on the stack was created by OOLua
//#define OOLUA_RUNTIME_CHECKS_ENABLED 0
#ifndef OOLUA_RUNTIME_CHECKS_ENABLED
#	define OOLUA_RUNTIME_CHECKS_ENABLED 1
#endif

///def OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA
//Does what it says on the tin, only valid when 
//#define OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA 0
#if OOLUA_RUNTIME_CHECKS_ENABLED == 1
#	ifndef OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA
#		define OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA 1
#	endif
#else
#	ifdef OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA
#		undef OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA
#	endif
#	define OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA  0
#endif

/*
Userdata optimisation which checks for a magic cookie to try and ensure it was created by OOLua, 
by default this is on when userdata checking is on. Turning this off by setting it to zero will
use a slower yet fully correct method.
*/
#if OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA == 1
#	ifndef OOLUA_USERDATA_OPTIMISATION
#		define OOLUA_USERDATA_OPTIMISATION 1
#	endif
#endif



///def OOLUA_STD_STRING_IS_INTEGRAL
///If 1 Allows std::string to be a parameter or a return type for a function. 
///NOTE: This is always by value
#ifndef OOLUA_STD_STRING_IS_INTEGRAL
#	define OOLUA_STD_STRING_IS_INTEGRAL 1
#endif


//How to handle errors only one of these should be used

///def OOLUA_USE_EXCEPTIONS
///If 1 Throws exceptions from C++ code
//		This could be the return of a pcall
//		Pulling an incorrect type of the stack if OOLUA_RUNTIME_CHECKS_ENABLED == 1
#ifndef OOLUA_USE_EXCEPTIONS
#	define OOLUA_USE_EXCEPTIONS 0
#endif


///def OOLUA_STORE_LAST_ERROR
///When it fails it stores the error in the Lua registry and is retrievable via 
//		OOLUA::get_last_error(lua);
//#define OOLUA_STORE_LAST_ERROR 0
#ifndef OOLUA_STORE_LAST_ERROR
#	define OOLUA_STORE_LAST_ERROR 1
#endif

#if OOLUA_USE_EXCEPTIONS == 1 && OOLUA_STORE_LAST_ERROR == 1
#	error Only one of these settings can be on
#endif

///def OOLUA_DEBUG_CHECKS
///Checks for null pointers 
///adds a stack trace to messages called within pcall
#if defined DEBUG || defined _DEBUG
#	define OOLUA_DEBUG_CHECKS 1
#else
#	define OOLUA_DEBUG_CHECKS 0
#endif


//TODO: implement this
#ifndef OOLUA_STACK_NUMBER_CAN_CONVERT_TO_BOOL
#	define OOLUA_STACK_NUMBER_CAN_CONVERT_TO_BOOL == 0
#endif

//check everything
#define OOLUA_SANDBOX 0

#if OOLUA_SANDBOX == 1
#	if defined OOLUA_RUNTIME_CHECKS_ENABLED && OOLUA_RUNTIME_CHECKS_ENABLED == 0
#		undef OOLUA_RUNTIME_CHECKS_ENABLED
#		define OOLUA_RUNTIME_CHECKS_ENABLED 1
#	endif

#	if defined OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA && OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA == 0 
#		undef OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA
#	endif

#	ifndef OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA
#		define OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA 1
#	endif

//if neither are set then default to storing errors
#	if defined OOLUA_USE_EXCEPTIONS && OOLUA_USE_EXCEPTIONS == 0 \
	&& defined OOLUA_STORE_LAST_ERROR && OOLUA_STORE_LAST_ERROR == 0
#		undef OOLUA_STORE_LAST_ERROR
#		define OOLUA_STORE_LAST_ERROR 1
#	endif
#endif



#ifdef _MSC_VER 
#	define MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA \
__pragma(warning(push)) \
__pragma(warning(disable : 4127)) 
#	define MSC_POP_COMPILER_WARNING_OOLUA \
__pragma(warning(pop)) 
#else
#	define MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA 
#	define MSC_POP_COMPILER_WARNING_OOLUA
#endif

#if OOLUA_USE_EXCEPTIONS == 1
#	if defined __GNUC__ && ( ( !defined __EXCEPTIONS) || (defined __EXCEPTIONS && __EXCEPTIONS != 1) ) 
#			error OOLua has been compiled with exceptions yet they have been disabled for this build 
#	elif defined _MSC_VER //&& !defined _HAS_EXCEPTIONS
#		if defined(_HAS_EXCEPTIONS) && (_HAS_EXCEPTIONS == 0) 
#			error OOLua has been compiled with exceptions yet they have been disabled for this build
#		endif
#	endif
#endif


#endif
