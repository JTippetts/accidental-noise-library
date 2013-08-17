#include "rgbablend.h"

namespace anl
{
    CRGBABlend::CRGBABlend() : m_low(), m_high(), m_control(0.0){}

    CRGBABlend::CRGBABlend(ANLFloatType control, SRGBA low, SRGBA high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(ANLFloatType control, SRGBA low, CRGBAModuleBase * high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(ANLFloatType control, CRGBAModuleBase * low, SRGBA high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(ANLFloatType control, CRGBAModuleBase * low, CRGBAModuleBase * high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(CImplicitModuleBase * control, SRGBA low, SRGBA high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(CImplicitModuleBase * control, SRGBA low, CRGBAModuleBase * high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(CImplicitModuleBase * control, CRGBAModuleBase * low, SRGBA high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(CImplicitModuleBase * control, CRGBAModuleBase * low, CRGBAModuleBase * high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}

    CRGBABlend::~CRGBABlend(){}

    void CRGBABlend::setLowSource(CRGBAModuleBase * m)
    {
        m_low.set(m);
    }

    void CRGBABlend::setHighSource(CRGBAModuleBase * m)
    {
        m_high.set(m);
    }

    void CRGBABlend::setLowSource(SRGBA c)
    {
        m_low.set(c);
    }

    void CRGBABlend::setHighSource(SRGBA c)
    {
        m_high.set(c);
    }

    void CRGBABlend::setControlSource(CImplicitModuleBase * m)
    {
        m_control.set(m);
    }

    void CRGBABlend::setControlSource(ANLFloatType v)
    {
        m_control.set(v);
    }

    SRGBA CRGBABlend::get(ANLFloatType x, ANLFloatType y)
    {
        SRGBA low=m_low.get(x,y);
        SRGBA high=m_high.get(x,y);
        ANLFloatType control=m_control.get(x,y);

        return SRGBA(
            (float)(low[0]+control*(high[0]-low[0])),
            (float)(low[1]+control*(high[1]-low[1])),
            (float)(low[2]+control*(high[2]-low[2])),
            (float)(low[3]+control*(high[3]-low[3])));
    }

    SRGBA CRGBABlend::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        SRGBA low=m_low.get(x,y,z);
        SRGBA high=m_high.get(x,y,z);
        ANLFloatType control=m_control.get(x,y,z);

        return SRGBA(
            (float)(low[0]+control*(high[0]-low[0])),
            (float)(low[1]+control*(high[1]-low[1])),
            (float)(low[2]+control*(high[2]-low[2])),
            (float)(low[3]+control*(high[3]-low[3])));
    }

    SRGBA CRGBABlend::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        SRGBA low=m_low.get(x,y,z,w);
        SRGBA high=m_high.get(x,y,z,w);
        ANLFloatType control=m_control.get(x,y,z,w);

        return SRGBA(
            (float)(low[0]+control*(high[0]-low[0])),
            (float)(low[1]+control*(high[1]-low[1])),
            (float)(low[2]+control*(high[2]-low[2])),
            (float)(low[3]+control*(high[3]-low[3])));
    }
    SRGBA CRGBABlend::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        SRGBA low=m_low.get(x,y,z,w,u,v);
        SRGBA high=m_high.get(x,y,z,w,u,v);
        ANLFloatType control=m_control.get(x,y,z,w,u,v);

        return SRGBA(
            (float)(low[0]+control*(high[0]-low[0])),
            (float)(low[1]+control*(high[1]-low[1])),
            (float)(low[2]+control*(high[2]-low[2])),
            (float)(low[3]+control*(high[3]-low[3])));
    }
};
