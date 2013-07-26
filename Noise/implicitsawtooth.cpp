#include "implicitsawtooth.h"
#include <cmath>
namespace anl
{
    CImplicitSawtooth::CImplicitSawtooth() : CImplicitModuleBase(), m_source(0.0), m_period(0.0){}
    CImplicitSawtooth::CImplicitSawtooth(double source, double period) : CImplicitModuleBase(), m_source(source), m_period(period){}
    CImplicitSawtooth::CImplicitSawtooth(double source, std::shared_ptr<CImplicitModuleBase> period) : CImplicitModuleBase(), m_source(source), m_period(period){}
    CImplicitSawtooth::CImplicitSawtooth(std::shared_ptr<CImplicitModuleBase> source, double period) : CImplicitModuleBase(), m_source(source), m_period(period){}
    CImplicitSawtooth::CImplicitSawtooth(std::shared_ptr<CImplicitModuleBase> source, std::shared_ptr<CImplicitModuleBase> period) : CImplicitModuleBase(), m_source(source), m_period(period){}
CImplicitSawtooth::~CImplicitSawtooth()
{
}

void CImplicitSawtooth::setSource(std::shared_ptr<CImplicitModuleBase> s)
{
    m_source.set(s);
}

void CImplicitSawtooth::setSource(double s)
{
    m_source.set(s);
}

void CImplicitSawtooth::setPeriod(std::shared_ptr<CImplicitModuleBase> p)
{
    m_period.set(p);
}

void CImplicitSawtooth::setPeriod(double p)
{
    m_period.set(p);
}

double CImplicitSawtooth::get(double x, double y)
{
    double val=m_source.get(x,y);
    double p=m_period.get(x,y);

    return 2.0*(val/p - floor(0.5 + val/p));
}

double CImplicitSawtooth::get(double x, double y, double z)
{
    double val=m_source.get(x,y,z);
    double p=m_period.get(x,y,z);

    return 2.0*(val/p - floor(0.5 + val/p));
}

double CImplicitSawtooth::get(double x, double y, double z, double w)
{
    double val=m_source.get(x,y,z,w);
    double p=m_period.get(x,y,z,w);

    return 2.0*(val/p - floor(0.5 + val/p));
}

double CImplicitSawtooth::get(double x, double y, double z, double w, double u, double v)
{
    double val=m_source.get(x,y,z,w,u,v);
    double p=m_period.get(x,y,z,w,u,v);

    return 2.0*(val/p - floor(0.5 + val/p));
}
};
