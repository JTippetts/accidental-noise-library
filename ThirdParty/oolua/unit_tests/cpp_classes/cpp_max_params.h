#ifndef CPP_MAX_PARAMS_H_
#	define CPP_MAX_PARAMS_H_

#	include "oolua_tests_pch.h"
#	include "gmock/gmock.h"

template<typename Return,typename Param>
class Max_params
{
public:
	virtual ~Max_params(){}
	virtual Return one(Param a) = 0;
	virtual Return two(Param a, Param b) = 0;
	virtual Return three(Param a, Param b,Param c) = 0;
	virtual Return four(Param a, Param b,Param c,Param d) = 0;
	virtual Return five(Param a, Param b,Param c,Param d,Param e) = 0;
	virtual Return six(Param a, Param b,Param c,Param d,Param e,Param f) = 0;
	virtual Return seven(Param a, Param b,Param c,Param d,Param e,Param f,Param g) = 0;
	virtual Return eight(Param a, Param b,Param c,Param d,Param e,Param f,Param g,Param h) = 0;
};

typedef Max_params<void,int> VoidReturnIntParam;

class MockVoidReturnIntParam : public VoidReturnIntParam 
{
public:
	MOCK_METHOD1(one,void   (int) );
	MOCK_METHOD2(two,void   (int,int) );
	MOCK_METHOD3(three,void (int,int,int) );
	MOCK_METHOD4(four,void  (int,int,int,int) );
	MOCK_METHOD5(five,void  (int,int,int,int,int) );
	MOCK_METHOD6(six,void   (int,int,int,int,int,int) );
	MOCK_METHOD7(seven,void (int,int,int,int,int,int,int) );
	MOCK_METHOD8(eight,void (int,int,int,int,int,int,int,int) );
};

#endif
