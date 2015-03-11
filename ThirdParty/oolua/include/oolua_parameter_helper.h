#ifndef OOLUA_PARAMETER_HELPER_H_
#	define OOLUA_PARAMETER_HELPER_H_

//#	include "param_traits.h"
#	include "oolua_userdata.h"
#	include "lua_includes.h"
#	include "class_from_stack.h"
#	include "oolua_config.h"

namespace OOLUA
{
	namespace INTERNAL
	{
		
		template<typename TypeWithTraits,int Is_intergral>
		struct index_can_convert_to_type
		{
			static int valid(lua_State* /*l*/,int const& /*index*/){return 0;}//noop
		};
		
		template<typename TypeWithTraits>
		struct index_can_convert_to_type<TypeWithTraits,0>
		{
			static int valid(lua_State* l,int index)
			{
MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA
				if( !TypeWithTraits::is_constant
				   && INTERNAL::userdata_is_constant(static_cast<INTERNAL::Lua_ud *>( lua_touserdata(l, index) ) )  )
				{
					return 0;
				}
				return OOLUA::INTERNAL::class_from_index<typename TypeWithTraits::raw_type>(l,index)!=0;
MSC_POP_COMPILER_WARNING_OOLUA
			}

		};
	
		template<typename ParamWithTraits>struct Param_helper;
		
		template<>
		struct Param_helper<param_type<calling_lua_state> >
		{
			static int param_is_of_type(lua_State* /*l*/, int& /*index*/)
			{
				return 1;
			}
		};

		template<typename ParamWithTraits>
		struct Param_helper
		{
			static int param_is_of_type(lua_State* l,int & index)
			{
				switch ( lua_type(l,index) ) 
				{
					case LUA_TBOOLEAN :
						return lua_type_is_cpp_type<typename ParamWithTraits::raw_type,LUA_TBOOLEAN>::value && ++index ? 1 : 0 ;
					case LUA_TNUMBER :
						return lua_type_is_cpp_type<typename ParamWithTraits::raw_type,LUA_TNUMBER>::value && ++index ? 1 : 0 ;
					case LUA_TSTRING :
						return lua_type_is_cpp_type<typename ParamWithTraits::raw_type,LUA_TSTRING>::value && ++index ? 1 : 0 ;
					case LUA_TFUNCTION :
						return lua_type_is_cpp_type<typename ParamWithTraits::raw_type,LUA_TFUNCTION>::value && ++index ? 1 : 0 ;
					case LUA_TTABLE :
						return lua_type_is_cpp_type<typename ParamWithTraits::raw_type,LUA_TTABLE>::value && ++index ? 1 : 0 ;
					case LUA_TUSERDATA:
						if( index_can_convert_to_type<ParamWithTraits,ParamWithTraits::is_integral>::valid(l,index) ) 
						{	++index;
							return 1;
						}
						return 0;					
					default:
						return 0;
						break;
				}
			}
		};
	}
}

#endif
