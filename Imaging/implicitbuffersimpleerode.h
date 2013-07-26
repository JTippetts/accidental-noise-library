#ifndef IMPLICITBUFFERSIMPLEERODE_H
#define IMPLICITBUFFERSIMPLEERODE_H

#include "implicitbufferbase.h"

namespace anl
{
    class CImplicitBufferSimpleErode : public CImplicitBufferBase
    {
    public:
        CImplicitBufferSimpleErode();
        CImplicitBufferSimpleErode(std::shared_ptr<CImplicitBufferBase> src, int numdrops, float power);
        ~CImplicitBufferSimpleErode();

        void setSource(std::shared_ptr<CImplicitBufferBase> src);
        void setNumDrops(int drops);
        void setPower(float power);

        void get(CArray2Dd &out);
    private:
        std::shared_ptr<CImplicitBufferBase> m_source;
        int m_numdrops;
        float m_power;
    };

    class CImplicitBufferSimpleRainfall : public CImplicitBufferBase
    {
    public:
        CImplicitBufferSimpleRainfall();
        CImplicitBufferSimpleRainfall(std::shared_ptr<CImplicitBufferBase> src, std::shared_ptr<CImplicitBufferBase> depth, int iterations);
        ~CImplicitBufferSimpleRainfall();

        void setSource(std::shared_ptr<CImplicitBufferBase> src);
        void setDepth(std::shared_ptr<CImplicitBufferBase> src);
        void setIterations(int iterations);

        void get(CArray2Dd &out);
    private:
        std::shared_ptr<CImplicitBufferBase> m_source, m_depth;
        int m_iterations;
    };
};

#endif
