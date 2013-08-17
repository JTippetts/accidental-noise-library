#ifndef IMPLICIT_CACHE_H
#define IMPLICIT_CACHE_H
#include "implicitmodulebase.h"

namespace anl
{
    struct SCache
    {
        ANLFloatType x,y,z,w,u,v;
        ANLFloatType val;
        bool valid;

        SCache() : valid(false){}
    };
    class CImplicitCache : public CImplicitModuleBase
    {
        public:
        CImplicitCache();
        CImplicitCache(ANLFloatType v);
        CImplicitCache(CImplicitModuleBase * v);
        ~CImplicitCache();

        void setSource(CImplicitModuleBase * m);
        void setSource(ANLFloatType v);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        //CImplicitModuleBase * m_source;
        CScalarParameter m_source;
        SCache m_c2, m_c3, m_c4, m_c6;
    };
};

#endif
