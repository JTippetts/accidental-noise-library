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
        CImplicitTranslateDomain(double src, double tx, double ty, std::shared_ptr<CImplicitModuleBase> tz);
        CImplicitTranslateDomain(double src, double tx, std::shared_ptr<CImplicitModuleBase> ty, double tz);
        CImplicitTranslateDomain(double src, double tx, std::shared_ptr<CImplicitModuleBase> ty, std::shared_ptr<CImplicitModuleBase> tz);
        CImplicitTranslateDomain(double src, std::shared_ptr<CImplicitModuleBase> tx, double ty, double tz);
        CImplicitTranslateDomain(double src, std::shared_ptr<CImplicitModuleBase> tx, double ty, std::shared_ptr<CImplicitModuleBase> tz);
        CImplicitTranslateDomain(double src, std::shared_ptr<CImplicitModuleBase> tx, std::shared_ptr<CImplicitModuleBase> ty, double tz);
        CImplicitTranslateDomain(double src, std::shared_ptr<CImplicitModuleBase> tx, std::shared_ptr<CImplicitModuleBase> ty, std::shared_ptr<CImplicitModuleBase> tz);
        CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, double tx, double ty, double tz);
        CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, double tx, double ty, std::shared_ptr<CImplicitModuleBase> tz);
        CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, double tx, std::shared_ptr<CImplicitModuleBase> ty, double tz);
        CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, double tx, std::shared_ptr<CImplicitModuleBase> ty, std::shared_ptr<CImplicitModuleBase> tz);
        CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> tx, double ty, double tz);
        CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> tx, double ty, std::shared_ptr<CImplicitModuleBase> tz);
        CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> tx, std::shared_ptr<CImplicitModuleBase> ty, double tz);
        CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> tx, std::shared_ptr<CImplicitModuleBase> ty, std::shared_ptr<CImplicitModuleBase> tz);

        ~CImplicitTranslateDomain();

        void setXAxisSource(std::shared_ptr<CImplicitModuleBase> m);
        void setYAxisSource(std::shared_ptr<CImplicitModuleBase> m);
        void setZAxisSource(std::shared_ptr<CImplicitModuleBase> m);
        void setWAxisSource(std::shared_ptr<CImplicitModuleBase> m);
        void setUAxisSource(std::shared_ptr<CImplicitModuleBase> m);
        void setVAxisSource(std::shared_ptr<CImplicitModuleBase> m);

        void setXAxisSource(double v);
        void setYAxisSource(double v);
        void setZAxisSource(double v);
        void setWAxisSource(double v);
        void setUAxisSource(double v);
        void setVAxisSource(double v);

        void setSource(std::shared_ptr<CImplicitModuleBase> m);
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
