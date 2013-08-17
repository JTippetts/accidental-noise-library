#ifndef IMPLICIT_BLEND_H
#define IMPLICIT_BLEND_H
#include "implicitmodulebase.h"

namespace anl
{

    class CImplicitBlend : public CImplicitModuleBase
    {
    public:
        CImplicitBlend();
        CImplicitBlend(ANLFloatType low, ANLFloatType high, ANLFloatType control);
        CImplicitBlend(ANLFloatType low, ANLFloatType high, CImplicitModuleBase * control);
        CImplicitBlend(ANLFloatType low, CImplicitModuleBase * high, ANLFloatType control);
        CImplicitBlend(CImplicitModuleBase * low, ANLFloatType high, ANLFloatType control);
        CImplicitBlend(ANLFloatType low, CImplicitModuleBase * high, CImplicitModuleBase * control);
        CImplicitBlend(CImplicitModuleBase * low, ANLFloatType high, CImplicitModuleBase * control);
        CImplicitBlend(CImplicitModuleBase * low, CImplicitModuleBase * high, ANLFloatType control);
        CImplicitBlend(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control);
        ~CImplicitBlend();

        void setLowSource(CImplicitModuleBase * b);
        void setHighSource(CImplicitModuleBase * b);
        void setControlSource(CImplicitModuleBase * b);
        void setLowSource(ANLFloatType v);
        void setHighSource(ANLFloatType v);
        void setControlSource(ANLFloatType v);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
        protected:
        CScalarParameter m_low,m_high,m_control;

    };
};
#endif
