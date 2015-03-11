
#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "common_cppunit_headers.h"
#	include "gmock/gmock.h"

#include "expose_stub_classes.h"

class Lua_caller : public CppUnit::TestFixture 
{
	CPPUNIT_TEST_SUITE(Lua_caller);
#if OOLUA_USE_EXCEPTIONS ==1
	CPPUNIT_TEST(functionRef_functionRefIsInvalidForTheState_throwsRuntimeError);
	CPPUNIT_TEST(functionRef_functionRefIsInvalidForTheState_afterCallStackIsEmpty);
	CPPUNIT_TEST(luaCaller_passedInvalidParameter_throwsRuntimeError);
	CPPUNIT_TEST(luaCaller_passedInvalidParameter_afterThrowStackTopEqualsTopBeforeCall);
	CPPUNIT_TEST(luaCaller_passedFunctionWhichCallsLuaError_throwsRuntimeError);
	CPPUNIT_TEST(luaCaller_passedFunctionWhichCallsLuaError_afterThrowStackIsEmpty);
	CPPUNIT_TEST(luaCaller_stackHasOneEntry_callsFunctionWhichRaisesLuaError_afterThrowStackTopEqualsTopBeforeCall);

	CPPUNIT_TEST(stringFunc_passedInvalidGlobalName_throwsRuntimeError);
	CPPUNIT_TEST(stringFunc_passedGlobalNameWhichIsNotAfunction_throwsRuntimeError);
	CPPUNIT_TEST(indexFunc_passedIndexWhichIsNotAfunction_throwsRuntimeError);
	
#endif
	
#if OOLUA_STORE_LAST_ERROR ==1
	CPPUNIT_TEST(functionRef_functionRefIsInvalidForTheState_returnsFalse);
	CPPUNIT_TEST(functionRef_functionRefIsInvalidForTheState_afterCallStackIsEmpty);
	CPPUNIT_TEST(functionRefWithParam_functionRefIsInvalidForTheState_afterCallStackIsEmpty);
	CPPUNIT_TEST(luaCaller_passedInvalidParameter_returnsFalse);
	CPPUNIT_TEST(luaCaller_passedInvalidParameter_afterCallStackIsEmpty);
	CPPUNIT_TEST(luaCaller_passedFunctionWhichCallsLuaError_returnsFalse);
	CPPUNIT_TEST(luaCaller_passedFunctionWhichCallsLuaError_afterCallStackIsEmpty);
	CPPUNIT_TEST(luaCaller_stackHasOneEntry_callsFunctionWhichRaisesLuaError_afterCallStackTopEqualsTopBeforeCall);

	CPPUNIT_TEST(stringFunc_passedInvalidGlobalName_returnsFalse);
	CPPUNIT_TEST(stringFunc_passedGlobalNameWhichIsNotAfunction_returnsFalse);
	CPPUNIT_TEST(indexFunc_passedIndexWhichIsNotAfunction_returnsFalse);
	
#endif	

	CPPUNIT_TEST(functionRef_functionRefIsFromAChildState_returnsTrue);
	CPPUNIT_TEST(stringFunc_callsFunctionInGlobalScope_returnsTrue);
	CPPUNIT_TEST(indexFunc_passedFunctionIndex_returnsTrue);
	CPPUNIT_TEST(indexFunc_passedFunctionIndex_StackSizeIsOneAfterCall);
	CPPUNIT_TEST(indexFunc_passedFunctionIndexAndStackCountIsTwo_StackSizeIsTwoAfterCall);
	CPPUNIT_TEST(indexFunc_passedFunctionIndexAndStackCountIsTwo_afterTheCallStackIndexOneAndTwoCompareEqual);

	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script* m_lua;
public:
    Lua_caller():m_lua(0){}
	void setUp()
	{
		m_lua = new OOLUA::Script;
	}
	void tearDown()
	{
		delete m_lua;
	}

