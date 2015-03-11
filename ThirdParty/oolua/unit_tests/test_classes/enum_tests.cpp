

#	include "oolua.h"
#	include "common_cppunit_headers.h"
#	include "expose_enum.h"

namespace 
{
	struct dummy_class{};
}

class Enum_tests : public CppUnit::TestFixture 
{
	CPPUNIT_TEST_SUITE(Enum_tests);
		CPPUNIT_TEST(memberFunction_returnsEnum_defaultValueIsInvalid);
		CPPUNIT_TEST(memberFunctionSetsEnum_passedGreen_resultIsGreen);
		CPPUNIT_TEST(constructWithEnum_passedValueGreen_functionReturnsGreen);


#	if OOLUA_USE_EXCEPTIONS == 1
		CPPUNIT_TEST(constructWithEnum_passedString_throwsOoluaRuntimeError);
		CPPUNIT_TEST(constructWithEnum_passedNil_throwsOoluaRuntimeError);
		CPPUNIT_TEST(constructWithEnum_passedTable_throwsOoluaRuntimeError);
		CPPUNIT_TEST(constructWithEnum_passedBool_throwsOoluaRuntimeError);
		CPPUNIT_TEST(constructWithEnum_passedFunction_throwsOoluaRuntimeError);
		CPPUNIT_TEST(constructWithEnum_passedCoroutine_throwsOoluaRuntimeError);
#	elif OOLUA_STORE_LAST_ERROR == 1
		CPPUNIT_TEST(constructWithEnum_passedString_callReturnsFalse);
		CPPUNIT_TEST(constructWithEnum_passedNil_callReturnsFalse);
		CPPUNIT_TEST(constructWithEnum_passedTable_callReturnsFalse);
		CPPUNIT_TEST(constructWithEnum_passedBool_callReturnsFalse);
		CPPUNIT_TEST(constructWithEnum_passedFunction_callReturnsFalse);
		CPPUNIT_TEST(constructWithEnum_passedCoroutine_callReturnsFalse);
#	endif
	
		CPPUNIT_TEST(canConvertToIntFrom_intType_valueEqualsOne);
		CPPUNIT_TEST(canConvertToIntFrom_classType_valueEqualsZero);
		CPPUNIT_TEST(canConvertToIntFrom_enumType_valueEqualsOne);
	
	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script* m_lua;
public:
	Enum_tests():m_lua(0){}
	void setUp()
	{
		m_lua = new OOLUA::Script;
	}
	void tearDown()
	{
		delete m_lua;
	}
	
	void memberFunction_returnsEnum_defaultValueIsInvalid()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
							"local obj = Enums:new() "
							"return obj:get_enum() "
						 "end");
		Enums::COLOUR result(Enums::GREEN);
		m_lua->call("foo");
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(Enums::INVALID,result);
		
	}
	
	void memberFunctionSetsEnum_passedGreen_resultIsGreen()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
							"local obj = Enums:new() "
							"obj:set_enum(obj.GREEN) "
							"return obj:get_enum() "
						 "end");
		Enums::COLOUR result(Enums::INVALID);
		m_lua->call("foo");
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(Enums::GREEN,result);
	}
	
	void constructWithEnum_passedValueGreen_functionReturnsGreen()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
							"local obj = Enums:new(Enums.GREEN) "
							"return obj:get_enum() "
						 "end");
		Enums::COLOUR result(Enums::INVALID);
		m_lua->call("foo");
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(Enums::GREEN,result);
	}
	
	
#	if OOLUA_USE_EXCEPTIONS == 1
	void constructWithEnum_passedString_throwsOoluaRuntimeError()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
							"local obj = Enums:new('foo') "
						 "end");
		CPPUNIT_ASSERT_THROW(m_lua->call("foo"),OOLUA::Runtime_error);
	}
	void constructWithEnum_passedNil_throwsOoluaRuntimeError()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
							"local obj = Enums:new(nil) "
						 "end");
		CPPUNIT_ASSERT_THROW(m_lua->call("foo"),OOLUA::Runtime_error);
	}
	void constructWithEnum_passedTable_throwsOoluaRuntimeError()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
							"local obj = Enums:new({}) "
						 "end");
		CPPUNIT_ASSERT_THROW(m_lua->call("foo"),OOLUA::Runtime_error);
	}
	void constructWithEnum_passedBool_throwsOoluaRuntimeError()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
							"local obj = Enums:new(true) "
						 "end");
		CPPUNIT_ASSERT_THROW(m_lua->call("foo"),OOLUA::Runtime_error);
	}
	void constructWithEnum_passedFunction_throwsOoluaRuntimeError()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
							"local obj = Enums:new( function() end) "
						 "end");
		CPPUNIT_ASSERT_THROW(m_lua->call("foo"),OOLUA::Runtime_error);
	}
	void constructWithEnum_passedCoroutine_throwsOoluaRuntimeError()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
						 "local obj = Enums:new( coroutine.create (foo)) "
						 "end");
		CPPUNIT_ASSERT_THROW(m_lua->call("foo"),OOLUA::Runtime_error);
	}
	
#	elif OOLUA_STORE_LAST_ERROR == 1	
	
	void constructWithEnum_passedString_callReturnsFalse()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
						 "local obj = Enums:new('foo') "
						 "end");
		CPPUNIT_ASSERT_EQUAL(false,m_lua->call("foo"));
	}
	void constructWithEnum_passedNil_callReturnsFalse()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
						 "local obj = Enums:new(nil) "
						 "end");
		CPPUNIT_ASSERT_EQUAL(false,m_lua->call("foo"));
	}
	void constructWithEnum_passedTable_callReturnsFalse()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
						 "local obj = Enums:new({}) "
						 "end");
		CPPUNIT_ASSERT_EQUAL(false,m_lua->call("foo"));
	}
	void constructWithEnum_passedBool_callReturnsFalse()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
						 "local obj = Enums:new(true) "
						 "end");
		CPPUNIT_ASSERT_EQUAL(false,m_lua->call("foo"));
	}
	void constructWithEnum_passedFunction_callReturnsFalse()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
						 "local obj = Enums:new( function() end) "
						 "end");
		CPPUNIT_ASSERT_EQUAL(false,m_lua->call("foo"));
	}
	void constructWithEnum_passedCoroutine_callReturnsFalse()
	{
		m_lua->register_class<Enums>();
		m_lua->run_chunk("foo = function() "
						 "local obj = Enums:new( coroutine.create (foo)) "
						 "end");
		CPPUNIT_ASSERT_EQUAL(false,m_lua->call("foo"));
	}
	
	
#	endif


	void canConvertToIntFrom_intType_valueEqualsOne()
	{
		CPPUNIT_ASSERT_EQUAL(1,(int)(OOLUA::INTERNAL::can_convert_to_int<int>::value));
	}
	
	void canConvertToIntFrom_classType_valueEqualsZero()
	{
		
		CPPUNIT_ASSERT_EQUAL(0,(int)(OOLUA::INTERNAL::can_convert_to_int<dummy_class>::value));
	}
	
	void canConvertToIntFrom_enumType_valueEqualsOne()
	{
		CPPUNIT_ASSERT_EQUAL(1,(int)(OOLUA::INTERNAL::can_convert_to_int<Enums::COLOUR>::value));
	}


	
};
CPPUNIT_TEST_SUITE_REGISTRATION(Enum_tests);
