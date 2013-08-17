#ifndef IMPLICIT_TIERS_H
#define IMPLICIT_TIERS_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitTiers : public CImplicitModuleBase
    {
        public:
        CImplicitTiers();
        CImplicitTiers(ANLFloatType src, int numtiers, bool smooth);
        CImplicitTiers(CImplicitModuleBase * src, int numtiers, bool smooth);
        ~CImplicitTiers();

        void setSource(ANLFloatType v);
        void setSource(CImplicitModuleBase * m);
        void setNumTiers(int numtiers);
        void setSmooth(bool smooth);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CScalarParameter m_source;
        int m_numtiers;
        bool m_smooth;
    };
};

#endif
