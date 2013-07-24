#include "implicitclamp.h"
#include "utility.h"

namespace anl
{
    CImplicitClamp::CImplicitClamp(double source, double low, double high) : CImplicitModuleBase(), m_source(source), m_low(low), m_high(high){}
    CImplicitClamp::CImplicitClamp(double source, double low, std::shared_ptr<CImplicitModuleBase>  high) : CImplicitModuleBase(), m_source(source), m_low(low), m_high(high){}
    CImplicitClamp::CImplicitClamp(double source, std::shared_ptr<CImplicitModuleBase>  low, double high) : CImplicitModuleBase(), m_source(source), m_low(low), m_high(high){}
    CImplicitClamp::CImplicitClamp(double source, std::shared_ptr<CImplicitModuleBase>  low, std::shared_ptr<CImplicitModuleBase>  high) : CImplicitModuleBase(), m_source(source), m_low(low), m_high(high){}
    CImplicitClamp::CImplicitClamp(std::shared_ptr<CImplicitModuleBase>  source, double low, double high) : CImplicitModuleBase(), m_source(source), m_low(low), m_high(high){}
    CImplicitClamp::CImplicitClamp(std::shared_ptr<CImplicitModuleBase>  source, double low, std::shared_ptr<CImplicitModuleBase>  high) : CImplicitModuleBase(), m_source(source), m_low(low), m_high(high){}
    CImplicitClamp::CImplicitClamp(std::shared_ptr<CImplicitModuleBase>  source, std::shared_ptr<CImplicitModuleBase>  low, double high) : CImplicitModuleBase(), m_source(source), m_low(low), m_high(high){}
    CImplicitClamp::CImplicitClamp(std::shared_ptr<CImplicitModuleBase>  source, std::shared_ptr<CImplicitModuleBase>  low, std::shared_ptr<CImplicitModuleBase>  high) : CImplicitModuleBase(), m_source(source), m_low(low), m_high(high){}
    CImplicitClamp::~CImplicitClamp(){}

    void CImplicitClamp::setRange(double low, double high)
    {
        m_low.set(low);
        m_high.set(high);
    }

    void CImplicitClamp::setRange(double low, std::shared_ptr<CImplicitModuleBase> high)
    {
        m_low.set(low);
        m_high.set(high);
    }

    void CImplicitClamp::setRange(std::shared_ptr<CImplicitModuleBase> low, double high)
    {
        m_low.set(low);
        m_high.set(high);
    }

    void CImplicitClamp::setRange(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high)
    {
        m_low.set(low);
        m_high.set(high);
    }


    void CImplicitClamp::setSource(double b)
    {
        m_source.set(b);
    }

    void CImplicitClamp::setSource(std::shared_ptr<CImplicitModuleBase> b)
    {
        m_source.set(b);
    }

    double CImplicitClamp::get(double x, double y)
    {
        return clamp(m_source.get(x,y),m_low.get(x,y),m_high.get(x,y));
    }

    double CImplicitClamp::get(double x, double y, double z)
    {
        return clamp(m_source.get(x,y,z),m_low.get(x,y,z),m_high.get(x,y,z));
    }

    double CImplicitClamp::get(double x, double y, double z, double w)
    {
        return clamp(m_source.get(x,y,z,w),m_low.get(x,y,z,w),m_high.get(x,y,z,w));
    }

    double CImplicitClamp::get(double x, double y, double z, double w, double u, double v)
    {
        return clamp(m_source.get(x,y,z,w,u,v),m_low.get(x,y,z,w,u,v),m_high.get(x,y,z,w,u,v));
    }
};
