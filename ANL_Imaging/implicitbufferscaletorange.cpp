#include "implicitbufferscaletorange.h"

namespace anl
{
    CImplicitBufferScaleToRange::CImplicitBufferScaleToRange() : CImplicitBufferBase(), m_source(), m_low(0), m_high(1)
    {
    }

    CImplicitBufferScaleToRange::CImplicitBufferScaleToRange(std::shared_ptr<CImplicitBufferBase> src, double low, double high) :
        CImplicitBufferBase(), m_source(src), m_low(low), m_high(high)
    {
    }

    CImplicitBufferScaleToRange::~CImplicitBufferScaleToRange()
    {
    }

    void CImplicitBufferScaleToRange::setRange(double low, double high)
    {
        m_low=low;
        m_high=high;
    }

    void CImplicitBufferScaleToRange::setSource(std::shared_ptr<CImplicitBufferBase> src)
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
