#include "rgbabufferimplicitbuffermultiply.h"

namespace anl
{
    CRGBABufferImplicitBufferMultiply::CRGBABufferImplicitBufferMultiply() : CRGBABufferBase(), m_rgbasource(), m_implicitsource()
    {
    }

    CRGBABufferImplicitBufferMultiply::CRGBABufferImplicitBufferMultiply(CRGBABufferBase * rgbasrc, CImplicitBufferBase * impsrc) :
        CRGBABufferBase(), m_rgbasource(rgbasrc), m_implicitsource(impsrc)
    {
    }

    CRGBABufferImplicitBufferMultiply::~CRGBABufferImplicitBufferMultiply()
    {
    }

    void CRGBABufferImplicitBufferMultiply::setRGBASource(CRGBABufferBase * src)
    {
        m_rgbasource=src;
    }

    void CRGBABufferImplicitBufferMultiply::setImplicitSource(CImplicitBufferBase * src)
    {
        m_implicitsource=src;
    }

    void CRGBABufferImplicitBufferMultiply::get(CArray2Drgba &out)
    {
        if(!m_rgbasource || !m_implicitsource) return;

        CArray2Dd tmp;
        tmp.resize(out.width(), out.height());

        m_rgbasource->get(out);
        m_implicitsource->get(tmp);

        for(int x=0; x<out.width(); ++x)
        {
            for(int y=0; y<out.height(); ++y)
            {
                SRGBA c=out.get(x,y);
                double v=tmp.get(x,y);
                out.set(x,y,SRGBA(c[0]*v, c[1]*v, c[2]*v, c[3]));
            }
        }
    }
};
