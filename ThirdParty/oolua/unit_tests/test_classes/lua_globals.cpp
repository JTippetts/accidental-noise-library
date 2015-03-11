#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "common_cppunit_headers.h"

int dummy_c_function_returns_stack_count(lua_State* l)
{
	int top = lua_gettop(l);
	OOLUA::push2lua(l,top);
	return 1;
}

class Lua_globals : public CppUnit::TestFixture 
{
	CPPUNIT_TEST_SUITE(Lua_globals);
		CPPUNIT_TEST(globalData_addFuncToGlobalThenCall_callReturnsTrue);
		CPPUNIT_TEST(globalData_addIntGlobalThenReturnItFromFunction_callReturnsTrue);
		CPPUNIT_TEST(globalData_addIntGlobalThenReturnItFromFunction_resultEqualsInput);
		CPPUNIT_TEST(globalData_setAndThenGetGlobalInt_resultEqualInput);
	
#if OOLUA_USE_EXCEPTIONS ==1 	
		CPPUNIT_TEST(globalData_setThenClearThenGetGlobalInt_getThrowsTypeError);
#endif
	
#if OOLUA_STORE_LAST_ERROR ==1
		CPPUNIT_TEST(globalData_setThenClearThenGetGlobalInt_getReturnsFalse);
#endif	
	
	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script* m_lua;
public:
	void setUp()
	{
		m_lua = new OOLUA::Script;
	}
	void tearDown()
	{	
		delete m_lua;
	}
	void globalData_addFuncToGlobalThenCall_callReturnsTrue()
	{
		OOLUA::set_global(*m_lua, "global_func", dummy_c_function_returns_stack_count);
		bool result = m_lua->call("global_func");
		CPPUNIT_ASSERT_EQUAL(true,result);
		
	}
	void globalData_addIntGlobalThenReturnItFromFunction_callReturnsTrue()
	{
		int input(1);
		OOLUA::set_global(*m_lua, "i", input);
		m_lua->run_chunk("foo = function() return i end");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(true,result);
		
	}
	void globalData_addIntGlobalThenReturnItFromFunction_resultEqualsInput()
	{
		int input(1);
		OOLUA::set_global(*m_lua, "i", input);
		
		m_lua->run_chunk("foo = function() return i end");
		m_lua->call("foo");
		int result;
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(input,result);
	}
	
	void globalData_setAndThenGetGlobalInt_resultEqualInput()
	{
		int input(1);
		int result(0);
		OOLUA::set_global(*m_lua,"i",input);
		OOLUA::get_global(*m_lua,"i",result);
		CPPUNIT_ASSERT_EQUAL(input,result);
	}
#if OOLUA_USE_EXCEPTIONS ==1 	
	void globalData_setThenClearThenGetGlobalInt_getThrowsTypeError()
	{
		int input(1);
		int result(0);
		OOLUA::set_global(*m_lua,"i",input);
		OOLUA::set_global_to_nil(*m_lua,"i");
		CPPUNIT_ASSERT_THROW( OOLUA::get_global(*m_lua,"i",result),OOLUA::Type_error );
	}
#endif
	
#if OOLUA_STORE_LAST_ERROR ==1 	
	void globalData_setThenClearThenGetGlobalInt_getReturnsFalse()
	{
		int input(1);
		int DontCare(0);
		OOLUA::set_global(*m_lua,"i",input);
		OOLUA::set_global_to_nil(*m_lua,"i");
		bool result = OOLUA::get_global(*m_lua,"i",DontCare);
		CPPUNIT_ASSERT_EQUAL( false,result );
	}
#endif
};
CPPUNIT_TEST_SUITE_REGISTRATION(Lua_globals);
