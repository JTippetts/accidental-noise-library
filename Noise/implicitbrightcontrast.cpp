#include "implicitbrightcontrast.h"

namespace anl
{
    CImplicitBrightContrast::CImplicitBrightContrast() : CImplicitModuleBase(), m_source(0.0), m_bright(0.0), m_threshold(0.0), m_factor(1.0){}
    CImplicitBrightContrast::CImplicitBrightContrast(ANLFloatType s,ANLFloatType b,ANLFloatType t,ANLFloatType f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(ANLFloatType s,ANLFloatType b,ANLFloatType t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(ANLFloatType s,ANLFloatType b,CImplicitModuleBase *  t,ANLFloatType f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(ANLFloatType s,ANLFloatType b,CImplicitModuleBase *  t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(ANLFloatType s,CImplicitModuleBase *  b,ANLFloatType t,ANLFloatType f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(ANLFloatType s,CImplicitModuleBase *  b,ANLFloatType t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(ANLFloatType s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,ANLFloatType f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(ANLFloatType s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,ANLFloatType b,ANLFloatType t,ANLFloatType f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,ANLFloatType b,ANLFloatType t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,ANLFloatType b,CImplicitModuleBase *  t,ANLFloatType f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,ANLFloatType b,CImplicitModuleBase *  t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,ANLFloatType t,ANLFloatType f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,ANLFloatType t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,ANLFloatType f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::CImplicitBrightContrast(CImplicitModuleBase *  s,CImplicitModuleBase *  b,CImplicitModuleBase *  t,CImplicitModuleBase *  f) : CImplicitModuleBase(), m_source(s), m_bright(b), m_threshold(t), m_factor(f) {}
    CImplicitBrightContrast::~CImplicitBrightContrast(){}

    void CImplicitBrightContrast::setSource(CImplicitModuleBase * m){m_source.set(m);}
    void CImplicitBrightContrast::setSource(ANLFloatType v){m_source.set(v);}

    void CImplicitBrightContrast::setBrightness(ANLFloatType b){m_bright.set(b);}
    void CImplicitBrightContrast::setContrastThreshold(ANLFloatType t){m_threshold.set(t);}
    void CImplicitBrightContrast::setContrastFactor(ANLFloatType t){m_factor.set(t);}
    void CImplicitBrightContrast::setBrightness(CImplicitModuleBase * b){m_bright.set(b);}
    void CImplicitBrightContrast::setContrastThreshold(CImplicitModuleBase * t){m_threshold.set(t);}
    void CImplicitBrightContrast::setContrastFactor(CImplicitModuleBase * t){m_factor.set(t);}

    ANLFloatType CImplicitBrightContrast::get(ANLFloatType x, ANLFloatType y)
    {
        ANLFloatType v=m_source.get(x,y);
        // Apply brightness
        v+=m_bright.get(x,y);

        // Subtract threshold, scale by factor, add threshold
        ANLFloatType threshold=m_threshold.get(x,y);
        v-=threshold;
        v*=m_factor.get(x,y);
        v+=threshold;
        return v;
    }

    ANLFloatType CImplicitBrightContrast::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        ANLFloatType v=m_source.get(x,y,z);
        // Apply brightness
        v+=m_bright.get(x,y,z);

        // Subtract threshold, scale by factor, add threshold
        ANLFloatType threshold=m_threshold.get(x,y,z);
        v-=threshold;
        v*=m_factor.get(x,y,z);
        v+=threshold;
        return v;
    }

    ANLFloatType CImplicitBrightContrast::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        ANLFloatType v=m_source.get(x,y,z,w);
        // Apply brightness
        v+=m_bright.get(x,y,z,w);

        // Subtract threshold, scale by factor, add threshold
        ANLFloatType threshold=m_threshold.get(x,y,z,w);
        v-=threshold;
        v*=m_factor.get(x,y,z,w);
        v+=threshold;
        return v;
    }

    ANLFloatType CImplicitBrightContrast::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        ANLFloatType c=m_source.get(x,y,z,w,u,v);
        // Apply brightness
        c+=m_bright.get(x,y,z,w,u,v);

        // Subtract threshold, scale by factor, add threshold
        ANLFloatType threshold=m_threshold.get(x,y,z,w,u,v);
        c-=threshold;
        c*=m_factor.get(x,y,z,w,u,v);
        c+=threshold;
        return c;
    }
};
