#include "rgbabufferrgbaadapter.h"

namespace anl
{
    CRGBABufferRGBAAdapter::CRGBABufferRGBAAdapter() : CRGBABufferBase(), m_source(), m_mapping(anl::SEAMLESS_NONE), m_use_z(false), m_z(0)
    {
    }

    CRGBABufferRGBAAdapter::CRGBABufferRGBAAdapter(CRGBAModuleBase * src, int mapping, SMappingRanges ranges, bool use_z, double z) :
        CRGBABufferBase(), m_source(src), m_mapping(mapping), m_ranges(ranges), m_use_z(use_z), m_z(z)
    {
    }
    CRGBABufferRGBAAdapter::~CRGBABufferRGBAAdapter()
    {
    }

    void CRGBABufferRGBAAdapter::setSource(CRGBAModuleBase * src)
    {
        m_source=src;
    }

    void CRGBABufferRGBAAdapter::setMapping(int mapping)
    {
        m_mapping=mapping;
    }

    void CRGBABufferRGBAAdapter::setRanges(SMappingRanges &ranges)
    {
        m_ranges=ranges;
    }

    void CRGBABufferRGBAAdapter::setUseZ(bool use_z)
    {
        m_use_z=use_z;
    }

    void CRGBABufferRGBAAdapter::setZ(double z)
    {
        m_z=z;
    }

    void CRGBABufferRGBAAdapter::get(CArray2Drgba &out)
    {
        if(!m_source) return;
        CRGBAModuleBase &m=(*m_source);

        if(m_use_z)
        {
            mapRGBA2D(m_mapping, out, m, m_ranges, m_z);
        }
        else
        {
            mapRGBA2DNoZ(m_mapping, out, m, m_ranges);
        }
    }
};

