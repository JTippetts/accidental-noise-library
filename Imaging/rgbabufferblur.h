#ifndef RGBABUFFERBLUR_H
#define RGBABUFFERBLUR_H
#include "rgbabufferbase.h"

namespace anl
{
    class CRGBABufferBlur : public CRGBABufferBase
    {
    public:
        CRGBABufferBlur();
        CRGBABufferBlur(CRGBABufferBase * src, ANLFloatType blursize, bool seamless);
        ~CRGBABufferBlur();

        void setSource(CRGBABufferBase * src);
        void setBlurSize(ANLFloatType blursize);
        void setSeamless(bool seamless);

        void get(CArray2Drgba &out);
    private:
        CRGBABufferBase * m_source;
        ANLFloatType m_blursize;
        bool m_seamless;
    };
};

#endif
