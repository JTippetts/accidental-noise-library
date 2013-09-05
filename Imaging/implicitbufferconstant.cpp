#include "implicitbufferconstant.h"

namespace anl
{
	CImplicitBufferConstant::CImplicitBufferConstant() : constant_(0)
	{
	}
	
	CImplicitBufferConstant::CImplicitBufferConstant(ANLFloatType c) : constant_(c)
	{
	}
	
	CImplicitBufferConstant::~CImplicitBufferConstant()
	{
	}
		
	void CImplicitBufferConstant::setConstant(ANLFloatType t)
	{
		constant_=t;
	}
	
	void CImplicitBufferConstant::get(CArray2Dd &out)
	{
		out.fill(constant_);
	}
};