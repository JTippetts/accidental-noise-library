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
        CRGBABufferImplicitBufferAdapter(std::shared_ptr<CImplicitBufferBase> src);
        ~CRGBABufferImplicitBufferAdapter();

        void setSource(std::shared_ptr<CImplicitBufferBase> src);

        void get(CArray2Drgba &out);
    private:
        std::shared_ptr<CImplicitBufferBase> m_source;
    };
};

#endif
