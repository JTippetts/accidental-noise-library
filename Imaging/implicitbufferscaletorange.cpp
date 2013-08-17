#include "implicitbufferscaletorange.h"

namespace anl
{
    CImplicitBufferScaleToRange::CImplicitBufferScaleToRange() : CImplicitBufferBase(), m_source(), m_low(0), m_high(1)
    {
    }

    CImplicitBufferScaleToRange::CImplicitBufferScaleToRange(CImplicitBufferBase * src, ANLFloatType low, ANLFloatType high) :
        CImplicitBufferBase(), m_source(src), m_low(low), m_high(high)
    {
    }

    CImplicitBufferScaleToRange::~CImplicitBufferScaleToRange()
    {
    }

    void CImplicitBufferScaleToRange::setRange(ANLFloatType low, ANLFloatType high)
    {
        m_low=low;
        m_high=high;
    }

    void CImplicitBufferScaleToRange::setSource(CImplicitBufferBase * src)
    {
        m_source=src;
    }

    void CImplicitBufferScaleToRange::get(CArray2Dd &out)
    {
        if(!m_source) return;

        m_source->get(out);
        out.scaleToRange(m_low, m_high);
    }
};
