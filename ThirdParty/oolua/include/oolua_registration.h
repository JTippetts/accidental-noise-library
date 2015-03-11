///////////////////////////////////////////////////////////////////////////////
///	 Orginally based on \n
///  http://lua-users.org/wiki/SimplerCppBinding \n
///	 http://www.lua.org/notes/ltn005.html \n
///  @author modified by Liam Devine
///  @email
///  See http://www.liamdevine.co.uk for contact details.
/// @licence
///	Copyright (c) 2005 Leonardo Palozzi
///	Permission is hereby granted, free of charge, to any person obtaining a copy of
///	this software and associated documentation files (the "Software"), to deal in the
///	Software without restriction, including without limitation the rights to use,
///	copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
///	Software, and to permit persons to whom the Software is furnished to do so,
///	subject to the following conditions:
///	The above copyright notice and this permission notice shall be included in all
///	copies or substantial portions of the Software.
///	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
///	INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
///	PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
///	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
///	OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
///	SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
///////////////////////////////////////////////////////////////////////////////
#ifndef OOLUA_REGISTRATION_H_
#   define OOLUA_REGISTRATION_H_

#include "lua_includes.h"
#include "class_from_stack.h"
#include "proxy_class.h"
#include "push_pointer_internal.h"
#include "oolua_userdata.h"
#include "lua_operator.h"
#include "oolua_member_function.h"
#include "oolua_storage.h"
#include "base_checker.h"
#include "oolua_char_arrays.h"
#include "lvd_types.h"
#include "oolua_typedefs.h"
#include "lua_table.h"

#include "oolua_config.h"
#if OOLUA_USING_SHARED_PTR == 1
#	include OOLUA_SHARED_PTR_INCLUDE
#endif

namespace OOLUA
{
    template<typename T>void register_class(lua_State *  l);

	template<typename T,typename K,typename V>
	void register_class_static(lua_State * const l,K const& k, V const& v);

	template<typename T>void register_class_and_bases(lua_State * l);

	namespace INTERNAL
	{
		template<typename T>struct garbage_collect;
		template<typename T>int set_methods(lua_State*  l);
		template<typename T>int set_const_methods(lua_State*   l,int none_const_methods,int none_const_mt);
        template<typename T, bool IsAbstract>struct set_create_function;
        template<typename T,typename B>struct Add_base;
        template<typename T,typename TL, int index,typename B>struct Register_base;
		template<typename T>int set_type_top_to_none_const(lua_State *  l);
		
		template<typename T,int HasNoPublicDestructor>struct set_delete_function;
		template<typename T,bool HasNoPublicDestructor>struct set_owner_function;
		
		template<typename T, bool IsAbstractOrNoConstructors>struct set_create_function;
		
		void set_function_in_table_with_upvalue(lua_State* l, char const * func_name, lua_CFunction func
														, int tableIndex, void* upvalue);
		void set_function_in_table(lua_State* l, char const* func_name,lua_CFunction func,int tableIndex);
		void set_oolua_userdata_creation_key_value_in_table(lua_State* l ,int tableIndex);

		void set_key_value_in_table(lua_State* l,char const* key_name,int valueIndex,int tableIndex);
		int check_for_key_in_stack_top(lua_State* l);
		
		bool class_name_is_already_registered(lua_State*l, char const* name);
		
		template<typename T,int HasRegisterEnumsTag>struct set_class_enums;
	
		int get_oolua_module(lua_State* L);
		void register_oolua_type(lua_State* L, char const* name,size_t const name_sz, int const stack_index);	
	}

    namespace INTERNAL
	{

		template<typename T>
		inline int set_type_top_to_none_const(lua_State * l)
		{
			luaL_getmetatable(l,Proxy_class<T>::class_name);//ud metatable
			lua_setmetatable(l,-2);//ud
			
			INTERNAL::Lua_ud* ud = static_cast<INTERNAL::Lua_ud*>(lua_touserdata(l,-1));
			userdata_const_value(ud,false);
			return 0;
		}

		template<typename T>
		struct garbage_collect 
		{
			static int gc(lua_State *  l)
			{
				Lua_ud *ud = static_cast<Lua_ud*>(lua_touserdata(l, 1));
				/*see http://code.google.com/p/oolua/issues/detail?id=29 for the Lua 5.2.* reason there is a userdata check here*/
				if( ud && ud->flags & GC_FLAG )delete static_cast<T*>(ud->void_class_ptr);
				return 0;
			}
		};

