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
		CRGBABufferSelect(CRGBABufferBase *low, CRGBABufferBase *high, CImplicitBufferBase *ctrl, ANLFloatType thresh, ANLFloatType fall);
		~CRGBABufferSelect();

		void setControl(CImplicitBufferBase *c){control_=c;}
		void setLow(CRGBABufferBase *l){low_=l;}
		void setHigh(CRGBABufferBase *h){high_=h;}
		void setThreshold(ANLFloatType t){threshold_=t;}
		void setFalloff(ANLFloatType f){falloff_=f;}

		void get(CArray2Drgba &out);

		private:
		CImplicitBufferBase *control_;
		CRGBABufferBase *low_, *high_;
		ANLFloatType threshold_, falloff_;
	};
};

#endif
