#ifndef RGBA_BLENDOPS_H
#define RGBA_BLENDOPS_H
#include "rgbamodulebase.h"

/*********************************************************
CRGBABlendOps

    Provide raster-ops-style blending of two RGBA channels.
**********************************************************/

namespace anl
{
    enum EBlendOps
    {
        SRC1_ALPHA,
        SRC2_ALPHA,
        ONE_MINUS_SRC1_ALPHA,
        ONE_MINUS_SRC2_ALPHA,
        ONE,
        ZERO
    };

    class CRGBABlendOps : public CRGBAModuleBase
    {
        public:
        CRGBABlendOps();
        CRGBABlendOps(SRGBA s1, SRGBA s2, int src1mode, int src2mode);
        CRGBABlendOps(SRGBA s1, CRGBAModuleBase * s2, int src1mode, int src2mode);
        CRGBABlendOps(CRGBAModuleBase * s1, SRGBA s2, int src1mode, int src2mode);
        CRGBABlendOps(CRGBAModuleBase * s1, CRGBAModuleBase * s2, int src1mode, int src2mode);

        ~CRGBABlendOps();

        void setSrc1Mode(int mode);
        void setSrc2Mode(int mode);
        void setSource1(CRGBAModuleBase * m);
        void setSource2(CRGBAModuleBase * m);
        void setSource1(SRGBA c);
        void setSource2(SRGBA c);

        SRGBA get(ANLFloatType x, ANLFloatType y);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CRGBAParameter m_source1, m_source2;
        int m_src1blend, m_src2blend;

        SRGBA blendRGBAs(SRGBA &s1, SRGBA &s2);
    };
};

#endif
