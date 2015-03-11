#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "cpp_class_ops.h"
#	include "lua_class_ops.h"

#	include "common_cppunit_headers.h"

namespace
{
	bool get_result(OOLUA::Script* lua)
	{
		bool result;
		OOLUA::pull2cpp(*lua,result);
		return result;
	}
	template<typename T>
	std::auto_ptr<T> get_class(OOLUA::Script* lua)
	{
		OOLUA::cpp_acquire_ptr<T*>  result;
		OOLUA::pull2cpp(*lua,result);
		return std::auto_ptr<T>(result.m_ptr);
	}
	template<typename T,typename T1>
	void operator_script(OOLUA::Script* lua,T& lhs, T1& rhs,std::string const& op)
	{
		std::string func(std::string("func = function(lhs,rhs) return lhs ")
						+ op
						+ std::string(" rhs end") );
		lua->run_chunk(func);
		lua->call("func",&lhs,&rhs);
	}

}
class ClassOperators : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(ClassOperators);
	CPPUNIT_TEST(lessThan_leftIsLessThanRight_returnsTrue);
	CPPUNIT_TEST(lessThan_leftIsGreaterThanRight_returnsFalse);
	CPPUNIT_TEST(greaterThan_leftIsGreaterThanRightNeitherSeenBefore_returnsTrue);
	CPPUNIT_TEST(equal_leftComparesEqualToRightNeitherSeenBefore_returnsTrue);
	CPPUNIT_TEST(equal_leftIsSameInstanceAsRight_returnsTrue);
	CPPUNIT_TEST(greaterThanEqual_leftIsSameInstanceAsRight_returnsTrue);
	CPPUNIT_TEST(greaterThanEqual_IsSameBothHaveBeenSeen_returnsTrue);
	CPPUNIT_TEST(greaterThanEqual_IsSameLeftHasBeenSeen_returnsTrue);
	CPPUNIT_TEST(greaterThanEqual_IsSameRightHasBeenSeen_returnsTrue);
	CPPUNIT_TEST(mul_leftTimesRight_comparesEqualToCalculateValue);
	CPPUNIT_TEST(sub_leftSubtractRight_comparesEqualToCalculateValue);
	CPPUNIT_TEST(div_leftDivededByRight_comparesEqualToCalculateValue);
	CPPUNIT_TEST(equal_leftComparesEqualToRightAndHaveBeenPreviouslySeenByLua_returnsTrue);
	CPPUNIT_TEST(equal_leftComparesEqualToRightAndLeftHasBeenPreviouslySeenByLua_returnsTrue);
	CPPUNIT_TEST(equal_leftComparesEqualToRightAndRightHasBeenPreviouslySeenByLua_returnsTrue);

	CPPUNIT_TEST(equal_noneConstantAndConstant_returnsTrue);
	CPPUNIT_TEST(equal_constantAndNoneConstant_returnsTrue);
	CPPUNIT_TEST(equal_bothConstant_returnsTrue);
	CPPUNIT_TEST(lessThan_noneConstleftIsLessThanConstantRight_returnsTrue);
	CPPUNIT_TEST(lessThan_constleftIsLessThanNoneConstantRight_returnsTrue);
	CPPUNIT_TEST(div_leftConstantDivededByRightNoneConstant_comparesEqualToCalculateValue);
	CPPUNIT_TEST(div_leftNoneConstantDivededByRightConstant_comparesEqualToCalculateValue);
	CPPUNIT_TEST(mul_leftConstantTimesRightNoneConstant_comparesEqualToCalculateValue);
	CPPUNIT_TEST(mul_leftNoneConstantTimesRightConstant_comparesEqualToCalculateValue);
	CPPUNIT_TEST(sub_leftConstantSubtractRightNoneConstant_comparesEqualToCalculateValue);
	CPPUNIT_TEST(sub_leftNoneConstantSubtractRightConstant_comparesEqualToCalculateValue);
	CPPUNIT_TEST(sub_leftintSubtractRightint_comparesEqualToCalculateValue);

	CPPUNIT_TEST(add_leftPlusRight_comparesEqualToCalculateValue);
	CPPUNIT_TEST(subChain_leftSubMiddleSubRight_comparesEqualToCalculateValue);
	CPPUNIT_TEST_SUITE_END();

	OOLUA::Script * m_lua;
