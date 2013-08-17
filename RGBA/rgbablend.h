#ifndef RGBA_BLEND_H
#define RGBA_BLEND_H
#include "rgbamodulebase.h"
#include "../Noise/implicitmodulebase.h"

namespace anl
{
    class CRGBABlend : public CRGBAModuleBase
    {
        public:
        CRGBABlend();
        CRGBABlend(ANLFloatType control, SRGBA low, SRGBA high);
        CRGBABlend(ANLFloatType control, SRGBA low, CRGBAModuleBase * high);
        CRGBABlend(ANLFloatType control, CRGBAModuleBase * low, SRGBA high);
        CRGBABlend(ANLFloatType control, CRGBAModuleBase * low, CRGBAModuleBase * high);
        CRGBABlend(CImplicitModuleBase * control, SRGBA low, SRGBA high);
        CRGBABlend(CImplicitModuleBase * control, SRGBA low, CRGBAModuleBase * high);
        CRGBABlend(CImplicitModuleBase * control, CRGBAModuleBase * low, SRGBA high);
        CRGBABlend(CImplicitModuleBase * control, CRGBAModuleBase * low, CRGBAModuleBase * high);

        ~CRGBABlend();

        void setLowSource(CRGBAModuleBase * m);
        void setHighSource(CRGBAModuleBase * m);
        void setLowSource(SRGBA c);
        void setHighSource(SRGBA c);
        void setControlSource(CImplicitModuleBase * m);
        void setControlSource(ANLFloatType v);

        SRGBA get(ANLFloatType x, ANLFloatType y);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CRGBAParameter m_low, m_high;
        CScalarParameter m_control;
    };
};

#endif
