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
        CImplicitClamp(double source, double low, CImplicitModuleBase *  high);
        CImplicitClamp(double source, CImplicitModuleBase *  low, double high);
        CImplicitClamp(double source, CImplicitModuleBase *  low, CImplicitModuleBase *  high);
        CImplicitClamp(CImplicitModuleBase *  source, double low, double high);
        CImplicitClamp(CImplicitModuleBase *  source, double low, CImplicitModuleBase *  high);
        CImplicitClamp(CImplicitModuleBase *  source, CImplicitModuleBase *  low, double high);
        CImplicitClamp(CImplicitModuleBase *  source, CImplicitModuleBase *  low, CImplicitModuleBase *  high);

        ~CImplicitClamp();

        void setRange(double low, double high);
        void setRange(double low, CImplicitModuleBase * high);
        void setRange(CImplicitModuleBase * low, double high);
        void setRange(CImplicitModuleBase * low, CImplicitModuleBase * high);

        void setSource(double b);
        void setSource(CImplicitModuleBase * b);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        //CImplicitModuleBase * m_source;
        //double m_low, m_high;
        CScalarParameter m_source, m_low, m_high;
    };
};
#endif
