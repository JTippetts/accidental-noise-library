///////////////////////////////////////////////////////////////////////////////
///  @file member_func_helper.h
///  @author Liam Devine
///  @email
///  See http://www.liamdevine.co.uk for contact details.
///  @licence
///  See licence.txt for more details. \n 
///////////////////////////////////////////////////////////////////////////////
#ifndef MEMBER_FUNC_HELPER_H_
#	define MEMBER_FUNC_HELPER_H_

#	include "lua_includes.h"
#	include "fwd_push_pull.h"
#	include "oolua_error.h"

#include<cassert>
#	include "push_pointer_internal.h"

namespace OOLUA
{

	namespace
	{
		template<typename Raw,typename T,int is_by_value = 0 >
		struct proxy_maybe_by_ref
		{
			static void push(lua_State* const s, T& value,Owner owner)
			{
				OOLUA::INTERNAL::push_pointer_which_has_a_proxy_class<Raw>(s,&value,owner);
			}
		};

		template<typename Raw,typename T>
		struct proxy_maybe_by_ref<Raw,T,1>
		{
			static void push(lua_State* const s, T& value,Owner /*owner*/)
			{
				Raw* ptr = new Raw(value);
				OOLUA::INTERNAL::push_pointer_which_has_a_proxy_class<Raw>(s,ptr,Lua);
			}
		};
		
	
		template<typename T,typename WT,int is_integral = 1>
		struct maybe_integral
		{
			static void pull(lua_State* const s, T& value)
			{
				OOLUA::INTERNAL::LUA_CALLED::pull2cpp(s,value);
			}
			static void push(lua_State* const s, T& value)
			{
				OOLUA::push2lua(s,value);
			}
		};

		//user defined type
		template<typename T,typename WT>
		struct maybe_integral<T,WT,0>
		{
			static void pull(lua_State* const s, T*& value)
			{
				OOLUA::INTERNAL::LUA_CALLED::pull2cpp(s,value);
			}
			static void push(lua_State* const s, T& value)
			{
				proxy_maybe_by_ref<typename WT::raw_type,T,WT::is_by_value>::push(s,value,(Owner)WT::owner);
			}
		};
	}


	
	namespace INTERNAL
	{

	template<typename TypeWithTraits, int owner>struct Member_func_helper;
	
	template<typename TypeWithTraits>
	struct Member_func_helper<TypeWithTraits,No_change>
	{
		
		template<typename T>
		static void pull2cpp(lua_State* const s, T*& value)
		{
			maybe_integral<T,TypeWithTraits,TypeWithTraits::is_integral>::pull(s,value);
		}
		template<typename T>
		static void pull2cpp(lua_State* const s, T& value)
		{
			maybe_integral<T,TypeWithTraits,TypeWithTraits::is_integral>::pull(s,value);
		}
		
		
		template<typename T>
		static void push2lua(lua_State* const s, T& value)
		{
			maybe_integral<T,TypeWithTraits,TypeWithTraits::is_integral>::push(s,value);
		}
		template<typename T>
		static void push2lua(lua_State* const s, T*& value)
		{
			OOLUA::push2lua(s,value,No_change);
		}
		///special case "T* const" and "T const * const"
		template<typename T>
		static void push2lua(lua_State* const s, T*const& value)
		{
			OOLUA::push2lua(s,value,No_change);
		}
		static void pull2cpp(lua_State* const s, lua_State *& l)
		{
			typedef char type_has_to_be_calling_lua_state[LVD::is_same<param_type<calling_lua_state>,TypeWithTraits>::value ? 1 : -1];
			l = s;
		}

		static void push2lua(lua_State* const , lua_State *& )
		{
			assert(0 && "this function should not be called");
		}

	};
	template<typename TypeWithTraits>
	struct Member_func_helper<TypeWithTraits,Cpp>
	{
		template<typename T>
		static void pull2cpp(lua_State* const s, T*& value)
		{
			OOLUA::cpp_acquire_ptr<typename TypeWithTraits::type > p;
			OOLUA::INTERNAL::LUA_CALLED::pull2cpp(s,p);
			value = p.m_ptr;
		}
		template<typename T>
		static void push2lua(lua_State* const /*s*/, T*& /*value*/)//noop
		{
			assert(0 && "this function should never be called");
		}
	};
	
	
	template<typename TypeWithTraits>
	struct Member_func_helper<TypeWithTraits,Lua>
	{
		template<typename T>
		static void push2lua(lua_State* const s, T*& value)
		{
			OOLUA::lua_acquire_ptr<typename TypeWithTraits::type> p(value);
			OOLUA::push2lua(s,p);
		}
		template<typename T>
		static void push2lua(lua_State* const s, T& value)
		{
			proxy_maybe_by_ref<typename TypeWithTraits::raw_type
								,T
								,TypeWithTraits::is_by_value>::push(s,value,(Owner)TypeWithTraits::owner);
		}
		
		template<typename T>
		static void pull2cpp(lua_State* const /*s*/, T& /*value*/)//noop
		{
			assert(0 && "this function should never be called");
		}
		
		template<typename T>
		static void pull2cpp(lua_State* const /*s*/, T*& /*value*/)//noop
		{
			assert(0 && "this function should never be called");
		}
	};

	}


}
 #endif

