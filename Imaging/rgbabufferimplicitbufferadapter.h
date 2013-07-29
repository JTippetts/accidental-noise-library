#ifndef RGBABUFFERIMPLICITBUFFERADAPTER_H
#define RGBABUFFERIMPLICITBUFFERADAPTER_H

#include "rgbabufferbase.h"
#include "implicitbufferbase.h"

namespace anl
{
    class CRGBABufferImplicitBufferAdapter : public CRGBABufferBase
    {
    public:
        CRGBABufferImplicitBufferAdapter();
        CRGBABufferImplicitBufferAdapter(CImplicitBufferBase * src);
        ~CRGBABufferImplicitBufferAdapter();

        void setSource(CImplicitBufferBase * src);

        void get(CArray2Drgba &out);
    private:
        CImplicitBufferBase * m_source;
    };
};

#endif
