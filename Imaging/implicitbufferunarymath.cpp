#include "implicitbufferunarymath.h"
#include "implicitmath.h"

namespace anl
{
    CImplicitBufferUnaryMath::CImplicitBufferUnaryMath() : CImplicitBufferBase(), m_source(), m_op(0)
    {
    }

    CImplicitBufferUnaryMath::CImplicitBufferUnaryMath(CImplicitBufferBase * source, int op) :
        CImplicitBufferBase(), m_source(source), m_op(op)
    {
    }

    CImplicitBufferUnaryMath::~CImplicitBufferUnaryMath()
    {
    }

    void CImplicitBufferUnaryMath::setSource(CImplicitBufferBase * source)
    {
        m_source=source;
    }

    void CImplicitBufferUnaryMath::setOp(int op)
    {
        m_op=op;
    }

    void CImplicitBufferUnaryMath::get(CArray2Dd &out)
    {
        if(!m_source) return;
        m_source->get(out);

        for(int x=0; x<out.width(); ++x)
        {
            for(int y=0; y<out.height(); ++y)
            {
                ANLFloatType v=out.get(x,y);
                switch(m_op)
                {
                    case ACOS: out.set(x,y,acos(v)); break;
                    case ASIN: out.set(x,y,asin(v)); break;
                    case ATAN: out.set(x,y,asin(v)); break;
                    case COS: out.set(x,y,cos(v)); break;
                    case SIN: out.set(x,y,sin(v)); break;
                    case TAN: out.set(x,y,tan(v)); break;
                    case ABS: out.set(x,y,fabs(v)); break;
                    case FLOOR: out.set(x,y,floor(v)); break;
                    case CEIL: out.set(x,y,ceil(v)); break;
                    case EXP: out.set(x,y,exp(v)); break;
                    case LOG10: out.set(x,y,log10(v)); break;
                    case LOG2: out.set(x,y,log(v)/log(2.0)); break;
                    case LOGN: out.set(x,y,log(v)); break;
                    case ONEMINUS: out.set(x,y, 1.0-v); break;
                    case SQRT: out.set(x,y,sqrt(v)); break;
                    case INTEGER: out.set(x,y,(int)v); break;
                    case FRACTIONAL: out.set(x,y,v-(ANLFloatType)(int)v); break;
                    default: break;
                };
            }
        }
    }
};
