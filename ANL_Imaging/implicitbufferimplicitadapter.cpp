#include "implicitbufferimplicitadapter.h"

namespace anl
{
    CImplicitBufferImplicitAdapter::CImplicitBufferImplicitAdapter() : CImplicitBufferBase(), m_source(), m_mapping(anl::SEAMLESS_NONE), m_use_z(false), m_z(0)
    {
    }

    CImplicitBufferImplicitAdapter::CImplicitBufferImplicitAdapter(std::shared_ptr<CImplicitModuleBase> src, int mapping, SMappingRanges ranges, bool use_z, double z) :
        CImplicitBufferBase(), m_source(src), m_mapping(mapping), m_ranges(ranges), m_use_z(use_z), m_z(z)
    {
    }
    CImplicitBufferImplicitAdapter::~CImplicitBufferImplicitAdapter()
    {
    }

    void CImplicitBufferImplicitAdapter::setSource(std::shared_ptr<CImplicitModuleBase> src)
    {
        m_source=src;
    }

    void CImplicitBufferImplicitAdapter::setMapping(int mapping)
    {
        m_mapping=mapping;
    }

    void CImplicitBufferImplicitAdapter::setRanges(SMappingRanges &ranges)
    {
        m_ranges=ranges;
    }

    void CImplicitBufferImplicitAdapter::setUseZ(bool use_z)
    {
        m_use_z=use_z;
    }

    void CImplicitBufferImplicitAdapter::setZ(double z)
    {
        m_z=z;
    }

    void CImplicitBufferImplicitAdapter::get(CArray2Dd &out)
    {
        if(!m_source) return;
        CImplicitModuleBase &m=(*m_source);

        if(m_use_z)
        {
            map2D(m_mapping, out, m, m_ranges, m_z);
        }
        else
        {
            map2DNoZ(m_mapping, out, m, m_ranges);
        }
    }
};
