#include "rgbacurve.h"

namespace anl
{
    CRGBACurve::CRGBACurve() : m_source(0.0), m_type(LINEAR){}
    CRGBACurve::~CRGBACurve(){}

    void CRGBACurve::pushPoint(double t,float r, float g, float b, float a)
    {
        m_curve.pushPoint(t,SRGBA(r,g,b,a));
    }

    void CRGBACurve::clearCurve()
    {
        m_curve.clear();
    }

    void CRGBACurve::setInterpType(int t)
    {
        m_type=t;
        if(m_type<0) m_type=0;
        if(m_type>QUINTIC) m_type=QUINTIC;
    }

    void CRGBACurve::setSource(double t)
    {
        m_source.set(t);
    }
    void CRGBACurve::setSource(CImplicitModuleBase * m)
    {
        m_source.set(m);
    }

    SRGBA CRGBACurve::get(double x, double y)
    {
        double t=m_source.get(x,y);
        switch(m_type)
        {
            case NONE: return m_curve.noInterp(t); break;
            case LINEAR: return m_curve.linearInterp(t); break;
            case CUBIC: return m_curve.cubicInterp(t); break;
            case QUINTIC: return m_curve.quinticInterp(t); break;
            default: return m_curve.linearInterp(t); break;
        }
    }

    SRGBA CRGBACurve::get(double x, double y, double z)
    {
        double t=m_source.get(x,y,z);
        switch(m_type)
        {
            case NONE: return m_curve.noInterp(t); break;
            case LINEAR: return m_curve.linearInterp(t); break;
            case CUBIC: return m_curve.cubicInterp(t); break;
            case QUINTIC: return m_curve.quinticInterp(t); break;
            default: return m_curve.linearInterp(t); break;
        }
    }

    SRGBA CRGBACurve::get(double x, double y, double z, double w)
    {
        double t=m_source.get(x,y,z,w);
        switch(m_type)
        {
            case NONE: return m_curve.noInterp(t); break;
            case LINEAR: return m_curve.linearInterp(t); break;
            case CUBIC: return m_curve.cubicInterp(t); break;
            case QUINTIC: return m_curve.quinticInterp(t); break;
            default: return m_curve.linearInterp(t); break;
        }
    }

    SRGBA CRGBACurve::get(double x, double y, double z, double w, double u, double v)
    {
        double t=m_source.get(x,y,z,w,u,v);
        switch(m_type)
        {
            case NONE: return m_curve.noInterp(t); break;
            case LINEAR: return m_curve.linearInterp(t); break;
            case CUBIC: return m_curve.cubicInterp(t); break;
            case QUINTIC: return m_curve.quinticInterp(t); break;
            default: return m_curve.linearInterp(t); break;
        }
    }


};

