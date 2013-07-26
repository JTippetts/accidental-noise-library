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
        CImplicitFunctionGradient(double s, int axis=X_AXIS, double spacing=0.001);
        CImplicitFunctionGradient(std::shared_ptr<CImplicitModuleBase> s, int axis=X_AXIS, double spacing=0.001);
        ~CImplicitFunctionGradient();

        void setSource(double v);
        void setSource(std::shared_ptr<CImplicitModuleBase> m);
        void setAxis(int axis);
        void setSpacing(double s);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        CScalarParameter m_source;
        int m_axis;
        double m_spacing;

    };
};

#endif
