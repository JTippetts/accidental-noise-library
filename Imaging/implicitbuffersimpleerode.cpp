#include "implicitbuffersimpleerode.h"
#include "erosion.h"

namespace anl
{
    CImplicitBufferSimpleErode::CImplicitBufferSimpleErode() : CImplicitBufferBase(), m_source(), m_numdrops(0), m_power(0.5)
    {
    }
    CImplicitBufferSimpleErode::CImplicitBufferSimpleErode(std::shared_ptr<CImplicitBufferBase> src, int numdrops, float power) :
        CImplicitBufferBase(), m_source(src), m_numdrops(numdrops), m_power(power)
    {
    }

    CImplicitBufferSimpleErode::~CImplicitBufferSimpleErode()
    {
    }

    void CImplicitBufferSimpleErode::setSource(std::shared_ptr<CImplicitBufferBase> src)
    {
        m_source=src;
    }

    void CImplicitBufferSimpleErode::setNumDrops(int drops)
    {
        m_numdrops=drops;
    }

    void CImplicitBufferSimpleErode::setPower(float power)
    {
        m_power=power;
    }

    void CImplicitBufferSimpleErode::get(CArray2Dd &out)
    {
        if(!m_source) return;

        m_source->get(out);
        simpleErode(out,m_numdrops,m_power);
    }

    CImplicitBufferSimpleRainfall::CImplicitBufferSimpleRainfall() : CImplicitBufferBase(), m_source(), m_depth(), m_iterations(0)
    {
    }

    CImplicitBufferSimpleRainfall::CImplicitBufferSimpleRainfall(std::shared_ptr<CImplicitBufferBase> src, std::shared_ptr<CImplicitBufferBase> depth, int iterations) :
        CImplicitBufferBase(), m_source(src), m_depth(depth), m_iterations(iterations)
    {
    }

    CImplicitBufferSimpleRainfall::~CImplicitBufferSimpleRainfall()
    {
    }

    void CImplicitBufferSimpleRainfall::setSource(std::shared_ptr<CImplicitBufferBase> src)
    {
        m_source=src;
    }

    void CImplicitBufferSimpleRainfall::setDepth(std::shared_ptr<CImplicitBufferBase> src)
    {
        m_depth=src;
    }

    void CImplicitBufferSimpleRainfall::setIterations(int iterations)
    {
        m_iterations=iterations;
    }

    void CImplicitBufferSimpleRainfall::get(CArray2Dd &out)
    {
        if(!m_source || !m_depth) return;

        m_depth->get(out);

        CArray2Dd tmp;
        tmp.resize(out.width(), out.height());
        m_source->get(tmp);
        simpleRainfall(tmp,out,m_iterations);
    }
};
