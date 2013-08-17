#include "rgbaselect.h"
#include "utility.h"

namespace anl
{
    CRGBASelect::CRGBASelect() : m_low(), m_high(), m_control(0.0), m_threshold(0.0), m_falloff(0.0){}
    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, CRGBAModuleBase * high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, CRGBAModuleBase * high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, CRGBAModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, CRGBAModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, SRGBA high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, SRGBA high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, SRGBA high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, SRGBA high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, SRGBA high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(CRGBAModuleBase * low, CRGBAModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}


    void CRGBASelect::setLowSource(CRGBAModuleBase * m)
    {
        m_low.set(m);
    }
    void CRGBASelect::setHighSource(CRGBAModuleBase * m)
    {
        m_high.set(m);
    }
    void CRGBASelect::setLowSource(SRGBA c)
    {
        m_low.set(c);
    }
    void CRGBASelect::setHighSource(SRGBA c)
    {
        m_high.set(c);
    }
    void CRGBASelect::setControlSource(CImplicitModuleBase * m)
    {
        m_control.set(m);
    }
    void CRGBASelect::setThreshold(CImplicitModuleBase * m)
    {
        m_threshold.set(m);
    }
    void CRGBASelect::setFalloff(CImplicitModuleBase * m)
    {
        m_falloff.set(m);
    }
    void CRGBASelect::setControlSource(ANLFloatType v)
    {
        m_control.set(v);
    }
    void CRGBASelect::setThreshold(ANLFloatType v)
    {
        m_threshold.set(v);
    }
    void CRGBASelect::setFalloff(ANLFloatType v)
    {
        m_falloff.set(v);
    }
    SRGBA CRGBASelect::get(ANLFloatType x, ANLFloatType y)
    {
        SRGBA s1=m_low.get(x,y);
        SRGBA s2=m_high.get(x,y);
        ANLFloatType control=m_control.get(x,y);
        ANLFloatType threshold=m_threshold.get(x,y);
        ANLFloatType falloff=m_falloff.get(x,y);

        if(falloff>0.0)
        {
            if(control<threshold-falloff)
            {
                return s1;
            }
            else if(control>threshold+falloff)
            {
                return s2;
            }
            else
            {
                ANLFloatType lower=threshold-falloff;
                ANLFloatType upper=threshold+falloff;
                ANLFloatType t=quintic_blend((control-lower)/(upper-lower));
                return SRGBA(
                    (float)(s1[0]+t*(s2[0]-s1[0])),
                    (float)(s1[1]+t*(s2[1]-s1[1])),
                    (float)(s1[2]+t*(s2[2]-s1[2])),
                    (float)(s1[3]+t*(s2[3]-s1[3])));
            }
        }
        else
        {
            if(control<threshold) return s1;
            else return s2;
        }
    }
    SRGBA CRGBASelect::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        SRGBA s1=m_low.get(x,y,z);
        SRGBA s2=m_high.get(x,y,z);
        ANLFloatType control=m_control.get(x,y,z);
        ANLFloatType threshold=m_threshold.get(x,y,z);
        ANLFloatType falloff=m_falloff.get(x,y,z);

        if(falloff>0.0)
        {
            if(control<threshold-falloff)
            {
                return s1;
            }
            else if(control>threshold+falloff)
            {
                return s2;
            }
            else
            {
                ANLFloatType lower=threshold-falloff;
                ANLFloatType upper=threshold+falloff;
                ANLFloatType t=quintic_blend((control-lower)/(upper-lower));
                return SRGBA(
                    (float)(s1[0]+t*(s2[0]-s1[0])),
                    (float)(s1[1]+t*(s2[1]-s1[1])),
                    (float)(s1[2]+t*(s2[2]-s1[2])),
                    (float)(s1[3]+t*(s2[3]-s1[3])));
            }
        }
        else
        {
            if(control<threshold) return s1;
            else return s2;
        }
    }

    SRGBA CRGBASelect::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        SRGBA s1=m_low.get(x,y,z,w);
        SRGBA s2=m_high.get(x,y,z,w);
        ANLFloatType control=m_control.get(x,y,z,w);
        ANLFloatType threshold=m_threshold.get(x,y,z,w);
        ANLFloatType falloff=m_falloff.get(x,y,z,w);

        if(falloff>0.0)
        {
            if(control<threshold-falloff)
            {
                return s1;
            }
            else if(control>threshold+falloff)
            {
                return s2;
            }
            else
            {
                ANLFloatType lower=threshold-falloff;
                ANLFloatType upper=threshold+falloff;
                ANLFloatType t=quintic_blend((control-lower)/(upper-lower));
                return SRGBA(
                    (float)(s1[0]+t*(s2[0]-s1[0])),
                    (float)(s1[1]+t*(s2[1]-s1[1])),
                    (float)(s1[2]+t*(s2[2]-s1[2])),
                    (float)(s1[3]+t*(s2[3]-s1[3])));
            }
        }
        else
        {
            if(control<threshold) return s1;
            else return s2;
        }
    }

    SRGBA CRGBASelect::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        SRGBA s1=m_low.get(x,y,z,w,u,v);
        SRGBA s2=m_high.get(x,y,z,w,u,v);
        ANLFloatType control=m_control.get(x,y,z,w,u,v);
        ANLFloatType threshold=m_threshold.get(x,y,z,w,u,v);
        ANLFloatType falloff=m_falloff.get(x,y,z,w,u,v);

        if(falloff>0.0)
        {
            if(control<threshold-falloff)
            {
                return s1;
            }
            else if(control>threshold+falloff)
            {
                return s2;
            }
            else
            {
                ANLFloatType lower=threshold-falloff;
                ANLFloatType upper=threshold+falloff;
                ANLFloatType t=quintic_blend((control-lower)/(upper-lower));
                return SRGBA(
                    (float)(s1[0]+t*(s2[0]-s1[0])),
                    (float)(s1[1]+t*(s2[1]-s1[1])),
                    (float)(s1[2]+t*(s2[2]-s1[2])),
                    (float)(s1[3]+t*(s2[3]-s1[3])));
            }
        }
        else
        {
            if(control<threshold) return s1;
            else return s2;
        }
    }
};
