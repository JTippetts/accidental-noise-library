#include "implicitscaledomain.h"

namespace anl
{
    CImplicitScaleDomain::CImplicitScaleDomain() : CImplicitModuleBase(), m_source(0.0),m_sx(1.0),m_sy(1.0),m_sz(1.0),m_sw(1.0),m_su(1.0),m_sv(1.0){}

    CImplicitScaleDomain::CImplicitScaleDomain(ANLFloatType src, ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(ANLFloatType src, ANLFloatType x, ANLFloatType y, CImplicitModuleBase * z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(ANLFloatType src, ANLFloatType x, CImplicitModuleBase * y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(ANLFloatType src, ANLFloatType x, CImplicitModuleBase * y, CImplicitModuleBase * z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(ANLFloatType src, CImplicitModuleBase * x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(ANLFloatType src, CImplicitModuleBase * x, ANLFloatType y, CImplicitModuleBase * z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(ANLFloatType src, CImplicitModuleBase * x, CImplicitModuleBase * y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(ANLFloatType src, CImplicitModuleBase * x, CImplicitModuleBase * y, CImplicitModuleBase * z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(CImplicitModuleBase * src, ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(CImplicitModuleBase * src, ANLFloatType x, ANLFloatType y, CImplicitModuleBase * z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(CImplicitModuleBase * src, ANLFloatType x, CImplicitModuleBase * y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(CImplicitModuleBase * src, ANLFloatType x, CImplicitModuleBase * y, CImplicitModuleBase * z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, ANLFloatType y, CImplicitModuleBase * z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, CImplicitModuleBase * y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}

    CImplicitScaleDomain::CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, CImplicitModuleBase * y, CImplicitModuleBase * z, ANLFloatType w, ANLFloatType u, ANLFloatType v):
        CImplicitModuleBase(), m_source(src), m_sx(x), m_sy(y), m_sz(z), m_sw(1), m_su(u), m_sv(v){}



    void CImplicitScaleDomain::setScale(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        m_sx.set(x); m_sy.set(y); m_sz.set(z); m_sw.set(w); m_su.set(u); m_sv.set(v);
    }

    void CImplicitScaleDomain::setXScale(ANLFloatType x){m_sx.set(x);}
    void CImplicitScaleDomain::setYScale(ANLFloatType x){m_sy.set(x);}
    void CImplicitScaleDomain::setZScale(ANLFloatType x){m_sz.set(x);}
    void CImplicitScaleDomain::setWScale(ANLFloatType x){m_sw.set(x);}
    void CImplicitScaleDomain::setUScale(ANLFloatType x){m_su.set(x);}
    void CImplicitScaleDomain::setVScale(ANLFloatType x){m_sv.set(x);}
    void CImplicitScaleDomain::setXScale(CImplicitModuleBase * x){m_sx.set(x);}
    void CImplicitScaleDomain::setYScale(CImplicitModuleBase * y){m_sy.set(y);}
    void CImplicitScaleDomain::setZScale(CImplicitModuleBase * z){m_sz.set(z);}
    void CImplicitScaleDomain::setWScale(CImplicitModuleBase * w){m_sw.set(w);}
    void CImplicitScaleDomain::setUScale(CImplicitModuleBase * u){m_su.set(u);}
    void CImplicitScaleDomain::setVScale(CImplicitModuleBase * v){m_sv.set(v);}


    void CImplicitScaleDomain::setSource(CImplicitModuleBase * m)
    {
        m_source.set(m);
    }

    void CImplicitScaleDomain::setSource(ANLFloatType v)
    {
        m_source.set(v);
    }

    ANLFloatType CImplicitScaleDomain::get(ANLFloatType x, ANLFloatType y)
    {
        return m_source.get(x*m_sx.get(x,y), y*m_sy.get(x,y));
    }

    ANLFloatType CImplicitScaleDomain::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        return m_source.get(x*m_sx.get(x,y,z), y*m_sy.get(x,y,z), z*m_sz.get(x,y,z));
    }

    ANLFloatType CImplicitScaleDomain::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        return m_source.get(x*m_sx.get(x,y,z,w), y*m_sy.get(x,y,z,w), z*m_sz.get(x,y,z,w), w*m_sw.get(x,y,z,w));
    }

    ANLFloatType CImplicitScaleDomain::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        return m_source.get(x*m_sx.get(x,y,z,w,u,v), y*m_sy.get(x,y,z,w,u,v), z*m_sz.get(x,y,z,w,u,v),
            w*m_sw.get(x,y,z,w,u,v), u*m_su.get(x,y,z,w,u,v), v*m_sv.get(x,y,z,w,u,v));
    }
};
