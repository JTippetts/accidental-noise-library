#include "implicitbufferbumpmap.h"
#include <cmath>
#include "arrayoperations.h"

namespace anl
{
    CImplicitBufferBumpMap::CImplicitBufferBumpMap() : CImplicitBufferBase(), m_source(), m_spacing(0.01), m_seamless(false)
    {
        setLightVector(1.5,3.5,-1.5);
    }

    CImplicitBufferBumpMap::CImplicitBufferBumpMap(CImplicitBufferBase * src, double lx, double ly, double lz, double spacing, bool seamless) :
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

    void CImplicitBufferBumpMap::setLightVector(double vx, double vy, double vz)
    {
        double len=sqrt(vx*vx+vy*vy+vz*vz);
        m_light[0]=vx/len;
        m_light[1]=vy/len;
        m_light[2]=vz/len;
    }

    void CImplicitBufferBumpMap::setSpacing(double spacing)
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
