#ifndef OOLUA_PUSH_PULL_H_
#	define OOLUA_PUSH_PULL_H_

#include <cassert>
#include <string>
#include "lua_includes.h"
#include "lua_table.h"
#include "lua_ref.h"
#include "lvd_types.h"
#include "param_traits.h"
#include "proxy_class.h"
#include "class_from_stack.h"
#include "push_pointer_internal.h"
#include "fwd_push_pull.h"
#include "oolua_parameter_helper.h"
#include "oolua_config.h"

namespace OOLUA
{
	
	bool push2lua(lua_State* const s, bool const& value);
	bool push2lua(lua_State* const s, std::string const& value);
	bool push2lua(lua_State* const s, char const * const& value);
	bool push2lua(lua_State* const s, char * const& value);
	bool push2lua(lua_State* const s, double const& value);
	bool push2lua(lua_State* const s, float const&  value);
	bool push2lua(lua_State* const s, lua_CFunction const &  value);
	bool push2lua(lua_State* const s, Lua_table const &  value);//can fail if from different state

	
	//cpp called
	bool pull2cpp(lua_State* const s, bool& value);
	bool pull2cpp(lua_State* const s, std::string& value);
	bool pull2cpp(lua_State* const s, double& value);
	bool pull2cpp(lua_State* const s, float& value);
	bool pull2cpp(lua_State* const s, lua_CFunction& value);
	bool pull2cpp(lua_State* const s, Lua_func_ref& value);
	bool pull2cpp(lua_State* const s, Lua_table&  value);
	bool pull2cpp(lua_State* const s, Lua_table_ref& value);
	
	
	namespace INTERNAL
	{
		
		typedef int (*compare_lua_type_func_sig)(lua_State*,int);
		bool cpp_runtime_type_check_of_top(lua_State* l, int looking_for_lua_type, char const * type);
		bool cpp_runtime_type_check_of_top(lua_State* l, compare_lua_type_func_sig compareFunc, char const * type);
		void handle_cpp_pull_fail(lua_State* l,char const * lookingFor);
		void local_function_to_set_owner( lua_State* l,void* ptr, Owner own);
		
		namespace LUA_CALLED
		{
			void pull_class_type_error(lua_State* const s,char const* type);
			void pull_error(lua_State* l, char const* when_pulling_this_type);
			
			
			void pull2cpp(lua_State* const s, bool& value);
			void pull2cpp(lua_State* const s, std::string& value);
			void pull2cpp(lua_State* const s, double& value);
			void pull2cpp(lua_State* const s, float& value);
			void pull2cpp(lua_State* const s, lua_CFunction& value);
			void pull2cpp(lua_State* const s, Lua_func_ref& value);
			void pull2cpp(lua_State* const s, Lua_table&  value);
			void pull2cpp(lua_State* const s, Lua_table_ref& value);
			
			template<typename T> 
			void pull2cpp(lua_State* const s, T& value);
			
			template<typename T>
			void pull2cpp(lua_State* const s, T *&  value);
			
			template<typename T>
			void pull2cpp(lua_State* const s, OOLUA::cpp_acquire_ptr<T>&  value);

		}
	}
	
	
	
	namespace INTERNAL
	{

		template<typename T,int is_integral>
		struct push_basic_type;


		template<typename T,bool IsIntegral>
		struct push_ptr_2lua;
		
		
		template<typename T>
		struct push_basic_type<T,0>
		{

			static bool push2lua(lua_State* const  s, T const&  value)
			{
				//enumeration type so a static cast must be allowed.
				//enums will be stronger in C++0x so this will need revisiting then
				typedef char dummy_can_convert [ can_convert_to_int<T>::value ? 1 : -1];
				lua_pushinteger(s, static_cast<lua_Integer>(value) );
				return true;

			}
		};

		template<typename T>
		struct push_basic_type<T,1>
		{
			static bool push2lua(lua_State* const  s, T const&  value)
			{
				lua_pushinteger(s, static_cast<lua_Integer>(value) );
				return true;
			}
		};




		template<typename T>
		struct push_ptr_2lua<T,false>
		{
			static bool push2lua(lua_State* const l, T * const &  value,Owner owner)
			{
				assert(l && value);
				OOLUA::INTERNAL::push_pointer_which_has_a_proxy_class<typename Raw_type<T>::type>(l,value,owner);
				return true;
			}

