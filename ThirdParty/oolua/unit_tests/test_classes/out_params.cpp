
#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "common_cppunit_headers.h"
#	include "gmock/gmock.h"
#	include "expose_out_params.h"
#	include <string>
#	include <sstream>

const std::string hello_world_str = "hello world";
void set_string_in_MockParamWithStringMember_ref(MockParamWithStringMember& mock)
{
	mock.str = hello_world_str;
}

class OutParams : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(OutParams);
		CPPUNIT_TEST(inOutTrait_luaPassesIntFunctionWantsRefToInt_calledWithExspectedValue);
		CPPUNIT_TEST(inOutTrait_luaPassesIntFunctionWantsRefToInt_returnTypeAtTopOfStackIsInt);
		CPPUNIT_TEST(inOutTrait_luaPassesIntFunctionWantsRefToInt_returnIsInput);
		CPPUNIT_TEST(inOutTrait_luaPassesIntFunctionWantsRefToInt_valueAtTopOfStackIsExspectedValue);

		CPPUNIT_TEST(inOutTrait_luaPassesIntFunctionWantsIntPtr_returnValueAtTopOfStackIsInputValue);

		CPPUNIT_TEST(inOutTrait_twoRefsToInt_calledOnceWithCorrectInputs);
		CPPUNIT_TEST(inOutTrait_twoRefsToInt_firstReturnIsCorrectValue);
		CPPUNIT_TEST(inOutTrait_twoRefsToInt_secondReturnIsCorrectValue);

		CPPUNIT_TEST(outTrait_luaPassesNoParamFunctionWantsRefToInt_valueAtTopOfStackIsExspectedValue);
		CPPUNIT_TEST(outTrait_luaPassesNoParamFunctionWantsIntPtr_calledOnce);
		CPPUNIT_TEST(outTrait_luaPassesNoParamFunctionWantsIntPtr_returnTypeAtTopOfStackIsInt);
		CPPUNIT_TEST(outTrait_luaPassesNoParamFunctionWantsIntPtr_valueAtTopOfStackIsExspectedValue);

		CPPUNIT_TEST(noTraits_luaPassesIntFunctionWantsIntPtr_callsFunctionWithCorrectPointeeValue);
		CPPUNIT_TEST(noTraits_luaPassesIntFunctionWantsIntPtr_afterCallTheStackIsTheSameAsBeforeCall);
		CPPUNIT_TEST(luaReturnOrder_luaFunctionWhichReturnsMultipleValues_orderIsAsExspectedElseError);
		CPPUNIT_TEST(luaReturnOrder_luaFunctionWhichReturnsMultipleValuesToCpp_orderFromTopOfStackIsParam3Param2Param1);
		CPPUNIT_TEST(ordering_functionWhichReturnsValueAndTwoInOutParams_orderFromTopOfStackIsParam2Param1Return);
	
	CPPUNIT_TEST(OutTrait_luaPassesNoParamFunctionWantsRefToUserData_topOfStackIsOwnedByLua);
	CPPUNIT_TEST(OutTrait_luaPassesNoParamFunctionWantsPtrToUserData_topOfStackIsOwnedByLua);
	
	CPPUNIT_TEST(OutTrait_luaPassesNoParamFunctionWantsRefToUserData_stringMemberIsSetToHelloWorld);
	CPPUNIT_TEST_SUITE_END();

	OOLUA::Script * m_lua;
	std::string stringify(int const& i)
	{
		std::stringstream ss;
		ss<<i;
		return ss.str();
	}
	std::string function_start(std::string const& func_name,bool returns)
	{
		std::string chunk = std::string("func = function(obj)");
		if(returns) chunk += std::string("return ");
		chunk +=std::string(" obj:") + func_name + std::string("(");
		return chunk;
	}
	std::string function_end()
	{
		return std::string(") end");
	}
	void run_chunk_function_push_int(std::string const& func_name,int value,bool returns)
	{
		std::string chunk = function_start(func_name,returns);
		chunk += stringify(value) + function_end();
		m_lua->run_chunk(chunk);
	}
	void run_chunk_function_pass_nothing(std::string const& func_name,bool returns)
	{
		std::string chunk = function_start(func_name,returns);
		chunk += function_end();
		m_lua->run_chunk(chunk);
	}
	void run_chunk_function_push_two_ints(std::string const& func_name,int value1,int value2,bool returns)
	{
		std::string chunk = function_start(func_name,returns);
		chunk += stringify(value1)+ std::string(",") + stringify(value2)+ function_end();
		m_lua->run_chunk(chunk);
	}
	template<typename InputAndResultType>
	void assert_top_of_stack_is_exspected_value(InputAndResultType const& exspected)
	{
		InputAndResultType top_of_stack(0);
		OOLUA::pull2cpp(*m_lua,top_of_stack);
		CPPUNIT_ASSERT_EQUAL(exspected,top_of_stack);
	}

