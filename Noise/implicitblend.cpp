#include "implicitblend.h"
#include "utility.h"

namespace anl
{

    CImplicitBlend::CImplicitBlend(): CImplicitModuleBase(), m_low(0.0), m_high(0.0), m_control(0.0){}
    CImplicitBlend::CImplicitBlend(double low, double high, double control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(double low, double high, CImplicitModuleBase * control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(double low, CImplicitModuleBase * high, double control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(CImplicitModuleBase * low, double high, double control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(double low, CImplicitModuleBase * high, CImplicitModuleBase * control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(CImplicitModuleBase * low, double high, CImplicitModuleBase * control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(CImplicitModuleBase * low, CImplicitModuleBase * high, double control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}

	CImplicitBlend::~CImplicitBlend(){}

	void CImplicitBlend::setLowSource(CImplicitModuleBase * b)
	{
		m_low.set(b);
	}

	void CImplicitBlend::setHighSource(CImplicitModuleBase * b)
	{
	    m_high.set(b);
	}

	void CImplicitBlend::setControlSource(CImplicitModuleBase * b)
	{
	    m_control.set(b);
	}

	void CImplicitBlend::setLowSource(double v)
	{
		m_low.set(v);
	}

	void CImplicitBlend::setHighSource(double v)
	{
	    m_high.set(v);
	}

	void CImplicitBlend::setControlSource(double v)
	{
	    m_control.set(v);
	}

	double CImplicitBlend::get(double x, double y)
	{
        double v1=m_low.get(x,y);
        double v2=m_high.get(x,y);
        double blend=m_control.get(x,y);
        blend=(blend+1.0) * 0.5;

        return lerp(blend,v1,v2);
	}

	double CImplicitBlend::get(double x, double y, double z)
	{
        double v1=m_low.get(x,y,z);
        double v2=m_high.get(x,y,z);
        double blend=m_control.get(x,y,z);
        return lerp(blend,v1,v2);
	}

	double CImplicitBlend::get(double x, double y, double z, double w)
	{
        double v1=m_low.get(x,y,z,w);
        double v2=m_high.get(x,y,z,w);
        double blend=m_control.get(x,y,z,w);
        return lerp(blend,v1,v2);
	}

	double CImplicitBlend::get(double x, double y, double z, double w, double u, double v)
    {
        double v1=m_low.get(x,y,z,w,u,v);
        double v2=m_high.get(x,y,z,w,u,v);
        double blend=m_control.get(x,y,z,w,u,v);
        return lerp(blend,v1,v2);
	}
};
