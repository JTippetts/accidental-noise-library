
#	include "oolua_tests_pch.h"
#	include "common_cppunit_headers.h"
#	include "gmock/gmock.h"
#	include "oolua.h"
#	include "expose_pulls_stub_param.h"

#	include <string>

//We are testing that a proxy class method can correctly pull a stub
//and can convert to the required type for the method which it is proxying.
class Pulls_stub_param : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(Pulls_stub_param);
		CPPUNIT_TEST(ref_noneConstantPointerPassed_CalledOnce);
		CPPUNIT_TEST(refConst_noneConstantPointerPassed_CalledOnce);
		CPPUNIT_TEST(refConst_ConstantPointerPassed_CalledOnce);
		CPPUNIT_TEST(ptr_noneConstantPointerPassed_CalledOnce);
		CPPUNIT_TEST(ptrConst_noneConstantPointerPassed_CalledOnce);
		CPPUNIT_TEST(ptrConst_ConstantPointerPassed_CalledOnce);
		CPPUNIT_TEST(refPtrConst_noneConstantPointerPassed_CalledOnce);
		CPPUNIT_TEST(refPtrConst_ConstantPointerPassed_CalledOnce);
		CPPUNIT_TEST(refConstPtrConst_noneConstantPointerPassed_CalledOnce);
		CPPUNIT_TEST(refConstPtrConst_ConstantPointerPassed_CalledOnce);
		CPPUNIT_TEST(constPtrConst_noneConstantPointerPassed_CalledOnce);
		CPPUNIT_TEST(constPtrConst_ConstantPointerPassed_CalledOnce);
	
	
#if OOLUA_STORE_LAST_ERROR	== 1
		CPPUNIT_TEST(ref_ConstantPointerPassed_callReturnsFalse);
		CPPUNIT_TEST(ptr_ConstantPointerPassed_callReturnsFalse);
#endif
	
	
#if OOLUA_USE_EXCEPTIONS == 1
		CPPUNIT_TEST(ref_ConstantPointerPassed_throwsRuntimeError);
		CPPUNIT_TEST(ptr_ConstantPointerPassed_throwsRuntimeError);
#endif	
	
	CPPUNIT_TEST_SUITE_END();

	struct Pull_stub_helper
	{
		Pull_stub_helper()
			:mock(),instance(&mock),stub()
		{}
		Stub1 const* ptr_const_stub()
		{
			return &stub;
		}
		Stub1* ptr_stub()
		{
			return &stub;
		}
		Mock_pulls_stub mock;
		Pulls_stub* instance;
		Stub1 stub;
		LVD_NOCOPY(Pull_stub_helper)
	};
	OOLUA::Script * m_lua;
	Pull_stub_helper * m_helper;

	//Generates a Lua function that when called and passed an class instance and stub
	//will call the method (func_name) on the instance.
	//returns the Lua function name which is generated.
	std::string generate_and_run_chunk_for_the_function_named(std::string const& func_name)
	{
		std::string lua_func_name("func");
		std::string chunk ( lua_func_name + std::string(" = function(obj,stub)\n")
			+std::string("obj:") + func_name + std::string("(stub)\n")
			+std::string("end\n"));

		m_lua->run_chunk(chunk);
		return lua_func_name;
	}
	bool generate_and_call_func_passing_const_ptr(std::string const& func_name)
	{
		std::string lua_func_name = generate_and_run_chunk_for_the_function_named(func_name);
		return m_lua->call(lua_func_name
						,m_helper->instance
						,m_helper->ptr_const_stub());
	}
	bool generate_and_call_func_passing_none_const_ptr(std::string const& func_name)
	{
		std::string lua_func_name = generate_and_run_chunk_for_the_function_named(func_name);
		return m_lua->call(lua_func_name
						,m_helper->instance
						,m_helper->ptr_stub());
	}

