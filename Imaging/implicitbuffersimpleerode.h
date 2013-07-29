#ifndef IMPLICITBUFFERSIMPLEERODE_H
#define IMPLICITBUFFERSIMPLEERODE_H

#include "implicitbufferbase.h"

namespace anl
{
    class CImplicitBufferSimpleErode : public CImplicitBufferBase
    {
    public:
        CImplicitBufferSimpleErode();
        CImplicitBufferSimpleErode(CImplicitBufferBase * src, int numdrops, float power);
        ~CImplicitBufferSimpleErode();

        void setSource(CImplicitBufferBase * src);
        void setNumDrops(int drops);
        void setPower(float power);

        void get(CArray2Dd &out);
    private:
        CImplicitBufferBase * m_source;
        int m_numdrops;
        float m_power;
    };

    class CImplicitBufferSimpleRainfall : public CImplicitBufferBase
    {
    public:
        CImplicitBufferSimpleRainfall();
        CImplicitBufferSimpleRainfall(CImplicitBufferBase * src, CImplicitBufferBase * depth, int iterations);
        ~CImplicitBufferSimpleRainfall();

        void setSource(CImplicitBufferBase * src);
        void setDepth(CImplicitBufferBase * src);
        void setIterations(int iterations);

        void get(CArray2Dd &out);
    private:
        CImplicitBufferBase *m_source, *m_depth;
        int m_iterations;
    };
};

#endif