public:
    OutParams():m_lua(0){}
    LVD_NOCOPY(OutParams)
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<OutParamsTest>();
	}
	void tearDown()
	{
		delete m_lua;
	}
	void inOutTrait_luaPassesIntFunctionWantsRefToInt_calledWithExspectedValue()
	{
		int exspected(OutParamsTest::Param1);
		run_chunk_function_push_int("int_ref",exspected,true);
		MockOutParamsTest mock;

		EXPECT_CALL(mock,int_ref(::testing::Eq( exspected ) ))
			.Times(1);
		m_lua->call("func",(OutParamsTest*)&mock);

	}
	void inOutTrait_luaPassesIntFunctionWantsRefToInt_returnTypeAtTopOfStackIsInt()
	{
		int exspected(OutParamsTest::Dummy);
		run_chunk_function_push_int("int_ref",exspected,true);
		::testing::NiceMock<MockOutParamsTest> stub;
		m_lua->call("func",(OutParamsTest*)&stub);
		CPPUNIT_ASSERT_EQUAL(true, lua_type(*m_lua,-1) == LUA_TNUMBER);
	}
	void inOutTrait_luaPassesIntFunctionWantsRefToInt_returnIsInput()
	{
		int exspected(OutParamsTest::Param1);
		run_chunk_function_push_int("int_ref",exspected,true);
		::testing::NiceMock<MockOutParamsTest> stub;
		m_lua->call("func",(OutParamsTest*)&stub);
		assert_top_of_stack_is_exspected_value(exspected);

	}
	void inOutTrait_luaPassesIntFunctionWantsRefToInt_valueAtTopOfStackIsExspectedValue()
	{
		int input(OutParamsTest::Param1);
		int exspected(OutParamsTest::Param1);
		run_chunk_function_push_int("int_ref_change",input,true);
		::testing::NiceMock<MockOutParamsTest> stub;
		m_lua->call("func",(OutParamsTest*)&stub);
		assert_top_of_stack_is_exspected_value(exspected);

	}
	void inOutTrait_luaPassesIntFunctionWantsIntPtr_returnValueAtTopOfStackIsInputValue()
	{
		int input_param(OutParamsTest::Param1);
		run_chunk_function_push_int("int_ptr_in_out",input_param,true);
		::testing::NiceMock<MockOutParamsTest> stub;
		m_lua->call("func",(OutParamsTest*)&stub);
		assert_top_of_stack_is_exspected_value(input_param);
	}

	void inOutTrait_twoRefsToInt_calledOnceWithCorrectInputs()
	{
		int value1(OutParamsTest::Param1);
		int value2(OutParamsTest::Param2);
		run_chunk_function_push_two_ints("two_int_refs",value1,value2,true);
		MockOutParamsTest mock;
		EXPECT_CALL(mock,two_int_refs(::testing::Eq( value1 ),::testing::Eq( value2 ) ))
			.Times(1);
		m_lua->call("func",(OutParamsTest*)&mock);
	}

	//parameters which return are pushed left to right after a return value.
	//The return is either at the bottom of the stack or if void the first parameter which
	//returns. Top of stack is furtherest right hand side parameter which returns a value.
	void inOutTrait_twoRefsToInt_firstReturnIsCorrectValue()
	{
		int value1(OutParamsTest::Dummy);
		int value2(OutParamsTest::Param2);
		run_chunk_function_push_two_ints("two_int_refs",value1,value2,true);
		::testing::NiceMock<MockOutParamsTest> stub;
		m_lua->call("func",(OutParamsTest*)&stub);
		assert_top_of_stack_is_exspected_value(value2);
	}

	void inOutTrait_twoRefsToInt_secondReturnIsCorrectValue()
	{
		int value1(OutParamsTest::Param1);
		int value2(OutParamsTest::Dummy);
		run_chunk_function_push_two_ints("two_int_refs",value1,value2,true);
		::testing::NiceMock<MockOutParamsTest> stub;
		m_lua->call("func",(OutParamsTest*)&stub);
		int ignore_int(0);
		int second(0);
		OOLUA::pull2cpp(*m_lua,ignore_int);
		OOLUA::pull2cpp(*m_lua,second);
		CPPUNIT_ASSERT_EQUAL(value1,second);
	}


	void outTrait_luaPassesNoParamFunctionWantsIntPtr_calledOnce()
	{
		run_chunk_function_pass_nothing("int_ptr_out",true);
		MockOutParamsTest mock;
		EXPECT_CALL(mock,int_ptr(::testing::_ ))
			.Times(1);
		m_lua->call("func",(OutParamsTest*)&mock);
	}
	void outTrait_luaPassesNoParamFunctionWantsRefToInt_valueAtTopOfStackIsExspectedValue()
	{
		int exspected(OutParamsTest::Param1);
		run_chunk_function_pass_nothing("int_ref_change",true);
		::testing::NiceMock<MockOutParamsTest> stub;
		m_lua->call("func",(OutParamsTest*)&stub);
		assert_top_of_stack_is_exspected_value(exspected);
	}

	void outTrait_luaPassesNoParamFunctionWantsIntPtr_returnTypeAtTopOfStackIsInt()
	{
		run_chunk_function_pass_nothing("int_ptr_out",true);
		::testing::NiceMock<MockOutParamsTest> stub;
		m_lua->call("func",(OutParamsTest*)&stub);
		CPPUNIT_ASSERT_EQUAL(true, lua_type(*m_lua,-1) == LUA_TNUMBER);
	}

	void outTrait_luaPassesNoParamFunctionWantsIntPtr_valueAtTopOfStackIsExspectedValue()
	{
		run_chunk_function_pass_nothing("int_ptr_change_pointee",true);
		::testing::NiceMock<MockOutParamsTest> stub;
		m_lua->call("func",(OutParamsTest*)&stub);
		int exspected(OutParamsTest::Param1);
		assert_top_of_stack_is_exspected_value(exspected);
	}

	void noTraits_luaPassesIntFunctionWantsIntPtr_callsFunctionWithCorrectPointeeValue()
	{
		int input_param(OutParamsTest::Param1);
		run_chunk_function_push_int("int_ptr",input_param,false);
		MockOutParamsTest mock;
		EXPECT_CALL(mock,int_ptr(::testing::Pointee( input_param ) ) )
			.Times(1);
		m_lua->call("func",(OutParamsTest*)&mock);
	}

	void noTraits_luaPassesIntFunctionWantsIntPtr_afterCallTheStackIsTheSameAsBeforeCall()
	{
		int input_param(OutParamsTest::Dummy);
		run_chunk_function_push_int("int_ptr",input_param,true/*false*/);
		int stackSizeBeforeCall = m_lua->stack_count();
		::testing::NiceMock<MockOutParamsTest> stub;
		m_lua->call("func",(OutParamsTest*)&stub);
		int stackSizeAfterCall = m_lua->stack_count();
		CPPUNIT_ASSERT_EQUAL(stackSizeBeforeCall,stackSizeAfterCall);
	}

	void luaReturnOrder_luaFunctionWhichReturnsMultipleValues_orderIsAsExspectedElseError()
	{
		//NOTE: With exceptions enabled this could throw, yet in reality it will never cause
		//an error. This test is for demostration purposes to show the return order in Lua.
		m_lua->run_chunk("bar = function(i1,i2,i3) return i1,i2,i3 end "
							"func = function() "
							" i1, i2 , i3 = bar(1,2,3) "
							" assert(i1 == 1) "
							" assert(i2 == 2) "
							" assert(i3 == 3) "
							"end ");
		CPPUNIT_ASSERT_EQUAL(true,m_lua->call("func"));
	}

	void luaReturnOrder_luaFunctionWhichReturnsMultipleValuesToCpp_orderFromTopOfStackIsParam3Param2Param1()
	{
		m_lua->run_chunk("func = function(i1,i2,i3) return i1,i2,i3 end ");
		int i1(OutParamsTest::Param1);
		int i2(OutParamsTest::Param2);
		int i3(OutParamsTest::Param3);
		int r1,r2,r3;
		m_lua->call("func",i1,i2,i3);

		OOLUA::pull2cpp(*m_lua,r1);//top of stack
		OOLUA::pull2cpp(*m_lua,r2);
		OOLUA::pull2cpp(*m_lua,r3);//bottom of stack

		CPPUNIT_ASSERT_EQUAL(i3,r1);
		CPPUNIT_ASSERT_EQUAL(i2,r2);
		CPPUNIT_ASSERT_EQUAL(i1,r3);
	}

	void ordering_functionWhichReturnsValueAndTwoInOutParams_orderFromTopOfStackIsParam2Param1Return()
	{
		int input1(OutParamsTest::Dummy);
		int input2(OutParamsTest::Dummy);
		run_chunk_function_push_two_ints("return_int_and_2_int_refs",input1,input2,true);
		::testing::NiceMock<MockOutParamsTest> stub;
		m_lua->call("func",(OutParamsTest*)&stub);

		int r1,r2,r3;
		OOLUA::pull2cpp(*m_lua,r1);//top of stack
		OOLUA::pull2cpp(*m_lua,r2);
		OOLUA::pull2cpp(*m_lua,r3);
		CPPUNIT_ASSERT_EQUAL((int)OutParamsTest::Param2,r1);
		CPPUNIT_ASSERT_EQUAL((int)OutParamsTest::Param1,r2);
		CPPUNIT_ASSERT_EQUAL((int)OutParamsTest::Return,r3);
	}
	
	void OutTrait_luaPassesNoParamFunctionWantsRefToUserData_topOfStackIsOwnedByLua()
	{
		m_lua->register_class<OutParamsUserData>();
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("foo = function(obj) return obj:ref() end");
		::testing::NiceMock<MockOutParamsUserData> stub;
		m_lua->call("foo",(OutParamsUserData*)&stub);
		OOLUA::INTERNAL::Lua_ud * ud = static_cast<OOLUA::INTERNAL::Lua_ud *>(lua_touserdata(*m_lua,-1) );
		CPPUNIT_ASSERT_EQUAL(true,OOLUA::INTERNAL::userdata_is_to_be_gced(ud));
	}

	void OutTrait_luaPassesNoParamFunctionWantsPtrToUserData_topOfStackIsOwnedByLua()
	{
		m_lua->register_class<OutParamsUserData>();
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("foo = function(obj) return obj:ptr() end");
		::testing::NiceMock<MockOutParamsUserData> stub;
		m_lua->call("foo",(OutParamsUserData*)&stub);
		OOLUA::INTERNAL::Lua_ud * ud = static_cast<OOLUA::INTERNAL::Lua_ud *>(lua_touserdata(*m_lua,-1) );
		CPPUNIT_ASSERT_EQUAL(true,OOLUA::INTERNAL::userdata_is_to_be_gced(ud));
	}

	
	void OutTrait_luaPassesNoParamFunctionWantsRefToUserData_stringMemberIsSetToHelloWorld()
	{
		m_lua->register_class<OutParamsUserData>();
		m_lua->register_class<MockParamWithStringMember>();
		m_lua->run_chunk("foo = function(obj) return obj:ref_param() end");
		MockOutParamsUserData stub;
		EXPECT_CALL(stub,ref_param(::testing::_))
					 .Times(1)
						.WillOnce(::testing::Invoke(&set_string_in_MockParamWithStringMember_ref));
					 
		m_lua->call("foo",(OutParamsUserData*)&stub);
		MockParamWithStringMember* ptr;
		OOLUA::pull2cpp(*m_lua,ptr);
		CPPUNIT_ASSERT_EQUAL(hello_world_str,ptr->str);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( OutParams );

