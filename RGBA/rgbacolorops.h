#ifndef RGBA_COLOR_OPS_H
#define RGBA_COLOR_OPS_H
#include "rgbamodulebase.h"

namespace anl
{
    enum EColorOperations
    {
        COLORMULTIPLY,
        COLORADD,
        SCREEN,
        OVERLAY,
        SOFTLIGHT,
        HARDLIGHT,
        DODGE,
        BURN,
        LINEARDODGE,
        LINEARBURN
    };
    class CRGBAColorOps : public CRGBAModuleBase
    {
        public:
        CRGBAColorOps();
        CRGBAColorOps(SRGBA s1, SRGBA s2, int op);
        CRGBAColorOps(SRGBA s1, CRGBAModuleBase * s2, int op);
        CRGBAColorOps(CRGBAModuleBase * s1, SRGBA s2, int op);
        CRGBAColorOps(CRGBAModuleBase * s1, CRGBAModuleBase * s2, int op);
        ~CRGBAColorOps();

        void setOperation(int op);

        void setSource1(SRGBA c);
        void setSource1(CRGBAModuleBase * m);
        void setSource2(SRGBA c);
        void setSource2(CRGBAModuleBase * m);

        SRGBA get(ANLFloatType x, ANLFloatType y);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CRGBAParameter m_source1, m_source2;
        int m_op;

        SRGBA multiply(SRGBA &s1, SRGBA &s2);
        SRGBA add(SRGBA &s1, SRGBA &s2);
        SRGBA screen(SRGBA &s1, SRGBA &s2);
        SRGBA overlay(SRGBA &s1, SRGBA &s2);
        SRGBA softLight(SRGBA &s1, SRGBA &s2);
        SRGBA hardLight(SRGBA &s1, SRGBA &s2);
        SRGBA dodge(SRGBA &s1, SRGBA &s2);
        SRGBA burn(SRGBA &s1, SRGBA &s2);
        SRGBA linearDodge(SRGBA &s1, SRGBA &s2);
        SRGBA linearBurn(SRGBA &s1, SRGBA &s2);
    };
};

#endif
