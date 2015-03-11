#include "oolua_registration.h"

namespace OOLUA
{
	namespace INTERNAL
	{
		int get_oolua_module(lua_State* L)
		{
			lua_getfield(L, LUA_REGISTRYINDEX,OOLUA::INTERNAL::oolua_str);
			return 1;
		}
		void register_oolua_type(lua_State* L, char const* name,size_t const name_sz, int const stack_index)
		{
			get_oolua_module(L);
			lua_pushlstring(L,name,name_sz);
			lua_pushvalue(L, stack_index);
			lua_rawset(L, -3);
			lua_pop(L,1);
		}

		void set_function_in_table_with_upvalue(lua_State* l, char const * func_name, lua_CFunction func
													, int tableIndex, void* upvalue)
		{
			lua_pushstring(l, func_name);
			lua_pushlightuserdata( l, upvalue );
			lua_pushcclosure(l, func, 1);
			lua_settable(l, tableIndex);
		}
		void set_function_in_table(lua_State* l, char const* func_name,lua_CFunction func,int tableIndex)
		{
			lua_pushstring(l, func_name);
			lua_pushcclosure(l, func, 0);
			lua_settable(l, tableIndex);
		}
		
		void set_oolua_userdata_creation_key_value_in_table(lua_State* l ,int tableIndex)
		{
#if OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA == 1 && OOLUA_USERDATA_OPTIMISATION == 0
			lua_pushlightuserdata(l,(void*)lua_topointer(l, LUA_REGISTRYINDEX));
			lua_pushboolean(l, 1);
			lua_settable(l, tableIndex);
#else
			(void)l;
			(void)tableIndex;
#endif
		}
		
		void set_key_value_in_table(lua_State* l,char const* key_name,int valueIndex,int tableIndex)
		{
			lua_pushstring(l, key_name);
			lua_pushvalue(l, valueIndex);
			lua_settable(l, tableIndex);
		}
		int check_for_key_in_stack_top(lua_State* l)
		{
			//on entry stack is : table keyString basetable
			lua_pushvalue(l, -2);//table keyString baseTable keyString
			lua_gettable(l, -2);//check for keyString in baseTable
			if( lua_isnil(l,-1) == 1)//table string baseTable valueOrNil
			{
				lua_pop(l,2);//table keyString
				return 0;
			}
			
			lua_remove(l,-2);//table keyString TheValueThatWeWereLookingFor
			return 1;
		}
		
		bool class_name_is_already_registered(lua_State*l, char const* name)
		{
			lua_getfield(l, LUA_REGISTRYINDEX, name);
			if( lua_isnil(l,-1) == 0 )// entryOrNil
			{
				lua_pop(l,1);//pop the table
				return true;
			}
			
			lua_pop(l,1);//pop the null
			return false;
		}
		
	}
}

