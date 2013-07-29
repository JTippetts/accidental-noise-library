#include "implicitautocorrect.h"
#include "random_gen.h"

namespace anl
{

    CImplicitAutoCorrect::CImplicitAutoCorrect() : CImplicitModuleBase(), m_source(0), m_low(-1.0), m_high(1.0){}
    CImplicitAutoCorrect::CImplicitAutoCorrect(double low, double high) : CImplicitModuleBase(), m_source(0), m_low(low), m_high(high){calculate();}
    CImplicitAutoCorrect::CImplicitAutoCorrect(CImplicitModuleBase * m, double low, double high) : CImplicitModuleBase(), m_source(m), m_low(low), m_high(high){calculate();}

    void CImplicitAutoCorrect::setSource(CImplicitModuleBase * m)
    {
        m_source=m;
        calculate();
    }

    void CImplicitAutoCorrect::setRange(double low, double high)
    {
        m_low=low; m_high=high;
        calculate();
    }

    void CImplicitAutoCorrect::calculate()
    {
        if(!m_source) return;
        double mn,mx;
        LCG lcg;
        //lcg.setSeedTime();

        // Calculate 2D
        mn=10000.0;
        mx=-10000.0;
        for(int c=0; c<10000; ++c)
        {
            double nx=lcg.get01()*4.0-2.0;
            double ny=lcg.get01()*4.0-2.0;

            double v=m_source->get(nx,ny);
            if(v<mn) mn=v;
            if(v>mx) mx=v;
        }
        m_scale2=(m_high-m_low) / (mx-mn);
        m_offset2=m_low-mn*m_scale2;

        // Calculate 3D
        mn=10000.0;
        mx=-10000.0;
        for(int c=0; c<10000; ++c)
        {
            double nx=lcg.get01()*4.0-2.0;
            double ny=lcg.get01()*4.0-2.0;
            double nz=lcg.get01()*4.0-2.0;

            double v=m_source->get(nx,ny,nz);
            if(v<mn) mn=v;
            if(v>mx) mx=v;
        }
        m_scale3=(m_high-m_low) / (mx-mn);
        m_offset3=m_low-mn*m_scale3;

        // Calculate 4D
        mn=10000.0;
        mx=-10000.0;
        for(int c=0; c<10000; ++c)
        {
            double nx=lcg.get01()*4.0-2.0;
            double ny=lcg.get01()*4.0-2.0;
            double nz=lcg.get01()*4.0-2.0;
            double nw=lcg.get01()*4.0-2.0;

            double v=m_source->get(nx,ny,nz,nw);
            if(v<mn) mn=v;
            if(v>mx) mx=v;
        }
        m_scale4=(m_high-m_low) / (mx-mn);
        m_offset4=m_low-mn*m_scale4;

        // Calculate 6D
        mn=10000.0;
        mx=-10000.0;
        for(int c=0; c<10000; ++c)
        {
            double nx=lcg.get01()*4.0-2.0;
            double ny=lcg.get01()*4.0-2.0;
            double nz=lcg.get01()*4.0-2.0;
            double nw=lcg.get01()*4.0-2.0;
            double nu=lcg.get01()*4.0-2.0;
            double nv=lcg.get01()*4.0-2.0;

            double v=m_source->get(nx,ny,nz,nw,nu,nv);
            if(v<mn) mn=v;
            if(v>mx) mx=v;
        }
        m_scale6=(m_high-m_low) / (mx-mn);
        m_offset6=m_low-mn*m_scale6;
    }


    double CImplicitAutoCorrect::get(double x, double y)
    {
        if(!m_source) return 0.0;

        double v=m_source->get(x,y);
        return std::max(m_low, std::min(m_high, v*m_scale2+m_offset2));
    }

    double CImplicitAutoCorrect::get(double x, double y, double z)
    {
        if(!m_source) return 0.0;

        double v=m_source->get(x,y,z);
        return std::max(m_low, std::min(m_high, v*m_scale3+m_offset3));
    }
    double CImplicitAutoCorrect::get(double x, double y, double z, double w)
    {
        if(!m_source) return 0.0;

        double v=m_source->get(x,y,z,w);
        return std::max(m_low, std::min(m_high, v*m_scale4+m_offset4));
    }

    double CImplicitAutoCorrect::get(double x, double y, double z, double w, double u, double v)
    {
        if(!m_source) return 0.0;

        double val=m_source->get(x,y,z,w,u,v);
        return std::max(m_low, std::min(m_high, val*m_scale6+m_offset6));
    }
};
