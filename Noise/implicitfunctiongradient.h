#ifndef IMPLICIT_FUNCTIONGRADIENT_H
#define IMPLICIT_FUNCTIONGRADIENT_H
#include "implicitmodulebase.h"

namespace anl
{
    enum EFunctionGradientAxis
    {
        X_AXIS,
        Y_AXIS,
        Z_AXIS,
        W_AXIS,
        U_AXIS,
        V_AXIS
    };

    class CImplicitFunctionGradient : public CImplicitModuleBase
    {
        public:
        CImplicitFunctionGradient();
        CImplicitFunctionGradient(ANLFloatType s, int axis=X_AXIS, ANLFloatType spacing=0.001);
        CImplicitFunctionGradient(CImplicitModuleBase * s, int axis=X_AXIS, ANLFloatType spacing=0.001);
        ~CImplicitFunctionGradient();

        void setSource(ANLFloatType v);
        void setSource(CImplicitModuleBase * m);
        void setAxis(int axis);
        void setSpacing(ANLFloatType s);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CScalarParameter m_source;
        int m_axis;
        ANLFloatType m_spacing;

    };
};

#endif
