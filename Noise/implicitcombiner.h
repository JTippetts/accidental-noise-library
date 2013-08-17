#ifndef IMPLICIT_COMBINER_H
#define IMPLICIT_COMBINER_H
#include "implicitmodulebase.h"

namespace anl
{
    enum ECombinerTypes
    {
        ADD,
        MULT,
        MAX,
        MIN,
        AVG
    };

    class CImplicitCombiner : public CImplicitModuleBase
    {
        public:
        CImplicitCombiner(unsigned int type);
        void setType(unsigned int type);
        void clearAllSources();
        void setSource(int which, CImplicitModuleBase * b);
        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CImplicitModuleBase * m_sources[MaxSources];
        unsigned int m_type;

        ANLFloatType Add_get(ANLFloatType x, ANLFloatType y);
        ANLFloatType Add_get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType Add_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType Add_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
        ANLFloatType Mult_get(ANLFloatType x, ANLFloatType y);
        ANLFloatType Mult_get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType Mult_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType Mult_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
        ANLFloatType Min_get(ANLFloatType x, ANLFloatType y);
        ANLFloatType Min_get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType Min_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType Min_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
        ANLFloatType Max_get(ANLFloatType x, ANLFloatType y);
        ANLFloatType Max_get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType Max_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType Max_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
        ANLFloatType Avg_get(ANLFloatType x, ANLFloatType y);
        ANLFloatType Avg_get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType Avg_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType Avg_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
    };
};

#endif
