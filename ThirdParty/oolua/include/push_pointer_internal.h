
#ifndef PUSH_POINTER_INTERAL_H_
#	define PUSH_POINTER_INTERAL_H_

#include "oolua_userdata.h"
#include "oolua_storage.h"
#include "determin_qualifier.h"

struct lua_State;

namespace OOLUA
{

	namespace INTERNAL
	{
		template<typename Raw,typename TypeMaybeConst>
		void push_pointer_which_has_a_proxy_class(lua_State * l, TypeMaybeConst * const ptr,Owner owner);
		
		void if_check_enabled_check_type_is_registered(lua_State* l, char const* name);
		void set_owner_if_change(Owner owner, Lua_ud* ud);
		
		template<typename Raw,typename TypeMaybeConst>
		inline void push_pointer_which_has_a_proxy_class(lua_State * l, TypeMaybeConst * const ptr,Owner owner)
		{
			if_check_enabled_check_type_is_registered(l,Proxy_class<Raw>::class_name);
			Lua_ud* ud( find_ud(l,(Raw*)ptr,(bool)LVD::is_const<TypeMaybeConst>::value) );
			if(! ud ) ud = add_ptr(l,(Raw*)ptr,(bool)LVD::is_const<TypeMaybeConst>::value);
			
			set_owner_if_change(owner,ud);
		}
		
	}
}

#endif

