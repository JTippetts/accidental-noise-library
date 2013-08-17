#ifndef IMPLICIT_RGBADOTPRODUCT_H
#define IMPLICIT_RGBADOTPRODUCT_H
#include "implicitmodulebase.h"
#include "rgbamodulebase.h"

namespace anl
{
    class CImplicitRGBADotProduct : public CImplicitModuleBase
    {
        public:
        CImplicitRGBADotProduct();
        ~CImplicitRGBADotProduct();

        void setSource1(CRGBAModuleBase * m);
        void setSource1(SRGBA c);
        void setSource2(CRGBAModuleBase * m);
        void setSource2(SRGBA c);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CRGBAParameter m_source1, m_source2;
    };
};

#endif
