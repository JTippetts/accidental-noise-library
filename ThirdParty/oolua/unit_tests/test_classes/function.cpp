
#include "oolua_tests_pch.h"
#include "oolua.h"
#include "common_cppunit_headers.h"
#include "expose_functions_with_ref_params.h"


class Lua_function_ref : public CppUnit::TestFixture 
{
	CPPUNIT_TEST_SUITE(Lua_function_ref);
	CPPUNIT_TEST(classMethod_takesLuaFuncRef_callReturnsTrue);
	CPPUNIT_TEST(returnsInput_takesRefAndReturnsIt_luaFunctionReturnsCorrectValueThenCallReturnsTrue);
#if OOLUA_USE_EXCEPTIONS == 1
	CPPUNIT_TEST(pull_CFunctionFromStackTopIsNotFunc_throwsRunTimeError);
#endif
	
#if OOLUA_STORE_LAST_ERROR == 1
	CPPUNIT_TEST(pull_CFunctionFromStackTopIsNotFunc_callReturnsFalse);
	CPPUNIT_TEST(pull_CFunctionFromStackTopIsNotFunc_errorStringIsNotEmpty);
#endif
	
	CPPUNIT_TEST_SUITE_END();
	
	OOLUA::Script* m_lua;
	Function_refs* m_class;
public:
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_class = new Function_refs;
		m_lua->register_class<Function_refs>();
	}
	void tearDown()
	{
		delete m_class;
		delete m_lua;
	}
	void classMethod_takesLuaFuncRef_callReturnsTrue()
	{
		m_lua->run_chunk("foo = function (obj) "
							"local f = function() end "
							"obj:lua_function(f) " 
						 "end ");
		bool result = m_lua->call("foo",m_class);
		std::cout <<OOLUA::get_last_error(*m_lua);
		CPPUNIT_ASSERT_EQUAL(true,result);
	}
	
	void returnsInput_takesRefAndReturnsIt_luaFunctionReturnsCorrectValueThenCallReturnsTrue()
	{
		m_lua->run_chunk("foo = function (obj) "
							"local str = \"Some string to return\" "
							"local initial = function() return str end "
							"local returned = obj:takes_and_returns_ref(initial) "
							"assert(returned() == str) "
						 "end");
		bool result = m_lua->call("foo",m_class);
		CPPUNIT_ASSERT_EQUAL(true,result);	
	}

#if OOLUA_USE_EXCEPTIONS == 1	
	void pull_CFunctionFromStackTopIsNotFunc_throwsRunTimeError()
	{
		OOLUA::Lua_func_ref func;
		CPPUNIT_ASSERT_THROW( OOLUA::pull2cpp(*m_lua,func),OOLUA::Runtime_error);
	}
#endif
	
#if OOLUA_STORE_LAST_ERROR == 1	
	void pull_CFunctionFromStackTopIsNotFunc_callReturnsFalse()
	{	
		OOLUA::Lua_func_ref func;
		bool result = OOLUA::pull2cpp(*m_lua,func);
		CPPUNIT_ASSERT_EQUAL(false,result);
	}
	void pull_CFunctionFromStackTopIsNotFunc_errorStringIsNotEmpty()
	{	
		OOLUA::Lua_func_ref func;
		OOLUA::pull2cpp(*m_lua,func);
		std::string error_str = OOLUA::get_last_error(*m_lua);
		CPPUNIT_ASSERT_EQUAL(false,error_str.empty() );
	}
	
#endif
	
};
CPPUNIT_TEST_SUITE_REGISTRATION(Lua_function_ref);

