#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "common_cppunit_headers.h"
#	include <limits>
#	include "expose_stub_classes.h"


namespace
{
	template<typename T>
	void push_then_pull(OOLUA::Script * lua,T input, T& output)
	{
		OOLUA::push2lua(*lua,input);
		OOLUA::pull2cpp(*lua,output);
	}
	template<typename T>
	void assert_result_equals_numeric_limits_max(OOLUA::Script * lua)
	{
		T input((std::numeric_limits<T >::max)());
		T result(0);
		push_then_pull(lua,input,result);
		CPPUNIT_ASSERT_EQUAL(input, result);
	}
	template<typename T>
	void assert_result_equals_numeric_limits_min(OOLUA::Script * lua)
	{
		T input((std::numeric_limits<T >::min)());
		T result(0);
		push_then_pull(lua,input,result);
		CPPUNIT_ASSERT_EQUAL(input, result);
	}
	const float epsilon_value(.0000001f);

}
enum ENUM{FIRST_VALUE = 123,SECOND_VALUE = 51};

class PushPull : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(PushPull);
		CPPUNIT_TEST(pushPull_pushBoolTrue_pulledValueEqualsTrue);
		CPPUNIT_TEST(pushPull_pushBoolFalse_pulledValueEqualsFalse);

		CPPUNIT_TEST(pushPull_pushCharMin_pulledValueEqualsCharMin);
		CPPUNIT_TEST(pushPull_pushCharMax_pulledValueEqualsCharMax);
		CPPUNIT_TEST(pushPull_pushSignedCharMin_pulledValueEqualsSignedCharMin);
		CPPUNIT_TEST(pushPull_pushSignedCharMax_pulledValueEqualsSignedCharMax);
		CPPUNIT_TEST(pushPull_pushUnsignedCharMax_pulledValueEqualsUnsignedCharMax);

		CPPUNIT_TEST(pushPull_pushSignedShortMin_pulledValueEqualsSignedShortMin);
		CPPUNIT_TEST(pushPull_pushSignedShortMax_pulledValueEqualsSingedShortMax);
		CPPUNIT_TEST(pushPull_pushUnsignedShortMax_pulledValueEqualsUnsignedShortMax);

		CPPUNIT_TEST(pushPull_pushUnsignedIntMax_pulledValueEqualsUnsignedIntMax);

		CPPUNIT_TEST(pushPull_pushUnsignedLongMax_pulledValueEqualsUnsignedLongMax);

		CPPUNIT_TEST(pushPull_pushFloatMin_pulledValueWithinEplisonOfFloatMin);
		CPPUNIT_TEST(pushPull_pushFloatMax_pulledValueWithinEplisonOfFloatMax);

		CPPUNIT_TEST(pushPull_pushDoubleMin_pulledValueWithinEplisonOfDoubleMin);
		CPPUNIT_TEST(pushPull_pushDoubleMax_pulledValueWithinEplisonOfDoubleMax);

		CPPUNIT_TEST(pushPull_pushStdString_resultEqualsPushedValue);
		CPPUNIT_TEST(pushPull_stdStringWithEmbededNull_resultEqualsPushedValue);
		CPPUNIT_TEST(pushPull_stdStringWithNullAtEnd_resultEqualsPushedValue);
		CPPUNIT_TEST(pushPull_emptyStdString_resultEqualsPushedValue);

		CPPUNIT_TEST(pushPull_pushEnum_resultEqualsPushedValue);

		CPPUNIT_TEST(pushpull_pushClassPointer_resultAddressEqualsPushValue);
		
		CPPUNIT_TEST(pushPull_constPtrToCChar_pulledValueEqualsInput);

	CPPUNIT_TEST_SUITE_END();

	OOLUA::Script * m_lua;

