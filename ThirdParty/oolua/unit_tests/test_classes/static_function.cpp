
#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "common_cppunit_headers.h"
#	include "expose_static_and_c_functions.h"
#	include "expose_hierarchy.h"

int returns_stack_count(lua_State* l)
{
	int top = lua_gettop(l);
	OOLUA::push2lua(l,top);
	return 1;
}

int stack_top_type(lua_State* l)
{
	int top = lua_type(l, -1);
	OOLUA::push2lua(l,top);
	return 1;
}
namespace 
{
	int static_func_base_return(0);
	int static_func_derived_return(1);
}
int staticFunction_pushes0(lua_State* l)
{
	OOLUA::push2lua(l,static_func_base_return);
	return 1;
}
int staticFunction_pushes1(lua_State* l)
{
	OOLUA::push2lua(l,static_func_derived_return);
	return 1;
}

struct DerivedClassHasStaticFunction : public ClassHasStaticFunction
{
};

OOLUA_PROXY_CLASS(DerivedClassHasStaticFunction,ClassHasStaticFunction)
	OOLUA_NO_TYPEDEFS
	OOLUA_ONLY_DEFAULT_CONSTRUCTOR
OOLUA_CLASS_END

EXPORT_OOLUA_NO_FUNCTIONS(DerivedClassHasStaticFunction)

class StaticFunction : public CppUnit::TestFixture 
{
	CPPUNIT_TEST_SUITE(StaticFunction);

	CPPUNIT_TEST(staticFunc_functionIsRegisteredUsingScript_callReturnsTrue);
	CPPUNIT_TEST(staticFunc_functionIsRegisteredUsingOOLua_callReturnsTrue);
	CPPUNIT_TEST(staticFunc_generatedProxy_callReturnsTrue);
	
	CPPUNIT_TEST(cFunctionAddedToClassTable_calledWithObjectInstaceAndReturnsStackCountOnEntry_returnEqualsOne);
	CPPUNIT_TEST(cFunctionAddedToClassTable_calledAsStaticFunctionAndReturnsStackCountOnEntry_returnEqualsOne);
	
	CPPUNIT_TEST(cFunctionAddedToClassTable_calledWithObjectInstaceAndReturnsStackTypeOfTop_returnEqualsUserData);
	CPPUNIT_TEST(cFunctionAddedToClassTable_calledAsStaticFunctionAndReturnsStackTypeOfTop_returnEqualsTable);
				 
	
	CPPUNIT_TEST(cFunctionAddedToClassTable_calledOnObjectInstaceWithFloatParamReturnsStackTypeOfTop_returnEqualsNumber);
	CPPUNIT_TEST(cFunctionAddedToClassTable_calledAsStaticFunctionWithFloatParamReturnsStackTypeOfTop_returnEqualsNumber);
	
	CPPUNIT_TEST(cFunctionAddedToClassTable_calledOnObjectInstaceWithFloatParamReturnsOneTypeOnStack_SecondReturnIsNil);
	
	CPPUNIT_TEST(cFunctionAddedToClassTable_calledProxyStaticWithObjectInstaceAndInputInt_returnEqualsInput);
	
