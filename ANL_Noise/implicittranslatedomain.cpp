#include "implicittranslatedomain.h"

namespace anl
{
    CImplicitTranslateDomain::CImplicitTranslateDomain() : CImplicitModuleBase(), m_source(0.0),
        m_ax(0.0), m_ay(0.0), m_az(0.0), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(double src, double tx, double ty, double tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(double src, double tx, double ty, std::shared_ptr<CImplicitModuleBase> tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(double src, double tx, std::shared_ptr<CImplicitModuleBase> ty, double tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(double src, double tx, std::shared_ptr<CImplicitModuleBase> ty, std::shared_ptr<CImplicitModuleBase> tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(double src, std::shared_ptr<CImplicitModuleBase> tx, double ty, double tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(double src, std::shared_ptr<CImplicitModuleBase> tx, double ty, std::shared_ptr<CImplicitModuleBase> tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(double src, std::shared_ptr<CImplicitModuleBase> tx, std::shared_ptr<CImplicitModuleBase> ty, double tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(double src, std::shared_ptr<CImplicitModuleBase> tx, std::shared_ptr<CImplicitModuleBase> ty, std::shared_ptr<CImplicitModuleBase> tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, double tx, double ty, double tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, double tx, double ty, std::shared_ptr<CImplicitModuleBase> tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, double tx, std::shared_ptr<CImplicitModuleBase> ty, double tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, double tx, std::shared_ptr<CImplicitModuleBase> ty, std::shared_ptr<CImplicitModuleBase> tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> tx, double ty, double tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> tx, double ty, std::shared_ptr<CImplicitModuleBase> tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> tx, std::shared_ptr<CImplicitModuleBase> ty, double tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}

    CImplicitTranslateDomain::CImplicitTranslateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> tx, std::shared_ptr<CImplicitModuleBase> ty, std::shared_ptr<CImplicitModuleBase> tz) :
        CImplicitModuleBase(), m_source(src), m_ax(tx), m_ay(ty), m_az(tz), m_aw(0.0), m_au(0.0), m_av(0.0){}



    CImplicitTranslateDomain::~CImplicitTranslateDomain(){}

    void CImplicitTranslateDomain::setXAxisSource(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_ax.set(m);
    }
    void CImplicitTranslateDomain::setYAxisSource(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_ay.set(m);
    }
    void CImplicitTranslateDomain::setZAxisSource(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_az.set(m);
    }
    void CImplicitTranslateDomain::setWAxisSource(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_aw.set(m);
    }
    void CImplicitTranslateDomain::setUAxisSource(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_au.set(m);
    }
    void CImplicitTranslateDomain::setVAxisSource(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_av.set(m);
    }
    void CImplicitTranslateDomain::setXAxisSource(double v)
    {
        m_ax.set(v);
    }
    void CImplicitTranslateDomain::setYAxisSource(double v)
    {
        m_ay.set(v);
    }
    void CImplicitTranslateDomain::setZAxisSource(double v)
    {
        m_az.set(v);
    }
    void CImplicitTranslateDomain::setWAxisSource(double v)
    {
        m_aw.set(v);
    }
    void CImplicitTranslateDomain::setUAxisSource(double v)
    {
        m_au.set(v);
    }
    void CImplicitTranslateDomain::setVAxisSource(double v)
    {
        m_av.set(v);
    }
    void CImplicitTranslateDomain::setSource(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_source.set(m);
    }
    void CImplicitTranslateDomain::setSource(double v)
    {
        m_source.set(v);
    }

    double CImplicitTranslateDomain::get(double x, double y)
    {
        return m_source.get(x+m_ax.get(x,y), y+m_ay.get(x,y));
    }
    double CImplicitTranslateDomain::get(double x, double y, double z)
    {
        return m_source.get(x+m_ax.get(x,y,z), y+m_ay.get(x,y,z), z+m_az.get(x,y,z));
    }
    double CImplicitTranslateDomain::get(double x, double y, double z, double w)
    {
        return m_source.get(x+m_ax.get(x,y,z,w), y+m_ay.get(x,y,z,w), z+m_az.get(x,y,z,w), w+m_aw.get(x,y,z,w));
    }
    double CImplicitTranslateDomain::get(double x, double y, double z, double w, double u, double v)
    {
        return m_source.get(x+m_ax.get(x,y,z,w,u,v), y+m_ay.get(x,y,z,w,u,v), z+m_az.get(x,y,z,w,u,v),
            w+m_aw.get(x,y,z,w,u,v), u+m_au.get(x,y,z,w,u,v), v+m_av.get(x,y,z,w,u,v));
    }
};
