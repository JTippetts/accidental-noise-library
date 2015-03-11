#ifndef LUA_OWNERSHIP_H_
#	define LUA_OWNERSHIP_H_

#include "expose_stub_classes.h"
#include "cpp_ownership.h"
#include "oolua.h"


OOLUA_PROXY_CLASS(OwnershipParamsAndReturns)
	OOLUA_TYPEDEFS Abstract OOLUA_END_TYPES

	OOLUA_MEM_FUNC_RENAME(lua_takes_ownership_of_ref_2_ptr,
						  void, ref_2_ptr,			lua_out_p<Stub1*&>)
	OOLUA_MEM_FUNC_RENAME(lua_takes_ownership_of_ref_2_ptr_const,
						  void, ref_2_ptr_const,	lua_out_p<Stub1 const * &>)


	OOLUA_MEM_FUNC_RENAME(cpp_takes_ownership_of_ptr_param,
						   void, ptr_param ,		cpp_in_p<Stub1*>)
	OOLUA_MEM_FUNC_RENAME(cpp_takes_ownership_of_ref_to_ptr_param,
						  void, ref_2_ptr,			cpp_in_p<Stub1*&>)


	OOLUA_MEM_FUNC_RENAME(cpp_takes_ownership_of_const_ptr_param,
						  void, const_ptr,			cpp_in_p<Stub1 * const>)
	OOLUA_MEM_FUNC_RENAME(cpp_takes_ownership_of_ref_2_const_ptr_param,
						  void, ref_2_const_ptr,	cpp_in_p<Stub1 * const &>)


	OOLUA_MEM_FUNC_RENAME(cpp_takes_ownership_of_ptr_to_const_param,
						  void, ptr_const,			cpp_in_p<Stub1 const*>)
	OOLUA_MEM_FUNC_RENAME(cpp_takes_ownership_of_ref_to_ptr_to_const_param,
						  void, ref_2_ptr_const,	cpp_in_p<Stub1 const*&>)

	OOLUA_MEM_FUNC_RENAME(cpp_takes_ownership_of_const_ptr_to_const_param,
						  void, const_2_ptr_2_const,		cpp_in_p<Stub1 const * const> )
	OOLUA_MEM_FUNC_RENAME(cpp_takes_ownership_of_ref_to_const_ptr_to_const_param,
						  void, ref_2_const_2_ptr_2_const,	cpp_in_p<Stub1 const * const&> )

OOLUA_CLASS_END


#endif

