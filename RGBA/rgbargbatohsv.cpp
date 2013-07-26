#include "rgbargbatohsv.h"
#include "hsv.h"

namespace anl
{
    CRGBARGBAToHSV::CRGBARGBAToHSV() : CRGBAModuleBase(), m_source(){}
    CRGBARGBAToHSV::CRGBARGBAToHSV(SRGBA s) : CRGBAModuleBase(), m_source(s){}
    CRGBARGBAToHSV::CRGBARGBAToHSV(std::shared_ptr<CRGBAModuleBase> s) : CRGBAModuleBase(), m_source(s){}

    void CRGBARGBAToHSV::setSource(std::shared_ptr<CRGBAModuleBase> m)
    {
        m_source.set(m);
    }
    void CRGBARGBAToHSV::setSource(SRGBA c)
    {
        m_source.set(c);
    }

    SRGBA CRGBARGBAToHSV::get(double x, double y)
    {
        SRGBA s=m_source.get(x,y);
        SRGBA d;
        RGBAtoHSV(s,d);
        return d;
    }
    SRGBA CRGBARGBAToHSV::get(double x, double y, double z)
    {
        SRGBA s=m_source.get(x,y,z);
        SRGBA d;
        RGBAtoHSV(s,d);
        return d;
    }
    SRGBA CRGBARGBAToHSV::get(double x, double y, double z, double w)
    {
        SRGBA s=m_source.get(x,y,z,w);
        SRGBA d;
        RGBAtoHSV(s,d);
        return d;
    }
    SRGBA CRGBARGBAToHSV::get(double x, double y, double z, double w, double u, double v)
    {
        SRGBA s=m_source.get(x,y,z,w,u,v);
        SRGBA d;
        RGBAtoHSV(s,d);
        return d;
    }
};
