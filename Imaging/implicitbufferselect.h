#ifndef IMPLICITBUFFERSELECT_H
#define IMPLICITBUFFERSELECT_H
#include "implicitbufferbase.h"

namespace anl
{
	class CImplicitBufferSelect : public CImplicitBufferBase
	{
		public:
		CImplicitBufferSelect();
		CImplicitBufferSelect(CImplicitBufferBase *low, CImplicitBufferBase *high, CImplicitBufferBase *ctrl, double thresh, double fall);
		~CImplicitBufferSelect();
		
		void get(CArray2Dd &out);
		void setControl(CImplicitBufferBase *c){control_=c;}
		void setLow(CImplicitBufferBase *l){low_=l;}
		void setHigh(CImplicitBufferBase *h){high_=h;}
		void setThreshold(double t){threshold_=t;}
		void setFalloff(double f){falloff_=f;}
		
		private:
		CImplicitBufferBase *control_, *low_, *high_;
		double threshold_, falloff_;
	};
};

#endif