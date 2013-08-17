#include "implicitscaleoffset.h"

namespace anl
{
    CImplicitScaleOffset::CImplicitScaleOffset() : CImplicitModuleBase(), m_source(0.0), m_scale(1.0), m_offset(0.0){}
    CImplicitScaleOffset::CImplicitScaleOffset(ANLFloatType source, ANLFloatType scale, ANLFloatType offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(ANLFloatType source, ANLFloatType scale, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(ANLFloatType source, CImplicitModuleBase * scale, ANLFloatType offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(ANLFloatType source, CImplicitModuleBase * scale, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(CImplicitModuleBase * source, ANLFloatType scale, ANLFloatType offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(CImplicitModuleBase * source, ANLFloatType scale, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(CImplicitModuleBase * source, CImplicitModuleBase * scale, ANLFloatType offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(CImplicitModuleBase * source, CImplicitModuleBase * scale, CImplicitModuleBase * offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::~CImplicitScaleOffset(){}

    void CImplicitScaleOffset::setSource(CImplicitModuleBase * b){m_source.set(b);}
    void CImplicitScaleOffset::setSource(ANLFloatType v){m_source.set(v);}

    void CImplicitScaleOffset::setScale(ANLFloatType scale)
    {
        m_scale.set(scale);
    }
    void CImplicitScaleOffset::setOffset(ANLFloatType offset)
    {
        m_offset.set(offset);
    }
    void CImplicitScaleOffset::setScale(CImplicitModuleBase * scale)
    {
        m_scale.set(scale);
    }
    void CImplicitScaleOffset::setOffset(CImplicitModuleBase * offset)
    {
        m_offset.set(offset);
    }

    ANLFloatType CImplicitScaleOffset::get(ANLFloatType x, ANLFloatType y)
    {

        return m_source.get(x,y)*m_scale.get(x,y)+m_offset.get(x,y);
    }

    ANLFloatType CImplicitScaleOffset::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {


        return m_source.get(x,y,z)*m_scale.get(x,y,z)+m_offset.get(x,y,z);
    }

    ANLFloatType CImplicitScaleOffset::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {


        return m_source.get(x,y,z,w)*m_scale.get(x,y,z,w)+m_offset.get(x,y,z,w);
    }

    ANLFloatType CImplicitScaleOffset::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {


        return m_source.get(x,y,z,w,u,v)*m_scale.get(x,y,z,w,u,v)+m_offset.get(x,y,z,w,u,v);
    }
};
