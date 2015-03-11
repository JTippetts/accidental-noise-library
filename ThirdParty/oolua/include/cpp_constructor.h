#ifndef OOLUA_CPP_CONSTRUCTOR_H_
#	define OOLUA_CPP_CONSTRUCTOR_H_

///////////////////////////////////////////////////////////////////////////////
///  @file cpp_constructor.h
///  @remarks Warning this file was generated, edits to it will not persist if 
///  the file is regenerated.
///  @author Liam Devine
///  @email
///  See http://www.liamdevine.co.uk for contact details.
///  @licence 
///  See licence.txt for more details. \n 
///////////////////////////////////////////////////////////////////////////////
#	include "lua_includes.h"
#	include "oolua_storage.h"
#	include "param_traits.h"
#	include "oolua_userdata.h"
#	include "member_func_helper.h"
#	include "oolua_parameter_helper.h"
#	include "oolua_converters.h"
namespace OOLUA
{
namespace INTERNAL
{
template<typename ObjType>
void add_and_set_gc(lua_State* l,ObjType obj)
{
	Lua_ud* ud = add_ptr(l,obj,false);
	userdata_gc_value(ud,true);
}

template<typename Type,int HasNoDefaultTypedef>
struct Constructor
{
	static int construct(lua_State * l)
	{
		Type* obj = new Type;
		add_and_set_gc(l,obj);
		return 1;
	}
};
template<typename Type>
struct Constructor<Type,1>
{
	static int construct(lua_State * l)
	{
		luaL_error(l,"%s %s %s","No parameters passed to the constructor of the type"
			,OOLUA::Proxy_class<Type>::class_name
			,"which does not have a default constructor.");
		return 0;//required by function sig yet luaL_error never returns
	}
};
template<typename Class,typename Param1WithTraits >
struct Constructor1
{
	static int construct(lua_State* l) 
	{
		int index(1);
		if(Param_helper<Param1WithTraits >::param_is_of_type(l,index))
		{
			valid_construct(l);
			return 1;
		}
		return 0;
	}
	static void valid_construct(lua_State* l)
	{
		typename Param1WithTraits::pull_type p1;
		Member_func_helper<Param1WithTraits,Param1WithTraits::owner>::pull2cpp(l,p1);
		Converter<typename Param1WithTraits::pull_type,typename Param1WithTraits::type> p1_(p1);
		Class* obj = new Class( p1_);
		add_and_set_gc(l,obj);
	}
};
template<typename Class,typename Param1WithTraits, typename Param2WithTraits >
struct Constructor2
{
	static int construct(lua_State* l) 
	{
		int index(1);
		if(Param_helper<Param1WithTraits >::param_is_of_type(l,index)
			&& Param_helper<Param2WithTraits >::param_is_of_type(l,index))
		{
			valid_construct(l);
			return 1;
		}
		return 0;
	}
	static void valid_construct(lua_State* l)
	{
		typename Param2WithTraits::pull_type p2;
		Member_func_helper<Param2WithTraits,Param2WithTraits::owner>::pull2cpp(l,p2);
		Converter<typename Param2WithTraits::pull_type,typename Param2WithTraits::type> p2_(p2);
		typename Param1WithTraits::pull_type p1;
		Member_func_helper<Param1WithTraits,Param1WithTraits::owner>::pull2cpp(l,p1);
		Converter<typename Param1WithTraits::pull_type,typename Param1WithTraits::type> p1_(p1);
		Class* obj = new Class( p1_,p2_);
		add_and_set_gc(l,obj);
	}
};
template<typename Class,typename Param1WithTraits, typename Param2WithTraits, typename Param3WithTraits >
struct Constructor3
{
	static int construct(lua_State* l) 
	{
		int index(1);
		if(Param_helper<Param1WithTraits >::param_is_of_type(l,index)
			&& Param_helper<Param2WithTraits >::param_is_of_type(l,index)
			&& Param_helper<Param3WithTraits >::param_is_of_type(l,index))
		{
			valid_construct(l);
			return 1;
		}
		return 0;
	}
	static void valid_construct(lua_State* l)
	{
		typename Param3WithTraits::pull_type p3;
		Member_func_helper<Param3WithTraits,Param3WithTraits::owner>::pull2cpp(l,p3);
		Converter<typename Param3WithTraits::pull_type,typename Param3WithTraits::type> p3_(p3);
		typename Param2WithTraits::pull_type p2;
		Member_func_helper<Param2WithTraits,Param2WithTraits::owner>::pull2cpp(l,p2);
		Converter<typename Param2WithTraits::pull_type,typename Param2WithTraits::type> p2_(p2);
		typename Param1WithTraits::pull_type p1;
		Member_func_helper<Param1WithTraits,Param1WithTraits::owner>::pull2cpp(l,p1);
		Converter<typename Param1WithTraits::pull_type,typename Param1WithTraits::type> p1_(p1);
		Class* obj = new Class( p1_,p2_,p3_);
		add_and_set_gc(l,obj);
	}
};
template<typename Class,typename Param1WithTraits, typename Param2WithTraits, typename Param3WithTraits, typename Param4WithTraits >
struct Constructor4
{
	static int construct(lua_State* l) 
	{
		int index(1);
		if(Param_helper<Param1WithTraits >::param_is_of_type(l,index)
			&& Param_helper<Param2WithTraits >::param_is_of_type(l,index)
			&& Param_helper<Param3WithTraits >::param_is_of_type(l,index)
			&& Param_helper<Param4WithTraits >::param_is_of_type(l,index))
		{
			valid_construct(l);
			return 1;
		}
		return 0;
	}
	static void valid_construct(lua_State* l)
	{
		typename Param4WithTraits::pull_type p4;
		Member_func_helper<Param4WithTraits,Param4WithTraits::owner>::pull2cpp(l,p4);
		Converter<typename Param4WithTraits::pull_type,typename Param4WithTraits::type> p4_(p4);
		typename Param3WithTraits::pull_type p3;
		Member_func_helper<Param3WithTraits,Param3WithTraits::owner>::pull2cpp(l,p3);
		Converter<typename Param3WithTraits::pull_type,typename Param3WithTraits::type> p3_(p3);
		typename Param2WithTraits::pull_type p2;
		Member_func_helper<Param2WithTraits,Param2WithTraits::owner>::pull2cpp(l,p2);
		Converter<typename Param2WithTraits::pull_type,typename Param2WithTraits::type> p2_(p2);
		typename Param1WithTraits::pull_type p1;
		Member_func_helper<Param1WithTraits,Param1WithTraits::owner>::pull2cpp(l,p1);
		Converter<typename Param1WithTraits::pull_type,typename Param1WithTraits::type> p1_(p1);
		Class* obj = new Class( p1_,p2_,p3_,p4_);
		add_and_set_gc(l,obj);
	}
};
template<typename Class,typename Param1WithTraits, typename Param2WithTraits, typename Param3WithTraits, typename Param4WithTraits, typename Param5WithTraits >
struct Constructor5
{
	static int construct(lua_State* l) 
	{
		int index(1);
		if(Param_helper<Param1WithTraits >::param_is_of_type(l,index)
			&& Param_helper<Param2WithTraits >::param_is_of_type(l,index)
			&& Param_helper<Param3WithTraits >::param_is_of_type(l,index)
			&& Param_helper<Param4WithTraits >::param_is_of_type(l,index)
			&& Param_helper<Param5WithTraits >::param_is_of_type(l,index))
		{
			valid_construct(l);
			return 1;
		}
		return 0;
	}
	static void valid_construct(lua_State* l)
	{
		typename Param5WithTraits::pull_type p5;
		Member_func_helper<Param5WithTraits,Param5WithTraits::owner>::pull2cpp(l,p5);
		Converter<typename Param5WithTraits::pull_type,typename Param5WithTraits::type> p5_(p5);
		typename Param4WithTraits::pull_type p4;
		Member_func_helper<Param4WithTraits,Param4WithTraits::owner>::pull2cpp(l,p4);
		Converter<typename Param4WithTraits::pull_type,typename Param4WithTraits::type> p4_(p4);
		typename Param3WithTraits::pull_type p3;
		Member_func_helper<Param3WithTraits,Param3WithTraits::owner>::pull2cpp(l,p3);
		Converter<typename Param3WithTraits::pull_type,typename Param3WithTraits::type> p3_(p3);
		typename Param2WithTraits::pull_type p2;
		Member_func_helper<Param2WithTraits,Param2WithTraits::owner>::pull2cpp(l,p2);
		Converter<typename Param2WithTraits::pull_type,typename Param2WithTraits::type> p2_(p2);
		typename Param1WithTraits::pull_type p1;
		Member_func_helper<Param1WithTraits,Param1WithTraits::owner>::pull2cpp(l,p1);
		Converter<typename Param1WithTraits::pull_type,typename Param1WithTraits::type> p1_(p1);
		Class* obj = new Class( p1_,p2_,p3_,p4_,p5_);
		add_and_set_gc(l,obj);
	}
};

}
}
#define OOLUA_CONSTRUCTORS_BEGIN \
static int oolua_factory_function(lua_State* l) \
{ \
	lua_remove(l, 1);/*remove class type*/ \
	int const stack_count = lua_gettop(l);
#define OOLUA_CONSTRUCTOR_1(param1Type) \
	MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA \
	if( (stack_count == 1 && TYPELIST::IndexOf<Type_list<param1Type>::type, calling_lua_state>::value == -1) \
		|| (stack_count == 0 && TYPELIST::IndexOf<Type_list<param1Type>::type, calling_lua_state>::value != -1) ) \
	{ \
		if(INTERNAL::Constructor1<class_,INTERNAL::param_type<param1Type > >::construct(l) ) return 1; \
	} \
	MSC_POP_COMPILER_WARNING_OOLUA

#define OOLUA_CONSTRUCTOR_2(param1Type,param2Type) \
	MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA \
	if( (stack_count == 2 && TYPELIST::IndexOf<Type_list<param1Type,param2Type>::type, calling_lua_state>::value == -1) \
		|| (stack_count == 1 && TYPELIST::IndexOf<Type_list<param1Type,param2Type>::type, calling_lua_state>::value != -1) ) \
	{ \
		if(INTERNAL::Constructor2<class_,INTERNAL::param_type<param1Type >,INTERNAL::param_type<param2Type > >::construct(l) ) return 1; \
	} \
	MSC_POP_COMPILER_WARNING_OOLUA

#define OOLUA_CONSTRUCTOR_3(param1Type,param2Type,param3Type) \
	MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA \
	if( (stack_count == 3 && TYPELIST::IndexOf<Type_list<param1Type,param2Type,param3Type>::type, calling_lua_state>::value == -1) \
		|| (stack_count == 2 && TYPELIST::IndexOf<Type_list<param1Type,param2Type,param3Type>::type, calling_lua_state>::value != -1) ) \
	{ \
		if(INTERNAL::Constructor3<class_,INTERNAL::param_type<param1Type >,INTERNAL::param_type<param2Type >,INTERNAL::param_type<param3Type > >::construct(l) ) return 1; \
	} \
	MSC_POP_COMPILER_WARNING_OOLUA

#define OOLUA_CONSTRUCTOR_4(param1Type,param2Type,param3Type,param4Type) \
	MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA \
	if( (stack_count == 4 && TYPELIST::IndexOf<Type_list<param1Type,param2Type,param3Type,param4Type>::type, calling_lua_state>::value == -1) \
		|| (stack_count == 3 && TYPELIST::IndexOf<Type_list<param1Type,param2Type,param3Type,param4Type>::type, calling_lua_state>::value != -1) ) \
	{ \
		if(INTERNAL::Constructor4<class_,INTERNAL::param_type<param1Type >,INTERNAL::param_type<param2Type >,INTERNAL::param_type<param3Type >,INTERNAL::param_type<param4Type > >::construct(l) ) return 1; \
	} \
	MSC_POP_COMPILER_WARNING_OOLUA

#define OOLUA_CONSTRUCTOR_5(param1Type,param2Type,param3Type,param4Type,param5Type) \
	MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA \
	if( (stack_count == 5 && TYPELIST::IndexOf<Type_list<param1Type,param2Type,param3Type,param4Type,param5Type>::type, calling_lua_state>::value == -1) \
		|| (stack_count == 4 && TYPELIST::IndexOf<Type_list<param1Type,param2Type,param3Type,param4Type,param5Type>::type, calling_lua_state>::value != -1) ) \
	{ \
		if(INTERNAL::Constructor5<class_,INTERNAL::param_type<param1Type >,INTERNAL::param_type<param2Type >,INTERNAL::param_type<param3Type >,INTERNAL::param_type<param4Type >,INTERNAL::param_type<param5Type > >::construct(l) ) return 1; \
	} \
	MSC_POP_COMPILER_WARNING_OOLUA

#define OOLUA_CONSTRUCTORS_END \
	if(stack_count == 0 ) \
	{ \
		return INTERNAL::Constructor<class_,INTERNAL::has_typedef<this_type, No_default_constructor>::Result>::construct(l); \
	} \
	luaL_error(l,"%s %d %s %s","Could not match",stack_count,"parameter constructor for type",class_name); \
	return 0;/*required by function sig yet luaL_error never returns*/  \
}

#define OOLUA_ONLY_DEFAULT_CONSTRUCTOR \
OOLUA_CONSTRUCTORS_BEGIN \
OOLUA_CONSTRUCTORS_END



#endif 
