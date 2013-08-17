#include "implicitbufferbumpmap.h"
#include <cmath>
#include "arrayoperations.h"

namespace anl
{
    CImplicitBufferBumpMap::CImplicitBufferBumpMap() : CImplicitBufferBase(), m_source(), m_spacing(0.01), m_seamless(false)
    {
        setLightVector(1.5,3.5,-1.5);
    }

    CImplicitBufferBumpMap::CImplicitBufferBumpMap(CImplicitBufferBase * src, float lx, float ly, float lz, ANLFloatType spacing, bool seamless) :
        CImplicitBufferBase(), m_source(src), m_spacing(spacing), m_seamless(seamless)
    {
        setLightVector(lx,ly,lz);
    }

    CImplicitBufferBumpMap::~CImplicitBufferBumpMap()
    {
    }

    void CImplicitBufferBumpMap::setSource(CImplicitBufferBase * src)
    {
        m_source=src;
    }

    void CImplicitBufferBumpMap::setLightVector(float vx, float vy, float vz)
    {
        ANLFloatType len=sqrt(vx*vx+vy*vy+vz*vz);
        m_light[0]=vx/len;
        m_light[1]=vy/len;
        m_light[2]=vz/len;
    }

    void CImplicitBufferBumpMap::setSpacing(ANLFloatType spacing)
    {
        m_spacing=spacing;
    }

    void CImplicitBufferBumpMap::setSeamless(bool seamless)
    {
        m_seamless=seamless;
    }

    void CImplicitBufferBumpMap::get(CArray2Dd &out)
    {
        if(!m_source) return;
        CArray2Dd temp;
        temp.resize(out.width(), out.height());
        m_source->get(temp);

        calcBumpMap(&temp, &out, m_light, m_spacing, m_seamless);
    }
};
