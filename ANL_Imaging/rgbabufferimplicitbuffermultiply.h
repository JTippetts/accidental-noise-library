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
        CRGBABufferImplicitBufferMultiply(std::shared_ptr<CRGBABufferBase> rgbasrc, std::shared_ptr<CImplicitBufferBase> impsrc);
        ~CRGBABufferImplicitBufferMultiply();

        void setRGBASource(std::shared_ptr<CRGBABufferBase> src);
        void setImplicitSource(std::shared_ptr<CImplicitBufferBase> src);

        void get(CArray2Drgba &out);

    private:
        std::shared_ptr<CRGBABufferBase> m_rgbasource;
        std::shared_ptr<CImplicitBufferBase> m_implicitsource;
    };
};

#endif