			static bool push2lua(lua_State* const l, T * const &  value)
			{
				return push_ptr_2lua<T,false>::push2lua(l,value,No_change);
			}
		};

		template<typename T>
		struct push_ptr_2lua<T,true>
		{
			//owner is here as it can be supplied but is ignored as the type is integral
			static bool push2lua(lua_State* const l, T * const &  value,Owner/* owner*/)
			{
				assert(l && value);
				return OOLUA::push2lua(l,*value);
			}
			static bool push2lua(lua_State* const l, T * const &  value)
			{
				assert(l && value);
				return OOLUA::push2lua(l,*value);
			}
		};

		///////////////////////////////////////////////////////////////////////////////
		///  Specialisation for C style strings
		///////////////////////////////////////////////////////////////////////////////
		template<>
		struct push_ptr_2lua<char,true>
		{
			static bool push2lua(lua_State* const l, char * const &  value,Owner/* owner*/)
			{
				assert(l && value);
				lua_pushstring (l,value);
				return true;
			}
			static bool push2lua(lua_State* const l, char * const &  value)
			{
				assert(l && value);
				lua_pushstring (l,value);
				return true;
			}
		};
		template<>
		struct push_ptr_2lua<char const,true>
		{
			static bool push2lua(lua_State* const l, char const * const &  value,Owner/* owner*/)
			{
				assert(l && value);
				lua_pushstring (l,value);
				return true;
			}
			static bool push2lua(lua_State* const l, char const * const &  value)
			{
				assert(l && value);
				lua_pushstring (l,value);
				return true;
			}
		};

	}



	template<int LuaType>
	inline bool push2lua(lua_State* const s, Lua_ref<LuaType> const &  value)
	{
		return value.push(s);
	}
	
	template<typename T>
	bool inline push2lua(lua_State* const  s, T const&  value)
	{
		return INTERNAL::push_basic_type<T,
		//			INTERNAL::Type_enum_defaults<T>::is_integral
		LVD::is_integral_type<T>::value 
				>::push2lua(s,value);
	}

	template<typename T>
	bool push2lua(lua_State* const s, OOLUA::lua_acquire_ptr<T>&  value)
	{
		assert(s && value.m_ptr);
		INTERNAL::push_pointer_which_has_a_proxy_class<typename OOLUA::lua_acquire_ptr<T>::raw>(s,value.m_ptr,Lua);
		return true;
	}

	template<typename T>
	inline bool push2lua(lua_State* const s, T * const &  value,Owner owner)
	{
		return INTERNAL::push_ptr_2lua<T,//LVD::is_integral_type<typename LVD::remove_const<T>::type >::value>::push2lua(s,value,owner);
										INTERNAL::Type_enum_defaults<typename LVD::remove_const<T>::type>::is_integral>::push2lua(s,value,owner);
	}
	template<typename T>
	inline bool push2lua(lua_State* const s, T * const &  value)
	{
		return INTERNAL::push_ptr_2lua<T,LVD::is_integral_type<T>::value>::push2lua(s,value);
	}








	


	namespace INTERNAL
	{
		
		template<typename T,int is_integral>
		struct pull_basic_type;

		template<typename T>
		struct pull_basic_type<T,0>//enum
		{
			static bool pull2cpp(lua_State* const  s, T &  value)
			{
				//enumeration type so a static cast should be allowed else this
				//is being called with the wrong type
				typedef char dummy_can_convert [ can_convert_to_int<T>::value ? 1 : -1];
				//value = static_cast<T>( lua_tonumber( s, -1) );
				if( !cpp_runtime_type_check_of_top(s,lua_isnumber,"enum type"))
					return false;
				value = static_cast<T>( lua_tointeger( s, -1) );
				lua_pop( s, 1);
				return true;
			}
		};

		template<typename T>
		struct pull_basic_type<T,1>
		{
			static bool pull2cpp(lua_State* const  s, T &  value)
			{
				if( !cpp_runtime_type_check_of_top(s,lua_isnumber,"interger compatabile type"))
					return false;
				value = static_cast<T>( lua_tointeger( s, -1) );
				lua_pop( s, 1);
				return true;
			}
		};
		
		
		///////////////////////////////////////////////////////////////////////////////
		///  @struct pull_ptr_2cpp
		///  Pulls a pointer to C++ depending on the second template parameter. If it
		///  is true then the type is an integral type and one of the normal overloaded
		///  OOLUA::pull2cpp functions are called. If on the other hand the type is not
		///  integral then pull_class_type is used.
		///////////////////////////////////////////////////////////////////////////////
		template<typename T,bool IsIntregal>
		struct pull_ptr_2cpp;
		
