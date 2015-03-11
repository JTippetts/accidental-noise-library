//#ifndef NAMESPACED_CLASS_H_ //why is this wrapped and when did it become wrapped?
//#	define NAMESPACED_CLASS_H_

#	include "oolua_tests_pch.h"

#	include "oolua.h"
#	include "common_cppunit_headers.h"

#	include "expose_namespaced_class.h"


class NamespacedClass : public CppUnit::TestFixture 
{
	CPPUNIT_TEST_SUITE(NamespacedClass);
	
	CPPUNIT_TEST(checkName_comparesEqualToNameInsideNamespace);
	
	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script* m_lua;
public:
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<TEST_NAMESPACED_CLASS::Namespaced>();
	}
	void tearDown()
	{	
		delete m_lua;
	}
	void checkName_comparesEqualToNameInsideNamespace()
	{
		CPPUNIT_ASSERT_EQUAL(std::string("Namespaced"),
							 std::string(OOLUA::Proxy_class<TEST_NAMESPACED_CLASS::Namespaced>::class_name));
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( NamespacedClass );
//#endif