	OOLUA::Lua_func_ref create_func_ref_with_child_state()
	{
		using namespace OOLUA;
		lua_State* child = lua_newthread(*m_lua);
		load_chunk(child,"return ");
		Lua_func_ref func;
		pull2cpp(child,func);
		return func;
	}
	
	OOLUA::Lua_func_ref simple_function_for_state(OOLUA::Script& differnt_state)
	{
		using namespace OOLUA;
		Lua_func_ref invalid_for_caller_state;
		load_chunk(differnt_state,"return");
		pull2cpp(differnt_state,invalid_for_caller_state);
		return invalid_for_caller_state;
	}
	
#if OOLUA_USE_EXCEPTIONS ==1
	void functionRef_functionRefIsInvalidForTheState_throwsRuntimeError()
	{
		
		using namespace OOLUA;
		Script different_lua_state;
		Lua_func_ref invalid_for_caller_state = simple_function_for_state(different_lua_state);
		Lua_function caller(*m_lua);
		CPPUNIT_ASSERT_THROW( caller(invalid_for_caller_state), OOLUA::Runtime_error);
	}
	
	void functionRef_functionRefIsInvalidForTheState_afterCallStackIsEmpty()
	{
		
		using namespace OOLUA;
		Script different_lua_state;
		Lua_func_ref invalid_for_caller_state = simple_function_for_state(different_lua_state);
		Lua_function caller(*m_lua);
		try{ caller(invalid_for_caller_state); }
		catch(...) { CPPUNIT_ASSERT_EQUAL(0,lua_gettop(*m_lua)); }
	}
	
	void luaCaller_passedInvalidParameter_throwsRuntimeError()
	{
		using namespace OOLUA;
		Script different_lua_state;
		Lua_func_ref func = simple_function_for_state(*m_lua);
		Lua_func_ref invalid_for_caller_state = simple_function_for_state(different_lua_state);
		Lua_function caller(*m_lua);
		CPPUNIT_ASSERT_THROW( caller(func,invalid_for_caller_state), OOLUA::Runtime_error);
	}
	void luaCaller_passedInvalidParameter_afterThrowStackTopEqualsTopBeforeCall()
	{
		using namespace OOLUA;

		int top = lua_gettop(*m_lua);
		Script different_lua_state;
		Lua_func_ref func = simple_function_for_state(*m_lua);
		Lua_func_ref invalid_for_caller_state = simple_function_for_state(different_lua_state);
		Lua_function caller(*m_lua);
		try { caller(func,invalid_for_caller_state); }
		catch(...) { CPPUNIT_ASSERT_EQUAL(top,lua_gettop(*m_lua)); }
	}
	void luaCaller_passedFunctionWhichCallsLuaError_throwsRuntimeError()
	{
		using namespace OOLUA;
		load_chunk(*m_lua,"error'foo'");
		Lua_func_ref func;
		pull2cpp(*m_lua,func);
		Lua_function caller(*m_lua);
		CPPUNIT_ASSERT_THROW( caller(func), OOLUA::Runtime_error);
	}
	void luaCaller_passedFunctionWhichCallsLuaError_afterThrowStackIsEmpty()
	{
		using namespace OOLUA;
		load_chunk(*m_lua,"error'foo'");
		Lua_func_ref func;
		pull2cpp(*m_lua,func);
		Lua_function caller(*m_lua);
		try { caller(func); }
		catch(...) { CPPUNIT_ASSERT_EQUAL(0,lua_gettop(*m_lua)); }
	}
	
	void luaCaller_stackHasOneEntry_callsFunctionWhichRaisesLuaError_afterThrowStackTopEqualsTopBeforeCall()
	{
		using namespace OOLUA;
		
		load_chunk(*m_lua,"error'foo'");
		Lua_func_ref func;
		pull2cpp(*m_lua,func);
		Lua_function caller(*m_lua);

		lua_pushnil(*m_lua);
		int const top = lua_gettop(*m_lua);
		try { caller(func); }
		catch(...) { CPPUNIT_ASSERT_EQUAL(top,lua_gettop(*m_lua)); }
	}
	
