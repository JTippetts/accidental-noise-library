#include "implicitmagnitude.h"

namespace anl
{
    CImplicitMagnitude::CImplicitMagnitude() : CImplicitModuleBase(), m_x(0.0), m_y(0.0), m_z(0.0), m_w(0.0), m_u(0.0), m_v(0.0){}
    CImplicitMagnitude::~CImplicitMagnitude(){}

    void CImplicitMagnitude::setX(double f){m_x.set(f);}
    void CImplicitMagnitude::setY(double f){m_y.set(f);}
    void CImplicitMagnitude::setZ(double f){m_z.set(f);}
    void CImplicitMagnitude::setW(double f){m_w.set(f);}
    void CImplicitMagnitude::setU(double f){m_u.set(f);}
    void CImplicitMagnitude::setV(double f){m_v.set(f);}

    void CImplicitMagnitude::setX(CImplicitModuleBase * f){m_x.set(f);}
    void CImplicitMagnitude::setY(CImplicitModuleBase * f){m_y.set(f);}
    void CImplicitMagnitude::setZ(CImplicitModuleBase * f){m_z.set(f);}
    void CImplicitMagnitude::setW(CImplicitModuleBase * f){m_w.set(f);}
    void CImplicitMagnitude::setU(CImplicitModuleBase * f){m_u.set(f);}
    void CImplicitMagnitude::setV(CImplicitModuleBase * f){m_v.set(f);}

    double CImplicitMagnitude::get(double x, double y)
    {
        double xx=m_x.get(x,y);
        double yy=m_y.get(x,y);
        return sqrt(xx*xx+yy*yy);
    }

    double CImplicitMagnitude::get(double x, double y, double z)
    {
        double xx=m_x.get(x,y,z);
        double yy=m_y.get(x,y,z);
        double zz=m_z.get(x,y,z);
        return sqrt(xx*xx+yy*yy+zz*zz);
    }

    double CImplicitMagnitude::get(double x, double y, double z, double w)
    {
        double xx=m_x.get(x,y,z,w);
        double yy=m_y.get(x,y,z,w);
        double zz=m_z.get(x,y,z,w);
        double ww=m_w.get(x,y,z,w);
        return sqrt(xx*xx+yy*yy+zz*zz+ww*ww);
    }

    double CImplicitMagnitude::get(double x, double y, double z, double w, double u, double v)
    {
        double xx=m_x.get(x,y,z,w,u,v);
        double yy=m_y.get(x,y,z,w,u,v);
        double zz=m_z.get(x,y,z,w,u,v);
        double ww=m_w.get(x,y,z,w,u,v);
        double uu=m_u.get(x,y,z,w,u,v);
        double vv=m_v.get(x,y,z,w,u,v);
        return sqrt(xx*xx+yy*yy+zz*zz+ww*ww+uu*uu+vv*vv);
    }

};
