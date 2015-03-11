#ifndef CPP_HEIRARCHY_H_
#	define CPP_HEIRARCHY_H_

#	include "oolua_tests_pch.h"
#	include "gmock/gmock.h"
#	include "oolua.h"
/*
NOTE: A change to this file which is to be propagated to Lua requires a change to the binder classes.
Also a change in the class hierarchy of DerivedFromTwoAbstractBasesAndAbstract3 requires a change
to the following functions 
BASE_HELPERS::allBasesOfDerivedFromTwoAbstractBasesAndAbstract3
and
BASE_HELPERS::rootBasesOfDerivedFromTwoAbstractBasesAndAbstract3
Both of which can be found in the file: expose_hierarhcy.h
*/


class Abstract1
{
public:
	virtual ~Abstract1(){}
	virtual void func1()=0;
	virtual void virtualVoidParam3Int(int,int,int) = 0;
};

class Abstract2
{
public:
	virtual ~Abstract2(){}
	virtual void func2_1()=0;
	virtual void constVirtualFunction() const = 0;
};
class Abstract3
{
public:
	virtual ~Abstract3(){}
	virtual void func3_1()=0;
};

class Derived1Abstract1 : public Abstract1
{
public:
	virtual ~Derived1Abstract1(){}
	MOCK_METHOD0(func1,void ());
	MOCK_METHOD3(virtualVoidParam3Int,void (int,int,int));
};
class TwoAbstractBases : public Abstract1, public Abstract2
{
public:
	virtual ~TwoAbstractBases(){}
	MOCK_METHOD0(func1,void ());
	MOCK_METHOD3(virtualVoidParam3Int,void (int,int,int));
	MOCK_METHOD0(func2_1,void ());
	MOCK_CONST_METHOD0(constVirtualFunction,void());
};

class DerivedFromTwoAbstractBasesAndAbstract3 : public TwoAbstractBases, public Abstract3
{
public:
	virtual ~DerivedFromTwoAbstractBasesAndAbstract3(){}
	MOCK_METHOD0(func3_1,void ());
};


#endif