	void stringFunc_passedInvalidGlobalName_throwsRuntimeError()
	{
		OOLUA::Lua_function caller(*m_lua);
		CPPUNIT_ASSERT_THROW( caller("invalid_name"), OOLUA::Runtime_error);
	}
	
	void stringFunc_passedGlobalNameWhichIsNotAfunction_throwsRuntimeError()
	{
		OOLUA::Lua_function caller(*m_lua);
		m_lua->run_chunk("_G['valid_name'] = {}");
		CPPUNIT_ASSERT_THROW( caller("invalid_name"), OOLUA::Runtime_error);
	}	

	void indexFunc_passedIndexWhichIsNotAfunction_throwsRuntimeError()
	{
		OOLUA::Lua_function caller(*m_lua);
		lua_pushnil(*m_lua);
		CPPUNIT_ASSERT_THROW( caller(1), OOLUA::Runtime_error);
	}
	
#endif	

	
#if OOLUA_STORE_LAST_ERROR ==1
	void functionRef_functionRefIsInvalidForTheState_returnsFalse()
	{
		
		using namespace OOLUA;
		Script different_lua_state;
		Lua_func_ref invalid_for_caller_state = simple_function_for_state(different_lua_state);
		Lua_function caller(*m_lua);
		CPPUNIT_ASSERT_EQUAL(false , caller(invalid_for_caller_state));
	}
	
	void functionRef_functionRefIsInvalidForTheState_afterCallStackIsEmpty()
	{
		
		using namespace OOLUA;
		Script different_lua_state;
		Lua_func_ref invalid_for_caller_state = simple_function_for_state(different_lua_state);
		Lua_function caller(*m_lua);
		caller(invalid_for_caller_state); 
		CPPUNIT_ASSERT_EQUAL(0,lua_gettop(*m_lua));
	}
	
	void functionRefWithParam_functionRefIsInvalidForTheState_afterCallStackIsEmpty()
	{
		
		using namespace OOLUA;
		Script different_lua_state;
		Lua_func_ref invalid_for_caller_state = simple_function_for_state(different_lua_state);
		Lua_function caller(*m_lua);
		caller(invalid_for_caller_state,1); 
		CPPUNIT_ASSERT_EQUAL(0,lua_gettop(*m_lua));
	}
	
	void luaCaller_passedInvalidParameter_returnsFalse()
	{
		
		using namespace OOLUA;
		Script different_lua_state;
		Lua_func_ref func = simple_function_for_state(*m_lua);
		Lua_func_ref invalid_for_caller_state = simple_function_for_state(different_lua_state);
		Lua_function caller(*m_lua);
		CPPUNIT_ASSERT_EQUAL(false , caller(func,invalid_for_caller_state));
	}
	
