#include "implicittranslatedomain.h"

namespace anl
{
    CImplicitTranslateDomain::CImplicitTranslateDomain() : CImplicitModuleBase(), m_source(0.0),
        m_ax(0.0), m_ay(0.0), m_az(0.0), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(ANLFloatType src, ANLFloatType tx, ANLFloatType ty, ANLFloatType tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(ANLFloatType src, ANLFloatType tx, ANLFloatType ty, CImplicitModuleBase * tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(ANLFloatType src, ANLFloatType tx, CImplicitModuleBase * ty, ANLFloatType tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(ANLFloatType src, ANLFloatType tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(ANLFloatType src, CImplicitModuleBase * tx, ANLFloatType ty, ANLFloatType tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(ANLFloatType src, CImplicitModuleBase * tx, ANLFloatType ty, CImplicitModuleBase * tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(ANLFloatType src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, ANLFloatType tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(ANLFloatType src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(CImplicitModuleBase * src, ANLFloatType tx, ANLFloatType ty, ANLFloatType tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(CImplicitModuleBase * src, ANLFloatType tx, ANLFloatType ty, CImplicitModuleBase * tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(CImplicitModuleBase * src, ANLFloatType tx, CImplicitModuleBase * ty, ANLFloatType tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(CImplicitModuleBase * src, ANLFloatType tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, ANLFloatType ty, ANLFloatType tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, ANLFloatType ty, CImplicitModuleBase * tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, ANLFloatType tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(CImplicitModuleBase * src, CImplicitModuleBase * tx, CImplicitModuleBase * ty, CImplicitModuleBase * tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}



    CImplicitTranslateDomain::~CImplicitTranslateDomain(){}

    void CImplicitTranslateDomain::setXAxisSource(CImplicitModuleBase * m)
    {
        m_ax.set(m);
    }
    void CImplicitTranslateDomain::setYAxisSource(CImplicitModuleBase * m)
    {
        m_ay.set(m);
    }
    void CImplicitTranslateDomain::setZAxisSource(CImplicitModuleBase * m)
    {
        m_az.set(m);
    }
    void CImplicitTranslateDomain::setWAxisSource(CImplicitModuleBase * m)
    {
        m_aw.set(m);
    }
    void CImplicitTranslateDomain::setUAxisSource(CImplicitModuleBase * m)
    {
        m_au.set(m);
    }
    void CImplicitTranslateDomain::setVAxisSource(CImplicitModuleBase * m)
    {
        m_av.set(m);
    }
    void CImplicitTranslateDomain::setXAxisSource(ANLFloatType v)
    {
        m_ax.set(v);
    }
    void CImplicitTranslateDomain::setYAxisSource(ANLFloatType v)
    {
        m_ay.set(v);
    }
    void CImplicitTranslateDomain::setZAxisSource(ANLFloatType v)
    {
        m_az.set(v);
    }
    void CImplicitTranslateDomain::setWAxisSource(ANLFloatType v)
    {
        m_aw.set(v);
    }
    void CImplicitTranslateDomain::setUAxisSource(ANLFloatType v)
    {
        m_au.set(v);
    }
    void CImplicitTranslateDomain::setVAxisSource(ANLFloatType v)
    {
        m_av.set(v);
    }
    void CImplicitTranslateDomain::setSource(CImplicitModuleBase * m)
    {
        m_source.set(m);
    }
    void CImplicitTranslateDomain::setSource(ANLFloatType v)
    {
        m_source.set(v);
    }

    ANLFloatType CImplicitTranslateDomain::get(ANLFloatType x, ANLFloatType y)
    {
        return m_source.get(x+m_ax.get(x,y), y+m_ay.get(x,y));
    }
    ANLFloatType CImplicitTranslateDomain::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        return m_source.get(x+m_ax.get(x,y,z), y+m_ay.get(x,y,z), z+m_az.get(x,y,z));
    }
    ANLFloatType CImplicitTranslateDomain::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        return m_source.get(x+m_ax.get(x,y,z,w), y+m_ay.get(x,y,z,w), z+m_az.get(x,y,z,w), w+m_aw.get(x,y,z,w));
    }
    ANLFloatType CImplicitTranslateDomain::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        return m_source.get(x+m_ax.get(x,y,z,w,u,v), y+m_ay.get(x,y,z,w,u,v), z+m_az.get(x,y,z,w,u,v),
            w+m_aw.get(x,y,z,w,u,v), u+m_au.get(x,y,z,w,u,v), v+m_av.get(x,y,z,w,u,v));
    }
};
