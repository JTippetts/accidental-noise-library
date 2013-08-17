#ifndef IMPLICIT_CLAMP_H
#define IMPLICIT_CLAMP_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitClamp : public CImplicitModuleBase
    {
        public:
        CImplicitClamp();
        CImplicitClamp(ANLFloatType source, ANLFloatType low, ANLFloatType high);
        CImplicitClamp(ANLFloatType source, ANLFloatType low, CImplicitModuleBase *  high);
        CImplicitClamp(ANLFloatType source, CImplicitModuleBase *  low, ANLFloatType high);
        CImplicitClamp(ANLFloatType source, CImplicitModuleBase *  low, CImplicitModuleBase *  high);
        CImplicitClamp(CImplicitModuleBase *  source, ANLFloatType low, ANLFloatType high);
        CImplicitClamp(CImplicitModuleBase *  source, ANLFloatType low, CImplicitModuleBase *  high);
        CImplicitClamp(CImplicitModuleBase *  source, CImplicitModuleBase *  low, ANLFloatType high);
        CImplicitClamp(CImplicitModuleBase *  source, CImplicitModuleBase *  low, CImplicitModuleBase *  high);

        ~CImplicitClamp();

        void setRange(ANLFloatType low, ANLFloatType high);
        void setRange(ANLFloatType low, CImplicitModuleBase * high);
        void setRange(CImplicitModuleBase * low, ANLFloatType high);
        void setRange(CImplicitModuleBase * low, CImplicitModuleBase * high);

        void setSource(ANLFloatType b);
        void setSource(CImplicitModuleBase * b);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        //CImplicitModuleBase * m_source;
        //ANLFloatType m_low, m_high;
        CScalarParameter m_source, m_low, m_high;
    };
};
#endif