public:
    ClassOperators():m_lua(0){}
    LVD_NOCOPY(ClassOperators)
    void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<Class_ops>();
	}
	void tearDown()
	{
		delete m_lua;
	}

	void lessThan_leftIsLessThanRight_returnsTrue()
	{
		Class_ops left(0);
		Class_ops right(899);
		operator_script(m_lua,left,right,"<");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}

	void lessThan_leftIsGreaterThanRight_returnsFalse()
	{
		Class_ops left(5465655);
		Class_ops right(665);
		operator_script(m_lua,left,right,"<");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(false, result );
	}

	void greaterThan_leftIsGreaterThanRightNeitherSeenBefore_returnsTrue()
	{
		Class_ops left(800);
		Class_ops right(665);
		operator_script(m_lua,left,right,">");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}

	void greaterThanEqual_leftIsSameInstanceAsRight_returnsTrue()
	{
		Class_ops left(60001);
		operator_script(m_lua,left,left,">=");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}

	void greaterThanEqual_IsSameLeftHasBeenSeen_returnsTrue()
	{
		Class_ops left(60001);
		Class_ops right(left);
		OOLUA::push2lua(*m_lua,&left);
		Class_ops * l;
		OOLUA::pull2cpp(*m_lua,l);
		operator_script(m_lua,left,right,">=");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}
	void greaterThanEqual_IsSameRightHasBeenSeen_returnsTrue()
	{
		Class_ops left(60001);
		Class_ops right(left);
		OOLUA::push2lua(*m_lua,&right);
		Class_ops * l;
		OOLUA::pull2cpp(*m_lua,l);
		operator_script(m_lua,left,right,">=");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}

	void greaterThanEqual_IsSameBothHaveBeenSeen_returnsTrue()
	{
		Class_ops left(60001);
		Class_ops right(left);
		OOLUA::push2lua(*m_lua,&left);
		Class_ops * l;
		OOLUA::pull2cpp(*m_lua,l);

		OOLUA::push2lua(*m_lua,&right);
		OOLUA::pull2cpp(*m_lua,l);
		operator_script(m_lua,left,right,">=");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}

	void equal_leftIsSameInstanceAsRight_returnsTrue()
	{
		Class_ops left(80005000);
		operator_script(m_lua,left,left,"==");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}

	void equal_leftComparesEqualToRightNeitherSeenBefore_returnsTrue()
	{
		Class_ops left(466666);
		Class_ops right(left);
		operator_script(m_lua,left,right,"==");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}
	void equal_leftComparesEqualToRightAndHaveBeenPreviouslySeenByLua_returnsTrue()
	{
		Class_ops left(466666);
		Class_ops right(left);
		OOLUA::push2lua(*m_lua,&left);
		Class_ops * l;
		OOLUA::pull2cpp(*m_lua,l);
		OOLUA::push2lua(*m_lua,&right);
		OOLUA::pull2cpp(*m_lua,l);

		operator_script(m_lua,left,right,"==");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}
	void equal_leftComparesEqualToRightAndLeftHasBeenPreviouslySeenByLua_returnsTrue()
	{
		Class_ops left(466666);
		Class_ops right(left);
		OOLUA::push2lua(*m_lua,&left);
		Class_ops * l;
		OOLUA::pull2cpp(*m_lua,l);

		operator_script(m_lua,left,right,"==");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}
	void equal_leftComparesEqualToRightAndRightHasBeenPreviouslySeenByLua_returnsTrue()
	{
		Class_ops left(466666);
		Class_ops right(left);
	/*	m_lua->run_chunk(
			"function Class_ops:__eq(rhs) "
						" return 0 "
						"end "
						);*/
		OOLUA::push2lua(*m_lua,&right);
		Class_ops * l;
		OOLUA::pull2cpp(*m_lua,l);

		operator_script(m_lua,left,right,"==");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}

	void mul_leftTimesRight_comparesEqualToCalculateValue()
	{
		int lhs(10);
		int rhs(100);
		Class_ops left(lhs);
		Class_ops right(rhs);
		operator_script(m_lua,left,right,"*");
		int result = get_class<Class_ops>(m_lua)->geti();
		CPPUNIT_ASSERT_EQUAL( lhs*rhs, result );
	}

	void sub_leftSubtractRight_comparesEqualToCalculateValue()
	{
		int lhs(10);
		int rhs(100);
		Class_ops left(lhs);
		Class_ops right(rhs);
		operator_script(m_lua,left,right,"-");
		int result = get_class<Class_ops>(m_lua)->geti();
		CPPUNIT_ASSERT_EQUAL( lhs-rhs,  result );
	}

	void div_leftDivededByRight_comparesEqualToCalculateValue()
	{
		int lhs(1000);
		int rhs(100);
		Class_ops left(lhs);
		Class_ops right(rhs);
		operator_script(m_lua,left,right,"/");
		int result = get_class<Class_ops>(m_lua)->geti();
		CPPUNIT_ASSERT_EQUAL( lhs/rhs,  result );
	}

	void equal_noneConstantAndConstant_returnsTrue()
	{
		Class_ops left(466666);
		Class_ops const right(left);
		operator_script(m_lua,left,right,"==");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}
	void equal_constantAndNoneConstant_returnsTrue()
	{
		Class_ops const left(466666);
		Class_ops right(left);
		operator_script(m_lua,left,right,"==");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}
	void equal_bothConstant_returnsTrue()
	{
		Class_ops const left(466666);
		Class_ops const right(left);
		operator_script(m_lua,left,right,"==");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}
	void lessThan_noneConstleftIsLessThanConstantRight_returnsTrue()
	{
		Class_ops left(0);
		Class_ops const right(899);
		operator_script(m_lua,left,right,"<");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}
	void lessThan_constleftIsLessThanNoneConstantRight_returnsTrue()
	{
		Class_ops const left(0);
		Class_ops right(899);
		operator_script(m_lua,left,right,"<");
		bool result = get_result(m_lua);
		CPPUNIT_ASSERT_EQUAL(true, result );
	}

	void div_leftConstantDivededByRightNoneConstant_comparesEqualToCalculateValue()
	{
		int lhs(1000);
		int rhs(100);
		Class_ops const left(lhs);
		Class_ops right(rhs);
		operator_script(m_lua,left,right,"/");
		int result = get_class<Class_ops>(m_lua)->geti();
		CPPUNIT_ASSERT_EQUAL( lhs/rhs,  result );
	}
	void div_leftNoneConstantDivededByRightConstant_comparesEqualToCalculateValue()
	{
		int lhs(1000);
		int rhs(100);
		Class_ops left(lhs);
		Class_ops const right(rhs);
		operator_script(m_lua,left,right,"/");
		int result = get_class<Class_ops>(m_lua)->geti();
		CPPUNIT_ASSERT_EQUAL( lhs/rhs,  result );
	}

	void mul_leftConstantTimesRightNoneConstant_comparesEqualToCalculateValue()
	{
		int lhs(10);
		int rhs(100);
		Class_ops const left(lhs);
		Class_ops right(rhs);
		operator_script(m_lua,left,right,"*");
		int result = get_class<Class_ops>(m_lua)->geti();
		CPPUNIT_ASSERT_EQUAL( lhs*rhs, result );
	}
	void mul_leftNoneConstantTimesRightConstant_comparesEqualToCalculateValue()
	{
		int lhs(10);
		int rhs(100);
		Class_ops left(lhs);
		Class_ops const right(rhs);
		operator_script(m_lua,left,right,"*");
		int result = get_class<Class_ops>(m_lua)->geti();
		CPPUNIT_ASSERT_EQUAL( lhs*rhs, result );
	}

	void sub_leftConstantSubtractRightNoneConstant_comparesEqualToCalculateValue()
	{
		int lhs(10);
		int rhs(100);
		Class_ops const left(lhs);
		Class_ops right(rhs);
		operator_script(m_lua,left,right,"-");
		int result = get_class<Class_ops>(m_lua)->geti();
		CPPUNIT_ASSERT_EQUAL( lhs-rhs,  result );
	}
	void sub_leftNoneConstantSubtractRightConstant_comparesEqualToCalculateValue()
	{
		int lhs(10);
		int rhs(100);
		Class_ops left(lhs);
		Class_ops const right(rhs);
		operator_script(m_lua,left,right,"-");
		int result = get_class<Class_ops>(m_lua)->geti();
		CPPUNIT_ASSERT_EQUAL( lhs-rhs,  result );
	}

	void sub_leftintSubtractRightint_comparesEqualToCalculateValue()
	{
		int lhs(10);
		int rhs(1);
		int result(0);
		operator_script(m_lua,lhs,rhs,"-");
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL( lhs-rhs,  result );
	}

	void add_leftPlusRight_comparesEqualToCalculateValue()
	{
		int lhs(1);
		int rhs(2);
		Class_ops left(lhs);
		Class_ops right(rhs);
		operator_script(m_lua,left,right,"+");
		int result = get_class<Class_ops>(m_lua)->geti();
		CPPUNIT_ASSERT_EQUAL( lhs+rhs,  result );
	}
	void subChain_leftSubMiddleSubRight_comparesEqualToCalculateValue()
	{
		int lhs(1);
		int mid(3);
		int rhs(2);
		Class_ops left(lhs);
		Class_ops middle(mid);
		Class_ops right(rhs);

		m_lua->run_chunk("func = function(l,m,r) "
							"return l - m - r "
						"end ");
		m_lua->call("func",&left,&middle,&right);
		int result = get_class<Class_ops>(m_lua)->geti();
		CPPUNIT_ASSERT_EQUAL( lhs-mid-rhs,  result );
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( ClassOperators );

