#ifndef IMPLICITMATH_H
#define IMPLICITMATH_H

#include "implicitmodulebase.h"

#include <cmath>

namespace anl
{
    enum EUnaryMathOperation
    {
        ACOS,
        ASIN,
        ATAN,
        COS,
        SIN,
        TAN,
        ABS,
        FLOOR,
        CEIL,
        EXP,
        LOG10,
        LOG2,
        LOGN,
        ONEMINUS,
        SQRT,
        INTEGER,
        FRACTIONAL,
		EASECUBIC,
		EASEQUINTIC,
    };

    enum EBinaryMathOperation
    {
        POW=EASEQUINTIC+1,
        FMOD,
        BIAS,
        GAIN,
        PMINUS,
        SUM,
        MULTIPLY,
        DIVIDE,
        SUBTRACT,
        MAXIMUM,
        MINIMUM
    };

    class CImplicitMath : public CImplicitModuleBase
    {
        public:
        CImplicitMath();
        CImplicitMath(unsigned int op, ANLFloatType source=1, ANLFloatType p=1);
        CImplicitMath(unsigned int op, CImplicitModuleBase * source=0, ANLFloatType p=1);
        CImplicitMath(unsigned int op, ANLFloatType source=0, CImplicitModuleBase * p=0);
        CImplicitMath(unsigned int op, CImplicitModuleBase * source=0, CImplicitModuleBase * p=0);
        ~CImplicitMath();

        void setSource(ANLFloatType v);
        void setSource(CImplicitModuleBase * b);
        void setParameter(ANLFloatType v);
        void setParameter(CImplicitModuleBase * b);
        void setOperation(unsigned int op);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        unsigned int m_op;
        CScalarParameter m_source;
        CScalarParameter m_parameter;

        ANLFloatType applyOp(ANLFloatType v, ANLFloatType p);
    };
};

#endif
