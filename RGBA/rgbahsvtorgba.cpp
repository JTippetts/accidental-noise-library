#include "rgbahsvtorgba.h"
#include "hsv.h"

namespace anl
{
    CRGBAHSVToRGBA::CRGBAHSVToRGBA() : CRGBAModuleBase(), m_source(){}

    CRGBAHSVToRGBA::CRGBAHSVToRGBA(SRGBA s) : CRGBAModuleBase(), m_source(s){}
    CRGBAHSVToRGBA::CRGBAHSVToRGBA(std::shared_ptr<CRGBAModuleBase> s) : CRGBAModuleBase(), m_source(s){}

    void CRGBAHSVToRGBA::setSource(std::shared_ptr<CRGBAModuleBase> m)
    {
        m_source.set(m);
    }
    void CRGBAHSVToRGBA::setSource(SRGBA c)
    {
        m_source.set(c);
    }

    SRGBA CRGBAHSVToRGBA::get(double x, double y)
    {
        SRGBA s=m_source.get(x,y);
        SRGBA d;
        HSVtoRGBA(s,d);
        return d;
    }
    SRGBA CRGBAHSVToRGBA::get(double x, double y, double z)
    {
        SRGBA s=m_source.get(x,y,z);
        SRGBA d;
        HSVtoRGBA(s,d);
        return d;
    }
    SRGBA CRGBAHSVToRGBA::get(double x, double y, double z, double w)
    {
        SRGBA s=m_source.get(x,y,z,w);
        SRGBA d;
        HSVtoRGBA(s,d);
        return d;
    }
    SRGBA CRGBAHSVToRGBA::get(double x, double y, double z, double w, double u, double v)
    {
        SRGBA s=m_source.get(x,y,z,w,u,v);
        SRGBA d;
        HSVtoRGBA(s,d);
        return d;
    }
};

