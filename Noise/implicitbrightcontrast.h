#ifndef IMPLICIT_BRIGHTCONTRAST_H
#define IMPLICIT_BRIGHTCONTRAST_H

#include "implicitmodulebase.h"
namespace anl
{
    class CImplicitBrightContrast : public CImplicitModuleBase
    {
        public:
        CImplicitBrightContrast();
        CImplicitBrightContrast(ANLFloatType s,ANLFloatType b,ANLFloatType t,ANLFloatType f);
        CImplicitBrightContrast(ANLFloatType s,ANLFloatType b,ANLFloatType t,CImplicitModuleBase *  f);
        CImplicitBrightContrast(ANLFloatType s,ANLFloatType b,CImplicitModuleBase *  t,ANLFloatType f);
        CImplicitBrightContrast(ANLFloatType s,ANLFloatType b,CImplicitModuleBase *  t,CImplicitModuleBase *  f);
        CImplicitBrightContrast(ANLFloatType s,CImplicitModuleBase *  b,ANLFloatType t,ANLFloatType f);
        CImplicitBrightContrast(ANLFloatType s,CImplicitModuleBase *  b,ANLFloatType t,CImplicitModuleBase *  f);
        CImplicitBrightContrast(ANLFloatType s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,ANLFloatType f);
        CImplicitBrightContrast(ANLFloatType s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,CImplicitModuleBase *  f);
        CImplicitBrightContrast(CImplicitModuleBase *  s,ANLFloatType b,ANLFloatType t,ANLFloatType f);
        CImplicitBrightContrast(CImplicitModuleBase *  s,ANLFloatType b,ANLFloatType t,CImplicitModuleBase *  f);
        CImplicitBrightContrast(CImplicitModuleBase *  s,ANLFloatType b,CImplicitModuleBase *  t,ANLFloatType f);
        CImplicitBrightContrast(CImplicitModuleBase *  s,ANLFloatType b,CImplicitModuleBase *  t,CImplicitModuleBase *  f);
        CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,ANLFloatType t,ANLFloatType f);
        CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,ANLFloatType t,CImplicitModuleBase *  f);
        CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,ANLFloatType f);
        CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,CImplicitModuleBase *  f);

        ~CImplicitBrightContrast();

        void setSource(CImplicitModuleBase * m);
        void setSource(ANLFloatType v);

        void setBrightness(ANLFloatType b);
        void setContrastThreshold(ANLFloatType t);
        void setContrastFactor(ANLFloatType t);
        void setBrightness(CImplicitModuleBase * m);
        void setContrastThreshold(CImplicitModuleBase * m);
        void setContrastFactor(CImplicitModuleBase * m);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
        protected:
        CScalarParameter m_source;
        CScalarParameter m_bright, m_threshold, m_factor;
    };
};

#endif
