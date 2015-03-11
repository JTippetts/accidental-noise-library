#	include "oolua.h"
#	include "common_cppunit_headers.h"
#	include <limits>


namespace
{
	template<typename T>
	void push_then_pull(OOLUA::Script * lua,T input, T& output)
	{
		OOLUA::push2lua(*lua,input);
		OOLUA::pull2cpp(*lua,output);
	}
	std::string ILP64_and_LP64_fail_message(bool large_number)
	{
		return std::string("If you want to use a value this ") +std::string(large_number ? "big" : "small") 
		+ std::string(" with Lua, you will need change some if not all of the following in luaconf.h :\n"
		"LUA_INTEGER\n"
		"LUA_NUMBER_DOUBLE \n"
		"LUA_NUMBER\n"
		"LUAI_UACNUMBER\n"
		"lua_number2int\n"
		"lua_number2integer");
	}
	template<typename T>
	void assert_result_equals_numeric_limits_max(OOLUA::Script * lua)
	{
		T input((std::numeric_limits<T >::max)());
		T result(0);
		push_then_pull(lua,input,result);
		CPPUNIT_ASSERT_EQUAL_MESSAGE(ILP64_and_LP64_fail_message(true),input, result);
	}
	template<typename T>
	void assert_result_equals_numeric_limits_min_plus_one(OOLUA::Script * lua)
	{
		T input((std::numeric_limits<T >::min)()+1);
		T result(0);
		push_then_pull(lua,input,result);
		CPPUNIT_ASSERT_EQUAL_MESSAGE(ILP64_and_LP64_fail_message(false),input, result);
	}
}

class PushPullMayFail : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(PushPullMayFail);
		CPPUNIT_TEST(pushPull_pushSignedIntMax_pulledValueEqualsSignedIntMax_ILP64dataModelWillFail);
		CPPUNIT_TEST(pushPull_pushSignedIntMinPlusOne_pulledValueEqualsSignedIntMinPlusOne_ILP64dataModelWillFail);
		CPPUNIT_TEST(pushPull_pushSignedLongMax_pulledValueEqualsSignedLongMax_ILP64andLP64dataModelsWillFail);
		CPPUNIT_TEST(pushPull_pushSignedLongMinPlusOne_pulledValueEqualsSignedLongMinPlusOne_ILP64andLP64dataModelsWillFail);
	CPPUNIT_TEST_SUITE_END();

	OOLUA::Script * m_lua;

public:
    PushPullMayFail():m_lua(0){}
    LVD_NOCOPY(PushPullMayFail)
	void setUp()
	{
		m_lua = new OOLUA::Script;
	}
	void tearDown()
	{
		delete m_lua;
	}
	void pushPull_pushSignedIntMax_pulledValueEqualsSignedIntMax_ILP64dataModelWillFail()
	{
		assert_result_equals_numeric_limits_max<int>(m_lua);
	}
	void pushPull_pushSignedIntMinPlusOne_pulledValueEqualsSignedIntMinPlusOne_ILP64dataModelWillFail()
	{
		assert_result_equals_numeric_limits_min_plus_one<int>(m_lua);
	}
	void pushPull_pushSignedLongMax_pulledValueEqualsSignedLongMax_ILP64andLP64dataModelsWillFail()
	{
		assert_result_equals_numeric_limits_max<signed long>(m_lua);
	}
	void pushPull_pushSignedLongMinPlusOne_pulledValueEqualsSignedLongMinPlusOne_ILP64andLP64dataModelsWillFail()
	{
		assert_result_equals_numeric_limits_min_plus_one<signed long>(m_lua);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( PushPullMayFail );
