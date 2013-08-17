#include "implicitbufferblur.h"

namespace anl
{
    CImplicitBufferBlur::CImplicitBufferBlur() : CImplicitBufferBase(), m_source(), m_blursize(3), m_seamless(false)
    {
    }

    CImplicitBufferBlur::CImplicitBufferBlur(CImplicitBufferBase * src, ANLFloatType blursize, bool seamless) :
        CImplicitBufferBase(), m_source(src), m_blursize(blursize), m_seamless(seamless)
    {
    }

    CImplicitBufferBlur::~CImplicitBufferBlur()
    {
    }

    void CImplicitBufferBlur::setSource(CImplicitBufferBase * src)
    {
        m_source=src;
    }

    void CImplicitBufferBlur::setBlurSize(ANLFloatType blursize)
    {
        m_blursize=blursize;
        if(m_blursize<3) m_blursize=3;
    }

    void CImplicitBufferBlur::setSeamless(bool seamless)
    {
        m_seamless=seamless;
    }

    void CImplicitBufferBlur::get(CArray2Dd &out)
    {
        if(!m_source) return;

        m_source->get(out);
        out.blur(m_blursize, m_seamless);
    }
};
