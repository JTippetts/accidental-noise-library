#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "common_cppunit_headers.h"
#	include "gmock/gmock.h"

#	include "expose_integral_function_params.h"
#	include "expose_member_function_calls.h"



struct Abstract_helper
{
	Abstract_helper(OOLUA::Script * lua):mock(),abs_class(&mock)
	{
		lua->register_class<Function_calls>();
	}
	FunctionCallsMock mock;
	Function_calls* abs_class;
	LVD_NOCOPY(Abstract_helper)
};

class LuaCallsCppFunctions : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(LuaCallsCppFunctions);
	CPPUNIT_TEST(cppMethodCall_callsMemberFunctionNoParams_calledOnce);
	CPPUNIT_TEST(cppMethodCall_callsMemberFunctionNoParamsViaADifferentThread_calledOnce);
	CPPUNIT_TEST(cppMethodCall_callsAbstractMemberFunctionNoParams_calledOnce);
	CPPUNIT_TEST(cppMethodCall_callsAbstractMemberFunctionOneParam_calledOnceWithCorrectParam);
	CPPUNIT_TEST(cppMethodCall_callsAbstractMemberFunctionThreeParam_calledOnceWithCorrectParams);
	CPPUNIT_TEST(cppMethodCall_callsPtrToCharFunction_calledOnceWithCorrectParam);
	CPPUNIT_TEST(cppMethodCall_callsPtrToConstCharFunction_calledOnceWithCorrectParam);
	CPPUNIT_TEST(cppMethodCall_callsFunctionWhichReturnsCharPtr_calledOnce);
	CPPUNIT_TEST(cppMethodCall_callsFunctionWhichReturnsHelloWorldCstring_returnCompareEqualToHelloWorldCstring);
	CPPUNIT_TEST(cppMethodCall_callsFunctionWhichReturnsConstHelloWorldCstring_returnCompareEqualToHelloWorldCstring);
	
#if	OOLUA_USE_EXCEPTIONS == 1
	CPPUNIT_TEST(fromLua_luaPassesBooleanToFunctionWantingInt_throwsRuntimeError);
#elif OOLUA_STORE_LAST_ERROR == 1
	CPPUNIT_TEST(fromLua_luaPassesBooleanToFunctionWantingInt_callReturnsFalse);
	CPPUNIT_TEST(fromLua_luaPassesBooleanToFunctionWantingInt_lastErrorHasAnEntry);
#endif
	
	CPPUNIT_TEST(fromLua_luaPassedNoParametersYetFunctionWantsALuaInstance_calledOnceWithCorrectInstance);

	CPPUNIT_TEST_SUITE_END();

	OOLUA::Script * m_lua;
