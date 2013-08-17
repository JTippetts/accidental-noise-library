#include "implicitmagnitude.h"

namespace anl
{
    CImplicitMagnitude::CImplicitMagnitude() : CImplicitModuleBase(), m_x(0.0), m_y(0.0), m_z(0.0), m_w(0.0), m_u(0.0), m_v(0.0){}
    CImplicitMagnitude::~CImplicitMagnitude(){}

    void CImplicitMagnitude::setX(ANLFloatType f){m_x.set(f);}
    void CImplicitMagnitude::setY(ANLFloatType f){m_y.set(f);}
    void CImplicitMagnitude::setZ(ANLFloatType f){m_z.set(f);}
    void CImplicitMagnitude::setW(ANLFloatType f){m_w.set(f);}
    void CImplicitMagnitude::setU(ANLFloatType f){m_u.set(f);}
    void CImplicitMagnitude::setV(ANLFloatType f){m_v.set(f);}

    void CImplicitMagnitude::setX(CImplicitModuleBase * f){m_x.set(f);}
    void CImplicitMagnitude::setY(CImplicitModuleBase * f){m_y.set(f);}
    void CImplicitMagnitude::setZ(CImplicitModuleBase * f){m_z.set(f);}
    void CImplicitMagnitude::setW(CImplicitModuleBase * f){m_w.set(f);}
    void CImplicitMagnitude::setU(CImplicitModuleBase * f){m_u.set(f);}
    void CImplicitMagnitude::setV(CImplicitModuleBase * f){m_v.set(f);}

    ANLFloatType CImplicitMagnitude::get(ANLFloatType x, ANLFloatType y)
    {
        ANLFloatType xx=m_x.get(x,y);
        ANLFloatType yy=m_y.get(x,y);
        return sqrt(xx*xx+yy*yy);
    }

    ANLFloatType CImplicitMagnitude::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        ANLFloatType xx=m_x.get(x,y,z);
        ANLFloatType yy=m_y.get(x,y,z);
        ANLFloatType zz=m_z.get(x,y,z);
        return sqrt(xx*xx+yy*yy+zz*zz);
    }

    ANLFloatType CImplicitMagnitude::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        ANLFloatType xx=m_x.get(x,y,z,w);
        ANLFloatType yy=m_y.get(x,y,z,w);
        ANLFloatType zz=m_z.get(x,y,z,w);
        ANLFloatType ww=m_w.get(x,y,z,w);
        return sqrt(xx*xx+yy*yy+zz*zz+ww*ww);
    }

    ANLFloatType CImplicitMagnitude::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        ANLFloatType xx=m_x.get(x,y,z,w,u,v);
        ANLFloatType yy=m_y.get(x,y,z,w,u,v);
        ANLFloatType zz=m_z.get(x,y,z,w,u,v);
        ANLFloatType ww=m_w.get(x,y,z,w,u,v);
        ANLFloatType uu=m_u.get(x,y,z,w,u,v);
        ANLFloatType vv=m_v.get(x,y,z,w,u,v);
        return sqrt(xx*xx+yy*yy+zz*zz+ww*ww+uu*uu+vv*vv);
    }

};
