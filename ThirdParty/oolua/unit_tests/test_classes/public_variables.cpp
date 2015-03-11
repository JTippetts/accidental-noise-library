#	include "oolua_tests_pch.h"
#       include "oolua.h"
#       include "common_cppunit_headers.h"
#		include "expose_public_instances.h"
#		include "expose_stub_classes.h"

class PublicVariablesTest : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(PublicVariablesTest);
	CPPUNIT_TEST(getAnInt_publicVariablesClassPassedToLua_returnsSetValue);
	CPPUNIT_TEST(setAnInt_publicVariablesClassAndIntPassedToLua_AnIntComparesEqualToSetValue);
	CPPUNIT_TEST(getIntPointer_publicVariablesWithIntPointerSetToOne_returnsSetValue);
	CPPUNIT_TEST(setIntPointer_publicVariablesAndIntSetToOne_IntEqualsSetValue);
	CPPUNIT_TEST(getClassInstance_passedPublicVariablesInstance_returnPtrComparesEqualToPublicClassInstance);
	CPPUNIT_TEST(setClassInstance_passedPublicVariablesInstanceAndDummyInstance_publicDummyInstancePtrCompareEqualsToInput);
	CPPUNIT_TEST(getClassInstance_passedPublicVariablesInstance_callReturnsTrue);
	CPPUNIT_TEST(getClassInstance_getDummyInstanceNonePtr_topOfStackGarbageCollectIsFalse);
	CPPUNIT_TEST(getClassInstance_getDummyInstanceNonePtr_topOfStackPointerEqualsMemberAddress);
	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script * m_lua;
	Public_variables* m_class_with_public_vars;
public:
    PublicVariablesTest():m_lua(0),m_class_with_public_vars(0){}
    LVD_NOCOPY(PublicVariablesTest)
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<Public_variables>();
		m_class_with_public_vars = new Public_variables;
	}
	void tearDown()
	{
		delete m_lua;
		delete m_class_with_public_vars;
		
	}
	void getAnInt_publicVariablesClassPassedToLua_returnsSetValue()
	{
		m_class_with_public_vars->an_int = Public_variables::set_value;
		m_lua->run_chunk("func = function(obj) return obj:get_an_int() end");
		m_lua->call("func",m_class_with_public_vars);
		int result;
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(Public_variables::set_value,result);
	}
	
	void setAnInt_publicVariablesClassAndIntPassedToLua_AnIntComparesEqualToSetValue()
	{
		m_lua->run_chunk("func = function(obj,i) obj:set_an_int(i) end");
		m_lua->call("func",m_class_with_public_vars,Public_variables::set_value);
		CPPUNIT_ASSERT_EQUAL(Public_variables::set_value,m_class_with_public_vars->an_int);
	}
	void getIntPointer_publicVariablesWithIntPointerSetToOne_returnsSetValue()
	{
		*m_class_with_public_vars->int_ptr = Public_variables::set_value;
		m_lua->run_chunk("func = function(obj) return obj:get_int_ptr() end");
		m_lua->call("func",m_class_with_public_vars);
		int result;
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(Public_variables::set_value,result); 
	}
	void setIntPointer_publicVariablesAndIntSetToOne_IntEqualsSetValue()
	{
		m_lua->run_chunk("func = function(obj,i) return obj:set_int_ptr(i) end");
		m_lua->call("func",m_class_with_public_vars,Public_variables::set_value);
		CPPUNIT_ASSERT_EQUAL(Public_variables::set_value,*m_class_with_public_vars->int_ptr);     
	}
	void getClassInstance_passedPublicVariablesInstance_returnPtrComparesEqualToPublicClassInstance()
	{
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("func = function(obj) return obj:get_dummy_instance() end");
		m_lua->call("func",m_class_with_public_vars);
		Stub1* result;
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(m_class_with_public_vars->dummy_instance,result);  
	}
	void setClassInstance_passedPublicVariablesInstanceAndDummyInstance_publicDummyInstancePtrCompareEqualsToInput()
	{
		m_lua->register_class<Stub1>();
		Stub1* input = m_class_with_public_vars->dummy_instance;
		m_class_with_public_vars->dummy_instance = 0;
		
		m_lua->run_chunk("func = function(obj,inst) obj:set_dummy_instance(inst) end");
		m_lua->call("func",m_class_with_public_vars,input);
		CPPUNIT_ASSERT_EQUAL(input,m_class_with_public_vars->dummy_instance);   
	}
	
	void getClassInstance_passedPublicVariablesInstance_callReturnsTrue()
	{
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("func = function(obj) return obj:get_dummy_instance_none_ptr() end");
		bool result = m_lua->call("func",m_class_with_public_vars);
		CPPUNIT_ASSERT_EQUAL(true,result);      
	}
	void getClassInstance_getDummyInstanceNonePtr_topOfStackGarbageCollectIsFalse()
	{
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("func = function(obj) return obj:get_dummy_instance_none_ptr() end");
		m_lua->call("func",m_class_with_public_vars);
		OOLUA::INTERNAL::Lua_ud* ud = static_cast<OOLUA::INTERNAL::Lua_ud *>( lua_touserdata(*m_lua, -1) );
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::INTERNAL::userdata_is_to_be_gced(ud));
	}
	void getClassInstance_getDummyInstanceNonePtr_topOfStackPointerEqualsMemberAddress()
	{
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("func = function(obj) return obj:get_dummy_instance_none_ptr() end");
		m_lua->call("func",m_class_with_public_vars);
		Stub1* result(0);
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(result ,&m_class_with_public_vars->dummy_instance_none_ptr);
	}
	
};
CPPUNIT_TEST_SUITE_REGISTRATION(PublicVariablesTest);