		template<typename T,int HasRegisterEnumsTag>
		struct set_class_enums
		{
			static void set(lua_State* /*l*/){}//nop
		};
		
		template<typename T>
		struct set_class_enums<T,1>
		{
			static void set(lua_State* l)
			{
				Proxy_class<T>::oolua_enums(l);
			}
		};
		
		template<typename T,int HasNoPublicDestructor>
		struct set_delete_function
		{
			static void set(lua_State* l, int methods)
			{
				set_function_in_table(l,"__gc",&INTERNAL::garbage_collect<T>::gc,methods);
			}
		};
		
		template<typename T>
		struct set_delete_function<T,1>
		{
			static void set( lua_State* /*l*/, int /*methods*/){}//no op
		};
		

		template<typename Base>
		struct Base_looker
		{
			static int findInBase(lua_State* l)
			{
				//table keyString
				lua_getglobal(l,Proxy_class<Base>::class_name);//table keyString baseTable
				return check_for_key_in_stack_top(l);
			}
		};


		template<typename T, typename Bases,int Index, typename BaseAtIndex>
		struct R_Base_looker
		{
			static int findInBase(lua_State* l)
			{
				if (Base_looker<BaseAtIndex>::findInBase(l) )return 1;
				return R_Base_looker<T,Bases,Index+1
								,typename TYPELIST::At_default<Bases,Index+1,TYPE::Null_type>::Result
								>::findInBase(l);
			}
		};
		
		template<typename T, typename Bases,int Index>
		struct R_Base_looker<T,Bases,Index,TYPE::Null_type>
		{
			static int findInBase(lua_State* /*l*/)
			{
				return 0;
			}
		};
		
		template<typename T> 
		int search_in_base_classes(lua_State* l)
		{
			return R_Base_looker<T,typename Proxy_class<T>::Bases,0
									,typename TYPELIST::At_default<typename Proxy_class<T>::Bases
									,0
									,TYPE::Null_type>::Result >::findInBase(l) ;
		}
		
		
		template<typename T>
		inline int set_methods(lua_State* l,int& mt)
		{
			lua_newtable(l);
			int methods = lua_gettop(l);//methods

			luaL_newmetatable(l, Proxy_class<T>::class_name);//methods mt
			//registry[name]= mt
			mt = lua_gettop(l);

			// store method table in globals so that scripts can add functions written in Lua.
			lua_pushvalue(l, methods);
			lua_setglobal(l,Proxy_class<T>::class_name);
			//global[name]=methods

			register_oolua_type(l, Proxy_class<T>::class_name, Proxy_class<T>::name_size,methods);
			//OOLua[name] = methods
			
			set_oolua_userdata_creation_key_value_in_table(l,mt);

			set_key_value_in_table(l,"__index",methods,mt);
			//mt["__index"]= methods

			//allow statics and functions to be added to the userdatatype metatable
			set_key_value_in_table(l,"__newindex",methods,mt);
			//mt["__newindex"]= methods

			set_delete_function<T,has_typedef<Proxy_class<T>, No_public_destructor >::Result>::set(l,mt);

			set_create_function<T,LVD::if_or< 
										has_typedef<Proxy_class<T>, Abstract >::Result
										,has_typedef<Proxy_class<T>, No_public_constructors >::Result 
									>::value
								>::set(l,methods);
			
			return methods;//methods mt
		}

