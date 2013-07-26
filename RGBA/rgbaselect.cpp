#include "rgbaselect.h"
#include "utility.h"

namespace anl
{
    CRGBASelect::CRGBASelect() : m_low(), m_high(), m_control(0.0), m_threshold(0.0), m_falloff(0.0){}
    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, double control, double threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, double control, double threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(SRGBA low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, double control, double threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, SRGBA high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, double control, double threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}

    CRGBASelect::CRGBASelect(std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff) :
        CRGBAModuleBase(), m_low(low), m_high(high), m_control(control), m_threshold(threshold), m_falloff(falloff){}


    void CRGBASelect::setLowSource(std::shared_ptr<CRGBAModuleBase> m)
    {
        m_low.set(m);
    }
    void CRGBASelect::setHighSource(std::shared_ptr<CRGBAModuleBase> m)
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
    void CRGBASelect::setControlSource(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_control.set(m);
    }
    void CRGBASelect::setThreshold(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_threshold.set(m);
    }
    void CRGBASelect::setFalloff(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_falloff.set(m);
    }
    void CRGBASelect::setControlSource(double v)
    {
        m_control.set(v);
    }
    void CRGBASelect::setThreshold(double v)
    {
        m_threshold.set(v);
    }
    void CRGBASelect::setFalloff(double v)
    {
        m_falloff.set(v);
    }
    SRGBA CRGBASelect::get(double x, double y)
    {
        SRGBA s1=m_low.get(x,y);
        SRGBA s2=m_high.get(x,y);
        double control=m_control.get(x,y);
        double threshold=m_threshold.get(x,y);
        double falloff=m_falloff.get(x,y);

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
                double lower=threshold-falloff;
                double upper=threshold+falloff;
                double t=quintic_blend((control-lower)/(upper-lower));
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
    SRGBA CRGBASelect::get(double x, double y, double z)
    {
        SRGBA s1=m_low.get(x,y,z);
        SRGBA s2=m_high.get(x,y,z);
        double control=m_control.get(x,y,z);
        double threshold=m_threshold.get(x,y,z);
        double falloff=m_falloff.get(x,y,z);

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
                double lower=threshold-falloff;
                double upper=threshold+falloff;
                double t=quintic_blend((control-lower)/(upper-lower));
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

    SRGBA CRGBASelect::get(double x, double y, double z, double w)
    {
        SRGBA s1=m_low.get(x,y,z,w);
        SRGBA s2=m_high.get(x,y,z,w);
        double control=m_control.get(x,y,z,w);
        double threshold=m_threshold.get(x,y,z,w);
        double falloff=m_falloff.get(x,y,z,w);

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
                double lower=threshold-falloff;
                double upper=threshold+falloff;
                double t=quintic_blend((control-lower)/(upper-lower));
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

    SRGBA CRGBASelect::get(double x, double y, double z, double w, double u, double v)
    {
        SRGBA s1=m_low.get(x,y,z,w,u,v);
        SRGBA s2=m_high.get(x,y,z,w,u,v);
        double control=m_control.get(x,y,z,w,u,v);
        double threshold=m_threshold.get(x,y,z,w,u,v);
        double falloff=m_falloff.get(x,y,z,w,u,v);

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
                double lower=threshold-falloff;
                double upper=threshold+falloff;
                double t=quintic_blend((control-lower)/(upper-lower));
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
