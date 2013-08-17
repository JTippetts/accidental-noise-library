#include "implicitbufferselect.h"
#include "../Noise/utility.h"

namespace anl
{
	CImplicitBufferSelect::CImplicitBufferSelect() : CImplicitBufferBase(), low_(0), high_(0), control_(0), threshold_(0), falloff_(0)
	{
	}

	CImplicitBufferSelect::CImplicitBufferSelect(CImplicitBufferBase *low, CImplicitBufferBase *high, CImplicitBufferBase *ctrl, ANLFloatType thresh, ANLFloatType fall) :
		CImplicitBufferBase(), low_(low), high_(high), control_(ctrl), threshold_(thresh), falloff_(fall)
	{
	}

	CImplicitBufferSelect::~CImplicitBufferSelect()
	{
	}

	void CImplicitBufferSelect::get(CArray2Dd &out)
	{
		if(!control_ || !low_ || !high_) return;

		int w=out.width(), h=out.height();
		CArray2Dd l,ha,c;
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
				ANLFloatType low=l.get(x,y);
				ANLFloatType high=ha.get(x,y);

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
						ANLFloatType val=lerp(blend,low,high);
						out.set(x,y,val);
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
