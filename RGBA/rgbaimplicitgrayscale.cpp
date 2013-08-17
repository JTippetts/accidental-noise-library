#include "rgbaimplicitgrayscale.h"

namespace anl
{
    CRGBAImplicitGrayscale::CRGBAImplicitGrayscale() : m_source(0.0){}

    CRGBAImplicitGrayscale::CRGBAImplicitGrayscale(ANLFloatType s) : CRGBAModuleBase(), m_source(s){}
    CRGBAImplicitGrayscale::CRGBAImplicitGrayscale(CImplicitModuleBase * s) : CRGBAModuleBase(), m_source(s){}

    CRGBAImplicitGrayscale::~CRGBAImplicitGrayscale(){}
    void CRGBAImplicitGrayscale::setSource(CImplicitModuleBase * m)
    {
        m_source.set(m);
    }
    void CRGBAImplicitGrayscale::setSource(ANLFloatType s)
    {
        m_source.set(s);
    }

    SRGBA CRGBAImplicitGrayscale::get(ANLFloatType x, ANLFloatType y)
    {
        ANLFloatType val=m_source.get(x,y);
        return SRGBA((float)val,(float)val,(float)val,1.0f);
    }
    SRGBA CRGBAImplicitGrayscale::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        ANLFloatType val=m_source.get(x,y,z);
        return SRGBA((float)val,(float)val,(float)val,1.0f);
    }

    SRGBA CRGBAImplicitGrayscale::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        ANLFloatType val=m_source.get(x,y,z,w);
        return SRGBA((float)val,(float)val,(float)val,1.0f);
    }
    SRGBA CRGBAImplicitGrayscale::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        ANLFloatType val=m_source.get(x,y,z,w,u,v);
        return SRGBA((float)val,(float)val,(float)val,1.0f);
    }
};
