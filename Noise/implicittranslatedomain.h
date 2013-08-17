#ifndef IMPLICIT_TRANSLATE_DOMAIN_H
#define IMPLICIT_TRANSLATE_DOMAIN_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitTranslateDomain : public CImplicitModuleBase
    {
        public:
        CImplicitTranslateDomain();
        CImplicitTranslateDomain(ANLFloatType src, ANLFloatType tx, ANLFloatType ty, ANLFloatType tz);
        CImplicitTranslateDomain(ANLFloatType src, ANLFloatType tx, ANLFloatType ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(ANLFloatType src, ANLFloatType tx, CImplicitModuleBase * ty, ANLFloatType tz);
        CImplicitTranslateDomain(ANLFloatType src, ANLFloatType tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(ANLFloatType src, CImplicitModuleBase * tx, ANLFloatType ty, ANLFloatType tz);
        CImplicitTranslateDomain(ANLFloatType src, CImplicitModuleBase * tx, ANLFloatType ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(ANLFloatType src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, ANLFloatType tz);
        CImplicitTranslateDomain(ANLFloatType src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, ANLFloatType tx, ANLFloatType ty, ANLFloatType tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, ANLFloatType tx, ANLFloatType ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, ANLFloatType tx, CImplicitModuleBase * ty, ANLFloatType tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, ANLFloatType tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, ANLFloatType ty, ANLFloatType tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, ANLFloatType ty, CImplicitModuleBase * tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, ANLFloatType tz);
        CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz);

        ~CImplicitTranslateDomain();

        void setXAxisSource(CImplicitModuleBase * m);
        void setYAxisSource(CImplicitModuleBase * m);
        void setZAxisSource(CImplicitModuleBase * m);
        void setWAxisSource(CImplicitModuleBase * m);
        void setUAxisSource(CImplicitModuleBase * m);
        void setVAxisSource(CImplicitModuleBase * m);

        void setXAxisSource(ANLFloatType v);
        void setYAxisSource(ANLFloatType v);
        void setZAxisSource(ANLFloatType v);
        void setWAxisSource(ANLFloatType v);
        void setUAxisSource(ANLFloatType v);
        void setVAxisSource(ANLFloatType v);

        void setSource(CImplicitModuleBase * m);
        void setSource(ANLFloatType v);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CScalarParameter m_source, m_ax, m_ay, m_az, m_aw, m_au, m_av;
    };
};

#endif
