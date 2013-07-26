#ifndef IMPLICIT_CACHE_H
#define IMPLICIT_CACHE_H
#include "implicitmodulebase.h"

namespace anl
{
    struct SCache
    {
        double x,y,z,w,u,v;
        double val;
        bool valid;

        SCache() : valid(false){}
    };
    class CImplicitCache : public CImplicitModuleBase
    {
        public:
        CImplicitCache();
        CImplicitCache(double v);
        CImplicitCache(std::shared_ptr<CImplicitModuleBase> v);
        ~CImplicitCache();

        void setSource(std::shared_ptr<CImplicitModuleBase> m);
        void setSource(double v);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        //std::shared_ptr<CImplicitModuleBase> m_source;
        CScalarParameter m_source;
        SCache m_c2, m_c3, m_c4, m_c6;
    };
};

#endif