	void luaCaller_passedInvalidParameter_afterCallStackIsEmpty()
	{
		using namespace OOLUA;
		int top = lua_gettop(*m_lua);
		Script different_lua_state;
		Lua_func_ref func = simple_function_for_state(*m_lua);
		Lua_func_ref invalid_for_caller_state = simple_function_for_state(different_lua_state);
		Lua_function caller(*m_lua);
		caller(func,invalid_for_caller_state);
		CPPUNIT_ASSERT_EQUAL(top,lua_gettop(*m_lua));
	}
	void luaCaller_passedFunctionWhichCallsLuaError_returnsFalse()
	{
		using namespace OOLUA;
		load_chunk(*m_lua,"error'foo'");
		Lua_func_ref func;
		pull2cpp(*m_lua,func);
		Lua_function caller(*m_lua);
		CPPUNIT_ASSERT_EQUAL(false,caller(func));
	}
	void luaCaller_passedFunctionWhichCallsLuaError_afterCallStackIsEmpty()
	{
		using namespace OOLUA;
		load_chunk(*m_lua,"error'foo'");
		Lua_func_ref func;
		pull2cpp(*m_lua,func);
		Lua_function caller(*m_lua);
		caller(func);
		CPPUNIT_ASSERT_EQUAL(0,lua_gettop(*m_lua));
	}
	void luaCaller_stackHasOneEntry_callsFunctionWhichRaisesLuaError_afterCallStackTopEqualsTopBeforeCall()
	{
		using namespace OOLUA;
		
		load_chunk(*m_lua,"error'foo'");
		Lua_func_ref func;
		pull2cpp(*m_lua,func);
		Lua_function caller(*m_lua);
		
		lua_pushnil(*m_lua);
		int const top = lua_gettop(*m_lua);
		caller(func);
		CPPUNIT_ASSERT_EQUAL(top,lua_gettop(*m_lua));
	}
	void stringFunc_passedInvalidGlobalName_returnsFalse()
	{
		OOLUA::Lua_function caller(*m_lua);
		CPPUNIT_ASSERT_EQUAL(false, caller("invalid_name"));
	}
	void stringFunc_passedGlobalNameWhichIsNotAfunction_returnsFalse()
	{
		OOLUA::Lua_function caller(*m_lua);
		m_lua->run_chunk("_G['valid_name'] = {}");
		CPPUNIT_ASSERT_EQUAL(false, caller("invalid_name"));
	}	
	
	void indexFunc_passedIndexWhichIsNotAfunction_returnsFalse()
	{
		OOLUA::Lua_function caller(*m_lua);
		lua_pushnil(*m_lua);
		CPPUNIT_ASSERT_EQUAL(false, caller(1));
	}
	
#endif	
	
	void functionRef_functionRefIsFromAChildState_returnsTrue()
	{
		using namespace OOLUA;
		Lua_func_ref func_from_child = create_func_ref_with_child_state();
		Lua_function caller(*m_lua);
		CPPUNIT_ASSERT_EQUAL( true, caller(func_from_child) );
	}

	void stringFunc_callsFunctionInGlobalScope_returnsTrue()
	{
		m_lua->run_chunk("_G['global_name'] = function() end");
		OOLUA::Lua_function caller(*m_lua);
		CPPUNIT_ASSERT_EQUAL(true , caller("global_name"));
	}
	
	void indexFunc_passedFunctionIndex_returnsTrue()
	{
		OOLUA::Lua_function caller(*m_lua);
		m_lua->load_chunk("return");
		CPPUNIT_ASSERT_EQUAL(true, caller(1));
	}
	void indexFunc_passedFunctionIndex_StackSizeIsOneAfterCall()
	{
		OOLUA::Lua_function caller(*m_lua);
		m_lua->load_chunk("return");
		caller(1);
		CPPUNIT_ASSERT_EQUAL(1,lua_gettop(*m_lua));
	}
	
	void indexFunc_passedFunctionIndexAndStackCountIsTwo_StackSizeIsTwoAfterCall()
	{
		OOLUA::Lua_function caller(*m_lua);
		m_lua->load_chunk("return");
		lua_pushvalue(*m_lua, 1);
		caller(1);
		CPPUNIT_ASSERT_EQUAL(2,lua_gettop(*m_lua));
	}
	
	void indexFunc_passedFunctionIndexAndStackCountIsTwo_afterTheCallStackIndexOneAndTwoCompareEqual()
	{
		m_lua->load_chunk("return");
		lua_pushvalue(*m_lua, 1);
		OOLUA::Lua_function caller(*m_lua);
		caller(1);
		CPPUNIT_ASSERT_EQUAL(lua_topointer(*m_lua,2),lua_topointer(*m_lua,1));
	}
	

};
CPPUNIT_TEST_SUITE_REGISTRATION(Lua_caller);

