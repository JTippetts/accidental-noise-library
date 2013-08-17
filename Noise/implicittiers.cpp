#include "implicittiers.h"
#include "utility.h"
#include <math.h>

namespace anl
{
    CImplicitTiers::CImplicitTiers() : CImplicitModuleBase(), m_source(0.0), m_numtiers(0.0), m_smooth(true){}
    CImplicitTiers::CImplicitTiers(ANLFloatType src, int numtiers, bool smooth) : CImplicitModuleBase(), m_source(src), m_numtiers(numtiers), m_smooth(smooth){}
    CImplicitTiers::CImplicitTiers(CImplicitModuleBase * src, int numtiers, bool smooth) : CImplicitModuleBase(), m_source(src), m_numtiers(numtiers), m_smooth(smooth){}
    CImplicitTiers::~CImplicitTiers(){}

    void CImplicitTiers::setSource(ANLFloatType v){m_source.set(v);}
    void CImplicitTiers::setSource(CImplicitModuleBase * m){m_source.set(m);}
    void CImplicitTiers::setNumTiers(int numtiers){m_numtiers=numtiers;}
    void CImplicitTiers::setSmooth(bool smooth){m_smooth=smooth;}

    ANLFloatType CImplicitTiers::get(ANLFloatType x, ANLFloatType y)
    {
        int numsteps=m_numtiers;
        if(m_smooth) --numsteps;
        ANLFloatType val=m_source.get(x,y);
        ANLFloatType Tb=floor(val*(ANLFloatType)(numsteps));
        ANLFloatType Tt=Tb+1.0;
        ANLFloatType t=val*(ANLFloatType)(numsteps)-Tb;
        Tb/=(ANLFloatType)(numsteps);
        Tt/=(ANLFloatType)(numsteps);
        ANLFloatType u;
        if(m_smooth) u=quintic_blend(t);
        else u=0.0;
        return Tb+u*(Tt-Tb);
    }
    ANLFloatType CImplicitTiers::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        int numsteps=m_numtiers;
        if(m_smooth) --numsteps;
        ANLFloatType val=m_source.get(x,y,z);
        ANLFloatType Tb=floor(val*(ANLFloatType)(numsteps));
        ANLFloatType Tt=Tb+1.0;
        ANLFloatType t=val*(ANLFloatType)(numsteps)-Tb;
        Tb/=(ANLFloatType)(numsteps);
        Tt/=(ANLFloatType)(numsteps);
        ANLFloatType u;
        if(m_smooth) u=quintic_blend(t);
        else u=0.0;
        return Tb+u*(Tt-Tb);
    }
    ANLFloatType CImplicitTiers::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        int numsteps=m_numtiers;
        if(m_smooth) --numsteps;
        ANLFloatType val=m_source.get(x,y,z,w);
        ANLFloatType Tb=floor(val*(ANLFloatType)(numsteps));
        ANLFloatType Tt=Tb+1.0;
        ANLFloatType t=val*(ANLFloatType)(numsteps)-Tb;
        Tb/=(ANLFloatType)(numsteps);
        Tt/=(ANLFloatType)(numsteps);
        ANLFloatType u;
        if(m_smooth) u=quintic_blend(t);
        else u=0.0;
        return Tb+u*(Tt-Tb);
    }

    ANLFloatType CImplicitTiers::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        int numsteps=m_numtiers;
        if(m_smooth) --numsteps;
        ANLFloatType val=m_source.get(x,y,z,w,u,v);
        ANLFloatType Tb=floor(val*(ANLFloatType)(numsteps));
        ANLFloatType Tt=Tb+1.0;
        ANLFloatType t=val*(ANLFloatType)(numsteps)-Tb;
        Tb/=(ANLFloatType)(numsteps);
        Tt/=(ANLFloatType)(numsteps);
        ANLFloatType s;
        if(m_smooth) s=quintic_blend(t);
        else s=0.0;
        return Tb+s*(Tt-Tb);
    }
};
