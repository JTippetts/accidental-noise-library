#ifndef CPP_METHOD_RETURNS_CLASS_H_
#	define CPP_METHOD_RETURNS_CLASS_H_

#include "cpp_stub_classes.h"

class Method_returns_class
{
public:
	Method_returns_class()
	:return_instance()
	,return_ptr(&return_instance)
	,return_ptr_const(return_ptr)
	,return_ref_const_ptr_const(return_ptr_const)
	{}
	Return_double& ref(){return return_instance;}
	Return_double const & ref_const(){return return_instance;}
	Return_double* ptr(){return return_ptr;}
	Return_double const* ptr_const(){return return_ptr_const;}
	Return_double const * & ref_ptr_const(){return return_ptr_const;}
	Return_double const*const& ref_const_ptr_const(){return return_ref_const_ptr_const;}
	Method_returns_class& operator = (Method_returns_class const&);
	Method_returns_class(Method_returns_class const&);
	Return_double return_stack_instance()
	{
		return  Return_double(); 
	}
	Return_double* returns_null()
	{
		return (Return_double*)0;
	}
private:
	Return_double return_instance;
public:
	Return_double* return_ptr;
private:
	Return_double const* return_ptr_const;
	Return_double const*const return_ref_const_ptr_const;
};

#endif
