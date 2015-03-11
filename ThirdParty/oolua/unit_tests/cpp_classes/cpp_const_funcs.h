#ifndef CPP_CONST_FUNCS_H
#	define CPP_CONST_FUNCS_H_

#	include "oolua_tests_pch.h"
#	include "gmock/gmock.h"

class Constant
{
public:
	Constant():i(0){}
	virtual ~Constant(){}
	virtual int cpp_func_const() const = 0;
	virtual void cpp_func() = 0;
	int function_to_test_rename_using_varags(int dont_care)const
	{
		return dont_care;
	}
private:
	int i;//stop functions being compiled away
};

class ConstantMock : public Constant
{
public:
	MOCK_CONST_METHOD0(cpp_func_const,int ());
	MOCK_METHOD0(cpp_func,void ());
};

#endif
