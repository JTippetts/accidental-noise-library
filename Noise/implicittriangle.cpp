#include "implicittriangle.h"
#include <cmath>

namespace anl
{
    double sawtooth(double x, double p)
    {
        return (2.0*(x/p-floor(0.5+x/p)))*0.5+0.5;
    }

    CImplicitTriangle::CImplicitTriangle() : CImplicitModuleBase(), m_source(0.0), m_period(0.0), m_offset(0.0){}
    CImplicitTriangle::CImplicitTriangle(double source, double period, double offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(double source, double period, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(double source, CImplicitModuleBase * period, double offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(double source, CImplicitModuleBase * period, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(CImplicitModuleBase * source, double period, double offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(CImplicitModuleBase * source, double period, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(CImplicitModuleBase * source, CImplicitModuleBase * period, double offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(CImplicitModuleBase * source, CImplicitModuleBase * period, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}

    CImplicitTriangle::~CImplicitTriangle(){}

    void CImplicitTriangle::setSource(double s){m_source.set(s);}
    void CImplicitTriangle::setSource(CImplicitModuleBase * s){m_source.set(s);}
    void CImplicitTriangle::setPeriod(double p){m_period.set(p);}
    void CImplicitTriangle::setPeriod(CImplicitModuleBase * p){m_period.set(p);}
    void CImplicitTriangle::setOffset(double o){m_offset.set(o);}
    void CImplicitTriangle::setOffset(CImplicitModuleBase * o){m_offset.set(o);}

    double CImplicitTriangle::get(double x, double y)
    {
        double val=m_source.get(x,y);
        double period=m_period.get(x,y);
        double offset=m_offset.get(x,y);

        if (offset>=1) return sawtooth(val, period);
        else if (offset<=0) return 1.0-sawtooth(val, period);
        else
        {
            double s1=(offset-sawtooth(val,period))>=0 ? 1.0 : 0.0;
            double s2=((1.0-offset)-(sawtooth(-val,period)))>=0 ? 1.0 : 0.0;
            return sawtooth(val,period) * s1/offset + sawtooth(-val,period)*s2/(1.0-offset);
        }
    }

    double CImplicitTriangle::get(double x, double y, double z)
    {
        double val=m_source.get(x,y,z);
        double period=m_period.get(x,y,z);
        double offset=m_offset.get(x,y,z);

        if (offset>=1) return sawtooth(val, period);
        else if (offset<=0) return 1.0-sawtooth(val, period);
        else
        {
            double s1=(offset-sawtooth(val,period))>=0 ? 1.0 : 0.0;
            double s2=((1.0-offset)-(sawtooth(-val,period)))>=0 ? 1.0 : 0.0;
            return sawtooth(val,period) * s1/offset + sawtooth(-val,period)*s2/(1.0-offset);
            //return sawtooth(val,period)*s1/offset;
        }
    }

    double CImplicitTriangle::get(double x, double y, double z, double w)
    {
        double val=m_source.get(x,y,z,w);
        double period=m_period.get(x,y,z,w);
        double offset=m_offset.get(x,y,z,w);

        if (offset>=1) return sawtooth(val, period);
        else if (offset<=0) return 1.0-sawtooth(val, period);
        else
        {
            double s1=(offset-sawtooth(val,period))>=0 ? 1.0 : 0.0;
            double s2=((1.0-offset)-(sawtooth(-val,period)))>=0 ? 1.0 : 0.0;
            return sawtooth(val,period) * s1/offset + sawtooth(-val,period)*s2/(1.0-offset);
        }
    }

    double CImplicitTriangle::get(double x, double y, double z, double w, double u, double v)
    {
        double val=m_source.get(x,y,z,w,u,v);
        double period=m_period.get(x,y,z,w,u,v);
        double offset=m_offset.get(x,y,z,w,u,v);

        if (offset>=1) return sawtooth(val, period);
        else if (offset<=0) return 1.0-sawtooth(val, period);
        else
        {
            double s1=(offset-sawtooth(val,period))>=0 ? 1.0 : 0.0;
            double s2=((1.0-offset)-(sawtooth(-val,period)))>=0 ? 1.0 : 0.0;
            return sawtooth(val,period) * s1/offset + sawtooth(-val,period)*s2/(1.0-offset);
        }
    }
};
