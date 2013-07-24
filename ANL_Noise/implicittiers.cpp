#include "implicittiers.h"
#include "utility.h"
#include <math.h>

namespace anl
{
    CImplicitTiers::CImplicitTiers() : CImplicitModuleBase(), m_source(0.0), m_numtiers(0.0), m_smooth(true){}
    CImplicitTiers::CImplicitTiers(double src, int numtiers, bool smooth) : CImplicitModuleBase(), m_source(src), m_numtiers(numtiers), m_smooth(smooth){}
    CImplicitTiers::CImplicitTiers(std::shared_ptr<CImplicitModuleBase> src, int numtiers, bool smooth) : CImplicitModuleBase(), m_source(src), m_numtiers(numtiers), m_smooth(smooth){}
    CImplicitTiers::~CImplicitTiers(){}

    void CImplicitTiers::setSource(double v){m_source.set(v);}
    void CImplicitTiers::setSource(std::shared_ptr<CImplicitModuleBase> m){m_source.set(m);}
    void CImplicitTiers::setNumTiers(int numtiers){m_numtiers=numtiers;}
    void CImplicitTiers::setSmooth(bool smooth){m_smooth=smooth;}

    double CImplicitTiers::get(double x, double y)
    {
        int numsteps=m_numtiers;
        if(m_smooth) --numsteps;
        double val=m_source.get(x,y);
        double Tb=floor(val*(double)(numsteps));
        double Tt=Tb+1.0;
        double t=val*(double)(numsteps)-Tb;
        Tb/=(double)(numsteps);
        Tt/=(double)(numsteps);
        double u;
        if(m_smooth) u=quintic_blend(t);
        else u=0.0;
        return Tb+u*(Tt-Tb);
    }
    double CImplicitTiers::get(double x, double y, double z)
    {
        int numsteps=m_numtiers;
        if(m_smooth) --numsteps;
        double val=m_source.get(x,y,z);
        double Tb=floor(val*(double)(numsteps));
        double Tt=Tb+1.0;
        double t=val*(double)(numsteps)-Tb;
        Tb/=(double)(numsteps);
        Tt/=(double)(numsteps);
        double u;
        if(m_smooth) u=quintic_blend(t);
        else u=0.0;
        return Tb+u*(Tt-Tb);
    }
    double CImplicitTiers::get(double x, double y, double z, double w)
    {
        int numsteps=m_numtiers;
        if(m_smooth) --numsteps;
        double val=m_source.get(x,y,z,w);
        double Tb=floor(val*(double)(numsteps));
        double Tt=Tb+1.0;
        double t=val*(double)(numsteps)-Tb;
        Tb/=(double)(numsteps);
        Tt/=(double)(numsteps);
        double u;
        if(m_smooth) u=quintic_blend(t);
        else u=0.0;
        return Tb+u*(Tt-Tb);
    }

    double CImplicitTiers::get(double x, double y, double z, double w, double u, double v)
    {
        int numsteps=m_numtiers;
        if(m_smooth) --numsteps;
        double val=m_source.get(x,y,z,w,u,v);
        double Tb=floor(val*(double)(numsteps));
        double Tt=Tb+1.0;
        double t=val*(double)(numsteps)-Tb;
        Tb/=(double)(numsteps);
        Tt/=(double)(numsteps);
        double s;
        if(m_smooth) s=quintic_blend(t);
        else s=0.0;
        return Tb+s*(Tt-Tb);
    }
};
