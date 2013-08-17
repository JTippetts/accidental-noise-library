#ifndef IMPLICIT_CURVE_H
#define IMPLICIT_CURVE_H
#include "implicitmodulebase.h"
#include "implicitbasisfunction.h"
#include "../Imaging/templates/tcurve.h"

#include <vector>
namespace anl
{
    class CImplicitCurve : public CImplicitModuleBase
    {
        public:
        CImplicitCurve();
        CImplicitCurve(ANLFloatType s, int interptype=LINEAR);
        CImplicitCurve(CImplicitModuleBase * s, int interptype=LINEAR);

        ~CImplicitCurve();

        void pushPoint(ANLFloatType t, ANLFloatType v);
        void clearCurve();
        void setSource(ANLFloatType t);
        void setSource(CImplicitModuleBase * m);
        void setInterpType(int type);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        TCurve<ANLFloatType> m_curve;
        CScalarParameter m_source;
        int m_type;
    };
};

#endif
