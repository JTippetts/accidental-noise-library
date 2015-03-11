#ifndef CPP_PULLS_STUB_PARAM_H_
#	define CPP_PULLS_STUB_PARAM_H_

#	include "oolua_tests_pch.h"
#	include "gmock/gmock.h"
#	include "cpp_stub_classes.h"


class Pulls_stub
{
public:
	virtual ~Pulls_stub(){}
	virtual void ref(Stub1& )=0;
	virtual void ref_const(Stub1 const &)=0;
	virtual void ptr(Stub1* )=0;
	virtual void ptr_const(Stub1 const * )=0;
	virtual void const_ptr_const(Stub1  const* const )=0;
	virtual void ref_ptr_const(Stub1 const *& )=0;
	virtual void ref_const_ptr_const(Stub1 const* const & )=0;
};

class Mock_pulls_stub : public Pulls_stub
{
public:
	MOCK_METHOD1(ref,void (Stub1&));
	MOCK_METHOD1(ref_const,void (Stub1 const &));
	MOCK_METHOD1(ptr,void (Stub1*));
	MOCK_METHOD1(ptr_const,void (Stub1 const * ));
	MOCK_METHOD1(const_ptr_const,void (Stub1  const* const ));
	MOCK_METHOD1(ref_ptr_const,void (Stub1 const *&  ));
	MOCK_METHOD1(ref_const_ptr_const,void (Stub1 const* const & ));
};

#endif