#ifndef LUA_FUNCTION_H_
#	define LUA_FUNCTION_H_

///////////////////////////////////////////////////////////////////////////////
///  @file lua_function.h
///  @remarks Warning this file was generated, edits to it will not persist if 
///  the file is regenerated.
///  @author Liam Devine
///  @email
///  See http://www.liamdevine.co.uk for contact details.
///  @licence 
///  See licence.txt for more details. \n 
///////////////////////////////////////////////////////////////////////////////
#	include "lua_includes.h"
#	include "fwd_push_pull.h"
#	include "lua_ref.h"
namespace OOLUA
{
///////////////////////////////////////////////////////////////////////////////
///  Lua_function
///  Struct which is used to call a lua function.
///  @remarks
///  The Lua function can either be called by name(std::string) or with the
///  use a Lua reference which is stored in a Lua_func.
///////////////////////////////////////////////////////////////////////////////
#if OOLUA_USE_EXCEPTIONS ==1 
#	define OOLUA_CALLER_TRY \
	try \
	{
#	define OOLUA_CALLER_HANDLE_FAIL \
	} \
	catch (...) \
	{ \
		lua_settop(m_lua, top); \
		throw; \
	} \
	return false; /*Shhhhhhhhhh*/
#else
#	define OOLUA_CALLER_TRY 
#	define OOLUA_CALLER_HANDLE_FAIL \
	lua_settop(m_lua, top); \
	return false; 
#endif
struct Lua_function
{
	Lua_function();
	Lua_function(lua_State* l);
	template<typename FUNC_TYPE>
	bool operator()(FUNC_TYPE const& func)
	{
		int error_index(0);
		const int top = get_top();
		OOLUA_CALLER_TRY
		if( prep_function(func,0,error_index) ) return call(0,error_index);
		OOLUA_CALLER_HANDLE_FAIL
	}
	template<typename FUNC_TYPE,typename P1>
	bool operator()(FUNC_TYPE const& func,P1 p1)
	{
		int error_index(0);
		const int top = get_top();
		OOLUA_CALLER_TRY
		if( prep_function(func,1,error_index) 
			&& push2lua(m_lua,p1)
		)
			return call(1,error_index);
		OOLUA_CALLER_HANDLE_FAIL
	}
	template<typename FUNC_TYPE,typename P1,typename P2>
	bool operator()(FUNC_TYPE const& func,P1 p1,P2 p2)
	{
		int error_index(0);
		const int top = get_top();
		OOLUA_CALLER_TRY
		if( prep_function(func,2,error_index) 
			&& push2lua(m_lua,p1)
			&& push2lua(m_lua,p2)
		)
			return call(2,error_index);
		OOLUA_CALLER_HANDLE_FAIL
	}
	template<typename FUNC_TYPE,typename P1,typename P2,typename P3>
	bool operator()(FUNC_TYPE const& func,P1 p1,P2 p2,P3 p3)
	{
		int error_index(0);
		const int top = get_top();
		OOLUA_CALLER_TRY
		if( prep_function(func,3,error_index) 
			&& push2lua(m_lua,p1)
			&& push2lua(m_lua,p2)
			&& push2lua(m_lua,p3)
		)
			return call(3,error_index);
		OOLUA_CALLER_HANDLE_FAIL
	}
	template<typename FUNC_TYPE,typename P1,typename P2,typename P3,typename P4>
	bool operator()(FUNC_TYPE const& func,P1 p1,P2 p2,P3 p3,P4 p4)
	{
		int error_index(0);
		const int top = get_top();
		OOLUA_CALLER_TRY
		if( prep_function(func,4,error_index) 
			&& push2lua(m_lua,p1)
			&& push2lua(m_lua,p2)
			&& push2lua(m_lua,p3)
			&& push2lua(m_lua,p4)
		)
			return call(4,error_index);
		OOLUA_CALLER_HANDLE_FAIL
	}
	template<typename FUNC_TYPE,typename P1,typename P2,typename P3,typename P4,typename P5>
	bool operator()(FUNC_TYPE const& func,P1 p1,P2 p2,P3 p3,P4 p4,P5 p5)
	{
		int error_index(0);
		const int top = get_top();
		OOLUA_CALLER_TRY
		if( prep_function(func,5,error_index) 
			&& push2lua(m_lua,p1)
			&& push2lua(m_lua,p2)
			&& push2lua(m_lua,p3)
			&& push2lua(m_lua,p4)
			&& push2lua(m_lua,p5)
		)
			return call(5,error_index);
		OOLUA_CALLER_HANDLE_FAIL
	}
	template<typename FUNC_TYPE,typename P1,typename P2,typename P3,typename P4,typename P5,typename P6>
	bool operator()(FUNC_TYPE const& func,P1 p1,P2 p2,P3 p3,P4 p4,P5 p5,P6 p6)
	{
		int error_index(0);
		const int top = get_top();
		OOLUA_CALLER_TRY
		if( prep_function(func,6,error_index) 
			&& push2lua(m_lua,p1)
			&& push2lua(m_lua,p2)
			&& push2lua(m_lua,p3)
			&& push2lua(m_lua,p4)
			&& push2lua(m_lua,p5)
			&& push2lua(m_lua,p6)
		)
			return call(6,error_index);
		OOLUA_CALLER_HANDLE_FAIL
	}
	template<typename FUNC_TYPE,typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7>
	bool operator()(FUNC_TYPE const& func,P1 p1,P2 p2,P3 p3,P4 p4,P5 p5,P6 p6,P7 p7)
	{
		int error_index(0);
		const int top = get_top();
		OOLUA_CALLER_TRY
		if( prep_function(func,7,error_index) 
			&& push2lua(m_lua,p1)
			&& push2lua(m_lua,p2)
			&& push2lua(m_lua,p3)
			&& push2lua(m_lua,p4)
			&& push2lua(m_lua,p5)
			&& push2lua(m_lua,p6)
			&& push2lua(m_lua,p7)
		)
			return call(7,error_index);
		OOLUA_CALLER_HANDLE_FAIL
	}
	template<typename FUNC_TYPE,typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7,typename P8>
	bool operator()(FUNC_TYPE const& func,P1 p1,P2 p2,P3 p3,P4 p4,P5 p5,P6 p6,P7 p7,P8 p8)
	{
		int error_index(0);
		const int top = get_top();
		OOLUA_CALLER_TRY
		if( prep_function(func,8,error_index) 
			&& push2lua(m_lua,p1)
			&& push2lua(m_lua,p2)
			&& push2lua(m_lua,p3)
			&& push2lua(m_lua,p4)
			&& push2lua(m_lua,p5)
			&& push2lua(m_lua,p6)
			&& push2lua(m_lua,p7)
			&& push2lua(m_lua,p8)
		)
			return call(8,error_index);
		OOLUA_CALLER_HANDLE_FAIL
	}
	template<typename FUNC_TYPE,typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7,typename P8,typename P9>
	bool operator()(FUNC_TYPE const& func,P1 p1,P2 p2,P3 p3,P4 p4,P5 p5,P6 p6,P7 p7,P8 p8,P9 p9)
	{
		int error_index(0);
		const int top = get_top();
		OOLUA_CALLER_TRY
		if( prep_function(func,9,error_index) 
			&& push2lua(m_lua,p1)
			&& push2lua(m_lua,p2)
			&& push2lua(m_lua,p3)
			&& push2lua(m_lua,p4)
			&& push2lua(m_lua,p5)
			&& push2lua(m_lua,p6)
			&& push2lua(m_lua,p7)
			&& push2lua(m_lua,p8)
			&& push2lua(m_lua,p9)
		)
			return call(9,error_index);
		OOLUA_CALLER_HANDLE_FAIL
	}
	template<typename FUNC_TYPE,typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7,typename P8,typename P9,typename P10>
	bool operator()(FUNC_TYPE const& func,P1 p1,P2 p2,P3 p3,P4 p4,P5 p5,P6 p6,P7 p7,P8 p8,P9 p9,P10 p10)
	{
		int error_index(0);
		const int top = get_top();
		OOLUA_CALLER_TRY
		if( prep_function(func,10,error_index) 
			&& push2lua(m_lua,p1)
			&& push2lua(m_lua,p2)
			&& push2lua(m_lua,p3)
			&& push2lua(m_lua,p4)
			&& push2lua(m_lua,p5)
			&& push2lua(m_lua,p6)
			&& push2lua(m_lua,p7)
			&& push2lua(m_lua,p8)
			&& push2lua(m_lua,p9)
			&& push2lua(m_lua,p10)
		)
			return call(10,error_index);
		OOLUA_CALLER_HANDLE_FAIL
	}
	void bind_script(lua_State* const lua);
private:
	int get_top();
	bool call(int const nparams, int const error_index);
	bool prep_function(Lua_func_ref const& func,int const nparams, int& error_index);
	bool prep_function(std::string const& func,int const nparams, int& error_index);
	bool prep_function(int const func,int const nparams, int& error_index);
	lua_State* m_lua;

};
}
#undef OOLUA_CALLER_TRY
#undef OOLUA_CALLER_HANDLE_FAIL


#endif 
