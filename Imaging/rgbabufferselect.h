#ifndef RGBABUFFERSELECT_H
#define RGBABUFFERSELECT_H
#include "rgbabufferbase.h"
#include "implicitbufferbase.h"

namespace anl
{
	class CRGBABufferSelect : public CRGBABufferBase
	{
		public:
		CRGBABufferSelect();
		CRGBABufferSelect(CRGBABufferBase *low, CRGBABufferBase *high, CImplicitBufferBase *ctrl, double thresh, double fall);
		~CRGBABufferSelect();
		
		void setControl(CImplicitBufferBase *c){control_=c;}
		void setLow(CRGBABufferBase *l){low_=l;}
		void setHigh(CRGBABufferBase *h){high_=h;}
		void setThreshold(double t){threshold_=t;}
		void setFalloff(double f){falloff_=f;}
		
		void get(CArray2Drgba &out);
		
		private:
		CImplicitBufferBase *control_;
		CRGBABufferBase *low_, *high_;
		double threshold_, falloff_;
	};
};

#endif