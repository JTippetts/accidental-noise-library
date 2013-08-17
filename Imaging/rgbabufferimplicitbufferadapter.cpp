#include "rgbabufferimplicitbufferadapter.h"

namespace anl
{
    CRGBABufferImplicitBufferAdapter::CRGBABufferImplicitBufferAdapter() : CRGBABufferBase(), m_source()
    {
    }

    CRGBABufferImplicitBufferAdapter::CRGBABufferImplicitBufferAdapter(CImplicitBufferBase * src) :
        CRGBABufferBase(), m_source(src)
    {
    }

    CRGBABufferImplicitBufferAdapter::~CRGBABufferImplicitBufferAdapter()
    {
    }

    void CRGBABufferImplicitBufferAdapter::setSource(CImplicitBufferBase * src)
    {
        m_source=src;
    }

    void CRGBABufferImplicitBufferAdapter::get(CArray2Drgba &out)
    {
        if(!m_source) return;
        CArray2Dd tmp;
        tmp.resize(out.width(), out.height());
        m_source->get(tmp);

        for(int x=0; x<out.width(); ++x)
        {
            for(int y=0; y<out.height(); ++y)
            {
                ANLFloatType v=tmp.get(x,y);
                out.set(x,y,SRGBA(v,v,v,1));
            }
        }
    }
};
