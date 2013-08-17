#include "implicitselect.h"
#include "utility.h"
#include <iostream>

namespace anl
{
    CImplicitSelect::CImplicitSelect() : CImplicitModuleBase(), m_low(0.0), m_high(0.0), m_control(0.0),
        m_threshold(0.0), m_falloff(0.0)
	{
	}

	CImplicitSelect::CImplicitSelect(ANLFloatType low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, ANLFloatType high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, ANLFloatType high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, ANLFloatType high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, ANLFloatType high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, ANLFloatType high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, ANLFloatType high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

	CImplicitSelect::~CImplicitSelect(){}

	void CImplicitSelect::setLowSource(CImplicitModuleBase * b)
	{
		m_low.set(b);
	}
	void CImplicitSelect::setHighSource(CImplicitModuleBase * b)
	{
		m_high.set(b);
	}
	void CImplicitSelect::setControlSource(CImplicitModuleBase * b)
	{
		m_control.set(b);
	}

	void CImplicitSelect::setLowSource(ANLFloatType b)
	{
		m_low.set(b);
	}
	void CImplicitSelect::setHighSource(ANLFloatType b)
	{
		m_high.set(b);
	}
	void CImplicitSelect::setControlSource(ANLFloatType b)
	{
		m_control.set(b);
	}

	void CImplicitSelect::setThreshold(ANLFloatType t)
	{
		//m_threshold=t;
		m_threshold.set(t);
	}
	void CImplicitSelect::setFalloff(ANLFloatType f)
	{
		//m_falloff=f;
		m_falloff.set(f);
	}
	void CImplicitSelect::setThreshold(CImplicitModuleBase * m)
	{
	    m_threshold.set(m);
	}
	void CImplicitSelect::setFalloff(CImplicitModuleBase * m)
	{
	    m_falloff.set(m);
	}

	ANLFloatType CImplicitSelect::get(ANLFloatType x, ANLFloatType y)
	{
		ANLFloatType control=m_control.get(x,y);
		ANLFloatType falloff=m_falloff.get(x,y);
		ANLFloatType threshold=m_threshold.get(x,y);

        if(falloff>0.0)
        {
            if(control < (threshold-falloff))
            {
                // Lies outside of falloff area below threshold, return first source
                return m_low.get(x,y);
            }
            else if(control > (threshold+falloff))
            {
                // Lise outside of falloff area above threshold, return second source
                return m_high.get(x,y);
            }
            else
            {
                // Lies within falloff area.
                ANLFloatType lower=threshold-falloff;
                ANLFloatType upper=threshold+falloff;
                ANLFloatType blend=quintic_blend((control-lower)/(upper-lower));
                return lerp(blend,m_low.get(x,y),m_high.get(x,y));
            }
        }
        else
        {
            if(control<threshold) return m_low.get(x,y);
            else return m_high.get(x,y);
        }
    }

    ANLFloatType CImplicitSelect::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
		ANLFloatType control=m_control.get(x,y,z);
		ANLFloatType falloff=m_falloff.get(x,y,z);
		ANLFloatType threshold=m_threshold.get(x,y,z);

        if(falloff>0.0)
        {
            if(control < (threshold-falloff))
            {
                // Lies outside of falloff area below threshold, return first source
                return m_low.get(x,y,z);
            }
            else if(control > (threshold+falloff))
            {
                // Lise outside of falloff area above threshold, return second source
                return m_high.get(x,y,z);
            }
            else
            {
                // Lies within falloff area.
                ANLFloatType lower=threshold-falloff;
                ANLFloatType upper=threshold+falloff;
                ANLFloatType blend=quintic_blend((control-lower)/(upper-lower));
                return lerp(blend,m_low.get(x,y,z),m_high.get(x,y,z));
            }
        }
        else
        {
			//std::cout << "Control: " << control << " Threshold: " << threshold << " Low: " << m_low.get(x,y,z) << " High: " << m_high.get(x,y,z) << std::endl;
            if(control<threshold) return m_low.get(x,y,z);
            else return m_high.get(x,y,z);
        }
    }

	ANLFloatType CImplicitSelect::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
	{
		ANLFloatType control=m_control.get(x,y,z,w);
		ANLFloatType falloff=m_falloff.get(x,y,z,w);
		ANLFloatType threshold=m_threshold.get(x,y,z,w);

        if(falloff>0.0)
        {
            if(control < (threshold-falloff))
            {
                // Lies outside of falloff area below threshold, return first source
                return m_low.get(x,y,z,w);
            }
            else if(control > (threshold+falloff))
            {
                // Lise outside of falloff area above threshold, return second source
                return m_high.get(x,y,z,w);
            }
            else
            {
                // Lies within falloff area.
                ANLFloatType lower=threshold-falloff;
                ANLFloatType upper=threshold+falloff;
                ANLFloatType blend=quintic_blend((control-lower)/(upper-lower));
                return lerp(blend,m_low.get(x,y,z,w),m_high.get(x,y,z,w));
            }
        }
        else
        {
            if(control<threshold) return m_low.get(x,y,z,w);
            else return m_high.get(x,y,z,w);
        }
    }

	ANLFloatType CImplicitSelect::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
	{
		ANLFloatType control=m_control.get(x,y,z,w,u,v);
		ANLFloatType falloff=m_falloff.get(x,y,z,w,u,v);
		ANLFloatType threshold=m_threshold.get(x,y,z,w,u,v);

        if(falloff>0.0)
        {
            if(control < (threshold-falloff))
            {
                // Lies outside of falloff area below threshold, return first source
                return m_low.get(x,y,z,w,u,v);
            }
            else if(control > (threshold+falloff))
            {
                // Lise outside of falloff area above threshold, return second source
                return m_high.get(x,y,z,w,u,v);
            }
            else
            {
                // Lies within falloff area.
                ANLFloatType lower=threshold-falloff;
                ANLFloatType upper=threshold+falloff;
                ANLFloatType blend=quintic_blend((control-lower)/(upper-lower));
                return lerp(blend,m_low.get(x,y,z,w,u,v),m_high.get(x,y,z,w,u,v));
            }
        }
        else
        {
            if(control<threshold) return m_low.get(x,y,z,w,u,v);
            else return m_high.get(x,y,z,w,u,v);
        }
    }
};
