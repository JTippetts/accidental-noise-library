#ifndef OOLUA_USERDATA_H_
#	define OOLUA_USERDATA_H_

#	include "oolua_config.h"
#	include "lvd_types.h"
struct lua_State;
namespace OOLUA
{
    namespace INTERNAL
    {
		struct Lua_ud;
		typedef bool (*oolua_function_check_base)(lua_State* const l,INTERNAL::Lua_ud*,int const&);
		typedef void (*oolua_type_check_function)(lua_State * l);
        struct Lua_ud
        {
			void* void_class_ptr;
			oolua_function_check_base base_checker;
			oolua_type_check_function type_check;
			LVD::uint32 flags;
		};
	
#if OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA == 1 && OOLUA_USERDATA_OPTIMISATION == 1
	/*lowest nibble is reserved for flags*/
#	define OOLUA_MAGIC_COOKIE	0xfC105Ef0
#	define OOLUA_CHECK_COOKIE(flags)(((flags) & 0xfffffff0) == OOLUA_MAGIC_COOKIE)
#	define OOLUA_SET_COOKIE(flags)	( (flags) = (OOLUA_MAGIC_COOKIE | ((flags) & 0xf)) )
#endif

		void userdata_const_value(Lua_ud* ud, bool value);
		bool userdata_is_constant(Lua_ud const* ud);
		bool userdata_is_to_be_gced(Lua_ud const * ud);
		void userdata_gc_value(Lua_ud* ud,bool value);
		
		enum UD_FLAGS {CONST_FLAG = 0x01,GC_FLAG = 0x02};
		
		inline void userdata_const_value(Lua_ud* ud, bool value)
		{
			if(value)ud->flags |= CONST_FLAG;
			else ud->flags &= (~CONST_FLAG);
		}
		inline bool userdata_is_constant(Lua_ud const* ud)
		{
			return (ud->flags & CONST_FLAG) != 0;
		}
		inline bool userdata_is_to_be_gced(Lua_ud const* ud)
		{
			return (ud->flags & GC_FLAG ) !=0;
		}
		inline void userdata_gc_value(Lua_ud* ud,bool value)
		{
			if(value) ud->flags |= GC_FLAG;
			else ud->flags &= (~ GC_FLAG);
		}	

    }
}

#endif
