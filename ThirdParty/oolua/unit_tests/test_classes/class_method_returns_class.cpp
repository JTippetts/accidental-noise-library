#	include "class_method_returns_class.h"
#	include "expose_stub_classes.h"
#	include "expose_method_returns_class.h"


class CppFunctionReturns : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(CppFunctionReturns);
		CPPUNIT_TEST(functionReturn_returnsRefToInstance_resultComparesEqualToInstance);
		CPPUNIT_TEST(functionReturn_returnsRefToConstantInstance_resultComparesEqualToInstance);
		CPPUNIT_TEST(functionReturn_returnsPtrToInstance_resultComparesEqualToInstance);
		CPPUNIT_TEST(functionReturn_returnsPtrToConstantInstance_resultComparesEqualToInstance);
		CPPUNIT_TEST(functionReturn_returnsRefPtrToConstantInstance_resultComparesEqualToInstance);
		CPPUNIT_TEST(functionReturn_returnsRefConstPtrToConstantInstance_resultComparesEqualToInstance);
		CPPUNIT_TEST(push_functionReturnsClassOnStackInstance_instanceIsToBeGarbageCollected);
	
	
	//CPPUNIT_TEST(functionReturn_functionReturnsNull_willAssert);
	
	CPPUNIT_TEST_SUITE_END();

	OOLUA::Script * m_lua;
	Method_returns_class* m_instance;
public:
    CppFunctionReturns():m_lua(0),m_instance(0){}
    LVD_NOCOPY(CppFunctionReturns)
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<Method_returns_class>();
		m_lua->register_class<Return_double>();
		m_instance = new Method_returns_class;
	}
	void tearDown()
	{
		delete m_instance;
		delete m_lua;
	}

	bool generate_lua_function_to_call_class_method(std::string const& method_name)
	{
		std::string generated_script = method_name + std::string(" = function(instance) ")
											+ std::string("return instance:") +method_name +std::string("() ")
									+std::string("end");
		return m_lua->run_chunk(generated_script);
	}
	bool generate_and_call_class_method(std::string const& method_name)
	{
		bool res = generate_lua_function_to_call_class_method(method_name);
		if(!res)return res;
		return m_lua->call(method_name,m_instance);
	}

	void functionReturn_returnsRefToInstance_resultComparesEqualToInstance()
	{
		generate_and_call_class_method("ref");
		assert_return_equals_input<Return_double*>(*m_lua,m_instance->return_ptr);
	};
	void functionReturn_returnsRefToConstantInstance_resultComparesEqualToInstance()
	{
		generate_and_call_class_method("ref_const");
		assert_return_equals_input<Return_double const*>(*m_lua,m_instance->return_ptr);
	};
	void functionReturn_returnsPtrToInstance_resultComparesEqualToInstance()
	{
		generate_and_call_class_method("ptr");
		assert_return_equals_input<Return_double*>(*m_lua,m_instance->return_ptr);
	};
	void functionReturn_returnsPtrToConstantInstance_resultComparesEqualToInstance()
	{
		generate_and_call_class_method("ptr_const");
		assert_return_equals_input<Return_double const * >(*m_lua,m_instance->return_ptr);
	};

	void functionReturn_returnsRefPtrToConstantInstance_resultComparesEqualToInstance()
	{
		generate_and_call_class_method("ref_ptr_const");
		assert_return_equals_input<Return_double const*>(*m_lua,m_instance->return_ptr);
	};
	void functionReturn_returnsRefConstPtrToConstantInstance_resultComparesEqualToInstance()
	{
		generate_and_call_class_method("ref_const_ptr_const");
		assert_return_equals_input<Return_double const*>(*m_lua,m_instance->return_ptr);
	};
	
	void push_functionReturnsClassOnStackInstance_instanceIsToBeGarbageCollected()
	{
		m_lua->run_chunk("function bugReport() "
						 "local object = Method_returns_class:new() "
						 "local stack = object:return_stack_instance() "
						 "return stack "
						 "end");
		m_lua->call("bugReport");

		OOLUA::INTERNAL::Lua_ud* ud = static_cast<OOLUA::INTERNAL::Lua_ud *>( lua_touserdata(*m_lua, -1) );
		CPPUNIT_ASSERT_EQUAL(true,OOLUA::INTERNAL::userdata_is_to_be_gced(ud));
		OOLUA::cpp_acquire_ptr<Return_double*> ret;
		OOLUA::pull2cpp(*m_lua,ret);
		delete ret.m_ptr;
		
		
	}
	void functionReturn_functionReturnsNull_willAssert()
	{
		generate_and_call_class_method("returns_null");
		Return_double* returnPtr(0);
		OOLUA::pull2cpp(*m_lua,returnPtr);
		CPPUNIT_ASSERT_EQUAL((Return_double*)0,returnPtr);
	}

};

CPPUNIT_TEST_SUITE_REGISTRATION(CppFunctionReturns);

