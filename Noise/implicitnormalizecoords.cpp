#include "implicitnormalizecoords.h"
#include <cmath>

namespace anl
{
    CImplicitNormalizeCoords::CImplicitNormalizeCoords() : CImplicitModuleBase(), m_source(0.0), m_length(1.0){}
    CImplicitNormalizeCoords::CImplicitNormalizeCoords(ANLFloatType s, ANLFloatType l) : CImplicitModuleBase(), m_source(s), m_length(l){}
    CImplicitNormalizeCoords::CImplicitNormalizeCoords(ANLFloatType s, CImplicitModuleBase *  l) : CImplicitModuleBase(), m_source(s), m_length(l){}
    CImplicitNormalizeCoords::CImplicitNormalizeCoords(CImplicitModuleBase * s, ANLFloatType l) : CImplicitModuleBase(), m_source(s), m_length(l){}
    CImplicitNormalizeCoords::CImplicitNormalizeCoords(CImplicitModuleBase * s, CImplicitModuleBase * l) : CImplicitModuleBase(), m_source(s), m_length(l){}

    void CImplicitNormalizeCoords::setSource(ANLFloatType v)
    {
        m_source.set(v);
    }
    void CImplicitNormalizeCoords::setSource(CImplicitModuleBase * v)
    {
        m_source.set(v);
    }

    void CImplicitNormalizeCoords::setLength(ANLFloatType v)
    {
        m_length.set(v);
    }
    void CImplicitNormalizeCoords::setLength(CImplicitModuleBase * v)
    {
        m_length.set(v);
    }

    ANLFloatType CImplicitNormalizeCoords::get(ANLFloatType x, ANLFloatType y)
    {
        if(x==0 && y==0) return m_source.get(x,y);

        ANLFloatType len=sqrt(x*x+y*y);
        ANLFloatType r=m_length.get(x,y);
        return m_source.get(x/len*r, y/len*r);
    }

    ANLFloatType CImplicitNormalizeCoords::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        if(x==0 && y==0 && z==0) return m_source.get(x,y,z);

        ANLFloatType len=sqrt(x*x+y*y+z*z);
        ANLFloatType r=m_length.get(x,y,z);
        return m_source.get(x/len*r, y/len*r, z/len*r);
    }
    ANLFloatType CImplicitNormalizeCoords::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        if(x==0 && y==0 && z==0 && w==0) return m_source.get(x,y,z,w);

        ANLFloatType len=sqrt(x*x+y*y+z*z+w*w);
        ANLFloatType r=m_length.get(x,y,z,w);
        return m_source.get(x/len*r, y/len*r, z/len*r, w/len*r);
    }

    ANLFloatType CImplicitNormalizeCoords::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        if(x==0 && y==0 && z==0 && w==0 && u==0 && v==0) return m_source.get(x,y,z,w,u,v);

        ANLFloatType len=sqrt(x*x+y*y+z*z+w*w+u*u+v*v);
        ANLFloatType r=m_length.get(x,y,z,w,u,v);
        return m_source.get(x/len*r, y/len*r, z/len*r, w/len*r, u/len*r, v/len*r);
    }
};

