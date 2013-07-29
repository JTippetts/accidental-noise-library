#include "rgbaimplicitgrayscale.h"

namespace anl
{
    CRGBAImplicitGrayscale::CRGBAImplicitGrayscale() : m_source(0.0){}

    CRGBAImplicitGrayscale::CRGBAImplicitGrayscale(double s) : CRGBAModuleBase(), m_source(s){}
    CRGBAImplicitGrayscale::CRGBAImplicitGrayscale(CImplicitModuleBase * s) : CRGBAModuleBase(), m_source(s){}

    CRGBAImplicitGrayscale::~CRGBAImplicitGrayscale(){}
    void CRGBAImplicitGrayscale::setSource(CImplicitModuleBase * m)
    {
        m_source.set(m);
    }
    void CRGBAImplicitGrayscale::setSource(double s)
    {
        m_source.set(s);
    }

    SRGBA CRGBAImplicitGrayscale::get(double x, double y)
    {
        double val=m_source.get(x,y);
        return SRGBA((float)val,(float)val,(float)val,1.0f);
    }
    SRGBA CRGBAImplicitGrayscale::get(double x, double y, double z)
    {
        double val=m_source.get(x,y,z);
        return SRGBA((float)val,(float)val,(float)val,1.0f);
    }

    SRGBA CRGBAImplicitGrayscale::get(double x, double y, double z, double w)
    {
        double val=m_source.get(x,y,z,w);
        return SRGBA((float)val,(float)val,(float)val,1.0f);
    }
    SRGBA CRGBAImplicitGrayscale::get(double x, double y, double z, double w, double u, double v)
    {
        double val=m_source.get(x,y,z,w,u,v);
        return SRGBA((float)val,(float)val,(float)val,1.0f);
    }
};
