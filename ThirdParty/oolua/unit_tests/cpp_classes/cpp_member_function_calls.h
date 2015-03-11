#ifndef CPP_MEMEBER_FUNCTION_CALLS_H_
#	define CPP_MEMEBER_FUNCTION_CALLS_H_

#	include "oolua_tests_pch.h"
#	include "gmock/gmock.h"


namespace OOLUA_UT
{
	static char const* hello_world_cstring = "hello world";
}

class Function_calls
{	
public:
	virtual ~Function_calls(){}
	virtual void func(){}
	virtual void abstract_func_0() = 0;
	virtual void abstract_func_1(int ) = 0;
	virtual int abstract_func_3(int  const& , int & ,int ) = 0;
	virtual void ptr_to_char(char * ) = 0;
	virtual void ptr_to_const_char(char const * ) = 0;
	virtual char* returns_char_ptr() = 0;
	virtual char const* returns_const_char_ptr() = 0;
	char const* returns(){return OOLUA_UT::hello_world_cstring;}
	virtual void lua_state(lua_State* ) const=0;
};

	
class FunctionCallsMock : public Function_calls
{
public:
	MOCK_METHOD0(func,void ());
	MOCK_METHOD0(abstract_func_0,void ());
	MOCK_METHOD1(abstract_func_1,void (int));
	MOCK_METHOD3(abstract_func_3,int (int  const&,int & ,int  ));
	MOCK_METHOD1(ptr_to_char,void (char *) );
	MOCK_METHOD1(ptr_to_const_char,void (char const*) );
	MOCK_METHOD0(returns_char_ptr,char* ());
	MOCK_METHOD0(returns_const_char_ptr,char const* ());
	MOCK_CONST_METHOD1(lua_state,void (lua_State*));
};

#endif

