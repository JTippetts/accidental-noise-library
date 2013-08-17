#include "implicitcache.h"

namespace anl
{
    CImplicitCache::CImplicitCache() : CImplicitModuleBase(), m_source(0.0) {}
    CImplicitCache::CImplicitCache(ANLFloatType v) : CImplicitModuleBase(), m_source(v) {}
    CImplicitCache::CImplicitCache(CImplicitModuleBase * v) : CImplicitModuleBase(), m_source(v) {}
    CImplicitCache::~CImplicitCache() {}
    void CImplicitCache::setSource(CImplicitModuleBase * m)
    {
        m_source.set(m);
    }
    void CImplicitCache::setSource(ANLFloatType v)
    {
        m_source.set(v);
    }
    ANLFloatType CImplicitCache::get(ANLFloatType x, ANLFloatType y)
    {
        if(!m_c2.valid || m_c2.x!=x || m_c2.y!=y)
        {
            m_c2.x=x;
            m_c2.y=y;
            m_c2.valid=true;
            m_c2.val=m_source.get(x,y);
        }
        return m_c2.val;
    }

    ANLFloatType CImplicitCache::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        if(!m_c3.valid || m_c3.x!=x || m_c3.y!=y || m_c3.z!=z)
        {
            m_c3.x=x;
            m_c3.y=y;
            m_c3.z=z;
            m_c3.valid=true;
            m_c3.val=m_source.get(x,y,z);
        }
        return m_c3.val;
    }

    ANLFloatType CImplicitCache::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        if(!m_c4.valid || m_c4.x!=x || m_c4.y!=y || m_c4.z!=z || m_c4.w!=w)
        {
            m_c4.x=x;
            m_c4.y=y;
            m_c4.z=z;
            m_c4.w=w;
            m_c4.valid=true;
            m_c4.val=m_source.get(x,y,z,w);
        }
        return m_c4.val;
    }

    ANLFloatType CImplicitCache::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        if(!m_c6.valid || m_c6.x!=x || m_c6.y!=y || m_c6.z!=z || m_c6.w!=w || m_c6.u!=u || m_c6.v!=v)
        {
            m_c6.x=x;
            m_c6.y=y;
            m_c6.z=z;
            m_c6.w=w;
            m_c6.u=u;
            m_c6.v=v;
            m_c6.valid=true;
            m_c6.val=m_source.get(x,y,z,w,u,v);
        }
        return m_c6.val;
    }
};
