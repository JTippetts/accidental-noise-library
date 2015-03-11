
#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "common_cppunit_headers.h"
#	include "gmock/gmock.h"
#	include "expose_const_func.h"

namespace
{
	char const* constant_function(OOLUA::Script* l)
	{
		l->run_chunk(
			"func = function(object) \n"
				"local i = object:cpp_func_const() \n"
			"end");
		return "func";
	}
	char const* none_constant_function(OOLUA::Script* l)
	{
		l->run_chunk(
			"func = function(object) \n"
				"object:cpp_func() \n"
			"end");
		return "func";
	}
	char const* add_lua_constant_function(OOLUA::Script* l)
	{
		l->run_chunk(
			"function Constant_const:lua_const_func() \n"
				"local i = self:cpp_func_const() \n"
			"end");
		return "lua_const_func";
	}

	char const* add_lua_none_constant_function(OOLUA::Script* l)
	{
		l->run_chunk(
			"function Constant:lua_none_const_func() \n"
				"self:cpp_func() \n"
			"end");
		return "lua_none_const_func";
	}
	char const* lua_added_func(OOLUA::Script* l,char const* lua_func_name)
	{
		l->run_chunk(
			std::string("lua_func = function(object) \n") +
				std::string("object:") + std::string(lua_func_name) + std::string("() \n") +
			std::string("end") );
		return "lua_func";
	}
	
	struct ConstantMockHelper 
	{
		ConstantMockHelper():mock(),ptr_to_const(&mock),ptr_to(&mock){}
		ConstantMock mock;
		Constant const* ptr_to_const;
		Constant * ptr_to;
	};

}


class Constant_functions : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( Constant_functions );
		CPPUNIT_TEST(callConstantFunction_passedConstantInstance_calledOnce);
		CPPUNIT_TEST(callConstantFunction_passedNoneConstantInstance_calledOnce);
		CPPUNIT_TEST(callNoneConstantFunction_passedNoneConstantInstance_calledOnce);
		CPPUNIT_TEST(callLuaAddedConstantFunction_passedConstantInstance_calledOnce);
		CPPUNIT_TEST(callLuaAddedConstantFunction_passedNoneConstantInstance_calledOnce);
		CPPUNIT_TEST(callLuaAddedNoneConstantFunction_passedNoneConstantInstance_calledOnce);
	
#if OOLUA_STORE_LAST_ERROR ==1
		CPPUNIT_TEST(callNoneConstantFunction_passedConstantInstance_callReturnsFalse);
		CPPUNIT_TEST(callLuaAddedNoneConstantFunction_passedConstantInstance_callReturnsFalse);
#endif	
	
#if OOLUA_USE_EXCEPTIONS ==1 
		CPPUNIT_TEST(callNoneConstantFunction_passedConstantInstance_throwsRuntimeError);
		CPPUNIT_TEST(callLuaAddedNoneConstantFunction_passedConstantInstance_throwsRuntimeError);
#endif
	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script * m_lua;
public:
    Constant_functions():m_lua(0){}
    LVD_NOCOPY(Constant_functions)
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<Constant>();
	}
	void tearDown()
	{
		delete m_lua;
	}

	void callConstantFunction_passedConstantInstance_calledOnce()
	{
		char const* name = constant_function(m_lua);
		ConstantMockHelper helper;
		EXPECT_CALL(helper.mock,cpp_func_const() )
			.Times(1);
		m_lua->call(name,helper.ptr_to_const);
	}
	void callConstantFunction_passedNoneConstantInstance_calledOnce()
	{
		char const* name = constant_function(m_lua);
		ConstantMockHelper helper;
		EXPECT_CALL(helper.mock,cpp_func_const() )
			.Times(1);
		m_lua->call(name,helper.ptr_to);
	}


	void callNoneConstantFunction_passedNoneConstantInstance_calledOnce()
	{
		char const* name = none_constant_function(m_lua);
		ConstantMockHelper helper;
		EXPECT_CALL(helper.mock,cpp_func() )
			.Times(1);
		m_lua->call(name,helper.ptr_to);
	}

	void callLuaAddedConstantFunction_passedConstantInstance_calledOnce()
	{
		char const* name = add_lua_constant_function(m_lua);
		char const* func_name = lua_added_func(m_lua,name);
		ConstantMockHelper helper;
		EXPECT_CALL(helper.mock,cpp_func_const() )
			.Times(1);
		m_lua->call(func_name,helper.ptr_to_const);
	}
	void callLuaAddedConstantFunction_passedNoneConstantInstance_calledOnce()
	{
		char const* name = add_lua_constant_function(m_lua);
		char const* func_name = lua_added_func(m_lua,name);
		ConstantMockHelper helper;
		EXPECT_CALL(helper.mock,cpp_func_const() )
			.Times(1);
		m_lua->call(func_name,helper.ptr_to);
	}



	void callLuaAddedNoneConstantFunction_passedNoneConstantInstance_calledOnce()
	{
		char const* name = add_lua_none_constant_function(m_lua);
		char const* func_name = lua_added_func(m_lua,name);
		ConstantMockHelper helper;
		EXPECT_CALL(helper.mock,cpp_func() )
			.Times(1);
		m_lua->call(func_name,helper.ptr_to);
	}
#if OOLUA_STORE_LAST_ERROR ==1
	void callNoneConstantFunction_passedConstantInstance_callReturnsFalse()
	{
		char const* name = none_constant_function(m_lua);
		ConstantMockHelper helper;
		CPPUNIT_ASSERT_EQUAL(false,m_lua->call(name,helper.ptr_to_const));
	}
	void callLuaAddedNoneConstantFunction_passedConstantInstance_callReturnsFalse()
	{
		char const* name = add_lua_none_constant_function(m_lua);
		char const* func_name = lua_added_func(m_lua,name);
		ConstantMockHelper helper;
		CPPUNIT_ASSERT_EQUAL(false,m_lua->call(func_name,helper.ptr_to_const));
	}
#endif
	
#if OOLUA_USE_EXCEPTIONS ==1 
	void callNoneConstantFunction_passedConstantInstance_throwsRuntimeError()
	{
		char const* name = none_constant_function(m_lua);
		ConstantMockHelper helper;
		CPPUNIT_ASSERT_THROW( (m_lua->call(name,helper.ptr_to_const)),OOLUA::Runtime_error);
	}
	void callLuaAddedNoneConstantFunction_passedConstantInstance_throwsRuntimeError()
	{
		char const* name = add_lua_none_constant_function(m_lua);
		char const* func_name = lua_added_func(m_lua,name);
		ConstantMockHelper helper;
		CPPUNIT_ASSERT_THROW( (m_lua->call(func_name,helper.ptr_to_const)),OOLUA::Runtime_error);
	}
	
#endif
};

CPPUNIT_TEST_SUITE_REGISTRATION( Constant_functions);

