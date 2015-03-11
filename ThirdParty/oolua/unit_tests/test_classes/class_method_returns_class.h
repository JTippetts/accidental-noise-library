#ifndef CLASS_METHOD_RETURNS_METHOD_H_
#	define CLASS_METHOD_RETURNS_METHOD_H_

#	include "oolua_tests_pch.h"
#	include "common_cppunit_headers.h"
#	include "oolua.h"

//bad includes we just net oolua_pushull_fwd
//and the include for CPPUNIT macro

template<typename Return_type,typename Input_type>
void assert_return_equals_input(lua_State* l, Input_type input)
{
	Return_type result;
	OOLUA::pull2cpp(l,result);
	CPPUNIT_ASSERT_EQUAL((Return_type)input,result);
}

#endif//TEST_PUSH_H_
