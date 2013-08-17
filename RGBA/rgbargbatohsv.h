#ifndef RGBA_RGBATOHSV_H
#define RGBA_RGBATOHSV_H
#include "rgbamodulebase.h"

namespace anl
{
    class CRGBARGBAToHSV :public CRGBAModuleBase
    {
        public:
        CRGBARGBAToHSV();
        CRGBARGBAToHSV(SRGBA s);
        CRGBARGBAToHSV(CRGBAModuleBase * s);

        ~CRGBARGBAToHSV(){}

        void setSource(CRGBAModuleBase * m);
        void setSource(SRGBA c);

        SRGBA get(ANLFloatType x, ANLFloatType y);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CRGBAParameter m_source;
    };
};

#endif
