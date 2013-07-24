#include "rgbablendops.h"

namespace anl
{
    CRGBABlendOps::CRGBABlendOps() : CRGBAModuleBase(), m_source1(), m_source2(), m_src1blend(SRC1_ALPHA), m_src2blend(ONE_MINUS_SRC1_ALPHA){}
    CRGBABlendOps::CRGBABlendOps(SRGBA s1, SRGBA s2, int src1mode, int src2mode) :
        CRGBAModuleBase(), m_source1(s1), m_source2(s2), m_src1blend(src1mode), m_src2blend(src2mode){}

    CRGBABlendOps::CRGBABlendOps(SRGBA s1, std::shared_ptr<CRGBAModuleBase> s2, int src1mode, int src2mode) :
        CRGBAModuleBase(), m_source1(s1), m_source2(s2), m_src1blend(src1mode), m_src2blend(src2mode){}

    CRGBABlendOps::CRGBABlendOps(std::shared_ptr<CRGBAModuleBase> s1, SRGBA s2, int src1mode, int src2mode) :
        CRGBAModuleBase(), m_source1(s1), m_source2(s2), m_src1blend(src1mode), m_src2blend(src2mode){}

    CRGBABlendOps::CRGBABlendOps(std::shared_ptr<CRGBAModuleBase> s1, std::shared_ptr<CRGBAModuleBase> s2, int src1mode, int src2mode) :
        CRGBAModuleBase(), m_source1(s1), m_source2(s2), m_src1blend(src1mode), m_src2blend(src2mode){}


    CRGBABlendOps::~CRGBABlendOps(){}

    void CRGBABlendOps::setSrc1Mode(int mode)
    {
        m_src1blend=mode;
    }
    void CRGBABlendOps::setSrc2Mode(int mode)
    {
        m_src2blend=mode;
    }
    void CRGBABlendOps::setSource1(std::shared_ptr<CRGBAModuleBase> m)
    {
        m_source1.set(m);
    }
    void CRGBABlendOps::setSource2(std::shared_ptr<CRGBAModuleBase> m)
    {
        m_source2.set(m);
    }
    void CRGBABlendOps::setSource1(SRGBA c)
    {
        m_source1.set(c);
    }
    void CRGBABlendOps::setSource2(SRGBA c)
    {
        m_source2.set(c);
    }
    SRGBA CRGBABlendOps::blendRGBAs(SRGBA &s1, SRGBA &s2)
    {
        float srcfactor, dstfactor;
        switch(m_src1blend)
        {
            case SRC1_ALPHA: srcfactor=s1[3]; break;
            case SRC2_ALPHA: srcfactor=s2[3]; break;
            case ONE_MINUS_SRC1_ALPHA: srcfactor=1.0f-s1[3]; break;
            case ONE_MINUS_SRC2_ALPHA: srcfactor=1.0f-s2[3]; break;
            case ONE: srcfactor=1.0f; break;
            case ZERO: srcfactor=0.0f; break;
            default: srcfactor=0.0f; break;
        };

        switch(m_src2blend)
        {
            case SRC1_ALPHA: dstfactor=s1[3]; break;
            case SRC2_ALPHA: dstfactor=s2[3]; break;
            case ONE_MINUS_SRC1_ALPHA: dstfactor=1.0f-s1[3]; break;
            case ONE_MINUS_SRC2_ALPHA: dstfactor=1.0f-s2[3]; break;
            case ONE: dstfactor=1.0f; break;
            case ZERO: dstfactor=1.0f; break;
            default: dstfactor=0.0f; break;
        };

        return SRGBA(s1[0]*srcfactor+s2[0]*dstfactor, s1[1]*srcfactor+s2[1]*dstfactor,
            s1[2]*srcfactor+s2[2]*dstfactor, s2[3]);
    }

    SRGBA CRGBABlendOps::get(double x, double y)
    {
        SRGBA s1=m_source1.get(x,y);
        SRGBA s2=m_source2.get(x,y);

        return blendRGBAs(s1,s2);
    }

    SRGBA CRGBABlendOps::get(double x, double y, double z)
    {
        SRGBA s1=m_source1.get(x,y,z);
        SRGBA s2=m_source2.get(x,y,z);

        return blendRGBAs(s1,s2);
    }

    SRGBA CRGBABlendOps::get(double x, double y, double z, double w)
    {
        SRGBA s1=m_source1.get(x,y,z,w);
        SRGBA s2=m_source2.get(x,y,z,w);

        return blendRGBAs(s1,s2);
    }
    SRGBA CRGBABlendOps::get(double x, double y, double z, double w, double u, double v)
    {
        SRGBA s1=m_source1.get(x,y,z,w,u,v);
        SRGBA s2=m_source2.get(x,y,z,w,u,v);

        return blendRGBAs(s1,s2);
    }
};
