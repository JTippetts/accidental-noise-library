#include "rgbacolorops.h"
#include <algorithm>
#include <cmath>

namespace anl
{
    CRGBAColorOps::CRGBAColorOps() : m_source1(), m_source2(), m_op(SOFTLIGHT){}

    CRGBAColorOps::CRGBAColorOps(SRGBA s1, SRGBA s2, int op) : CRGBAModuleBase(), m_source1(s1), m_source2(s2), m_op(op){}
    CRGBAColorOps::CRGBAColorOps(SRGBA s1, std::shared_ptr<CRGBAModuleBase> s2, int op) : CRGBAModuleBase(), m_source1(s1), m_source2(s2), m_op(op){}
    CRGBAColorOps::CRGBAColorOps(std::shared_ptr<CRGBAModuleBase> s1, SRGBA s2, int op) : CRGBAModuleBase(), m_source1(s1), m_source2(s2), m_op(op){}
    CRGBAColorOps::CRGBAColorOps(std::shared_ptr<CRGBAModuleBase> s1, std::shared_ptr<CRGBAModuleBase> s2, int op) : CRGBAModuleBase(), m_source1(s1), m_source2(s2), m_op(op){}

    CRGBAColorOps::~CRGBAColorOps(){}
    void CRGBAColorOps::setOperation(int op)
    {
        m_op=op;
        if(m_op<0) m_op=0;
        if(m_op>LINEARBURN) m_op=LINEARBURN;
    }

    void CRGBAColorOps::setSource1(SRGBA c)
    {
        m_source1.set(c);
    }
    void CRGBAColorOps::setSource1(std::shared_ptr<CRGBAModuleBase> m)
    {
        m_source1.set(m);
    }
    void CRGBAColorOps::setSource2(SRGBA c)
    {
        m_source2.set(c);
    }
    void CRGBAColorOps::setSource2(std::shared_ptr<CRGBAModuleBase> m)
    {
        m_source2.set(m);
    }

    SRGBA CRGBAColorOps::multiply(SRGBA &s1, SRGBA &s2)
    {
        return SRGBA(s1[0]*s2[0], s1[1]*s2[1], s1[2]*s2[2], s1[3]);
    }
    SRGBA CRGBAColorOps::add(SRGBA &s1, SRGBA &s2)
    {
        return SRGBA(s1[0]+s2[0], s1[1]+s2[1], s1[2]+s2[2], s1[3]);
    }
    SRGBA CRGBAColorOps::screen(SRGBA &s1, SRGBA &s2)
    {
        float r,g,b;
        r=s1[0] + s2[0] - s1[0]*s2[0];
        g=s1[1] + s2[1] - s1[1]*s2[1];
        b=s1[2] + s2[2] - s1[2]*s2[2];
        return SRGBA(r,g,b,s1[3]);
    }
    SRGBA CRGBAColorOps::overlay(SRGBA &s1, SRGBA &s2)
    {
        float r,g,b,a;
        r = (s2[0] < 0.5f) ? (2.0f * s1[0] * s2[0]) : (1.0f-2.0f * (1.0f-s1[0]) * (1.0f-s2[0]));
        g = (s2[1] < 0.5f) ? (2.0f * s1[1] * s2[1]) : (1.0f-2.0f * (1.0f-s1[1]) * (1.0f-s2[1]));
        b = (s2[2] < 0.5f) ? (2.0f * s1[2] * s2[2]) : (1.0f-2.0f * (1.0f-s1[2]) * (1.0f-s2[2]));
        a=s1[3];
        return SRGBA(r,g,b,a);
    }