		void pull_class_type_error(lua_State* const s,char const* type);

		template<typename Raw_type>
		inline void pull_class_type(lua_State *const s,int Is_const,Raw_type*& class_type)
		{
MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA
			if(Is_const) class_type = INTERNAL::class_from_stack_top< Raw_type >(s);
			else class_type = INTERNAL::none_const_class_from_stack_top<Raw_type>(s);
MSC_POP_COMPILER_WARNING_OOLUA
		}


		template<typename T>
		struct pull_ptr_2cpp<T,false>
		{
			//this needs to return a bool as it was called from C++
			static bool pull2cpp(lua_State* const s, T *&  value)
			{
				assert(s);
				typename OOLUA::INTERNAL::param_type<T>::raw_type* class_ptr;
				pull_class_type<typename OOLUA::INTERNAL::param_type<T>::raw_type>(s
																				   ,OOLUA::INTERNAL::param_type<T*>::is_constant
																				   ,class_ptr);

				if(!class_ptr )
				{
#	if OOLUA_RUNTIME_CHECKS_ENABLED  == 1
					INTERNAL::handle_cpp_pull_fail(s,OOLUA::INTERNAL::param_type<T*>::is_constant
												   ? Proxy_class<typename OOLUA::INTERNAL::param_type<T>::raw_type>::class_name_const 
												   : Proxy_class<typename OOLUA::INTERNAL::param_type<T>::raw_type>::class_name);
#	elif OOLUA_DEBUG_CHECKS == 1
					assert(class_ptr);
#	endif
#	if OOLUA_USE_EXCEPTIONS == 0//prevent vs warnings
					value = 0;
					return false;
#	endif

				}
				
				value = class_ptr;
				lua_pop(s,1);
				return true;
			}
		};
		template<typename T>
		struct pull_ptr_2cpp<T,true>
		{
			static bool pull2cpp(lua_State* const s, T *&  value)
			{
#if OOLUA_DEBUG_CHECKS == 1
				///integral type, dereference and call the normal pull function
				///we may well be dereferencing a null or uninitialised
				///pointer here!
				assert(value);
#endif
				return OOLUA::pull2cpp(s,*value);
			}
		};

	}
	
	

	template<typename T> 
	inline bool pull2cpp(lua_State* const s, T& value)
	{
		return INTERNAL::pull_basic_type<T,LVD::is_integral_type<T>::value>::pull2cpp(s,value);
	}
	
	
	//pulls a pointer from the stack which Cpp will then own and call delete on
	template<typename T>
	inline bool pull2cpp(lua_State* const s, OOLUA::cpp_acquire_ptr<T>&  value)
	{
		INTERNAL::pull_class_type<typename OOLUA::cpp_acquire_ptr<T>::raw>(s
																	,OOLUA::cpp_acquire_ptr<T>::is_constant
																	,value.m_ptr);
		
		if(!value.m_ptr )
		{
#if OOLUA_RUNTIME_CHECKS_ENABLED  == 1
			INTERNAL::handle_cpp_pull_fail(s,OOLUA::cpp_acquire_ptr<T>::is_constant
										   ? Proxy_class<typename cpp_acquire_ptr<T>::raw>::class_name_const 
										   : Proxy_class<typename cpp_acquire_ptr<T>::raw>::class_name);
#elif OOLUA_DEBUG_CHECKS == 1
			assert(value.m_ptr);
#endif
#	if OOLUA_USE_EXCEPTIONS == 0//prevent vs warnings
			return false;
#	endif
		}
		INTERNAL::local_function_to_set_owner(s,value.m_ptr,OOLUA::Cpp);
		lua_pop( s, 1);
		return true;
	}
	
	
	
	///////////////////////////////////////////////////////////////////////////////
	///  inline public overloaded  pull2cpp
	///  Checks if it is an integral type( LVD::is_integral_type ) or that is a type
	///  that should be registered to OOLUA and calls the correct function.
	///  @param [in]       s lua_State *const \copydoc lua_State
	///  @param [in, out]  value T *&
	///  This function doesn't return a value
	///  @remarks
	///  @copydoc pulling_cpp_values
	///  @see pulling_cpp_values
	///////////////////////////////////////////////////////////////////////////////
	template<typename T>
	inline bool pull2cpp(lua_State* const s, T *&  value)
	{
		return INTERNAL::pull_ptr_2cpp<T,LVD::is_integral_type<T>::value>::pull2cpp(s,value);
	}
	
	
	
	
	
	
	
	
	
	
	
