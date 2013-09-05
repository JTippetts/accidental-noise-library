#ifndef IMPLICITBUFFERCONSTANT_H
#define IMPLICITBUFFERCONSTANT_H

#include "implicitbufferbase.h"

namespace anl
{
	class CImplicitBufferConstant : public CImplicitBufferBase
	{
		public:
		CImplicitBufferConstant();
		CImplicitBufferConstant(ANLFloatType c);
		~CImplicitBufferConstant();
		
		void setConstant(ANLFloatType t);
		void get(CArray2Dd &out);
		
		private:
		ANLFloatType constant_;
	};
};

#endif