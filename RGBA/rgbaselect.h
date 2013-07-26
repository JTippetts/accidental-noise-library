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
        CRGBASelect(SRGBA low, SRGBA high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(SRGBA low, SRGBA high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
        CRGBASelect(SRGBA low, SRGBA high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(SRGBA low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff);
        CRGBASelect(SRGBA low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(SRGBA low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
        CRGBASelect(SRGBA low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, double control, double threshold, double falloff);
        CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
        CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff);
        CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
        CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);

        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, double control, double threshold, double falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, double control, double threshold, double falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
        CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);

        void setLowSource(std::shared_ptr<CRGBAModuleBase> m);
        void setHighSource(std::shared_ptr<CRGBAModuleBase> m);
        void setLowSource(SRGBA c);
        void setHighSource(SRGBA c);
        void setControlSource(std::shared_ptr<CImplicitModuleBase> m);
        void setThreshold(std::shared_ptr<CImplicitModuleBase> m);
        void setFalloff(std::shared_ptr<CImplicitModuleBase> m);
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