    SRGBA CRGBAColorOps::softLight(SRGBA &s1, SRGBA &s2)
    {
        float r,g,b;
        if(s1[0] > 0.5f)
        {
            r=s2[0]+(1.0f-s2[0])*((s1[0]-0.5f) / 0.5f) * (0.5 - std::abs(s2[0]-0.5f));
        }
        else
        {
            r= s2[0] - s2[0] * ((0.5f-s1[0]) / 0.5f) * (0.5f - std::abs(s2[0]-0.5f));
        }

        if(s1[1] > 0.5f)
        {
            g=s2[1]+(1.0f-s2[1])*((s1[1]-0.5f) / 0.5f) * (0.5 - std::abs(s2[1]-0.5f));
        }
        else
        {
            g= s2[1] - s2[1] * ((0.5f-s1[1]) / 0.5f) * (0.5f - std::abs(s2[1]-0.5f));
        }

        if(s1[2] > 0.5f)
        {
            b=s2[2]+(1.0f-s2[2])*((s1[2]-0.5f) / 0.5f) * (0.5 - std::abs(s2[2]-0.5f));
        }
        else
        {
            b= s2[2] - s2[2] * ((0.5f-s1[2]) / 0.5f) * (0.5f - std::abs(s2[2]-0.5f));
        }

        return SRGBA(r,g,b,s1[3]);
    }

    SRGBA CRGBAColorOps::hardLight(SRGBA &s1, SRGBA &s2)
    {
        float r,g,b;
        if(s1[0] > 0.5f)
        {
            r = s2[0] + (1.0f - s2[0]) * ((s1[0] - 0.5f) / 0.5f);
        }
        else
        {
            r = s2[0] * s1[0] / 0.5f;
        }

        if(s1[1] > 0.5f)
        {
            g = s2[1] + (1.0f - s2[1]) * ((s1[1] - 0.5f) / 0.5f);
        }
        else
        {
            g = s2[1] * s1[1] / 0.5f;
        }

        if(s1[2] > 0.5f)
        {
            b = s2[2] + (1.0f - s2[2]) * ((s1[2] - 0.5f) / 0.5f);
        }
        else
        {
            b = s2[2] * s1[2] / 0.5f;
        }

        return SRGBA(r,g,b,s1[3]);
    }

    SRGBA CRGBAColorOps::dodge(SRGBA &s1, SRGBA &s2)
    {
        float r,g,b;
        r = (s1[0] == 1.0f) ? s1[0] : std::min(1.0f, ((s2[0]) / (1.0f-s1[0])));
        g = (s1[1] == 1.0f) ? s1[1] : std::min(1.0f, ((s2[1]) / (1.0f-s1[1])));
        b = (s1[2] == 1.0f) ? s1[2] : std::min(1.0f, ((s2[2]) / (1.0f-s1[2])));

        return SRGBA(r,g,b,s1[3]);
    }

    SRGBA CRGBAColorOps::burn(SRGBA &s1, SRGBA &s2)
    {
        float r,g,b;
        r = (s1[0]==1.0f) ? s1[0] : std::max(0.0f, (1.0f - ((1.0f-s2[0])) / s1[0]));
        g = (s1[1]==1.0f) ? s1[1] : std::max(0.0f, (1.0f - ((1.0f-s2[1])) / s1[1]));
        b = (s1[2]==1.0f) ? s1[2] : std::max(0.0f, (1.0f - ((1.0f-s2[2])) / s1[2]));

        return SRGBA(r,g,b,s1[3]);
    }

    SRGBA CRGBAColorOps::linearDodge(SRGBA &s1, SRGBA &s2)
    {
        float r,g,b;
        r = std::min(s1[0]+s2[0], 1.0f);
        g = std::min(s1[1]+s2[1], 1.0f);
        b = std::min(s1[2]+s2[2], 1.0f);

        return SRGBA(r,g,b,s1[3]);
    }

