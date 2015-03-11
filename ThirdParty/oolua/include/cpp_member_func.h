///////////////////////////////////////////////////////////////////////////////
///  @file cpp_member_func.h
///  @remarks Warning this file was generated, edits to it will not persist if 
///  the file is regenerated.
///  @author Liam Devine
///  @email
///  See http://www.liamdevine.co.uk for contact details.
///  @licence 
///  See licence.txt for more details. \n 
///////////////////////////////////////////////////////////////////////////////
#ifndef CPP_MEMBER_FUNC_H_
#	define CPP_MEMBER_FUNC_H_

#	include "param_traits.h"
#	include "oolua_paramater_macros.h"
#	include "proxy_caller.h"
#	include <cassert>
#define OOLUA_CONST_FUNC const
#define OOLUA_NON_CONST_FUNC

//member function macros
#define OOLUA_MEM_FUNC_0(return_value,func)\
	LUA_CLASS_MEMBER_FUNCTION_0(func,return_value,func,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_0_CONST(return_value,func)\
	LUA_CLASS_MEMBER_FUNCTION_0(func,return_value,func,OOLUA_CONST_FUNC)
#define OOLUA_MEM_FUNC_0_RENAME(name,return_value,func)\
	LUA_CLASS_MEMBER_FUNCTION_0(name,return_value,func,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_0_CONST_RENAME(name,return_value,func)\
	LUA_CLASS_MEMBER_FUNCTION_0(name,return_value,func,OOLUA_CONST_FUNC)


#define OOLUA_MEM_FUNC_1(return_value,func,P1)\
	LUA_CLASS_MEMBER_FUNCTION_1(func,return_value,func,P1,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_1_CONST(return_value,func,P1)\
	LUA_CLASS_MEMBER_FUNCTION_1(func,return_value,func,P1,OOLUA_CONST_FUNC)
#define OOLUA_MEM_FUNC_1_RENAME(name,return_value,func,P1)\
	LUA_CLASS_MEMBER_FUNCTION_1(name,return_value,func,P1,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_1_CONST_RENAME(name,return_value,func,P1)\
	LUA_CLASS_MEMBER_FUNCTION_1(name,return_value,func,P1,OOLUA_CONST_FUNC)


#define OOLUA_MEM_FUNC_2(return_value,func,P1,P2)\
	LUA_CLASS_MEMBER_FUNCTION_2(func,return_value,func,P1,P2,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_2_CONST(return_value,func,P1,P2)\
	LUA_CLASS_MEMBER_FUNCTION_2(func,return_value,func,P1,P2,OOLUA_CONST_FUNC)
#define OOLUA_MEM_FUNC_2_RENAME(name,return_value,func,P1,P2)\
	LUA_CLASS_MEMBER_FUNCTION_2(name,return_value,func,P1,P2,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_2_CONST_RENAME(name,return_value,func,P1,P2)\
	LUA_CLASS_MEMBER_FUNCTION_2(name,return_value,func,P1,P2,OOLUA_CONST_FUNC)


#define OOLUA_MEM_FUNC_3(return_value,func,P1,P2,P3)\
	LUA_CLASS_MEMBER_FUNCTION_3(func,return_value,func,P1,P2,P3,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_3_CONST(return_value,func,P1,P2,P3)\
	LUA_CLASS_MEMBER_FUNCTION_3(func,return_value,func,P1,P2,P3,OOLUA_CONST_FUNC)
#define OOLUA_MEM_FUNC_3_RENAME(name,return_value,func,P1,P2,P3)\
	LUA_CLASS_MEMBER_FUNCTION_3(name,return_value,func,P1,P2,P3,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_3_CONST_RENAME(name,return_value,func,P1,P2,P3)\
	LUA_CLASS_MEMBER_FUNCTION_3(name,return_value,func,P1,P2,P3,OOLUA_CONST_FUNC)


#define OOLUA_MEM_FUNC_4(return_value,func,P1,P2,P3,P4)\
	LUA_CLASS_MEMBER_FUNCTION_4(func,return_value,func,P1,P2,P3,P4,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_4_CONST(return_value,func,P1,P2,P3,P4)\
	LUA_CLASS_MEMBER_FUNCTION_4(func,return_value,func,P1,P2,P3,P4,OOLUA_CONST_FUNC)
#define OOLUA_MEM_FUNC_4_RENAME(name,return_value,func,P1,P2,P3,P4)\
	LUA_CLASS_MEMBER_FUNCTION_4(name,return_value,func,P1,P2,P3,P4,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_4_CONST_RENAME(name,return_value,func,P1,P2,P3,P4)\
	LUA_CLASS_MEMBER_FUNCTION_4(name,return_value,func,P1,P2,P3,P4,OOLUA_CONST_FUNC)


#define OOLUA_MEM_FUNC_5(return_value,func,P1,P2,P3,P4,P5)\
	LUA_CLASS_MEMBER_FUNCTION_5(func,return_value,func,P1,P2,P3,P4,P5,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_5_CONST(return_value,func,P1,P2,P3,P4,P5)\
	LUA_CLASS_MEMBER_FUNCTION_5(func,return_value,func,P1,P2,P3,P4,P5,OOLUA_CONST_FUNC)
#define OOLUA_MEM_FUNC_5_RENAME(name,return_value,func,P1,P2,P3,P4,P5)\
	LUA_CLASS_MEMBER_FUNCTION_5(name,return_value,func,P1,P2,P3,P4,P5,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_5_CONST_RENAME(name,return_value,func,P1,P2,P3,P4,P5)\
	LUA_CLASS_MEMBER_FUNCTION_5(name,return_value,func,P1,P2,P3,P4,P5,OOLUA_CONST_FUNC)


#define OOLUA_MEM_FUNC_6(return_value,func,P1,P2,P3,P4,P5,P6)\
	LUA_CLASS_MEMBER_FUNCTION_6(func,return_value,func,P1,P2,P3,P4,P5,P6,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_6_CONST(return_value,func,P1,P2,P3,P4,P5,P6)\
	LUA_CLASS_MEMBER_FUNCTION_6(func,return_value,func,P1,P2,P3,P4,P5,P6,OOLUA_CONST_FUNC)
#define OOLUA_MEM_FUNC_6_RENAME(name,return_value,func,P1,P2,P3,P4,P5,P6)\
	LUA_CLASS_MEMBER_FUNCTION_6(name,return_value,func,P1,P2,P3,P4,P5,P6,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_6_CONST_RENAME(name,return_value,func,P1,P2,P3,P4,P5,P6)\
	LUA_CLASS_MEMBER_FUNCTION_6(name,return_value,func,P1,P2,P3,P4,P5,P6,OOLUA_CONST_FUNC)


#define OOLUA_MEM_FUNC_7(return_value,func,P1,P2,P3,P4,P5,P6,P7)\
	LUA_CLASS_MEMBER_FUNCTION_7(func,return_value,func,P1,P2,P3,P4,P5,P6,P7,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_7_CONST(return_value,func,P1,P2,P3,P4,P5,P6,P7)\
	LUA_CLASS_MEMBER_FUNCTION_7(func,return_value,func,P1,P2,P3,P4,P5,P6,P7,OOLUA_CONST_FUNC)
#define OOLUA_MEM_FUNC_7_RENAME(name,return_value,func,P1,P2,P3,P4,P5,P6,P7)\
	LUA_CLASS_MEMBER_FUNCTION_7(name,return_value,func,P1,P2,P3,P4,P5,P6,P7,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_7_CONST_RENAME(name,return_value,func,P1,P2,P3,P4,P5,P6,P7)\
	LUA_CLASS_MEMBER_FUNCTION_7(name,return_value,func,P1,P2,P3,P4,P5,P6,P7,OOLUA_CONST_FUNC)


#define OOLUA_MEM_FUNC_8(return_value,func,P1,P2,P3,P4,P5,P6,P7,P8)\
	LUA_CLASS_MEMBER_FUNCTION_8(func,return_value,func,P1,P2,P3,P4,P5,P6,P7,P8,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_8_CONST(return_value,func,P1,P2,P3,P4,P5,P6,P7,P8)\
	LUA_CLASS_MEMBER_FUNCTION_8(func,return_value,func,P1,P2,P3,P4,P5,P6,P7,P8,OOLUA_CONST_FUNC)
#define OOLUA_MEM_FUNC_8_RENAME(name,return_value,func,P1,P2,P3,P4,P5,P6,P7,P8)\
	LUA_CLASS_MEMBER_FUNCTION_8(name,return_value,func,P1,P2,P3,P4,P5,P6,P7,P8,OOLUA_NON_CONST_FUNC)
#define OOLUA_MEM_FUNC_8_CONST_RENAME(name,return_value,func,P1,P2,P3,P4,P5,P6,P7,P8)\
	LUA_CLASS_MEMBER_FUNCTION_8(name,return_value,func,P1,P2,P3,P4,P5,P6,P7,P8,OOLUA_CONST_FUNC)


//proxy implementations
#define LUA_CLASS_MEMBER_FUNCTION_0(func_name,return_value,func,mod)\
int func_name(lua_State* const l)mod\
{\
	assert(m_this);\
	typedef INTERNAL::return_type_traits<return_value > R;\
	typedef R::type (class_::*funcType )()mod ;\
	OOLUA::INTERNAL::Proxy_caller<R,class_,LVD::is_void< R::type >::value >::call<funcType>(l,m_this,&class_::func);\
	return INTERNAL::lua_return_count< Type_list<R  >::type> ::out;\
}
#define LUA_CLASS_MEMBER_FUNCTION_1(func_name,return_value,func,P1,mod)\
int func_name(lua_State* const l)mod\
{\
	assert(m_this);\
	OOLUA_PARAMS_INTERNAL_1(P1)\
	typedef INTERNAL::return_type_traits<return_value > R;\
	typedef R::type (class_::*funcType )(P1_::type)mod ;\
	OOLUA::INTERNAL::Proxy_caller<R,class_,LVD::is_void< R::type >::value >::call<P1_,funcType>(l,m_this,&class_::func,p1);\
	OOLUA_BACK_INTERNAL_1\
	return INTERNAL::lua_return_count< Type_list<R ,P1_ >::type> ::out;\
}
#define LUA_CLASS_MEMBER_FUNCTION_2(func_name,return_value,func,P1,P2,mod)\
int func_name(lua_State* const l)mod\
{\
	assert(m_this);\
	OOLUA_PARAMS_INTERNAL_2(P1,P2)\
	typedef INTERNAL::return_type_traits<return_value > R;\
	typedef R::type (class_::*funcType )(P1_::type,P2_::type)mod ;\
	OOLUA::INTERNAL::Proxy_caller<R,class_,LVD::is_void< R::type >::value >::call<P1_,P2_,funcType>(l,m_this,&class_::func,p1,p2);\
	OOLUA_BACK_INTERNAL_2\
	return INTERNAL::lua_return_count< Type_list<R ,P1_,P2_ >::type> ::out;\
}
#define LUA_CLASS_MEMBER_FUNCTION_3(func_name,return_value,func,P1,P2,P3,mod)\
int func_name(lua_State* const l)mod\
{\
	assert(m_this);\
	OOLUA_PARAMS_INTERNAL_3(P1,P2,P3)\
	typedef INTERNAL::return_type_traits<return_value > R;\
	typedef R::type (class_::*funcType )(P1_::type,P2_::type,P3_::type)mod ;\
	OOLUA::INTERNAL::Proxy_caller<R,class_,LVD::is_void< R::type >::value >::call<P1_,P2_,P3_,funcType>(l,m_this,&class_::func,p1,p2,p3);\
	OOLUA_BACK_INTERNAL_3\
	return INTERNAL::lua_return_count< Type_list<R ,P1_,P2_,P3_ >::type> ::out;\
}
#define LUA_CLASS_MEMBER_FUNCTION_4(func_name,return_value,func,P1,P2,P3,P4,mod)\
int func_name(lua_State* const l)mod\
{\
	assert(m_this);\
	OOLUA_PARAMS_INTERNAL_4(P1,P2,P3,P4)\
	typedef INTERNAL::return_type_traits<return_value > R;\
	typedef R::type (class_::*funcType )(P1_::type,P2_::type,P3_::type,P4_::type)mod ;\
	OOLUA::INTERNAL::Proxy_caller<R,class_,LVD::is_void< R::type >::value >::call<P1_,P2_,P3_,P4_,funcType>(l,m_this,&class_::func,p1,p2,p3,p4);\
	OOLUA_BACK_INTERNAL_4\
	return INTERNAL::lua_return_count< Type_list<R ,P1_,P2_,P3_,P4_ >::type> ::out;\
}
#define LUA_CLASS_MEMBER_FUNCTION_5(func_name,return_value,func,P1,P2,P3,P4,P5,mod)\
int func_name(lua_State* const l)mod\
{\
	assert(m_this);\
	OOLUA_PARAMS_INTERNAL_5(P1,P2,P3,P4,P5)\
	typedef INTERNAL::return_type_traits<return_value > R;\
	typedef R::type (class_::*funcType )(P1_::type,P2_::type,P3_::type,P4_::type,P5_::type)mod ;\
	OOLUA::INTERNAL::Proxy_caller<R,class_,LVD::is_void< R::type >::value >::call<P1_,P2_,P3_,P4_,P5_,funcType>(l,m_this,&class_::func,p1,p2,p3,p4,p5);\
	OOLUA_BACK_INTERNAL_5\
	return INTERNAL::lua_return_count< Type_list<R ,P1_,P2_,P3_,P4_,P5_ >::type> ::out;\
}
#define LUA_CLASS_MEMBER_FUNCTION_6(func_name,return_value,func,P1,P2,P3,P4,P5,P6,mod)\
int func_name(lua_State* const l)mod\
{\
	assert(m_this);\
	OOLUA_PARAMS_INTERNAL_6(P1,P2,P3,P4,P5,P6)\
	typedef INTERNAL::return_type_traits<return_value > R;\
	typedef R::type (class_::*funcType )(P1_::type,P2_::type,P3_::type,P4_::type,P5_::type,P6_::type)mod ;\
	OOLUA::INTERNAL::Proxy_caller<R,class_,LVD::is_void< R::type >::value >::call<P1_,P2_,P3_,P4_,P5_,P6_,funcType>(l,m_this,&class_::func,p1,p2,p3,p4,p5,p6);\
	OOLUA_BACK_INTERNAL_6\
	return INTERNAL::lua_return_count< Type_list<R ,P1_,P2_,P3_,P4_,P5_,P6_ >::type> ::out;\
}
#define LUA_CLASS_MEMBER_FUNCTION_7(func_name,return_value,func,P1,P2,P3,P4,P5,P6,P7,mod)\
int func_name(lua_State* const l)mod\
{\
	assert(m_this);\
	OOLUA_PARAMS_INTERNAL_7(P1,P2,P3,P4,P5,P6,P7)\
	typedef INTERNAL::return_type_traits<return_value > R;\
	typedef R::type (class_::*funcType )(P1_::type,P2_::type,P3_::type,P4_::type,P5_::type,P6_::type,P7_::type)mod ;\
	OOLUA::INTERNAL::Proxy_caller<R,class_,LVD::is_void< R::type >::value >::call<P1_,P2_,P3_,P4_,P5_,P6_,P7_,funcType>(l,m_this,&class_::func,p1,p2,p3,p4,p5,p6,p7);\
	OOLUA_BACK_INTERNAL_7\
	return INTERNAL::lua_return_count< Type_list<R ,P1_,P2_,P3_,P4_,P5_,P6_,P7_ >::type> ::out;\
}
#define LUA_CLASS_MEMBER_FUNCTION_8(func_name,return_value,func,P1,P2,P3,P4,P5,P6,P7,P8,mod)\
int func_name(lua_State* const l)mod\
{\
	assert(m_this);\
	OOLUA_PARAMS_INTERNAL_8(P1,P2,P3,P4,P5,P6,P7,P8)\
	typedef INTERNAL::return_type_traits<return_value > R;\
	typedef R::type (class_::*funcType )(P1_::type,P2_::type,P3_::type,P4_::type,P5_::type,P6_::type,P7_::type,P8_::type)mod ;\
	OOLUA::INTERNAL::Proxy_caller<R,class_,LVD::is_void< R::type >::value >::call<P1_,P2_,P3_,P4_,P5_,P6_,P7_,P8_,funcType>(l,m_this,&class_::func,p1,p2,p3,p4,p5,p6,p7,p8);\
	OOLUA_BACK_INTERNAL_8\
	return INTERNAL::lua_return_count< Type_list<R ,P1_,P2_,P3_,P4_,P5_,P6_,P7_,P8_ >::type> ::out;\
}


//member functions using default traits
#define OOLUA_USES_PARAMS_0
#define OOLUA_USES_PARAMS_1 typename P1,
#define OOLUA_USES_PARAMS_2 OOLUA_USES_PARAMS_1 typename P2,
#define OOLUA_USES_PARAMS_3 OOLUA_USES_PARAMS_2 typename P3,
#define OOLUA_USES_PARAMS_4 OOLUA_USES_PARAMS_3 typename P4,
#define OOLUA_USES_PARAMS_5 OOLUA_USES_PARAMS_4 typename P5,
#define OOLUA_USES_PARAMS_6 OOLUA_USES_PARAMS_5 typename P6,
#define OOLUA_USES_PARAMS_7 OOLUA_USES_PARAMS_6 typename P7,
#define OOLUA_USES_PARAMS_8 OOLUA_USES_PARAMS_7 typename P8,


#define OOLUA_FUNCTION_PARAMS_0
#define OOLUA_FUNCTION_PARAMS_1 P1
#define OOLUA_FUNCTION_PARAMS_2 OOLUA_FUNCTION_PARAMS_1 , P2
#define OOLUA_FUNCTION_PARAMS_3 OOLUA_FUNCTION_PARAMS_2 , P3
#define OOLUA_FUNCTION_PARAMS_4 OOLUA_FUNCTION_PARAMS_3 , P4
#define OOLUA_FUNCTION_PARAMS_5 OOLUA_FUNCTION_PARAMS_4 , P5
#define OOLUA_FUNCTION_PARAMS_6 OOLUA_FUNCTION_PARAMS_5 , P6
#define OOLUA_FUNCTION_PARAMS_7 OOLUA_FUNCTION_PARAMS_6 , P7
#define OOLUA_FUNCTION_PARAMS_8 OOLUA_FUNCTION_PARAMS_7 , P8


#define OOLUA_TPARAMS_0
#define OOLUA_TPARAMS_1 P1_,
#define OOLUA_TPARAMS_2 OOLUA_TPARAMS_1 P2_,
#define OOLUA_TPARAMS_3 OOLUA_TPARAMS_2 P3_,
#define OOLUA_TPARAMS_4 OOLUA_TPARAMS_3 P4_,
#define OOLUA_TPARAMS_5 OOLUA_TPARAMS_4 P5_,
#define OOLUA_TPARAMS_6 OOLUA_TPARAMS_5 P6_,
#define OOLUA_TPARAMS_7 OOLUA_TPARAMS_6 P7_,
#define OOLUA_TPARAMS_8 OOLUA_TPARAMS_7 P8_,


#define OOLUA_RETURNS_0
#define OOLUA_RETURNS_1 ,P1_
#define OOLUA_RETURNS_2 OOLUA_RETURNS_1 ,P2_
#define OOLUA_RETURNS_3 OOLUA_RETURNS_2 ,P3_
#define OOLUA_RETURNS_4 OOLUA_RETURNS_3 ,P4_
#define OOLUA_RETURNS_5 OOLUA_RETURNS_4 ,P5_
#define OOLUA_RETURNS_6 OOLUA_RETURNS_5 ,P6_
#define OOLUA_RETURNS_7 OOLUA_RETURNS_6 ,P7_
#define OOLUA_RETURNS_8 OOLUA_RETURNS_7 ,P8_


#define OOLUA_PPARAMS_0
#define OOLUA_PPARAMS_1 ,p1
#define OOLUA_PPARAMS_2 OOLUA_PPARAMS_1 ,p2
#define OOLUA_PPARAMS_3 OOLUA_PPARAMS_2 ,p3
#define OOLUA_PPARAMS_4 OOLUA_PPARAMS_3 ,p4
#define OOLUA_PPARAMS_5 OOLUA_PPARAMS_4 ,p5
#define OOLUA_PPARAMS_6 OOLUA_PPARAMS_5 ,p6
#define OOLUA_PPARAMS_7 OOLUA_PPARAMS_6 ,p7
#define OOLUA_PPARAMS_8 OOLUA_PPARAMS_7 ,p8


namespace OOLUA
{
	namespace INTERNAL
	{
		/*Two structures are used here instead of one and specialising so that compile 
		errors are forced instead of a runtime error when an incorrect macro is used */
		template<typename func_type, typename type = func_type>
		struct default_traits_caller;
		template<typename func_type, typename type = func_type>
		struct default_traits_const_caller;
	}
}




#define OOLUA_GENERATE_DEFAULT_TRAIT_CALLER(num) \
namespace OOLUA \
{ \
	namespace INTERNAL \
	{ \
		template <class class_type, typename return_type, OOLUA_USES_PARAMS_##num typename func_type> \
		struct default_traits_caller<return_type (class_type::*) (OOLUA_FUNCTION_PARAMS_##num),func_type> \
		{ \
			typedef OOLUA::INTERNAL::return_type_traits<return_type > R; \
			static int call (lua_State* l, class_type* this_, func_type mfptr) \
			{ \
				assert(this_); \
				OOLUA_PARAMS_T_INTERNAL_##num \
				OOLUA::INTERNAL::Proxy_caller< R, class_type, LVD::is_void<return_type >::value >:: template call<OOLUA_TPARAMS_##num func_type>(l,this_,mfptr OOLUA_PPARAMS_##num); \
				OOLUA_BACK_INTERNAL_ ##num \
				return OOLUA::INTERNAL::lua_return_count<typename Type_list<R OOLUA_RETURNS_##num >::type> ::out; \
			} \
		}; \
		template <class class_type, typename return_type, OOLUA_USES_PARAMS_##num typename func_type> \
		struct default_traits_const_caller<return_type (class_type::*) (OOLUA_FUNCTION_PARAMS_##num)const,func_type> \
		{ \
			typedef OOLUA::INTERNAL::return_type_traits<return_type > R; \
			static int call (lua_State* l, class_type* this_, func_type mfptr) \
			{ \
				assert(this_); \
				OOLUA_PARAMS_T_INTERNAL_##num \
				OOLUA::INTERNAL::Proxy_caller< R, class_type, LVD::is_void<return_type >::value >:: template call<OOLUA_TPARAMS_##num func_type>(l,this_,mfptr OOLUA_PPARAMS_##num); \
				OOLUA_BACK_INTERNAL_ ##num \
				return OOLUA::INTERNAL::lua_return_count<typename Type_list<R OOLUA_RETURNS_##num >::type> ::out; \
			} \
		}; \
	} \
}


OOLUA_GENERATE_DEFAULT_TRAIT_CALLER(0)
OOLUA_GENERATE_DEFAULT_TRAIT_CALLER(1)
OOLUA_GENERATE_DEFAULT_TRAIT_CALLER(2)
OOLUA_GENERATE_DEFAULT_TRAIT_CALLER(3)
OOLUA_GENERATE_DEFAULT_TRAIT_CALLER(4)
OOLUA_GENERATE_DEFAULT_TRAIT_CALLER(5)
OOLUA_GENERATE_DEFAULT_TRAIT_CALLER(6)
OOLUA_GENERATE_DEFAULT_TRAIT_CALLER(7)
OOLUA_GENERATE_DEFAULT_TRAIT_CALLER(8)


namespace OOLUA
{
	namespace INTERNAL
	{
		template<typename this_type,typename func_type>
		int proxy_member_function_with_default_traits(lua_State* l,this_type* this_,func_type mfptr)
		{
			return default_traits_caller<func_type>::call(l,this_,mfptr);
		}
		template<typename this_type,typename func_type>
		int proxy_const_member_function_with_default_traits(lua_State* l,this_type* this_,func_type mfptr)
		{
			return default_traits_const_caller<func_type>::call(l,this_,mfptr);
		}
	}
}

#define OOLUA_DEDUCE_FUNC(Name) \
int Name(lua_State* l) \
{ \
	return OOLUA::INTERNAL::proxy_member_function_with_default_traits(l, m_this, &class_::Name); \
}

#define OOLUA_DEDUCE_FUNC_CONST(Name) \
int Name(lua_State* l)const \
{ \
	return OOLUA::INTERNAL::proxy_const_member_function_with_default_traits(l, m_this, &class_::Name); \
}


#endif 
