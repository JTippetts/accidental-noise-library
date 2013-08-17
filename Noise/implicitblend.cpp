#include "implicitblend.h"
#include "utility.h"

namespace anl
{

    CImplicitBlend::CImplicitBlend(): CImplicitModuleBase(), m_low(0.0), m_high(0.0), m_control(0.0){}
    CImplicitBlend::CImplicitBlend(ANLFloatType low, ANLFloatType high, ANLFloatType control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(ANLFloatType low, ANLFloatType high, CImplicitModuleBase * control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(ANLFloatType low, CImplicitModuleBase * high, ANLFloatType control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(CImplicitModuleBase * low, ANLFloatType high, ANLFloatType control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(ANLFloatType low, CImplicitModuleBase * high, CImplicitModuleBase * control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(CImplicitModuleBase * low, ANLFloatType high, CImplicitModuleBase * control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
    CImplicitBlend::CImplicitBlend(CImplicitModuleBase * low, CImplicitModuleBase * high, ANLFloatType control) : CImplicitModuleBase(), m_low(low), m_high(high), m_control(control){}
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

	void CImplicitBlend::setLowSource(ANLFloatType v)
	{
		m_low.set(v);
	}

	void CImplicitBlend::setHighSource(ANLFloatType v)
	{
	    m_high.set(v);
	}

	void CImplicitBlend::setControlSource(ANLFloatType v)
	{
	    m_control.set(v);
	}

	ANLFloatType CImplicitBlend::get(ANLFloatType x, ANLFloatType y)
	{
        ANLFloatType v1=m_low.get(x,y);
        ANLFloatType v2=m_high.get(x,y);
        ANLFloatType blend=m_control.get(x,y);
        blend=(blend+1.0) * 0.5;

        return lerp(blend,v1,v2);
	}

	ANLFloatType CImplicitBlend::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
	{
        ANLFloatType v1=m_low.get(x,y,z);
        ANLFloatType v2=m_high.get(x,y,z);
        ANLFloatType blend=m_control.get(x,y,z);
        return lerp(blend,v1,v2);
	}

	ANLFloatType CImplicitBlend::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
	{
        ANLFloatType v1=m_low.get(x,y,z,w);
        ANLFloatType v2=m_high.get(x,y,z,w);
        ANLFloatType blend=m_control.get(x,y,z,w);
        return lerp(blend,v1,v2);
	}

	ANLFloatType CImplicitBlend::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        ANLFloatType v1=m_low.get(x,y,z,w,u,v);
        ANLFloatType v2=m_high.get(x,y,z,w,u,v);
        ANLFloatType blend=m_control.get(x,y,z,w,u,v);
        return lerp(blend,v1,v2);
	}
};
