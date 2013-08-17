#include "rgbahsvtorgba.h"
#include "hsv.h"

namespace anl
{
    CRGBAHSVToRGBA::CRGBAHSVToRGBA() : CRGBAModuleBase(), m_source(){}

    CRGBAHSVToRGBA::CRGBAHSVToRGBA(SRGBA s) : CRGBAModuleBase(), m_source(s){}
    CRGBAHSVToRGBA::CRGBAHSVToRGBA(CRGBAModuleBase * s) : CRGBAModuleBase(), m_source(s){}

    void CRGBAHSVToRGBA::setSource(CRGBAModuleBase * m)
    {
        m_source.set(m);
    }
    void CRGBAHSVToRGBA::setSource(SRGBA c)
    {
        m_source.set(c);
    }

    SRGBA CRGBAHSVToRGBA::get(ANLFloatType x, ANLFloatType y)
    {
        SRGBA s=m_source.get(x,y);
        SRGBA d;
        HSVtoRGBA(s,d);
        return d;
    }
    SRGBA CRGBAHSVToRGBA::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        SRGBA s=m_source.get(x,y,z);
        SRGBA d;
        HSVtoRGBA(s,d);
        return d;
    }
    SRGBA CRGBAHSVToRGBA::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        SRGBA s=m_source.get(x,y,z,w);
        SRGBA d;
        HSVtoRGBA(s,d);
        return d;
    }
    SRGBA CRGBAHSVToRGBA::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        SRGBA s=m_source.get(x,y,z,w,u,v);
        SRGBA d;
        HSVtoRGBA(s,d);
        return d;
    }
};

