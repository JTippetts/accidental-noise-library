#include "implicitextractrgbachannel.h"

namespace anl
{
    CImplicitExtractRGBAChannel::CImplicitExtractRGBAChannel() : CImplicitModuleBase(), m_source(SRGBA(0,0,0,0)), m_channel(RED){}
    CImplicitExtractRGBAChannel::CImplicitExtractRGBAChannel(int channel) : CImplicitModuleBase(), m_source(SRGBA(0,0,0,0)), m_channel(channel){}

    void CImplicitExtractRGBAChannel::setSource(std::shared_ptr<CRGBAModuleBase> m)
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
    double CImplicitExtractRGBAChannel::get(double x, double y)
    {
        SRGBA s=m_source.get(x,y);

        return s[m_channel];
    }

    double CImplicitExtractRGBAChannel::get(double x, double y, double z)
    {
        SRGBA s=m_source.get(x,y,z);

        return s[m_channel];
    }
    double CImplicitExtractRGBAChannel::get(double x, double y, double z, double w)
    {
        SRGBA s=m_source.get(x,y,z,w);

        return s[m_channel];
    }
    double CImplicitExtractRGBAChannel::get(double x, double y, double z, double w, double u, double v)
    {
        SRGBA s=m_source.get(x,y,z,w,u,v);

        return s[m_channel];
    }
};
