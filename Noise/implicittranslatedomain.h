#ifndef IMPLICIT_TRANSLATE_DOMAIN_H
#define IMPLICIT_TRANSLATE_DOMAIN_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitTranslateDomain : public CImplicitModuleBase
    {
        public:
        CImplicitTranslateDomain();
        CImplicitTranslateDomain(double src, double tx, double ty, double tz);
        CImplicitTranslateDomain(double src, double tx, double ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(double src, double tx, CImplicitModuleBase * ty, double tz);
        CImplicitTranslateDomain(double src, double tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(double src, CImplicitModuleBase * tx, double ty, double tz);
        CImplicitTranslateDomain(double src, CImplicitModuleBase * tx, double ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(double src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, double tz);
        CImplicitTranslateDomain(double src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, double tx, double ty, double tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, double tx, double ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, double tx, CImplicitModuleBase * ty, double tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, double tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, double ty, double tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, double ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, double tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz);

        ~CImplicitTranslateDomain();

        void setXAxisSource(CImplicitModuleBase * m);
        void setYAxisSource(CImplicitModuleBase * m);
        void setZAxisSource(CImplicitModuleBase * m);
        void setWAxisSource(CImplicitModuleBase * m);
        void setUAxisSource(CImplicitModuleBase * m);
        void setVAxisSource(CImplicitModuleBase * m);

        void setXAxisSource(double v);
        void setYAxisSource(double v);
        void setZAxisSource(double v);
        void setWAxisSource(double v);
        void setUAxisSource(double v);
        void setVAxisSource(double v);

        void setSource(CImplicitModuleBase * m);
        void setSource(double v);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        CScalarParameter m_source, m_ax, m_ay, m_az, m_aw, m_au, m_av;
    };
};

#endif