		///////////////////////////////////////////////////////////////////////////////
		///  inline private static  set_const_methods
		///  Sets up the constant functions and operators for the class and links it to
		///  the none constant version via a metatable.
		///  @param [in]       l lua_State *const \copydoc lua_State
		///  @return int requirement of a Lua function
		///////////////////////////////////////////////////////////////////////////////
		template<typename T>
		inline int set_const_methods(lua_State* l,int none_const_methods,int none_const_mt)
		{
			lua_newtable(l);
			int const_methods = lua_gettop(l);//const_methods

			luaL_newmetatable(l, Proxy_class<T>::class_name_const);
			//registry[name#_const]= const_mt
			int const_mt = lua_gettop(l);//const_methods const_mt

			// store method table in globals so that scripts can add functions written in Lua.
			lua_pushvalue(l, const_methods);
			lua_setglobal(l,Proxy_class<T>::class_name_const);
			//global[name#_const]=const_methods
			
			register_oolua_type(l, Proxy_class<T>::class_name_const, Proxy_class<T>::name_size + sizeof("_const") -1,const_methods);
			//OOLua[name#const] = const_methods		

			set_oolua_userdata_creation_key_value_in_table(l,const_mt);
			
			set_function_in_table(l,change_mt_to_none_const_field
								  ,&INTERNAL::set_type_top_to_none_const<T>,const_mt);
			//const_mt[change_string_key]=&set_type_top_to_none_const()
			
			set_key_value_in_table(l,"__index",const_methods,const_mt);
			//const_mt["__index"]= const_methods

			//allow statics and new functions to be added to the userdatatype metatable
			set_key_value_in_table(l,"__newindex",const_methods,const_mt);
			//const_mt["__newindex"]= const_methods
			
			//set const_methods as it's own metatable
			lua_pushvalue(l, const_methods);
			lua_setmetatable(l, const_methods);
	
			set_function_in_table(l,"__index",&INTERNAL::search_in_base_classes<T>,const_methods);
			//const_methods["__index"]= function to search bases classes for the key
			
			set_owner_function<T,has_typedef<Proxy_class<T>, No_public_destructor >::Result>::set(l,const_methods);

			set_delete_function<T,has_typedef<Proxy_class<T>, No_public_destructor >::Result>::set(l,const_mt);

			//set none const methods as the metatable for the const metatable
			lua_pushvalue(l, const_mt);//const_methods const_mt const_mt
			lua_setmetatable(l, none_const_methods);//const_methods const_mt
			//none_const_methods[mt] = const_mt

			set_equal_function<T, has_typedef<Proxy_class<T>,Equal_op>::Result>::set(l,const_mt,none_const_mt);
			set_less_than_function<T,has_typedef<Proxy_class<T>,Less_op>::Result>::set(l,const_mt,none_const_mt);
			set_less_than_or_equal_function<T,has_typedef<Proxy_class<T>,Less_equal_op>::Result>::set(l,const_mt,none_const_mt);
			set_add_function<T,has_typedef<Proxy_class<T>,Add_op>::Result>::set(l,const_mt,none_const_mt);
			set_sub_function<T,has_typedef<Proxy_class<T>,Sub_op>::Result>::set(l,const_mt,none_const_mt);
			set_mul_function<T,has_typedef<Proxy_class<T>,Mul_op>::Result>::set(l,const_mt,none_const_mt);
			set_div_function<T,has_typedef<Proxy_class<T>,Div_op>::Result>::set(l,const_mt,none_const_mt);
			
			
			set_class_enums<T,has_typedef<Proxy_class<T>,Register_class_enums>::Result>::set(l);
			
			lua_pop(l, 1);//const_methods
			return const_methods;
		}


		template<typename T,typename B>
		struct Add_base
		{
			void operator()(lua_State * const l,int const& methods,int const& const_methods)
			{
				for (typename Proxy_class<B >::Reg_type *r = Proxy_class<B >::class_methods; r->name; r++)
				{
					INTERNAL::set_function_in_table_with_upvalue(l, r->name, &OOLUA::INTERNAL::member_caller<T,B >
													   , methods, reinterpret_cast<void*> (r));
				}
				// fill constant method table with methods from class Proxy_class<T>
				for (typename Proxy_class<B >::Reg_type_const *r = Proxy_class<B >::class_methods_const; r->name; ++r)
				{
					INTERNAL::set_function_in_table_with_upvalue(l, r->name, &OOLUA::INTERNAL::member_caller<T,B >
													   , const_methods, reinterpret_cast<void*> (r));
				}
				Register_base<T
								,typename Proxy_class<B>::Bases
								,0
								,typename TYPELIST::At_default< typename Proxy_class<B>::Bases, 0, TYPE::Null_type >::Result
							> b;
				
				b(l,methods,const_methods);
			}
		};
		template<typename T>
		struct Add_base<T,TYPE::Null_type>
		{
			void operator()(lua_State *  const /*l*/,int const&/*methods*/,int const& /*const_methods*/){}///no-op
		};

		template<typename T,typename TL, int index,typename B>
		struct Register_base
		{
			void operator()(lua_State * const l,int const& methods,int const& const_methods)
			{
				Add_base<T,typename TYPELIST::At_default< TL, index, TYPE::Null_type >::Result> adder;
				adder(l,methods,const_methods);
				Register_base<T,TL,index + 1,typename TYPELIST::At_default< TL, index + 1, TYPE::Null_type >::Result> base;
				base(l,methods,const_methods);
			}
		};

