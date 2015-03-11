#ifndef CPP_OUT_PARAMS_OOULA_H_
# define CPP_OUT_PARAMS_OOLUA_H_

#	include "oolua_tests_pch.h"
#	include "gmock/gmock.h"
#	include "cpp_stub_classes.h"

class OutParamsTest
{
public:
	enum PARAM_CONSTANTS{Return=-1,Param1=1,Param2=2,Param3=3,Dummy=6500};
    virtual ~OutParamsTest(){}
	virtual void int_ref(int& ) =0;
	virtual void two_int_refs(int& ,int&) =0;
	virtual void int_ref_change(int& i)
	{
		i =static_cast<int>(Param1);
	}
	virtual void int_ptr(int* i)=0;
	virtual void int_ptr_change_pointee(int* i)
	{
		*i =static_cast<int>(Param1);
	}
	virtual int return_int_and_2_int_refs(int& i1, int& i2)
	{
		i1 = static_cast<int>(Param1);
		i2 = static_cast<int>(Param2);
		return Return;
	}

};

class MockOutParamsTest : public OutParamsTest
{
public:
	MOCK_METHOD1(int_ref,void (int&));
	MOCK_METHOD2(two_int_refs,void(int& i,int&) );
	MOCK_METHOD1(int_ptr,void (int*));
};

struct MockParamWithStringMember 
{
	std::string str;
};

class OutParamsUserData
{
public:
	virtual ~OutParamsUserData(){}
	virtual void ref(Stub1 & stub)=0;
	virtual void ptr(Stub1* stub) = 0;
	virtual void by_value(Stub1 stub) = 0;
	virtual void ref_param(MockParamWithStringMember& mock) = 0;

};


class MockOutParamsUserData : public OutParamsUserData
{
public:
	MOCK_METHOD1(ref,void (Stub1&));
	MOCK_METHOD1(ptr,void (Stub1*));
	MOCK_METHOD1(by_value,void (Stub1));
	MOCK_METHOD1(ref_param,void (MockParamWithStringMember& ));
};

#endif

