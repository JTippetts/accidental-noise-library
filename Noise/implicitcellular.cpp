#include "implicitcellular.h"

namespace anl
{
    CImplicitCellular::CImplicitCellular() : CImplicitModuleBase(), m_generator(0)
{
    setCoefficients(1,0,0,0);
}
CImplicitCellular::CImplicitCellular(double a, double b, double c, double d) : CImplicitModuleBase(), m_generator(0)
{
    setCoefficients(a,b,c,d);
}
CImplicitCellular::CImplicitCellular(CCellularGenerator* m, double a, double b, double c, double d) : CImplicitModuleBase(), m_generator(m)
{
    setCoefficients(a,b,c,d);
}

void CImplicitCellular::setCoefficients(double a, double b, double c, double d)
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

double CImplicitCellular::get(double x, double y)
{
    if(!m_generator) return 0.0;

    SCellularCache &c=m_generator->get(x,y);
    return c.f[0]*m_coefficients[0] + c.f[1]*m_coefficients[1] + c.f[2]*m_coefficients[2] + c.f[3]*m_coefficients[3];
}

double CImplicitCellular::get(double x, double y, double z)
{
    if(!m_generator) return 0.0;

    SCellularCache &c=m_generator->get(x,y,z);
    return c.f[0]*m_coefficients[0] + c.f[1]*m_coefficients[1] + c.f[2]*m_coefficients[2] + c.f[3]*m_coefficients[3];
}
double CImplicitCellular::get(double x, double y, double z, double w)
{
    if(!m_generator) return 0.0;

    SCellularCache &c=m_generator->get(x,y,z,w);
    return c.f[0]*m_coefficients[0] + c.f[1]*m_coefficients[1] + c.f[2]*m_coefficients[2] + c.f[3]*m_coefficients[3];
}
double CImplicitCellular::get(double x, double y, double z, double w, double u, double v)
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

    double CImplicitVoronoi::get(double x, double y)
    {
        if(!m_generator) return 0.0;
        SCellularCache &c=m_generator->get(x,y);
        return c.d[0];
    }


    double CImplicitVoronoi::get(double x, double y, double z)
    {
        if(!m_generator) return 0.0;
        SCellularCache &c=m_generator->get(x,y,z);
        return c.d[0];
    }

    double CImplicitVoronoi::get(double x, double y, double z, double w)
    {
        if(!m_generator) return 0.0;
        SCellularCache &c=m_generator->get(x,y,z,w);
        return c.d[0];
    }

    double CImplicitVoronoi::get(double x, double y, double z, double w, double u, double v)
    {
        if(!m_generator) return 0.0;
        SCellularCache &c=m_generator->get(x,y,z,w,u,v);
        return c.d[0];
    }


};