    SRGBA CRGBAColorOps::linearBurn(SRGBA &s1, SRGBA &s2)
    {
        float r,g,b;
        r = ((s1[0] + s2[0]) < 1.0f) ? 0.0f : (s1[0] + s2[0] - 1.0f);
        g = ((s1[1] + s2[1]) < 1.0f) ? 0.0f : (s1[1] + s2[1] - 1.0f);
        b = ((s1[2] + s2[2]) < 1.0f) ? 0.0f : (s1[2] + s2[2] - 1.0f);

        return SRGBA(r,g,b,s1[3]);
    }

    SRGBA CRGBAColorOps::get(double x, double y)
    {
        SRGBA s1=m_source1.get(x,y);
        SRGBA s2=m_source2.get(x,y);
        switch(m_op)
        {
            case COLORMULTIPLY: return multiply(s1,s2); break;
            case COLORADD: return add(s1,s2); break;
            case SCREEN: return screen(s1,s2); break;
            case OVERLAY: return overlay(s1,s2); break;
            case SOFTLIGHT: return softLight(s1,s2); break;
            case HARDLIGHT: return hardLight(s1,s2); break;
            case DODGE: return dodge(s1,s2); break;
            case BURN: return burn(s1,s2); break;
            case LINEARDODGE: return linearDodge(s1,s2); break;
            case LINEARBURN: return linearBurn(s1,s2); break;
            default: return softLight(s1,s2); break;
        }
    }

    SRGBA CRGBAColorOps::get(double x, double y, double z)
    {
        SRGBA s1=m_source1.get(x,y,z);
        SRGBA s2=m_source2.get(x,y,z);
        switch(m_op)
        {
            case COLORMULTIPLY: return multiply(s1,s2); break;
            case COLORADD: return add(s1,s2); break;
            case SCREEN: return screen(s1,s2); break;
            case OVERLAY: return overlay(s1,s2); break;
            case SOFTLIGHT: return softLight(s1,s2); break;
            case HARDLIGHT: return hardLight(s1,s2); break;
            case DODGE: return dodge(s1,s2); break;
            case BURN: return burn(s1,s2); break;
            case LINEARDODGE: return linearDodge(s1,s2); break;
            case LINEARBURN: return linearBurn(s1,s2); break;
            default: return softLight(s1,s2); break;
        }
    }

    SRGBA CRGBAColorOps::get(double x, double y, double z, double w)
    {
        SRGBA s1=m_source1.get(x,y,z,w);
        SRGBA s2=m_source2.get(x,y,z,w);
        switch(m_op)
        {
            case COLORMULTIPLY: return multiply(s1,s2); break;
            case COLORADD: return add(s1,s2); break;
            case SCREEN: return screen(s1,s2); break;
            case OVERLAY: return overlay(s1,s2); break;
            case SOFTLIGHT: return softLight(s1,s2); break;
            case HARDLIGHT: return hardLight(s1,s2); break;
            case DODGE: return dodge(s1,s2); break;
            case BURN: return burn(s1,s2); break;
            case LINEARDODGE: return linearDodge(s1,s2); break;
            case LINEARBURN: return linearBurn(s1,s2); break;
            default: return softLight(s1,s2); break;
        }
    }

    SRGBA CRGBAColorOps::get(double x, double y, double z, double w, double u, double v)
    {
        SRGBA s1=m_source1.get(x,y,z,w,u,v);
        SRGBA s2=m_source2.get(x,y,z,w,u,v);
        switch(m_op)
        {
            case COLORMULTIPLY: return multiply(s1,s2); break;
            case COLORADD: return add(s1,s2); break;
            case SCREEN: return screen(s1,s2); break;
            case OVERLAY: return overlay(s1,s2); break;
            case SOFTLIGHT: return softLight(s1,s2); break;
            case HARDLIGHT: return hardLight(s1,s2); break;
            case DODGE: return dodge(s1,s2); break;
            case BURN: return burn(s1,s2); break;
            case LINEARDODGE: return linearDodge(s1,s2); break;
            case LINEARBURN: return linearBurn(s1,s2); break;
            default: return softLight(s1,s2); break;
        }
    }

};
