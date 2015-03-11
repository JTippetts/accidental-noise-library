#ifndef CPP_INTEGRAL_FUNCTION_PARAMS_H_
#	define CPP_INTEGRAL_FUNCTION_PARAMS_H_

#	include "oolua_tests_pch.h"
#	include "gmock/gmock.h"

class Int_params
{
public:
	virtual ~Int_params(){}
	virtual void int_(int i) = 0;
	virtual void int_ref(int &) = 0;
	virtual void int_ptr(int *) = 0;
	virtual void int_const(int const i) = 0;
	virtual void int_const_ref(int const&) = 0;
	virtual void int_const_ptr(int const* i) = 0;
	virtual void int_const_ptr_const(int const * const) = 0;
	virtual void bool_(bool b) = 0;
};

class MockInt : public Int_params 
{
public:
	MOCK_METHOD1(int_,void (int) );
	MOCK_METHOD1(int_ref,void (int&) );
	MOCK_METHOD1(int_ptr,void (int*) );
	MOCK_METHOD1(int_const,void (int const ) );
	MOCK_METHOD1(int_const_ref,void (int const&) );
	MOCK_METHOD1(int_const_ptr,void (int const*) );
	MOCK_METHOD1(int_const_ptr_const,void (int const * const) );
	MOCK_METHOD1(bool_,void (bool) );
};


#endif
