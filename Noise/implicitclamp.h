#ifndef IMPLICIT_CLAMP_H
#define IMPLICIT_CLAMP_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitClamp : public CImplicitModuleBase
    {
        public:
        CImplicitClamp();
        CImplicitClamp(double source, double low, double high);
        CImplicitClamp(double source, double low, std::shared_ptr<CImplicitModuleBase>  high);
        CImplicitClamp(double source, std::shared_ptr<CImplicitModuleBase>  low, double high);
        CImplicitClamp(double source, std::shared_ptr<CImplicitModuleBase>  low, std::shared_ptr<CImplicitModuleBase>  high);
        CImplicitClamp(std::shared_ptr<CImplicitModuleBase>  source, double low, double high);
        CImplicitClamp(std::shared_ptr<CImplicitModuleBase>  source, double low, std::shared_ptr<CImplicitModuleBase>  high);
        CImplicitClamp(std::shared_ptr<CImplicitModuleBase>  source, std::shared_ptr<CImplicitModuleBase>  low, double high);
        CImplicitClamp(std::shared_ptr<CImplicitModuleBase>  source, std::shared_ptr<CImplicitModuleBase>  low, std::shared_ptr<CImplicitModuleBase>  high);

        ~CImplicitClamp();

        void setRange(double low, double high);
        void setRange(double low, std::shared_ptr<CImplicitModuleBase> high);
        void setRange(std::shared_ptr<CImplicitModuleBase> low, double high);
        void setRange(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high);

        void setSource(double b);
        void setSource(std::shared_ptr<CImplicitModuleBase> b);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        //std::shared_ptr<CImplicitModuleBase> m_source;
        //double m_low, m_high;
        CScalarParameter m_source, m_low, m_high;
    };
};
#endif
