#include "rgbacurve.h"

namespace anl
{
    CRGBACurve::CRGBACurve() : m_source(0.0), m_type(LINEAR){}

	CRGBACurve::CRGBACurve(CImplicitModuleBase *src, int interp) : m_source(src), m_type(interp)
	{
	}

    CRGBACurve::~CRGBACurve(){}

    void CRGBACurve::pushPoint(ANLFloatType t,float r, float g, float b, float a)
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

    void CRGBACurve::setSource(ANLFloatType t)
    {
        m_source.set(t);
    }
    void CRGBACurve::setSource(CImplicitModuleBase * m)
    {
        m_source.set(m);
    }

    SRGBA CRGBACurve::get(ANLFloatType x, ANLFloatType y)
    {
        ANLFloatType t=m_source.get(x,y);
        switch(m_type)
        {
            case NONE: return m_curve.noInterp(t); break;
            case LINEAR: return m_curve.linearInterp(t); break;
            case CUBIC: return m_curve.cubicInterp(t); break;
            case QUINTIC: return m_curve.quinticInterp(t); break;
            default: return m_curve.linearInterp(t); break;
        }
    }

    SRGBA CRGBACurve::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        ANLFloatType t=m_source.get(x,y,z);
        switch(m_type)
        {
            case NONE: return m_curve.noInterp(t); break;
            case LINEAR: return m_curve.linearInterp(t); break;
            case CUBIC: return m_curve.cubicInterp(t); break;
            case QUINTIC: return m_curve.quinticInterp(t); break;
            default: return m_curve.linearInterp(t); break;
        }
    }

    SRGBA CRGBACurve::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        ANLFloatType t=m_source.get(x,y,z,w);
        switch(m_type)
        {
            case NONE: return m_curve.noInterp(t); break;
            case LINEAR: return m_curve.linearInterp(t); break;
            case CUBIC: return m_curve.cubicInterp(t); break;
            case QUINTIC: return m_curve.quinticInterp(t); break;
            default: return m_curve.linearInterp(t); break;
        }
    }

    SRGBA CRGBACurve::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        ANLFloatType t=m_source.get(x,y,z,w,u,v);
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

