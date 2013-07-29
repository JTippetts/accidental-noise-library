#ifndef IMPLICIT_BLEND_H
#define IMPLICIT_BLEND_H
#include "implicitmodulebase.h"

namespace anl
{

    class CImplicitBlend : public CImplicitModuleBase
    {
    public:
        CImplicitBlend();
        CImplicitBlend(double low, double high, double control);
        CImplicitBlend(double low, double high, CImplicitModuleBase * control);
        CImplicitBlend(double low, CImplicitModuleBase * high, double control);
        CImplicitBlend(CImplicitModuleBase * low, double high, double control);
        CImplicitBlend(double low, CImplicitModuleBase * high, CImplicitModuleBase * control);
        CImplicitBlend(CImplicitModuleBase * low, double high, CImplicitModuleBase * control);
        CImplicitBlend(CImplicitModuleBase * low, CImplicitModuleBase * high, double control);
        CImplicitBlend(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control);
        ~CImplicitBlend();

        void setLowSource(CImplicitModuleBase * b);
        void setHighSource(CImplicitModuleBase * b);
        void setControlSource(CImplicitModuleBase * b);
        void setLowSource(double v);
        void setHighSource(double v);
        void setControlSource(double v);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);
        protected:
        CScalarParameter m_low,m_high,m_control;

    };
};
#endif