		template<typename T,typename TL, int index>
		struct Register_base<T,TL,index, TYPE::Null_type>
		{
			void operator()(lua_State * const  /*l*/,int const& /*methods*/,int const& /*const_methods*/){}///no-op
		};

		template<typename T, bool IsAbstractOrNoConstructors>
		struct set_create_function
		{
			static void set(lua_State*  const l, int methods)
			{
				set_function_in_table(l
									  ,new_str
									  ,&OOLUA::Proxy_class<T>::oolua_factory_function
									  ,methods);
				// methods["new"] = create_type
			}
			
		};

		template<typename T>
		struct set_create_function<T, true>
		{
			static void set(lua_State*  const /*l*/,int /*methods*/){}///no-op
		};

		
		template<typename T, bool HasNoDestructors>
		struct set_owner_function
		{
			static void set(lua_State*  const l, int methods)
			{
				set_function_in_table(l
									  ,set_owner_str
									  ,&INTERNAL::lua_set_owner<T>
									  ,methods);
				//methods["set_owner"]=&lua_set_owner()
			}

		};
		
    template<typename T>
		struct set_owner_function<T, true>
		{
			static void set(lua_State*  const /*l*/,int /*methods*/){}///no-op
		};

	}

    template<typename T>
	inline void register_class(lua_State * /*const*/ l)
	{

		if(OOLUA::INTERNAL::class_name_is_already_registered(l,Proxy_class<T>::class_name)) return;

		//set none constant operator methods, constructor etc...
		int none_const_mt(0);
		int none_const_methods ( INTERNAL::set_methods<T>(l,none_const_mt) );
		//setup constant member function table and add operators
		int const_methods ( INTERNAL::set_const_methods<T>(l,none_const_methods,none_const_mt ));

		// fill method table with methods from class Proxy_class<T>
		for (typename Proxy_class<T >::Reg_type *r = Proxy_class<T >::class_methods; r->name; r++)
		{
			INTERNAL::set_function_in_table_with_upvalue(l
											   , r->name
											   ,&OOLUA::INTERNAL::member_caller<Proxy_class<T>,T>
											   , none_const_methods
											    , reinterpret_cast<void*> (r));
		}

		// fill constant method table with methods from class Proxy_class<T>
		for (typename Proxy_class<T >::Reg_type_const *r = Proxy_class<T >::class_methods_const; r->name; ++r)
		{
			INTERNAL::set_function_in_table_with_upvalue(l
											   , r->name
											   ,&OOLUA::INTERNAL::const_member_caller<Proxy_class<T>,T>
											   , const_methods
											   , reinterpret_cast<void*> (r));
		}
		//recursively register any base class methods
		INTERNAL::Register_base<Proxy_class<T>
									,typename Proxy_class<T>::Bases
									,0
									,typename TYPELIST::At_default<typename Proxy_class<T>::Bases, 0, TYPE::Null_type >::Result
								> recursive_worker;
		recursive_worker(l,none_const_methods,const_methods);

		lua_pop(l, 3);//stack = methods|mt|const_methods    |const_mt
	}

	template<typename T,typename K,typename V>
	inline void register_class_static(lua_State * const l,K const& k, V const& v)
	{
		Lua_table meth(l,Proxy_class<T>::class_name);
		meth.set_value(k,v);
	}

	namespace INTERNAL
	{
		template<int Index,typename Bases, typename Type>
		struct Register_bases_with_lua;

		template<int Index,typename Bases, typename Type>
		struct Register_bases_with_lua
		{
			static void work(lua_State * l)
			{
				register_class<Type>(l);
				Register_bases_with_lua<Index+1
								,Bases
								,typename TYPELIST::At_default<Bases,Index+1,TYPE::Null_type>::Result
						>::work(l);
			}
		};
		template<int index,typename TL>
		struct Register_bases_with_lua<index,TL,TYPE::Null_type>
		{
			static void work(lua_State * /*l*/)
			{}
		};
	}

	template<typename T>
	inline void register_class_and_bases(lua_State * l)
	{
		register_class<T>(l);
		INTERNAL::Register_bases_with_lua<0
								,typename OOLUA::Proxy_class<T>::AllBases
								,typename TYPELIST::At_default<typename OOLUA::Proxy_class<T>::AllBases,0,TYPE::Null_type>::Result 
						>::work(l);
	}

}
#endif
