#ifndef RGBABUFFERIMPLICITBUFFERMULTIPLY_H
#define RGBABUFFERIMPLICITBUFFERMULTIPLY_H

#include "rgbabufferbase.h"
#include "implicitbufferbase.h"

namespace anl
{
    class CRGBABufferImplicitBufferMultiply : public CRGBABufferBase
    {
    public:
        CRGBABufferImplicitBufferMultiply();
        CRGBABufferImplicitBufferMultiply(CRGBABufferBase * rgbasrc, CImplicitBufferBase * impsrc);
        ~CRGBABufferImplicitBufferMultiply();

        void setRGBASource(CRGBABufferBase * src);
        void setImplicitSource(CImplicitBufferBase * src);

        void get(CArray2Drgba &out);

    private:
        CRGBABufferBase * m_rgbasource;
        CImplicitBufferBase * m_implicitsource;
    };
};

#endif
