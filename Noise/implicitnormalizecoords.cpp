#include "implicitnormalizecoords.h"
#include <cmath>

namespace anl
{
    CImplicitNormalizeCoords::CImplicitNormalizeCoords() : CImplicitModuleBase(), m_source(0.0), m_length(1.0){}
    CImplicitNormalizeCoords::CImplicitNormalizeCoords(double s, double l) : CImplicitModuleBase(), m_source(s), m_length(l){}
    CImplicitNormalizeCoords::CImplicitNormalizeCoords(double s, CImplicitModuleBase *  l) : CImplicitModuleBase(), m_source(s), m_length(l){}
    CImplicitNormalizeCoords::CImplicitNormalizeCoords(CImplicitModuleBase * s, double l) : CImplicitModuleBase(), m_source(s), m_length(l){}
    CImplicitNormalizeCoords::CImplicitNormalizeCoords(CImplicitModuleBase * s, CImplicitModuleBase * l) : CImplicitModuleBase(), m_source(s), m_length(l){}

    void CImplicitNormalizeCoords::setSource(double v)
    {
        m_source.set(v);
    }
    void CImplicitNormalizeCoords::setSource(CImplicitModuleBase * v)
    {
        m_source.set(v);
    }

    void CImplicitNormalizeCoords::setLength(double v)
    {
        m_length.set(v);
    }
    void CImplicitNormalizeCoords::setLength(CImplicitModuleBase * v)
    {
        m_length.set(v);
    }

    double CImplicitNormalizeCoords::get(double x, double y)
    {
        if(x==0 && y==0) return m_source.get(x,y);

        double len=sqrt(x*x+y*y);
        double r=m_length.get(x,y);
        return m_source.get(x/len*r, y/len*r);
    }

    double CImplicitNormalizeCoords::get(double x, double y, double z)
    {
        if(x==0 && y==0 && z==0) return m_source.get(x,y,z);

        double len=sqrt(x*x+y*y+z*z);
        double r=m_length.get(x,y,z);
        return m_source.get(x/len*r, y/len*r, z/len*r);
    }
    double CImplicitNormalizeCoords::get(double x, double y, double z, double w)
    {
        if(x==0 && y==0 && z==0 && w==0) return m_source.get(x,y,z,w);

        double len=sqrt(x*x+y*y+z*z+w*w);
        double r=m_length.get(x,y,z,w);
        return m_source.get(x/len*r, y/len*r, z/len*r, w/len*r);
    }

    double CImplicitNormalizeCoords::get(double x, double y, double z, double w, double u, double v)
    {
        if(x==0 && y==0 && z==0 && w==0 && u==0 && v==0) return m_source.get(x,y,z,w,u,v);

        double len=sqrt(x*x+y*y+z*z+w*w+u*u+v*v);
        double r=m_length.get(x,y,z,w,u,v);
        return m_source.get(x/len*r, y/len*r, z/len*r, w/len*r, u/len*r, v/len*r);
    }
};

