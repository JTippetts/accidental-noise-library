#include "implicitmodulebase.h"

namespace anl
{
ANLFloatType CImplicitModuleBase::get_dx(ANLFloatType x, ANLFloatType y)
{
    return (get(x-m_spacing,y)-get(x+m_spacing,y))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dy(ANLFloatType x, ANLFloatType y)
{
    return (get(x,y-m_spacing)-get(x,y+m_spacing))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dx(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    return (get(x-m_spacing,y,z)-get(x+m_spacing,y,z))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dy(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    return (get(x,y-m_spacing,z)-get(x,y+m_spacing,z))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dz(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    return (get(x,y,z-m_spacing)-get(x,y,z+m_spacing))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dx(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
    return (get(x-m_spacing,y,z,w)-get(x+m_spacing,y,z,w))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dy(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
    return (get(x,y-m_spacing,z,w)-get(x,y+m_spacing,z,w))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dz(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
    return (get(x,y,z-m_spacing,w)-get(x,y,z+m_spacing,w))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dw(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
    return (get(x,y,z,w-m_spacing)-get(x,y,z,w+m_spacing))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dx(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
    return (get(x-m_spacing,y,z,w,u,v)-get(x+m_spacing,y,z,w,u,v))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dy(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
    return (get(x,y-m_spacing,z,w,u,v)-get(x,y+m_spacing,z,w,u,v))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dz(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
    return (get(x,y,z-m_spacing,w,u,v)-get(x,y,z+m_spacing,w,u,v))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dw(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
    return (get(x,y,z,w-m_spacing,u,v)-get(x,y,z,w+m_spacing,u,v))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_du(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
    return (get(x,y,z,w,u-m_spacing,v)-get(x,y,z,w,u+m_spacing,v))/m_spacing;
}

ANLFloatType CImplicitModuleBase::get_dv(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
    return (get(x,y,z,w,u,v-m_spacing)-get(x,y,z,w,u,v+m_spacing))/m_spacing;
}

};