public:
    LuaCallsCppFunctions():m_lua(0){}
    LVD_NOCOPY(LuaCallsCppFunctions)
	void setUp()
	{
		m_lua = new OOLUA::Script;
	}
	void tearDown()
	{
		delete m_lua;
	}

	void cppMethodCall_callsMemberFunctionNoParams_calledOnce()
	{
		m_lua->run_chunk(
				"foo = function(object)\n"
					"object:func()\n"
				"end");

		Abstract_helper helper(m_lua);
		EXPECT_CALL(helper.mock,func() )
			.Times(1);
		m_lua->call("foo",helper.abs_class);

	}
	
	void cppMethodCall_callsMemberFunctionNoParamsViaADifferentThread_calledOnce()
	{
		m_lua->run_chunk(
						 "foo = function(object)\n"
						 "local c = coroutine.create( function() object:func() end )\n"
						 "local res, err = coroutine.resume(c)\n"						 
						 "if res == false then error(err) end\n"
						 "end");
		
		Abstract_helper helper(m_lua);
		EXPECT_CALL(helper.mock,func() )
		.Times(1);
		m_lua->call("foo",helper.abs_class);
	}
	
	void cppMethodCall_callsAbstractMemberFunctionNoParams_calledOnce()
	{
		m_lua->run_chunk(
				"foo = function(object)\n"
					"object:abstract_func_0() \n"
				"end");

		Abstract_helper helper(m_lua);
		EXPECT_CALL(helper.mock,abstract_func_0() )
			.Times(1);
		m_lua->call("foo",helper.abs_class);
	}

	void cppMethodCall_callsAbstractMemberFunctionOneParam_calledOnceWithCorrectParam()
	{
		m_lua->run_chunk(
				"foo = function(object,i)\n"
					"object:abstract_func_1(i) \n"
				"end");

		Abstract_helper helper(m_lua);
		int p1(552);
		EXPECT_CALL(helper.mock,abstract_func_1( p1 ) )
			.Times(1);
		m_lua->call("foo",helper.abs_class,p1);
	}

	void cppMethodCall_callsAbstractMemberFunctionThreeParam_calledOnceWithCorrectParams()
	{

		m_lua->run_chunk(
				"foo = function(object,i,j,k)\n"
					"object:abstract_func_3(i,j,k) \n"
				"end");

		Abstract_helper helper(m_lua);
		int p1(1);
		int p2(2);
		int p3(3);
		EXPECT_CALL(helper.mock,abstract_func_3( p1,p2,p3 ) )
			.Times(1);
		m_lua->call("foo",helper.abs_class,p1,p2,p3);
	}
	void cppMethodCall_callsPtrToCharFunction_calledOnceWithCorrectParam()
	{
		m_lua->run_chunk(
			"foo = function(object,i)\n"
			"object:ptr_to_char('hello world') \n"
			"end");

		Abstract_helper helper(m_lua);
		EXPECT_CALL(helper.mock,ptr_to_char( ::testing::StrEq(OOLUA_UT::hello_world_cstring) ) )
			.Times(1);
		m_lua->call("foo",helper.abs_class,OOLUA_UT::hello_world_cstring);
	}

	void cppMethodCall_callsPtrToConstCharFunction_calledOnceWithCorrectParam()
	{
		m_lua->run_chunk(
			"foo = function(object,i)\n"
			"object:ptr_to_const_char('hello world') \n"
			"end");

		Abstract_helper helper(m_lua);
		EXPECT_CALL(helper.mock,ptr_to_const_char( ::testing::StrEq(OOLUA_UT::hello_world_cstring) ) )
			.Times(1);
		m_lua->call("foo",helper.abs_class,OOLUA_UT::hello_world_cstring);
	}

	void cppMethodCall_callsFunctionWhichReturnsCharPtr_calledOnce()
	{
		m_lua->run_chunk(
			"foo = function(object)\n"
			"result = object:returns_char_ptr() \n"
			"return result \n"
			"end");

		Abstract_helper helper(m_lua);
		EXPECT_CALL(helper.mock,returns_char_ptr( ) )
			.Times(1)
			.WillOnce(::testing::Return((char*)OOLUA_UT::hello_world_cstring));
		m_lua->call("foo",helper.abs_class);
	}
	void cppMethodCall_callsFunctionWhichReturnsHelloWorldCstring_returnCompareEqualToHelloWorldCstring()
	{
		m_lua->run_chunk(
			"foo = function(object)\n"
			"result = object:returns_char_ptr() \n"
			"return result \n"
			"end");

		Abstract_helper helper(m_lua);
		EXPECT_CALL(helper.mock,returns_char_ptr( ) )
			.Times(1)
			.WillOnce(::testing::Return<char*>((char*)OOLUA_UT::hello_world_cstring));
		m_lua->call("foo",helper.abs_class);

		std::string result;
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(std::string(OOLUA_UT::hello_world_cstring),result);
	}
	void cppMethodCall_callsFunctionWhichReturnsConstHelloWorldCstring_returnCompareEqualToHelloWorldCstring()
	{
		m_lua->run_chunk(
			"foo = function(object)\n"
			"result = object:returns_const_char_ptr() \n"
			"return result \n"
			"end");

		Abstract_helper helper(m_lua);
		EXPECT_CALL(helper.mock,returns_const_char_ptr( ) )
			.Times(1)
			.WillOnce(::testing::Return(OOLUA_UT::hello_world_cstring));
		m_lua->call("foo",helper.abs_class);

		std::string result;
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(std::string(OOLUA_UT::hello_world_cstring),result);
	}
	
#if	OOLUA_USE_EXCEPTIONS == 1
	void fromLua_luaPassesBooleanToFunctionWantingInt_throwsRuntimeError()
	{
		m_lua->register_class<Int_params>();
		m_lua->run_chunk("foo = function(obj) "
						 "obj:int_(true) "
						 "end");
		::testing::NiceMock<MockInt> instance;
		CPPUNIT_ASSERT_THROW((m_lua->call("foo",(Int_params*)&instance)) ,OOLUA::Runtime_error);
		
	}
#elif OOLUA_STORE_LAST_ERROR == 1
	void fromLua_luaPassesBooleanToFunctionWantingInt_callReturnsFalse()
	{
		m_lua->register_class<Int_params>();
		m_lua->run_chunk("foo = function(obj) "
						 "obj:int_(true) "
						 "end");
		::testing::NiceMock<MockInt> instance;
		CPPUNIT_ASSERT_EQUAL(false,m_lua->call("foo",(Int_params*)&instance));
		
	}
	void fromLua_luaPassesBooleanToFunctionWantingInt_lastErrorHasAnEntry()
	{
		m_lua->register_class<Int_params>();
		m_lua->run_chunk("foo = function(obj) "
						 "obj:int_(true) "
						 "end");
		::testing::NiceMock<MockInt> instance;
		m_lua->call("foo",(Int_params*)&instance);
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::get_last_error(*m_lua).empty() );
		
	}
#endif 
	
	void fromLua_luaPassedNoParametersYetFunctionWantsALuaInstance_calledOnceWithCorrectInstance()
	{
		m_lua->run_chunk("foo = function(object)\n"
						 "object:lua_state()\n"
						 "end");
		Abstract_helper helper(m_lua);
		lua_State* l = *m_lua;
		EXPECT_CALL(helper.mock,lua_state(::testing::Eq(l)) )
		.Times(1);
		m_lua->call("foo",helper.abs_class);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( LuaCallsCppFunctions );

