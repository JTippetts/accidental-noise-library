#ifndef RGBA_SELECT_H
#define RGBA_SELECT_H
#include "rgbamodulebase.h"
#include "../Noise/implicitmodulebase.h"

namespace anl
{
    class CRGBASelect : public CRGBAModuleBase
    {
        public:
        CRGBASelect();
        CRGBASelect(SRGBA low, SRGBA high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CRGBASelect(SRGBA low, SRGBA high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, SRGBA high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff);
        CRGBASelect(SRGBA low, SRGBA high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff);
        CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff);
        CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);

        CRGBASelect(CRGBAModuleBase * low, SRGBA high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);

        void setLowSource(CRGBAModuleBase * m);
        void setHighSource(CRGBAModuleBase * m);
        void setLowSource(SRGBA c);
        void setHighSource(SRGBA c);
        void setControlSource(CImplicitModuleBase * m);
        void setThreshold(CImplicitModuleBase * m);
        void setFalloff(CImplicitModuleBase * m);
        void setControlSource(ANLFloatType v);
        void setThreshold(ANLFloatType v);
        void setFalloff(ANLFloatType v);

        SRGBA get(ANLFloatType x, ANLFloatType y);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CRGBAParameter m_low, m_high;
        CScalarParameter m_control, m_threshold, m_falloff;
    };
};

#endif
