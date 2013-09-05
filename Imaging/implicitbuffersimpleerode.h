#ifndef IMPLICITBUFFERSIMPLEERODE_H
#define IMPLICITBUFFERSIMPLEERODE_H

#include "implicitbufferbase.h"

namespace anl
{
    class CImplicitBufferSimpleErode : public CImplicitBufferBase
    {
    public:
        CImplicitBufferSimpleErode();
        CImplicitBufferSimpleErode(CImplicitBufferBase * src, int numdrops, float power, unsigned int iterations=1);
        ~CImplicitBufferSimpleErode();

        void setSource(CImplicitBufferBase * src);
        void setNumDrops(int drops);
        void setPower(float power);
		void setIterations(unsigned int iter);

        void get(CArray2Dd &out);
    private:
        CImplicitBufferBase * m_source;
        int m_numdrops;
        float m_power;
		int m_iterations;
    };

    class CImplicitBufferSimpleRainfall : public CImplicitBufferBase
    {
    public:
        CImplicitBufferSimpleRainfall();
        CImplicitBufferSimpleRainfall(CImplicitBufferBase * src);
        ~CImplicitBufferSimpleRainfall();

        void setSource(CImplicitBufferBase * src);
        void get(CArray2Dd &out);
    private:
        CImplicitBufferBase *m_source;
        int m_iterations;
    };
};

#endif
