#include "implicitgradient.h"
#include "utility.h"
#include <math.h>

namespace anl
{
CImplicitGradient::CImplicitGradient() :  CImplicitModuleBase()
{
    setGradient(0,1,0,1,0,0,0,0,0,0,0,0);
}

CImplicitGradient::CImplicitGradient(double x1, double x2, double y1, double y2, double z1, double z2,
        double w1, double w2, double u1, double u2, double v1, double v2)
{
    setGradient(x1,x2,y1,y2,z1,z2,w1,w2,u1,u2,v1,v2);
}

CImplicitGradient::~CImplicitGradient(){}

void CImplicitGradient::setGradient(double x1, double x2, double y1, double y2, double z1, double z2,
    double w1, double w2, double u1, double u2, double v1, double v2)
{
    m_gx1=x1; m_gx2=x2;
    m_gy1=y1; m_gy2=y2;
    m_gz1=z1; m_gz2=z2;
    m_gw1=w1; m_gw2=w2;
    m_gu1=u1; m_gu2=u2;
    m_gv1=v1; m_gv2=v2;

    m_x=x2-x1;
    m_y=y2-y1;
    m_z=z2-z1;
    m_w=w2-w1;
    m_u=u2-u1;
    m_v=v2-v1;

    m_vlen=(m_x*m_x+m_y*m_y+m_z*m_z+m_w*m_w+m_u*m_u+m_v*m_v);
}

double CImplicitGradient::get(double x, double y)
{
    // Subtract from (1) and take dotprod
    double dx=x-m_gx1;
    double dy=y-m_gy1;
    double dp=dx*m_x+dy*m_y;
    dp/=m_vlen;
    //dp=clamp(dp/m_vlen,0.0,1.0);
    //return lerp(dp,1.0,-1.0);
    return dp;
}

double CImplicitGradient::get(double x, double y, double z)
{
    double dx=x-m_gx1;
    double dy=y-m_gy1;
    double dz=z-m_gz1;
    double dp=dx*m_x+dy*m_y+dz*m_z;
    dp/=m_vlen;
    //dp=clamp(dp/m_vlen,0.0,1.0);
    //return lerp(dp,1.0,-1.0);
    return dp;
}

double CImplicitGradient::get(double x, double y, double z, double w)
{
    double dx=x-m_gx1;
    double dy=y-m_gy1;
    double dz=z-m_gz1;
    double dw=w-m_gw1;
    double dp=dx*m_x+dy*m_y+dz*m_z+dw*m_w;
    dp/=m_vlen;
    //dp=clamp(dp/m_vlen,0.0,1.0);
    //return lerp(dp,1.0,-1.0);
    return dp;
}

double CImplicitGradient::get(double x, double y, double z, double w, double u, double v)
{
    double dx=x-m_gx1;
    double dy=y-m_gy1;
    double dz=z-m_gz1;
    double dw=w-m_gw1;
    double du=u-m_gu1;
    double dv=v-m_gv1;
    double dp=dx*m_x+dy*m_y+dz*m_z+dw*m_w+du*m_u+dv*m_v;
    dp/=m_vlen;
    //dp=clamp(dp/m_vlen,0.0,1.0);
    //return lerp(clamp(dp,0.0,1.0),1.0,-1.0);
    return dp;
}
};
