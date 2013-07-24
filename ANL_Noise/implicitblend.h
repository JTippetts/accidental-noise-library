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
        CImplicitBlend(double low, double high, std::shared_ptr<CImplicitModuleBase> control);
        CImplicitBlend(double low, std::shared_ptr<CImplicitModuleBase> high, double control);
        CImplicitBlend(std::shared_ptr<CImplicitModuleBase> low, double high, double control);
        CImplicitBlend(double low, std::shared_ptr<CImplicitModuleBase> high, std::shared_ptr<CImplicitModuleBase> control);
        CImplicitBlend(std::shared_ptr<CImplicitModuleBase> low, double high, std::shared_ptr<CImplicitModuleBase> control);
        CImplicitBlend(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high, double control);
        CImplicitBlend(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high, std::shared_ptr<CImplicitModuleBase> control);
        ~CImplicitBlend();

        void setLowSource(std::shared_ptr<CImplicitModuleBase> b);
        void setHighSource(std::shared_ptr<CImplicitModuleBase> b);
        void setControlSource(std::shared_ptr<CImplicitModuleBase> b);
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
