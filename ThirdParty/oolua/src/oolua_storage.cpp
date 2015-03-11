
#include "lua_includes.h"
#include "oolua_userdata.h"
#include "oolua_storage.h"
#include "oolua_push_pull.h"


#if OOLUA_DEBUG_CHECKS == 1
#	include <cassert>
#endif



namespace OOLUA
{

	namespace INTERNAL
	{
		
		//pushes the weak table on top and returns its absolute index
		//The weak table is a table in the Lua registry specific to OOLua,
		//which has void pointer keys and values of userdata pointers.
		int push_weak_table(lua_State* l)
		{
			Weak_table::getWeakTable(l);
			return lua_gettop(l);
		}

		//if found it is left on the top of the stack and returns true
		//else the stack is same as on entrance to the function and false returned
		bool is_there_an_entry_for_this_void_pointer(lua_State* l,void* ptr)
		{
			int wt = push_weak_table(l);
			bool result = is_there_an_entry_for_this_void_pointer(l,ptr,wt);
			lua_remove(l,wt);
			return result;
		}
		bool is_there_an_entry_for_this_void_pointer(lua_State* l,void* ptr,int tableIndex)
		{
			lua_pushlightuserdata(l,ptr);//weakTable ... ptr
			lua_rawget(l,tableIndex);//weakTable .... (full user data or nil)
			if(! lua_isnil(l,-1) )
			{
				return true;//leave ud on top
			}
			lua_pop(l,1);//pop nil
			return false;
		}
		//returns the ud if found and cleans the stack else a NULL pointer
		Lua_ud* find_ud_dont_care_about_type_and_clean_stack(lua_State*  l,void* ptr)
		{
			Lua_ud* ud(0);
			if( is_there_an_entry_for_this_void_pointer(l,ptr) )
			{
				ud = static_cast<Lua_ud *>( lua_touserdata(l, -1) );
				lua_pop(l,1);//pop ud
				return ud;
			}
			return ud;
		}


		//on entering user data and weaktable are on the stack
		void add_ptr_if_required(lua_State* const l, void* ptr,int udIndex,int weakIndex)
		{
			lua_pushlightuserdata(l,ptr);//ptr
			lua_rawget(l,weakIndex);//(null or ptr)
			if( lua_isnil(l,-1) == 0 )
			{
				lua_pop(l, 1);//pop the ud
				return;
			}
			lua_pop(l,1);//pop the null

			lua_pushlightuserdata(l,ptr);//key
			lua_pushvalue(l,udIndex);//key ud
			lua_rawset(l,weakIndex);//table[key]=value
		}
		void set_owner( lua_State* l,void* ptr, Owner own)
		{
#if OOLUA_DEBUG_CHECKS == 1
			//It is an error to ever call this function with No_change
			assert(own != No_change);
#endif
			Lua_ud* ud = find_ud_dont_care_about_type_and_clean_stack(l,ptr);
	
#if OOLUA_DEBUG_CHECKS == 1
			//ud will always be found, if there is no entry it is an error
			if(!ud)
			{	
				assert(0 && "Did not find the user data");
			}
			else
#endif
			{
				userdata_gc_value(ud, own == Cpp ? false : true);
			}
		}

		bool ud_at_index_is_const(lua_State* l, int index)
		{
			return INTERNAL::userdata_is_constant( static_cast<Lua_ud *>( lua_touserdata(l, index) ) ); 
		}
		
		Lua_ud* new_userdata(lua_State* l, void* ptr,bool is_const,oolua_function_check_base base_checker,oolua_type_check_function type_check)
		{
			Lua_ud* ud = static_cast<Lua_ud*>(lua_newuserdata(l, sizeof(Lua_ud)));
			ud->flags = 0;
			reset_userdata(ud,ptr,is_const,base_checker,type_check);			
#if OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA == 1 && OOLUA_USERDATA_OPTIMISATION == 1
			OOLUA_SET_COOKIE(ud->flags);
#endif	
			return ud;
		}
		
		void reset_userdata(Lua_ud* ud, void* ptr,bool is_const,oolua_function_check_base base_checker,oolua_type_check_function type_check)
		{
			ud->void_class_ptr = ptr;
			ud->base_checker = base_checker;
			ud->type_check = type_check;
			userdata_const_value(ud,is_const);
		}
		
		//on entrance ud is on top
		Lua_ud* change_to_none_const_and_return_ud(lua_State* l)
		{
			lua_getmetatable(l,-1);//ud mt
			push_char_carray(l,change_mt_to_none_const_field);//ud mt str
			lua_gettable(l,-2);//ud mt func
			lua_CFunction set_metatable_none_const = lua_tocfunction(l,-1);
			lua_pop(l,2);//ud
			set_metatable_none_const(l);
			return static_cast<Lua_ud *>( lua_touserdata(l, -1) );
		}
		
	}
}


