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
        CRGBASelect(SRGBA low, SRGBA high, double control, double threshold, double falloff);
        CRGBASelect(SRGBA low, SRGBA high, double control, double threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, SRGBA high, double control, CImplicitModuleBase * threshold, double falloff);
        CRGBASelect(SRGBA low, SRGBA high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, double threshold, double falloff);
        CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff);
        CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, double control, double threshold, double falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, double control, double threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, double control, CImplicitModuleBase * threshold, double falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, double threshold, double falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff);
        CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);

        CRGBASelect(CRGBAModuleBase * low, SRGBA high, double control, double threshold, double falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, double control, double threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, double control, CImplicitModuleBase * threshold, double falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, double threshold, double falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff);
        CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, double control, double threshold, double falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, double control, double threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, double control, CImplicitModuleBase * threshold, double falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, double threshold, double falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff);
        CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);

        void setLowSource(CRGBAModuleBase * m);
        void setHighSource(CRGBAModuleBase * m);
        void setLowSource(SRGBA c);
        void setHighSource(SRGBA c);
        void setControlSource(CImplicitModuleBase * m);
        void setThreshold(CImplicitModuleBase * m);
        void setFalloff(CImplicitModuleBase * m);
        void setControlSource(double v);
        void setThreshold(double v);
        void setFalloff(double v);

        SRGBA get(double x, double y);
        SRGBA get(double x, double y, double z);
        SRGBA get(double x, double y, double z, double w);
        SRGBA get(double x, double y, double z, double w, double u, double v);

        protected:
        CRGBAParameter m_low, m_high;
        CScalarParameter m_control, m_threshold, m_falloff;
    };
};

#endif
