#ifndef RGBA_HSVTORGBA_H
#define RGBA_HSVTORGBA_H
#include "rgbamodulebase.h"

namespace anl
{
    class CRGBAHSVToRGBA :public CRGBAModuleBase
    {
        public:
        CRGBAHSVToRGBA();
        CRGBAHSVToRGBA(SRGBA s);
        CRGBAHSVToRGBA(CRGBAModuleBase * s);

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

