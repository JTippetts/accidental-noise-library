#ifndef IMPLICITBUFFERBUMPMAP_H
#define IMPLICITBUFFERBUMPMAP_H
#include "implicitbufferbase.h"

namespace anl
{
    class CImplicitBufferBumpMap : public CImplicitBufferBase
    {
    public:
        CImplicitBufferBumpMap();
        CImplicitBufferBumpMap(std::shared_ptr<CImplicitBufferBase> src, double lx, double ly, double lz, double spacing, bool seamless);
        ~CImplicitBufferBumpMap();

        void setSource(std::shared_ptr<CImplicitBufferBase> src);
        void setLightVector(double vx, double vy, double vz);
        void setSpacing(double spacing);
        void setSeamless(bool seamless);

        void get(CArray2Dd &out);
    private:
        std::shared_ptr<CImplicitBufferBase> m_source;
        double m_light[3];
        double m_spacing;
        bool m_seamless;
    };
};

#endif
