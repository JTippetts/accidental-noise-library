#include "implicitselect.h"
#include "utility.h"
#include <iostream>

namespace anl
{
    CImplicitSelect::CImplicitSelect() : CImplicitModuleBase(), m_low(0.0), m_high(0.0), m_control(0.0),
        m_threshold(0.0), m_falloff(0.0)
	{
	}

	CImplicitSelect::CImplicitSelect(double low, double high, double control, double threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, double high, double control, double threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, double high, double control, CImplicitModuleBase * threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, double high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, double high, CImplicitModuleBase * control, double threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, double high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, double high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, double high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, CImplicitModuleBase * high, double control, double threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, CImplicitModuleBase * high, double control, double threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, CImplicitModuleBase * high, double control, CImplicitModuleBase * threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, CImplicitModuleBase * high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, CImplicitModuleBase * high, CImplicitModuleBase * control, double threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, CImplicitModuleBase * high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(double low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, double high, double control, double threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, double high, double control, double threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, double high, double control, CImplicitModuleBase * threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, double high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, double high, CImplicitModuleBase * control, double threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, double high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, double high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, double high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, double control, double threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, double control, double threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, double control, CImplicitModuleBase * threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, double threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
	CImplicitSelect::CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}
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

	void CImplicitSelect::setLowSource(double b)
	{
		m_low.set(b);
	}
	void CImplicitSelect::setHighSource(double b)
	{
		m_high.set(b);
	}
	void CImplicitSelect::setControlSource(double b)
	{
		m_control.set(b);
	}

	void CImplicitSelect::setThreshold(double t)
	{
		//m_threshold=t;
		m_threshold.set(t);
	}
	void CImplicitSelect::setFalloff(double f)
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

	double CImplicitSelect::get(double x, double y)
	{
		double control=m_control.get(x,y);
		double falloff=m_falloff.get(x,y);
		double threshold=m_threshold.get(x,y);

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
                double lower=threshold-falloff;
                double upper=threshold+falloff;
                double blend=quintic_blend((control-lower)/(upper-lower));
                return lerp(blend,m_low.get(x,y),m_high.get(x,y));
            }
        }
        else
        {
            if(control<threshold) return m_low.get(x,y);
            else return m_high.get(x,y);
        }
    }

    double CImplicitSelect::get(double x, double y, double z)
    {
		double control=m_control.get(x,y,z);
		double falloff=m_falloff.get(x,y,z);
		double threshold=m_threshold.get(x,y,z);

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
                double lower=threshold-falloff;
                double upper=threshold+falloff;
                double blend=quintic_blend((control-lower)/(upper-lower));
                return lerp(blend,m_low.get(x,y,z),m_high.get(x,y,z));
            }
        }
        else
        {
			std::cout << "Control: " << control << " Threshold: " << threshold << " Low: " << m_low.get(x,y,z) << " High: " << m_high.get(x,y,z) << std::endl;
            if(control<threshold) return m_low.get(x,y,z);
            else return m_high.get(x,y,z);
        }
    }

	double CImplicitSelect::get(double x, double y, double z, double w)
	{
		double control=m_control.get(x,y,z,w);
		double falloff=m_falloff.get(x,y,z,w);
		double threshold=m_threshold.get(x,y,z,w);

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
                double lower=threshold-falloff;
                double upper=threshold+falloff;
                double blend=quintic_blend((control-lower)/(upper-lower));
                return lerp(blend,m_low.get(x,y,z,w),m_high.get(x,y,z,w));
            }
        }
        else
        {
            if(control<threshold) return m_low.get(x,y,z,w);
            else return m_high.get(x,y,z,w);
        }
    }

	double CImplicitSelect::get(double x, double y, double z, double w, double u, double v)
	{
		double control=m_control.get(x,y,z,w,u,v);
		double falloff=m_falloff.get(x,y,z,w,u,v);
		double threshold=m_threshold.get(x,y,z,w,u,v);

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
                double lower=threshold-falloff;
                double upper=threshold+falloff;
                double blend=quintic_blend((control-lower)/(upper-lower));
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