public:
    Pulls_stub_param():m_lua(0),m_helper(0){}
    LVD_NOCOPY(Pulls_stub_param)
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<Pulls_stub>();
		m_lua->register_class<Stub1>();
		m_helper = new Pull_stub_helper;
	}
	void tearDown()
	{
		delete m_helper;
		delete m_lua;
	}

	void ref_noneConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock,ref(::testing::Ref(m_helper->stub)))
			.Times(1);
		generate_and_call_func_passing_none_const_ptr("ref");
	}

	void refConst_noneConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock
					,ref_const(::testing::Ref(m_helper->stub)))
					.Times(1);
		generate_and_call_func_passing_none_const_ptr("ref_const");
	}
	void refConst_ConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock,ref_const(::testing::Ref(m_helper->stub)))
			.Times(1);
		generate_and_call_func_passing_const_ptr("ref_const");
	}
	void ptr_noneConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock,ptr(::testing::Eq( m_helper->ptr_stub() )))
			.Times(1);
		generate_and_call_func_passing_none_const_ptr("ptr");
	}

	void ptrConst_noneConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock,ptr_const(::testing::Eq( m_helper->ptr_stub() )))
			.Times(1);
		generate_and_call_func_passing_none_const_ptr("ptr_const");
	}
	void ptrConst_ConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock,ptr_const(::testing::Eq(m_helper->ptr_stub())))
			.Times(1);
		generate_and_call_func_passing_const_ptr("ptr_const");
	}

	void refPtrConst_noneConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock,ref_ptr_const(::testing::Eq(m_helper->ptr_stub())))
			.Times(1);
		generate_and_call_func_passing_none_const_ptr("ref_ptr_const");
	}

	void refPtrConst_ConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock,ref_ptr_const(::testing::Eq(m_helper->ptr_stub())))
			.Times(1);
		generate_and_call_func_passing_const_ptr("ref_ptr_const");
	}
	void refConstPtrConst_noneConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock,ref_const_ptr_const(::testing::Eq(m_helper->ptr_stub())))
			.Times(1);
		generate_and_call_func_passing_none_const_ptr("ref_const_ptr_const");
	}
	void refConstPtrConst_ConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock,ref_const_ptr_const(::testing::Eq(m_helper->ptr_stub())))
			.Times(1);
		generate_and_call_func_passing_const_ptr("ref_const_ptr_const");
	}
	void constPtrConst_noneConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock,const_ptr_const(::testing::Eq(m_helper->ptr_stub())))
			.Times(1);
		generate_and_call_func_passing_none_const_ptr("const_ptr_const");
	}
	void constPtrConst_ConstantPointerPassed_CalledOnce()
	{
		EXPECT_CALL(m_helper->mock,const_ptr_const(::testing::Eq(m_helper->ptr_stub())))
			.Times(1);
		generate_and_call_func_passing_const_ptr("const_ptr_const");
	}
	
#if OOLUA_STORE_LAST_ERROR	== 1
	void ref_ConstantPointerPassed_callReturnsFalse()
	{
		CPPUNIT_ASSERT_EQUAL(false,generate_and_call_func_passing_const_ptr("ref"));
	}
	void ptr_ConstantPointerPassed_callReturnsFalse()
	{
		CPPUNIT_ASSERT_EQUAL(false,generate_and_call_func_passing_const_ptr("ptr"));
	}
#endif
	
	
#if OOLUA_USE_EXCEPTIONS == 1
	void ref_ConstantPointerPassed_throwsRuntimeError()
	{
		CPPUNIT_ASSERT_THROW( (generate_and_call_func_passing_const_ptr("ref")), OOLUA::Runtime_error);
	}
	void ptr_ConstantPointerPassed_throwsRuntimeError()
	{
		CPPUNIT_ASSERT_THROW( (generate_and_call_func_passing_const_ptr("ptr")), OOLUA::Runtime_error);
	}
#endif	
};

CPPUNIT_TEST_SUITE_REGISTRATION( Pulls_stub_param );