	CPPUNIT_TEST(staticFunction_addedToBaseCalledInDerived_callReturnsTrue);
	CPPUNIT_TEST(staticFunction_addedToBaseOverriddenInDerived_callsDerivedVersion);
	CPPUNIT_TEST(staticFunction_addedToBaseInLuaAndCalledFromDerivedClassName_callReturnsTrue);
	CPPUNIT_TEST(staticData_addedOnBaseInLuaOnBase_calledOnDerived_callReturnsTrue);
	CPPUNIT_TEST(staticData_addedOnBaseInLuaOnBase_calledOnDerived_resultIsSetValue);
	
#if OOLUA_STORE_LAST_ERROR ==1
	CPPUNIT_TEST(staticFunc_functionIsUnregistered_callReturnsFalse);
#endif
	
#if OOLUA_USE_EXCEPTIONS ==1 
	CPPUNIT_TEST(staticFunc_functionIsUnregistered_throwsRuntimeError);
#endif	
	
	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script* m_lua;
public:
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<ClassHasStaticFunction>();
	}
	void tearDown()
	{	
		delete m_lua;
	}
	

	void staticFunc_functionIsRegisteredUsingScript_callReturnsTrue()
	{
		m_lua->register_class_static<ClassHasStaticFunction>("static_function"
															  ,&oolua_ClassHasStaticFunction_static_function);

		m_lua->run_chunk("foo = function() "
						 "ClassHasStaticFunction:static_function() "
						 "end ");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(true,result); 
	}
	void staticFunc_functionIsRegisteredUsingOOLua_callReturnsTrue()
	{
		OOLUA::register_class_static<ClassHasStaticFunction>(*m_lua
															  ,"static_function"
															  ,&oolua_ClassHasStaticFunction_static_function);
		m_lua->run_chunk("foo = function() "
						 "ClassHasStaticFunction:static_function() "
						 "end ");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(true,result); 
	}
	void staticFunc_generatedProxy_callReturnsTrue()
	{
		OOLUA::register_class_static<ClassHasStaticFunction>(*m_lua
															 ,"static_function"
															 ,&oolua_ClassHasStaticFunction_static_function);
		
		m_lua->run_chunk("foo = function() "
						 "ClassHasStaticFunction:static_function() "
						 "end ");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(true,result); 
	}


	void cFunctionAddedToClassTable_calledWithObjectInstaceAndReturnsStackCountOnEntry_returnEqualsOne()
	{
		OOLUA::register_class_static<ClassHasStaticFunction>(*m_lua
															 ,"stack_count"
															 ,&returns_stack_count);
		
		m_lua->run_chunk("foo = function(obj) "
						 "return obj:stack_count() "
						 "end ");
		ClassHasStaticFunction stack;
		ClassHasStaticFunction* obj = &stack;
		m_lua->call("foo",obj);
		int result(-1);
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(int(1),result); 
	}
	void cFunctionAddedToClassTable_calledAsStaticFunctionAndReturnsStackCountOnEntry_returnEqualsOne()
	{
		OOLUA::register_class_static<ClassHasStaticFunction>(*m_lua
															 ,"stack_count"
															 ,&returns_stack_count);
		
		m_lua->run_chunk("foo = function() "
						 "return ClassHasStaticFunction:stack_count() "
						 "end ");
		
		m_lua->call("foo");
		int result(-1);
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(int(1),result); 
	}
	
	void cFunctionAddedToClassTable_calledWithObjectInstaceAndReturnsStackTypeOfTop_returnEqualsUserData()
	{
		//userdata type on stack
		OOLUA::register_class_static<ClassHasStaticFunction>(*m_lua
															 ,"stack_top_type"
															 ,&stack_top_type);
		
		m_lua->run_chunk("foo = function(obj) "
						 "return obj:stack_top_type() "
						 "end ");
		ClassHasStaticFunction stack;
		ClassHasStaticFunction* obj = &stack;
		m_lua->call("foo",obj);
		int result(-1);
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(int(LUA_TUSERDATA),result); 
	}
	void cFunctionAddedToClassTable_calledAsStaticFunctionAndReturnsStackTypeOfTop_returnEqualsTable()
	{
		//table of type on top
		OOLUA::register_class_static<ClassHasStaticFunction>(*m_lua
															 ,"stack_top_type"
															 ,&stack_top_type);
		
		m_lua->run_chunk("foo = function() "
						 "return ClassHasStaticFunction:stack_top_type() "
						 "end ");
		
		m_lua->call("foo");
		int result(-1);
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(int(LUA_TTABLE),result); 
	}
	
	
	void cFunctionAddedToClassTable_calledOnObjectInstaceWithFloatParamReturnsStackTypeOfTop_returnEqualsNumber()
	{
		OOLUA::register_class_static<ClassHasStaticFunction>(*m_lua
															 ,"stack_top_type"
															 ,&stack_top_type);
		
		m_lua->run_chunk("foo = function(obj) "
						 "return obj:stack_top_type(1.0) "
						 "end ");
		ClassHasStaticFunction stack;
		ClassHasStaticFunction* obj = &stack;
		m_lua->call("foo",obj);
		int result(-1);
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(int(LUA_TNUMBER),result); 
	}
	void cFunctionAddedToClassTable_calledAsStaticFunctionWithFloatParamReturnsStackTypeOfTop_returnEqualsNumber()
	{
		OOLUA::register_class_static<ClassHasStaticFunction>(*m_lua
															 ,"stack_top_type"
															 ,&stack_top_type);
		
		m_lua->run_chunk("foo = function() "
						 "return ClassHasStaticFunction:stack_top_type(1.0) "
						 "end ");
		
		m_lua->call("foo");
		int result(-1);
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(int(LUA_TNUMBER),result); 
	}
	
	
	void cFunctionAddedToClassTable_calledOnObjectInstaceWithFloatParamReturnsOneTypeOnStack_SecondReturnIsNil()
	{
		OOLUA::register_class_static<ClassHasStaticFunction>(*m_lua
															 ,"stack_top_type"
															 ,&stack_top_type);
		
		m_lua->run_chunk("foo = function(obj) "
						 "a,b  =obj:stack_top_type(1.0) "
						 "assert(b == nil) "
						 "end ");
		ClassHasStaticFunction stack;
		ClassHasStaticFunction* obj = &stack;
		bool result =m_lua->call("foo",obj);
		CPPUNIT_ASSERT_EQUAL(true,result); 
	}


	void cFunctionAddedToClassTable_calledProxyStaticWithObjectInstaceAndInputInt_returnEqualsInput()
	{
		
		m_lua->register_class_static<ClassHasStaticFunction>(
															 "returns_input"
															 ,&OOLUA::Proxy_class<ClassHasStaticFunction>::returns_input);
		
		
		
		
		m_lua->run_chunk("foo = function(obj,input) "
						 "return obj:returns_input(input) "
						 "end ");
		ClassHasStaticFunction stack;
		ClassHasStaticFunction* obj = &stack;
		int input = 1;
		m_lua->call("foo",obj,input);
		int result(-1);
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(input,result); 
	}
	void staticFunction_registeredInBaseCalledInDerived_resultReturnsTrue()
	{
		OOLUA::register_class_and_bases<DerivedClassHasStaticFunction>(*m_lua);
		m_lua->register_class_static<ClassHasStaticFunction>("stack_count"
															 ,&returns_stack_count);
		
		m_lua->run_chunk("foo = function(obj) "
						 "return obj:stack_count() "
						 "end ");
		DerivedClassHasStaticFunction derived;
		DerivedClassHasStaticFunction* dp = &derived;
		//std::cout <<"length of bases  " <<TYPELIST::Length<OOLUA::Proxy_class<DerivedClassHasStaticFunction>::Bases>::value 
		//<<"\twrote in file :" <<__FILE__ <<std::endl;
		bool result = m_lua->call("foo",dp);
		CPPUNIT_ASSERT_EQUAL(result, true);
	}

	void staticFunction_addedToBaseCalledInDerived_callReturnsTrue()
	{
		OOLUA::register_class_and_bases<DerivedFromTwoAbstractBasesAndAbstract3>(*m_lua);
		m_lua->register_class_static<Abstract3>("stack_count",&returns_stack_count);
		
		m_lua->run_chunk("foo = function(obj) "
						 "return obj:stack_count() "
						 "end ");
		DerivedFromTwoAbstractBasesAndAbstract3 derived;
		bool result = m_lua->call("foo",&derived);
		CPPUNIT_ASSERT_EQUAL(result, true);
	}

	void staticFunction_addedToBaseOverriddenInDerived_callsDerivedVersion()
	{
		OOLUA::register_class_and_bases<DerivedFromTwoAbstractBasesAndAbstract3>(*m_lua);
		m_lua->register_class_static<Abstract3>("static_func",&staticFunction_pushes0);
		m_lua->register_class_static<DerivedFromTwoAbstractBasesAndAbstract3>("static_func",&staticFunction_pushes1);
		
		m_lua->run_chunk("foo = function(obj) "
						 "return obj:static_func() "
						 "end ");
		DerivedFromTwoAbstractBasesAndAbstract3 derived;
		m_lua->call("foo",&derived);
		int result;
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(static_func_derived_return, result);
	}
	void staticFunction_addedToBaseInLuaAndCalledFromDerivedClassName_callReturnsTrue()
	{
		OOLUA::register_class_and_bases<DerivedFromTwoAbstractBasesAndAbstract3>(*m_lua);
		m_lua->run_chunk("function Abstract3:lua_func() return 1 end ");
		
		//m_lua->run_chunk("Abstract3[\"static_data\"]=3 ");

		m_lua->run_chunk("foo = function() "
						 "return DerivedFromTwoAbstractBasesAndAbstract3:lua_func() "
						 "end ");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(result, true);
	}
	void staticData_addedOnBaseInLuaOnBase_calledOnDerived_callReturnsTrue()
	{
		OOLUA::register_class_and_bases<DerivedFromTwoAbstractBasesAndAbstract3>(*m_lua);
		m_lua->run_chunk("Abstract3[\"static_data\"]=1 ");
		
		m_lua->run_chunk("foo = function() "
						 "return DerivedFromTwoAbstractBasesAndAbstract3.static_data "
						 "end ");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(result, true);
	}
	
	void staticData_addedOnBaseInLuaOnBase_calledOnDerived_resultIsSetValue()
	{
		OOLUA::register_class_and_bases<DerivedFromTwoAbstractBasesAndAbstract3>(*m_lua);
		m_lua->run_chunk("Abstract3[\"static_data\"]=1 ");
		
		m_lua->run_chunk("foo = function() "
						 "return DerivedFromTwoAbstractBasesAndAbstract3.static_data "
						 "end ");
		m_lua->call("foo");
		int result;
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(int(1),result);
	}




	
	
#if OOLUA_STORE_LAST_ERROR ==1
	void staticFunc_functionIsUnregistered_callReturnsFalse()
	{
		m_lua->run_chunk("foo = function() "
						 "ClassHasStaticFunction:static_function() "
						 "end ");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(false,result); 
	}
#endif
	
#if OOLUA_USE_EXCEPTIONS ==1 
	void staticFunc_functionIsUnregistered_throwsRuntimeError()
	{
		m_lua->run_chunk("foo = function() "
						 "ClassHasStaticFunction:static_function() "
						 "end ");
		CPPUNIT_ASSERT_THROW( (m_lua->call("foo")),OOLUA::Runtime_error);
	}

	
#endif
};

CPPUNIT_TEST_SUITE_REGISTRATION(StaticFunction);






