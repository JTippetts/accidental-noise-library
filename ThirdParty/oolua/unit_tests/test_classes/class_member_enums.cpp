#	include "oolua_tests_pch.h"

#	include "common_cppunit_headers.h"
#	include "oolua.h"
#	include "expose_class_enums.h"

class ClassMemberEnums : public CppUnit::TestFixture 
{
	CPPUNIT_TEST_SUITE(ClassMemberEnums);
	CPPUNIT_TEST(enumIsRegistered_safeAtReturnsTrue);
	CPPUNIT_TEST(queriesKnownValue_enum0AsInt_safeAtreturnsEnum0);
	CPPUNIT_TEST(queriesKnownValue_enum0Enum_safeAtreturnsEnum0);
	CPPUNIT_TEST(luaReturnsEnum0_resultIsEqualToEnum0);
	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script* m_lua;
public:
	ClassMemberEnums():m_lua(0){}
	void setUp()
	{
		m_lua = new OOLUA::Script;
	}
	void tearDown()
	{
		delete m_lua;
	}
	void enumIsRegistered_safeAtReturnsTrue()
	{
		m_lua->register_class<ClassWithEnums>();
		OOLUA::Lua_table t(*m_lua,OOLUA::Proxy_class<ClassWithEnums>::class_name);
		int value=-1;
		bool result = t.safe_at("ENUM_0",value);
		CPPUNIT_ASSERT_EQUAL(true , result);
	}
	
	
	void queriesKnownValue_enum0AsInt_safeAtreturnsEnum0()
	{
		m_lua->register_class<ClassWithEnums>();
		OOLUA::Lua_table t(*m_lua,OOLUA::Proxy_class<ClassWithEnums>::class_name);
		int value=-1;
		t.safe_at("ENUM_0",value);
		CPPUNIT_ASSERT_EQUAL((int)ClassWithEnums::ENUM_0 , value);
	}
	
	void queriesKnownValue_enum0Enum_safeAtreturnsEnum0()
	{
		m_lua->register_class<ClassWithEnums>();
		OOLUA::Lua_table t(*m_lua,OOLUA::Proxy_class<ClassWithEnums>::class_name);
		ClassWithEnums::ClassEnum return_value = ClassWithEnums::ENUM_1;
		t.safe_at("ENUM_0",return_value);
		CPPUNIT_ASSERT_EQUAL(ClassWithEnums::ENUM_0 , return_value);
	}
	
	void luaReturnsEnum0_resultIsEqualToEnum0()
	{
		m_lua->register_class<ClassWithEnums>();
		m_lua->run_chunk("return ClassWithEnums.ENUM_0");
		ClassWithEnums::ClassEnum return_value = ClassWithEnums::ENUM_1;
		OOLUA::pull2cpp(*m_lua,return_value);
		CPPUNIT_ASSERT_EQUAL(ClassWithEnums::ENUM_0 , return_value);
	}


};
CPPUNIT_TEST_SUITE_REGISTRATION(ClassMemberEnums);