public:
    PushPull():m_lua(0){}
    LVD_NOCOPY(PushPull)
	void setUp()
	{
		m_lua = new OOLUA::Script;
	}
	void tearDown()
	{
		delete m_lua;
	}
	void pushPull_pushBoolTrue_pulledValueEqualsTrue()
	{
		bool input(true);
		bool result(false);
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_EQUAL(input, result);
	}
	void pushPull_pushBoolFalse_pulledValueEqualsFalse()
	{
		bool input(false);
		bool result(true);
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_EQUAL(input, result);
	}
	void pushPull_pushCharMin_pulledValueEqualsCharMin()
	{
		assert_result_equals_numeric_limits_min<char>(m_lua);
	}
	void pushPull_pushCharMax_pulledValueEqualsCharMax()
	{
		assert_result_equals_numeric_limits_max<char>(m_lua);
	}
	void pushPull_pushSignedCharMin_pulledValueEqualsSignedCharMin()
	{
		assert_result_equals_numeric_limits_min<signed char>(m_lua);
	}
	void pushPull_pushSignedCharMax_pulledValueEqualsSignedCharMax()
	{
		assert_result_equals_numeric_limits_max<signed char>(m_lua);
	}
	void pushPull_pushUnsignedCharMax_pulledValueEqualsUnsignedCharMax()
	{
		assert_result_equals_numeric_limits_max<unsigned char>(m_lua);
	}
	void pushPull_pushSignedShortMin_pulledValueEqualsSignedShortMin()
	{
		assert_result_equals_numeric_limits_min<signed short>(m_lua);
	}
	void pushPull_pushSignedShortMax_pulledValueEqualsSingedShortMax()
	{
		assert_result_equals_numeric_limits_max<signed short>(m_lua);
	}
	void pushPull_pushUnsignedShortMax_pulledValueEqualsUnsignedShortMax()
	{
		assert_result_equals_numeric_limits_max<unsigned short>(m_lua);
	}
	void pushPull_pushUnsignedIntMax_pulledValueEqualsUnsignedIntMax()
	{
		assert_result_equals_numeric_limits_max<unsigned int>(m_lua);
	}
	void pushPull_pushUnsignedLongMax_pulledValueEqualsUnsignedLongMax()
	{
		assert_result_equals_numeric_limits_max<unsigned long>(m_lua);
	}
	void pushPull_pushFloatMin_pulledValueWithinEplisonOfFloatMin()
	{
		float input((std::numeric_limits<float>::min)());
		float result(0.f);
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_DOUBLES_EQUAL(input, result,epsilon_value);
	}
	void pushPull_pushFloatMax_pulledValueWithinEplisonOfFloatMax()
	{
		float input((std::numeric_limits<float>::max)());
		float result(0.f);
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_DOUBLES_EQUAL(input, result,epsilon_value);
	}
	void pushPull_pushDoubleMin_pulledValueWithinEplisonOfDoubleMin()
	{
		double input((std::numeric_limits<double>::min)());
		double result(0.0);
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_DOUBLES_EQUAL(input, result,epsilon_value);
	}
	void pushPull_pushDoubleMax_pulledValueWithinEplisonOfDoubleMax()
	{
		double input((std::numeric_limits<double>::max)());
		double result(0.0);
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_DOUBLES_EQUAL(input, result,epsilon_value);
	}

	void pushPull_pushStdString_resultEqualsPushedValue()
	{
		std::string input("input");
		std::string  result;
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_EQUAL(input, result);
	}
	void pushPull_stdStringWithEmbededNull_resultEqualsPushedValue()
	{
		std::string input("inp\0ut",6);
		std::string  result;
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_EQUAL(input, result);	
	}

	void pushPull_stdStringWithNullAtEnd_resultEqualsPushedValue()
	{
		std::string input("input\0",6);
		std::string result;
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_EQUAL(input,result);
	}
	void pushPull_emptyStdString_resultEqualsPushedValue()
	{
		std::string input;
		std::string result;
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_EQUAL(input,result);
	}


	void pushPull_pushEnum_resultEqualsPushedValue()
	{
		ENUM input(FIRST_VALUE);
		ENUM result(SECOND_VALUE);
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_EQUAL(true, input == result);
	}
	void pushpull_pushClassPointer_resultAddressEqualsPushValue()
	{
		m_lua->register_class<Stub1>();
		Stub1 d;
		Stub1* input = &d;
		Stub1* result;
		push_then_pull(m_lua,input,result);
		CPPUNIT_ASSERT_EQUAL(input, result);
	}
	void pushPull_constPtrToCChar_pulledValueEqualsInput()
	{
		/*cast stops the warning that char is not const,this is the type I want*/
		char * const  constPtrToChar =(char * const )"hello world";
		OOLUA::push2lua(*m_lua,constPtrToChar);
		std::string result;
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(std::string(constPtrToChar),result);
	}


};

CPPUNIT_TEST_SUITE_REGISTRATION( PushPull );
