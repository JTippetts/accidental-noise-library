#include "implicitgradient.h"
#include "utility.h"
#include <math.h>

namespace anl
{
CImplicitGradient::CImplicitGradient() :  CImplicitModuleBase()
{
    setGradient(0,1,0,1,0,0,0,0,0,0,0,0);
}

CImplicitGradient::CImplicitGradient(ANLFloatType x1, ANLFloatType x2, ANLFloatType y1, ANLFloatType y2, ANLFloatType z1, ANLFloatType z2,
        ANLFloatType w1, ANLFloatType w2, ANLFloatType u1, ANLFloatType u2, ANLFloatType v1, ANLFloatType v2)
{
    setGradient(x1,x2,y1,y2,z1,z2,w1,w2,u1,u2,v1,v2);
}

CImplicitGradient::~CImplicitGradient(){}

void CImplicitGradient::setGradient(ANLFloatType x1, ANLFloatType x2, ANLFloatType y1, ANLFloatType y2, ANLFloatType z1, ANLFloatType z2,
    ANLFloatType w1, ANLFloatType w2, ANLFloatType u1, ANLFloatType u2, ANLFloatType v1, ANLFloatType v2)
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

ANLFloatType CImplicitGradient::get(ANLFloatType x, ANLFloatType y)
{
    // Subtract from (1) and take dotprod
    ANLFloatType dx=x-m_gx1;
    ANLFloatType dy=y-m_gy1;
    ANLFloatType dp=dx*m_x+dy*m_y;
    dp/=m_vlen;
    //dp=clamp(dp/m_vlen,0.0,1.0);
    //return lerp(dp,1.0,-1.0);
    return dp;
}

ANLFloatType CImplicitGradient::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    ANLFloatType dx=x-m_gx1;
    ANLFloatType dy=y-m_gy1;
    ANLFloatType dz=z-m_gz1;
    ANLFloatType dp=dx*m_x+dy*m_y+dz*m_z;
    dp/=m_vlen;
    //dp=clamp(dp/m_vlen,0.0,1.0);
    //return lerp(dp,1.0,-1.0);
    return dp;
}

ANLFloatType CImplicitGradient::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
    ANLFloatType dx=x-m_gx1;
    ANLFloatType dy=y-m_gy1;
    ANLFloatType dz=z-m_gz1;
    ANLFloatType dw=w-m_gw1;
    ANLFloatType dp=dx*m_x+dy*m_y+dz*m_z+dw*m_w;
    dp/=m_vlen;
    //dp=clamp(dp/m_vlen,0.0,1.0);
    //return lerp(dp,1.0,-1.0);
    return dp;
}

ANLFloatType CImplicitGradient::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
    ANLFloatType dx=x-m_gx1;
    ANLFloatType dy=y-m_gy1;
    ANLFloatType dz=z-m_gz1;
    ANLFloatType dw=w-m_gw1;
    ANLFloatType du=u-m_gu1;
    ANLFloatType dv=v-m_gv1;
    ANLFloatType dp=dx*m_x+dy*m_y+dz*m_z+dw*m_w+du*m_u+dv*m_v;
    dp/=m_vlen;
    //dp=clamp(dp/m_vlen,0.0,1.0);
    //return lerp(clamp(dp,0.0,1.0),1.0,-1.0);
    return dp;
}
};
