#include <cmath>
#include <algorithm>
#include "implicitmath.h"
#include "utility.h"

namespace anl
{
    CImplicitMath::CImplicitMath() : CImplicitModuleBase(), m_op(ABS), m_source(0.0), m_parameter(0.0){}

    CImplicitMath::CImplicitMath(unsigned int op, double source, double p) : CImplicitModuleBase(), m_op(op), m_source(source), m_parameter(p){}
    CImplicitMath::CImplicitMath(unsigned int op, CImplicitModuleBase * source, double p) : CImplicitModuleBase(), m_op(op), m_source(source), m_parameter(p){}
    CImplicitMath::CImplicitMath(unsigned int op, double source, CImplicitModuleBase * p) : CImplicitModuleBase(), m_op(op), m_source(source), m_parameter(p){}
    CImplicitMath::CImplicitMath(unsigned int op, CImplicitModuleBase * source, CImplicitModuleBase * p) : CImplicitModuleBase(), m_op(op), m_source(source), m_parameter(p){}
    CImplicitMath::~CImplicitMath() {}

    void CImplicitMath::setSource(double v)
    {
        m_source.set(v);
    }

    void CImplicitMath::setSource(CImplicitModuleBase * b)
    {
        m_source.set(b);
    }

    void CImplicitMath::setParameter(double v)
    {
        m_parameter.set(v);
    }

    void CImplicitMath::setParameter(CImplicitModuleBase * b)
    {
        m_parameter.set(b);
    }

    void CImplicitMath::setOperation(unsigned int op)
    {
        m_op=op;
    }

    double CImplicitMath::get(double x, double y)
    {
        double v=m_source.get(x,y);
        double p=m_parameter.get(x,y);
        return applyOp(v,p);
    }

    double CImplicitMath::get(double x, double y, double z)
    {
        double v=m_source.get(x,y,z);
        double p=m_parameter.get(x,y,z);
        return applyOp(v,p);
    }

    double CImplicitMath::get(double x, double y, double z, double w)
    {
        double v=m_source.get(x,y,z,w);
        double p=m_parameter.get(x,y,z,w);
        return applyOp(v,p);
    }

    double CImplicitMath::get(double x, double y, double z, double w, double u, double v)
    {
        double val=m_source.get(x,y,z,w,u,v);
        double p=m_parameter.get(x,y,z,w,u,v);
        return applyOp(val,p);
    }


    double CImplicitMath::applyOp(double v, double p)
    {
        switch(m_op)
        {
            case ACOS: return acos(v); break;
            case ASIN: return asin(v); break;
            case ATAN: return atan(v); break;
            case COS: return cos(v); break;
            case SIN: return sin(v); break;
            case TAN: return tan(v); break;
            case ABS: return (v<0) ? -v : v; break;
            case FLOOR: return floor(v); break;
            case CEIL: return ceil(v); break;
            case POW: return pow(v,p); break;
            case EXP: return exp(v); break;
            case LOG10: return log10(v); break;
            case LOG2: return log(v)/log(2.0); break;
            case LOGN: return log(v); break;
            case FMOD: return fmod(v,p); break;
            case BIAS: return bias(p,v); break;
            case GAIN: return gain(p,v); break;
            case ONEMINUS: return 1.0-v; break;
            case PMINUS: return p-v; break;
            case SQRT: return sqrt(v); break;
            case INTEGER: return (double)(int)v; break;
            case FRACTIONAL: return v-(double)(int)v; break;
			case EASECUBIC: return hermite_blend(v); break;
			case EASEQUINTIC: return quintic_blend(v); break;
            case SUM: return v+p; break;
            case MULTIPLY: return v*p; break;
            case DIVIDE: return v/p; break;
            case SUBTRACT: return v-p; break;
            case MAXIMUM: return std::max(v,p); break;
            case MINIMUM: return std::min(v,p); break;
            default: return v; break;
        }
    }
};
