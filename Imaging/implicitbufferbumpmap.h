#ifndef IMPLICITBUFFERBUMPMAP_H
#define IMPLICITBUFFERBUMPMAP_H
#include "implicitbufferbase.h"

namespace anl
{
    class CImplicitBufferBumpMap : public CImplicitBufferBase
    {
    public:
        CImplicitBufferBumpMap();
        CImplicitBufferBumpMap(CImplicitBufferBase * src, float lx, float ly, float lz, ANLFloatType spacing, bool seamless);
        ~CImplicitBufferBumpMap();

        void setSource(CImplicitBufferBase * src);
        void setLightVector(float vx, float vy, float vz);
        void setSpacing(ANLFloatType spacing);
        void setSeamless(bool seamless);

        void get(CArray2Dd &out);
    private:
        CImplicitBufferBase * m_source;
        float m_light[3];
        ANLFloatType m_spacing;
        bool m_seamless;
    };
};

#endif