	namespace INTERNAL 
	{
		namespace LUA_CALLED
		{
			
			template<typename T,int is_integral>
			struct pull_basic_type;
			
			template<typename T>
			struct pull_basic_type<T,0>//enum
			{
				static void pull2cpp(lua_State* const  s, T &  value)
				{
					//enumeration type so a static cast should be allowed else this
					//is being called with the wrong type
					typedef char dummy_can_convert [ can_convert_to_int<T>::value ? 1 : -1];
#if OOLUA_RUNTIME_CHECKS_ENABLED  == 1
					if(! lua_isnumber(s,-1) )pull_error(s,"enum type");
#endif
					value = static_cast<T>( lua_tointeger( s, -1) );
					lua_pop( s, 1);
				}
			};
			
			template<typename T>
			struct pull_basic_type<T,1>
			{
				static void pull2cpp(lua_State* const  s, T &  value)
				{
#if OOLUA_RUNTIME_CHECKS_ENABLED  == 1
					if(! lua_isnumber(s,-1) )pull_error(s,"interger compatabile type");
#endif
					value = static_cast<T>( lua_tointeger( s, -1) );
					lua_pop( s, 1);
				}
			};
			
			
			
			template<typename T,int is_integral>
			struct pull_ptr_2cpp;
			
			template<typename T>
			struct pull_ptr_2cpp<T,false>
			{
				static void pull2cpp(lua_State* const s, T *&  value)
				{
					typename OOLUA::INTERNAL::param_type<T>::raw_type* class_ptr;
					INTERNAL::pull_class_type<typename OOLUA::INTERNAL::param_type<T>::raw_type>(s,OOLUA::INTERNAL::param_type<T*>::is_constant,class_ptr);
#if OOLUA_RUNTIME_CHECKS_ENABLED  == 1
					if(!class_ptr )
					{
						pull_class_type_error(s,OOLUA::INTERNAL::param_type<T*>::is_constant 
												? Proxy_class<typename OOLUA::INTERNAL::param_type<T>::raw_type>::class_name_const 
												: Proxy_class<typename OOLUA::INTERNAL::param_type<T>::raw_type>::class_name);
					}
#endif
					value = class_ptr;
					lua_pop(s,1);
				}
			};
			template<typename T>
			struct pull_ptr_2cpp<T,true>
			{
				static void pull2cpp(lua_State* const s, T *&  value)
				{
#if OOLUA_DEBUG_CHECKS == 1
					if(!value)
					{
						pull_error(s,"pulling pointer to intergral type and was passed NULL. OOLua can not dereference it");
					}
#endif				
					OOLUA::INTERNAL::LUA_CALLED::pull2cpp(s,*value);
				}
			};
			

			
			template<typename T> 
			inline void pull2cpp(lua_State* const s, T& value)
			{
				LUA_CALLED::pull_basic_type<T,LVD::is_integral_type<T>::value>::pull2cpp(s,value);
			}
			
			
			template<typename T>
			inline void pull2cpp(lua_State* const s, T *&  value)
			{
				LUA_CALLED::pull_ptr_2cpp<T,LVD::is_integral_type<T>::value>::pull2cpp(s,value);
			}
			
			
			//pulls a pointer from the stack which Cpp will then own and call delete on
			template<typename T>
			inline void pull2cpp(lua_State* const s, OOLUA::cpp_acquire_ptr<T>&  value)
			{
				typedef cpp_acquire_ptr<T> Type;
				typedef typename Type::raw raw;
				INTERNAL::pull_class_type<raw>(s,Type::is_constant,value.m_ptr);
#if OOLUA_RUNTIME_CHECKS_ENABLED  == 1
				if(! value.m_ptr )
				{
					pull_class_type_error(s,Type::is_constant 
										  ? Proxy_class<raw>::class_name_const 
										  : Proxy_class<raw>::class_name);
				}
#endif
				INTERNAL::local_function_to_set_owner(s,value.m_ptr,OOLUA::Cpp);
				lua_pop( s, 1);
			}
		}
		
		
	}
	

}



#endif







