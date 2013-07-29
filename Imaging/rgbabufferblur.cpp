#include "rgbabufferblur.h"

namespace anl
{
    CRGBABufferBlur::CRGBABufferBlur() : CRGBABufferBase(), m_source(), m_blursize(3), m_seamless(false)
    {
    }

    CRGBABufferBlur::CRGBABufferBlur(CRGBABufferBase * src, double blursize, bool seamless) :
        CRGBABufferBase(), m_source(src), m_blursize(blursize), m_seamless(seamless)
    {
    }

    CRGBABufferBlur::~CRGBABufferBlur()
    {
    }

    void CRGBABufferBlur::setSource(CRGBABufferBase * src)
    {
        m_source=src;
    }

    void CRGBABufferBlur::setBlurSize(double blursize)
    {
        m_blursize=blursize;
        if(m_blursize<3) m_blursize=3;
    }

    void CRGBABufferBlur::setSeamless(bool seamless)
    {
        m_seamless=seamless;
    }

    void CRGBABufferBlur::get(CArray2Drgba &out)
    {
        if(!m_source) return;

        m_source->get(out);
        out.blur(m_blursize, m_seamless);
    }
};

