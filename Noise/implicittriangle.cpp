#include "implicittriangle.h"
#include <cmath>

namespace anl
{
    ANLFloatType sawtooth(ANLFloatType x, ANLFloatType p)
    {
        return (2.0*(x/p-floor(0.5+x/p)))*0.5+0.5;
    }

    CImplicitTriangle::CImplicitTriangle() : CImplicitModuleBase(), m_source(0.0), m_period(0.0), m_offset(0.0){}
    CImplicitTriangle::CImplicitTriangle(ANLFloatType source, ANLFloatType period, ANLFloatType offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(ANLFloatType source, ANLFloatType period, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(ANLFloatType source, CImplicitModuleBase * period, ANLFloatType offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(ANLFloatType source, CImplicitModuleBase * period, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(CImplicitModuleBase * source, ANLFloatType period, ANLFloatType offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(CImplicitModuleBase * source, ANLFloatType period, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(CImplicitModuleBase * source, CImplicitModuleBase * period, ANLFloatType offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}
    CImplicitTriangle::CImplicitTriangle(CImplicitModuleBase * source, CImplicitModuleBase * period, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_period(period), m_offset(offset){}

    CImplicitTriangle::~CImplicitTriangle(){}

    void CImplicitTriangle::setSource(ANLFloatType s){m_source.set(s);}
    void CImplicitTriangle::setSource(CImplicitModuleBase * s){m_source.set(s);}
    void CImplicitTriangle::setPeriod(ANLFloatType p){m_period.set(p);}
    void CImplicitTriangle::setPeriod(CImplicitModuleBase * p){m_period.set(p);}
    void CImplicitTriangle::setOffset(ANLFloatType o){m_offset.set(o);}
    void CImplicitTriangle::setOffset(CImplicitModuleBase * o){m_offset.set(o);}

    ANLFloatType CImplicitTriangle::get(ANLFloatType x, ANLFloatType y)
    {
        ANLFloatType val=m_source.get(x,y);
        ANLFloatType period=m_period.get(x,y);
        ANLFloatType offset=m_offset.get(x,y);

        if (offset>=1) return sawtooth(val, period);
        else if (offset<=0) return 1.0-sawtooth(val, period);
        else
        {
            ANLFloatType s1=(offset-sawtooth(val,period))>=0 ? 1.0 : 0.0;
            ANLFloatType s2=((1.0-offset)-(sawtooth(-val,period)))>=0 ? 1.0 : 0.0;
            return sawtooth(val,period) * s1/offset + sawtooth(-val,period)*s2/(1.0-offset);
        }
    }

    ANLFloatType CImplicitTriangle::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        ANLFloatType val=m_source.get(x,y,z);
        ANLFloatType period=m_period.get(x,y,z);
        ANLFloatType offset=m_offset.get(x,y,z);

        if (offset>=1) return sawtooth(val, period);
        else if (offset<=0) return 1.0-sawtooth(val, period);
        else
        {
            ANLFloatType s1=(offset-sawtooth(val,period))>=0 ? 1.0 : 0.0;
            ANLFloatType s2=((1.0-offset)-(sawtooth(-val,period)))>=0 ? 1.0 : 0.0;
            return sawtooth(val,period) * s1/offset + sawtooth(-val,period)*s2/(1.0-offset);
            //return sawtooth(val,period)*s1/offset;
        }
    }

    ANLFloatType CImplicitTriangle::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        ANLFloatType val=m_source.get(x,y,z,w);
        ANLFloatType period=m_period.get(x,y,z,w);
        ANLFloatType offset=m_offset.get(x,y,z,w);

        if (offset>=1) return sawtooth(val, period);
        else if (offset<=0) return 1.0-sawtooth(val, period);
        else
        {
            ANLFloatType s1=(offset-sawtooth(val,period))>=0 ? 1.0 : 0.0;
            ANLFloatType s2=((1.0-offset)-(sawtooth(-val,period)))>=0 ? 1.0 : 0.0;
            return sawtooth(val,period) * s1/offset + sawtooth(-val,period)*s2/(1.0-offset);
        }
    }

    ANLFloatType CImplicitTriangle::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        ANLFloatType val=m_source.get(x,y,z,w,u,v);
        ANLFloatType period=m_period.get(x,y,z,w,u,v);
        ANLFloatType offset=m_offset.get(x,y,z,w,u,v);

        if (offset>=1) return sawtooth(val, period);
        else if (offset<=0) return 1.0-sawtooth(val, period);
        else
        {
            ANLFloatType s1=(offset-sawtooth(val,period))>=0 ? 1.0 : 0.0;
            ANLFloatType s2=((1.0-offset)-(sawtooth(-val,period)))>=0 ? 1.0 : 0.0;
            return sawtooth(val,period) * s1/offset + sawtooth(-val,period)*s2/(1.0-offset);
        }
    }
};
