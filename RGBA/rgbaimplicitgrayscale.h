#ifndef RGBA_IMPLICITGRAYSCALE_H
#define RGBA_IMPLICITGRAYSCALE_H
#include "rgbamodulebase.h"
#include "../Noise/implicitmodulebase.h"

/***************************************************************
CRGBAImplicitGrayscale

    Given an input source (CImplicitModuleBase), output an RGBA value
that represents the grayscale value of the input, with an alpha of 1
****************************************************************/

namespace anl
{
    class CRGBAImplicitGrayscale : public CRGBAModuleBase
    {
        public:
        CRGBAImplicitGrayscale();
        CRGBAImplicitGrayscale(ANLFloatType s);
        CRGBAImplicitGrayscale(CImplicitModuleBase * s);
        ~CRGBAImplicitGrayscale();

        void setSource(CImplicitModuleBase * m);
        void setSource(ANLFloatType s);

        SRGBA get(ANLFloatType x, ANLFloatType y);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CScalarParameter m_source;
    };
};

#endif
