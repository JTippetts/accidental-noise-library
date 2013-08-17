#include "rgbabufferselect.h"
#include "../Noise/utility.h"

namespace anl
{
	CRGBABufferSelect::CRGBABufferSelect() : CRGBABufferBase(), control_(0), low_(0), high_(0), threshold_(0), falloff_(0){}

	CRGBABufferSelect::CRGBABufferSelect(CRGBABufferBase *low, CRGBABufferBase *high, CImplicitBufferBase *ctrl, ANLFloatType thresh, ANLFloatType fall)
		: CRGBABufferBase(), control_(ctrl), low_(low), high_(high), threshold_(thresh), falloff_(fall)
	{
	}

	CRGBABufferSelect::~CRGBABufferSelect()
	{
	}

	void CRGBABufferSelect::get(CArray2Drgba &out)
	{
		if(!control_ || !low_ || !high_) return;

		int w=out.width(), h=out.height();
		CArray2Drgba l,ha;
		CArray2Dd c;
		l.resize(w,h);
		ha.resize(w,h);
		c.resize(w,h);
		control_->get(c);
		low_->get(l);
		high_->get(ha);

		for(int x=0; x<w; ++x)
		{
			for(int y=0; y<h; ++y)
			{
				ANLFloatType ctrl=c.get(x,y);
				SRGBA low=l.get(x,y);
				SRGBA high=ha.get(x,y);

				if(falloff_>0.0)
				{
					if(ctrl < (threshold_-falloff_))
					{
						out.set(x,y,low);
					}
					else if(ctrl > (threshold_+falloff_))
					{
						out.set(x,y,high);
					}
					else
					{
						ANLFloatType lower=threshold_-falloff_;
						ANLFloatType upper=threshold_+falloff_;
						ANLFloatType blend=quintic_blend((ctrl-lower)/(upper-lower));
						//ANLFloatType val=lerp(blend,low,high);
						out.set(x,y,low+(high-low)*blend);
					}
				}
				else
				{
					if(ctrl<threshold_) out.set(x,y,low);
					else out.set(x,y,high);
				}
			}
		}
	}
};
