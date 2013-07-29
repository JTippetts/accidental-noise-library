#include "implicitbrightcontrast.h"

namespace anl
{
    CImplicitBrightContrast::CImplicitBrightContrast() : CImplicitModuleBase(), m_source(0.0), m_bright(0.0), m_threshold(0.0), m_factor(1.0){}
    CImplicitBrightContrast::CImplicitBrightContrast(double s,double b,double t,double f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(double s,double b,double t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(double s,double b,CImplicitModuleBase *  t,double f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(double s,double b,CImplicitModuleBase *  t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(double s,CImplicitModuleBase *  b,double t,double f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(double s,CImplicitModuleBase *  b,double t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(double s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,double f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(double s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,double b,double t,double f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,double b,double t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,double b,CImplicitModuleBase *  t,double f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,double b,CImplicitModuleBase *  t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,double t,double f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,double t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,double f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::~CImplicitBrightContrast(){}

    void CImplicitBrightContrast::setSource(CImplicitModuleBase * m){m_source.set(m);}
    void CImplicitBrightContrast::setSource(double v){m_source.set(v);}

    void CImplicitBrightContrast::setBrightness(double b){m_bright.set(b);}
    void CImplicitBrightContrast::setContrastThreshold(double t){m_threshold.set(t);}
    void CImplicitBrightContrast::setContrastFactor(double t){m_factor.set(t);}
    void CImplicitBrightContrast::setBrightness(CImplicitModuleBase * b){m_bright.set(b);}
    void CImplicitBrightContrast::setContrastThreshold(CImplicitModuleBase * t){m_threshold.set(t);}
    void CImplicitBrightContrast::setContrastFactor(CImplicitModuleBase * t){m_factor.set(t);}

    double CImplicitBrightContrast::get(double x, double y)
    {
        double v=m_source.get(x,y);
        // Apply brightness
        v+=m_bright.get(x,y);

        // Subtract threshold, scale by factor, add threshold
        double threshold=m_threshold.get(x,y);
        v-=threshold;
        v*=m_factor.get(x,y);
        v+=threshold;
        return v;
    }

    double CImplicitBrightContrast::get(double x, double y, double z)
    {
        double v=m_source.get(x,y,z);
        // Apply brightness
        v+=m_bright.get(x,y,z);

        // Subtract threshold, scale by factor, add threshold
        double threshold=m_threshold.get(x,y,z);
        v-=threshold;
        v*=m_factor.get(x,y,z);
        v+=threshold;
        return v;
    }

    double CImplicitBrightContrast::get(double x, double y, double z, double w)
    {
        double v=m_source.get(x,y,z,w);
        // Apply brightness
        v+=m_bright.get(x,y,z,w);

        // Subtract threshold, scale by factor, add threshold
        double threshold=m_threshold.get(x,y,z,w);
        v-=threshold;
        v*=m_factor.get(x,y,z,w);
        v+=threshold;
        return v;
    }

    double CImplicitBrightContrast::get(double x, double y, double z, double w, double u, double v)
    {
        double c=m_source.get(x,y,z,w,u,v);
        // Apply brightness
        c+=m_bright.get(x,y,z,w,u,v);

        // Subtract threshold, scale by factor, add threshold
        double threshold=m_threshold.get(x,y,z,w,u,v);
        c-=threshold;
        c*=m_factor.get(x,y,z,w,u,v);
        c+=threshold;
        return c;
    }
};
