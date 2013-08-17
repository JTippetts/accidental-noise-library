#include "rgbacomposechannels.h"
#include "hsv.h"

namespace anl
{
    CRGBACompositeChannels::CRGBACompositeChannels() : m_c1(0.0), m_c2(0.0), m_c3(0.0), m_c4(1.0), m_mode(RGB){};

    CRGBACompositeChannels::CRGBACompositeChannels(ANLFloatType r, ANLFloatType g, ANLFloatType b, ANLFloatType a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(ANLFloatType r, ANLFloatType g, ANLFloatType b, CImplicitModuleBase * a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(ANLFloatType r, ANLFloatType g, CImplicitModuleBase * b, ANLFloatType a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(ANLFloatType r, ANLFloatType g, CImplicitModuleBase * b, CImplicitModuleBase * a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(ANLFloatType r, CImplicitModuleBase * g, ANLFloatType b, ANLFloatType a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(ANLFloatType r, CImplicitModuleBase * g, ANLFloatType b, CImplicitModuleBase * a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(ANLFloatType r, CImplicitModuleBase * g, CImplicitModuleBase * b, ANLFloatType a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(ANLFloatType r, CImplicitModuleBase * g, CImplicitModuleBase * b, CImplicitModuleBase * a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(CImplicitModuleBase * r, ANLFloatType g, ANLFloatType b, ANLFloatType a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(CImplicitModuleBase * r, ANLFloatType g, ANLFloatType b, CImplicitModuleBase * a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(CImplicitModuleBase * r, ANLFloatType g, CImplicitModuleBase * b, ANLFloatType a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(CImplicitModuleBase * r, ANLFloatType g, CImplicitModuleBase * b, CImplicitModuleBase * a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(CImplicitModuleBase * r, CImplicitModuleBase * g, ANLFloatType b, ANLFloatType a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(CImplicitModuleBase * r, CImplicitModuleBase * g, ANLFloatType b, CImplicitModuleBase * a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(CImplicitModuleBase * r, CImplicitModuleBase * g, CImplicitModuleBase * b, ANLFloatType a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}

    CRGBACompositeChannels::CRGBACompositeChannels(CImplicitModuleBase * r, CImplicitModuleBase * g, CImplicitModuleBase * b, CImplicitModuleBase * a, int mode) :
        CRGBAModuleBase(), m_c1(r), m_c2(g), m_c3(b), m_c4(a), m_mode(mode){}



    CRGBACompositeChannels::~CRGBACompositeChannels(){}

    void CRGBACompositeChannels::setRedSource(CImplicitModuleBase * m)
    {
        m_c1.set(m);
    }
    void CRGBACompositeChannels::setGreenSource(CImplicitModuleBase * m)
    {
        m_c2.set(m);
    }
    void CRGBACompositeChannels::setBlueSource(CImplicitModuleBase * m)
    {
        m_c3.set(m);
    }
    void CRGBACompositeChannels::setHueSource(CImplicitModuleBase * m)
    {
        m_c1.set(m);
    }
    void CRGBACompositeChannels::setSatSource(CImplicitModuleBase * m)
    {
        m_c2.set(m);
    }
    void CRGBACompositeChannels::setValSource(CImplicitModuleBase * m)
    {
        m_c3.set(m);
    }
    void CRGBACompositeChannels::setAlphaSource(CImplicitModuleBase * m)
    {
        m_c4.set(m);
    }
    void CRGBACompositeChannels::setRedSource(ANLFloatType r)
    {
        m_c1.set(r);
    }
    void CRGBACompositeChannels::setGreenSource(ANLFloatType g)
    {
        m_c2.set(g);
    }
    void CRGBACompositeChannels::setBlueSource(ANLFloatType b)
    {
        m_c3.set(b);
    }
    void CRGBACompositeChannels::setAlphaSource(ANLFloatType a)
    {
        m_c4.set(a);
    }
    void CRGBACompositeChannels::setHueSource(ANLFloatType h)
    {
        m_c1.set(h);
    }
    void CRGBACompositeChannels::setSatSource(ANLFloatType s)
    {
        m_c2.set(s);
    }
    void CRGBACompositeChannels::setValSource(ANLFloatType v)
    {
        m_c3.set(v);
    }

    SRGBA CRGBACompositeChannels::get(ANLFloatType x, ANLFloatType y)
    {
        float r=(float)m_c1.get(x,y);
        float g=(float)m_c2.get(x,y);
        float b=(float)m_c3.get(x,y);
        float a=(float)m_c4.get(x,y);
        if(m_mode==RGB) return SRGBA(r,g,b,a);
        else
        {
            SRGBA hsv(r,g,b,a);
            SRGBA rgb;
            HSVtoRGBA(hsv,rgb);
            return rgb;
        }
    }
    SRGBA CRGBACompositeChannels::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        float r=(float)m_c1.get(x,y,z);
        float g=(float)m_c2.get(x,y,z);
        float b=(float)m_c3.get(x,y,z);
        float a=(float)m_c4.get(x,y,z);
        if(m_mode==RGB) return SRGBA(r,g,b,a);
        else
        {
            SRGBA hsv(r,g,b,a);
            SRGBA rgb;
            HSVtoRGBA(hsv,rgb);
            return rgb;
        }
    }
    SRGBA CRGBACompositeChannels::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        float r=(float)m_c1.get(x,y,z,w);
        float g=(float)m_c2.get(x,y,z,w);
        float b=(float)m_c3.get(x,y,z,w);
        float a=(float)m_c4.get(x,y,z,w);
        if(m_mode==RGB) return SRGBA(r,g,b,a);
        else
        {
            SRGBA hsv(r,g,b,a);
            SRGBA rgb;
            HSVtoRGBA(hsv,rgb);
            return rgb;
        }
    }
    SRGBA CRGBACompositeChannels::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        float r=(float)m_c1.get(x,y,z,w,u,v);
        float g=(float)m_c2.get(x,y,z,w,u,v);
        float b=(float)m_c3.get(x,y,z,w,u,v);
        float a=(float)m_c4.get(x,y,z,w,u,v);
        if(m_mode==RGB) return SRGBA(r,g,b,a);
        else
        {
            SRGBA hsv(r,g,b,a);
            SRGBA rgb;
            HSVtoRGBA(hsv,rgb);
            return rgb;
        }
    }
};
