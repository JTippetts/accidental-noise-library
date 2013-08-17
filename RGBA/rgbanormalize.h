#ifndef RGBA_NORMALIZE_H
#define RGBA_NORMALIZE_H
#include "rgbamodulebase.h"

namespace anl
{
    class CRGBANormalize : public CRGBAModuleBase
    {
        public:
        CRGBANormalize();
        CRGBANormalize(SRGBA s);
        CRGBANormalize(CRGBAModuleBase * s);
        ~CRGBANormalize();

        void setSource(CRGBAModuleBase * m);
        void setSource(SRGBA c);

        SRGBA get(ANLFloatType x, ANLFloatType y);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
        protected:
        CRGBAParameter m_source;
    };
}


#endif
