#include "implicitextractrgbachannel.h"

namespace anl
{
    CImplicitExtractRGBAChannel::CImplicitExtractRGBAChannel() : CImplicitModuleBase(), m_source(SRGBA(0,0,0,0)), m_channel(RED){}
    CImplicitExtractRGBAChannel::CImplicitExtractRGBAChannel(int channel) : CImplicitModuleBase(), m_source(SRGBA(0,0,0,0)), m_channel(channel){}

    void CImplicitExtractRGBAChannel::setSource(CRGBAModuleBase * m)
    {
        m_source.set(m);
    }
    void CImplicitExtractRGBAChannel::setSource(SRGBA c)
    {
        m_source.set(c);
    }
    void CImplicitExtractRGBAChannel::setChannel(int channel)
    {
        m_channel=channel;
        if(channel<RED) channel=RED;
        if(channel>ALPHA) channel=ALPHA;
    }
    ANLFloatType CImplicitExtractRGBAChannel::get(ANLFloatType x, ANLFloatType y)
    {
        SRGBA s=m_source.get(x,y);

        return s[m_channel];
    }

    ANLFloatType CImplicitExtractRGBAChannel::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        SRGBA s=m_source.get(x,y,z);

        return s[m_channel];
    }
    ANLFloatType CImplicitExtractRGBAChannel::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        SRGBA s=m_source.get(x,y,z,w);

        return s[m_channel];
    }
    ANLFloatType CImplicitExtractRGBAChannel::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        SRGBA s=m_source.get(x,y,z,w,u,v);

        return s[m_channel];
    }
};
