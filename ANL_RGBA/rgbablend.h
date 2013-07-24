#ifndef RGBA_BLEND_H
#define RGBA_BLEND_H
#include "rgbamodulebase.h"
#include "../ANL_Noise/implicitmodulebase.h"

namespace anl
{
    class CRGBABlend : public CRGBAModuleBase
    {
        public:
        CRGBABlend();
        CRGBABlend(double control, SRGBA low, SRGBA high);
        CRGBABlend(double control, SRGBA low, std::shared_ptr<CRGBAModuleBase> high);
        CRGBABlend(double control, std::shared_ptr<CRGBAModuleBase> low, SRGBA high);
        CRGBABlend(double control, std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high);
        CRGBABlend(std::shared_ptr<CImplicitModuleBase> control, SRGBA low, SRGBA high);
        CRGBABlend(std::shared_ptr<CImplicitModuleBase> control, SRGBA low, std::shared_ptr<CRGBAModuleBase> high);
        CRGBABlend(std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CRGBAModuleBase> low, SRGBA high);
        CRGBABlend(std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high);

        ~CRGBABlend();

        void setLowSource(std::shared_ptr<CRGBAModuleBase> m);
        void setHighSource(std::shared_ptr<CRGBAModuleBase> m);
        void setLowSource(SRGBA c);
        void setHighSource(SRGBA c);
        void setControlSource(std::shared_ptr<CImplicitModuleBase> m);
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
