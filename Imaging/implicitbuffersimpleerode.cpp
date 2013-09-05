#include "implicitbuffersimpleerode.h"
#include "erosion.h"

namespace anl
{
    CImplicitBufferSimpleErode::CImplicitBufferSimpleErode() : CImplicitBufferBase(), m_source(), m_numdrops(0), m_power(0.5), m_iterations(1)
    {
    }
    CImplicitBufferSimpleErode::CImplicitBufferSimpleErode(CImplicitBufferBase * src, int numdrops, float power, unsigned int iterations) :
        CImplicitBufferBase(), m_source(src), m_numdrops(numdrops), m_power(power), m_iterations(iterations)
    {
    }

    CImplicitBufferSimpleErode::~CImplicitBufferSimpleErode()
    {
    }

    void CImplicitBufferSimpleErode::setSource(CImplicitBufferBase * src)
    {
        m_source=src;
    }

    void CImplicitBufferSimpleErode::setNumDrops(int drops)
    {
        m_numdrops=drops;
    }
	
	void CImplicitBufferSimpleErode::setIterations(unsigned int iter)
	{
		m_iterations=iter;
	}

    void CImplicitBufferSimpleErode::setPower(float power)
    {
        m_power=power;
    }

    void CImplicitBufferSimpleErode::get(CArray2Dd &out)
    {
        if(!m_source) return;

        m_source->get(out);
		for(unsigned int c=0; c<m_iterations; ++c)
        {
			simpleErode(out,m_numdrops,m_power);
		}
    }

    CImplicitBufferSimpleRainfall::CImplicitBufferSimpleRainfall() : CImplicitBufferBase(), m_source()
    {
    }

    CImplicitBufferSimpleRainfall::CImplicitBufferSimpleRainfall(CImplicitBufferBase * src) :
        CImplicitBufferBase(), m_source(src)
    {
    }

    CImplicitBufferSimpleRainfall::~CImplicitBufferSimpleRainfall()
    {
    }

    void CImplicitBufferSimpleRainfall::setSource(CImplicitBufferBase * src)
    {
        m_source=src;
    }

   

    void CImplicitBufferSimpleRainfall::get(CArray2Dd &out)
    {
        if(!m_source) return;

        CArray2Dd tmp;
        tmp.resize(out.width(), out.height());
        m_source->get(tmp);
        simpleRainfall(tmp,out,m_iterations);
    }
};
