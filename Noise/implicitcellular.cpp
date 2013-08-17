#include "implicitcellular.h"

namespace anl
{
    CImplicitCellular::CImplicitCellular() : CImplicitModuleBase(), m_generator(0)
{
    setCoefficients(1,0,0,0);
}
CImplicitCellular::CImplicitCellular(ANLFloatType a, ANLFloatType b, ANLFloatType c, ANLFloatType d) : CImplicitModuleBase(), m_generator(0)
{
    setCoefficients(a,b,c,d);
}
CImplicitCellular::CImplicitCellular(CCellularGenerator* m, ANLFloatType a, ANLFloatType b, ANLFloatType c, ANLFloatType d) : CImplicitModuleBase(), m_generator(m)
{
    setCoefficients(a,b,c,d);
}

void CImplicitCellular::setCoefficients(ANLFloatType a, ANLFloatType b, ANLFloatType c, ANLFloatType d)
{
    m_coefficients[0]=a;
    m_coefficients[1]=b;
    m_coefficients[2]=c;
    m_coefficients[3]=d;
}

void CImplicitCellular::setCellularSource(CCellularGenerator* m)
{
    m_generator=m;
}

ANLFloatType CImplicitCellular::get(ANLFloatType x, ANLFloatType y)
{
    if(!m_generator) return 0.0;

    SCellularCache &c=m_generator->get(x,y);
    return c.f[0]*m_coefficients[0] + c.f[1]*m_coefficients[1] + c.f[2]*m_coefficients[2] + c.f[3]*m_coefficients[3];
}

ANLFloatType CImplicitCellular::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    if(!m_generator) return 0.0;

    SCellularCache &c=m_generator->get(x,y,z);
    return c.f[0]*m_coefficients[0] + c.f[1]*m_coefficients[1] + c.f[2]*m_coefficients[2] + c.f[3]*m_coefficients[3];
}
ANLFloatType CImplicitCellular::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
    if(!m_generator) return 0.0;

    SCellularCache &c=m_generator->get(x,y,z,w);
    return c.f[0]*m_coefficients[0] + c.f[1]*m_coefficients[1] + c.f[2]*m_coefficients[2] + c.f[3]*m_coefficients[3];
}
ANLFloatType CImplicitCellular::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
    if(!m_generator) return 0.0;

    SCellularCache &c=m_generator->get(x,y,z,w,u,v);
    return c.f[0]*m_coefficients[0] + c.f[1]*m_coefficients[1] + c.f[2]*m_coefficients[2] + c.f[3]*m_coefficients[3];
}

    CImplicitVoronoi::CImplicitVoronoi() : CImplicitModuleBase()
    {
    }

    CImplicitVoronoi::CImplicitVoronoi(CCellularGenerator* m) : CImplicitModuleBase(), m_generator(m)
    {
    }

    CImplicitVoronoi::~CImplicitVoronoi()
    {
    }

    ANLFloatType CImplicitVoronoi::get(ANLFloatType x, ANLFloatType y)
    {
        if(!m_generator) return 0.0;
        SCellularCache &c=m_generator->get(x,y);
        return c.d[0];
    }


    ANLFloatType CImplicitVoronoi::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        if(!m_generator) return 0.0;
        SCellularCache &c=m_generator->get(x,y,z);
        return c.d[0];
    }

    ANLFloatType CImplicitVoronoi::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        if(!m_generator) return 0.0;
        SCellularCache &c=m_generator->get(x,y,z,w);
        return c.d[0];
    }

    ANLFloatType CImplicitVoronoi::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        if(!m_generator) return 0.0;
        SCellularCache &c=m_generator->get(x,y,z,w,u,v);
        return c.d[0];
    }


};
