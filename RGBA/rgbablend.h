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
        CRGBABlend(double control, SRGBA low, SRGBA high);
        CRGBABlend(double control, SRGBA low, CRGBAModuleBase * high);
        CRGBABlend(double control, CRGBAModuleBase * low, SRGBA high);
        CRGBABlend(double control, CRGBAModuleBase * low, CRGBAModuleBase * high);
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
        void setControlSource(double v);

        SRGBA get(double x, double y);
        SRGBA get(double x, double y, double z);
        SRGBA get(double x, double y, double z, double w);
        SRGBA get(double x, double y, double z, double w, double u, double v);

        protected:
        CRGBAParameter m_low, m_high;
        CScalarParameter m_control;
    };
};

#endif
