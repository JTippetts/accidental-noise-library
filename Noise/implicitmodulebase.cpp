#include "implicitmodulebase.h"

namespace anl
{
double CImplicitModuleBase::get_dx(double x, double y)
{
    return (get(x-m_spacing,y)-get(x+m_spacing,y))/m_spacing;
}

double CImplicitModuleBase::get_dy(double x, double y)
{
    return (get(x,y-m_spacing)-get(x,y+m_spacing))/m_spacing;
}

double CImplicitModuleBase::get_dx(double x, double y, double z)
{
    return (get(x-m_spacing,y,z)-get(x+m_spacing,y,z))/m_spacing;
}

double CImplicitModuleBase::get_dy(double x, double y, double z)
{
    return (get(x,y-m_spacing,z)-get(x,y+m_spacing,z))/m_spacing;
}

double CImplicitModuleBase::get_dz(double x, double y, double z)
{
    return (get(x,y,z-m_spacing)-get(x,y,z+m_spacing))/m_spacing;
}

double CImplicitModuleBase::get_dx(double x, double y, double z, double w)
{
    return (get(x-m_spacing,y,z,w)-get(x+m_spacing,y,z,w))/m_spacing;
}

double CImplicitModuleBase::get_dy(double x, double y, double z, double w)
{
    return (get(x,y-m_spacing,z,w)-get(x,y+m_spacing,z,w))/m_spacing;
}

double CImplicitModuleBase::get_dz(double x, double y, double z, double w)
{
    return (get(x,y,z-m_spacing,w)-get(x,y,z+m_spacing,w))/m_spacing;
}

double CImplicitModuleBase::get_dw(double x, double y, double z, double w)
{
    return (get(x,y,z,w-m_spacing)-get(x,y,z,w+m_spacing))/m_spacing;
}

double CImplicitModuleBase::get_dx(double x, double y, double z, double w, double u, double v)
{
    return (get(x-m_spacing,y,z,w,u,v)-get(x+m_spacing,y,z,w,u,v))/m_spacing;
}

double CImplicitModuleBase::get_dy(double x, double y, double z, double w, double u, double v)
{
    return (get(x,y-m_spacing,z,w,u,v)-get(x,y+m_spacing,z,w,u,v))/m_spacing;
}

double CImplicitModuleBase::get_dz(double x, double y, double z, double w, double u, double v)
{
    return (get(x,y,z-m_spacing,w,u,v)-get(x,y,z+m_spacing,w,u,v))/m_spacing;
}

double CImplicitModuleBase::get_dw(double x, double y, double z, double w, double u, double v)
{
    return (get(x,y,z,w-m_spacing,u,v)-get(x,y,z,w+m_spacing,u,v))/m_spacing;
}

double CImplicitModuleBase::get_du(double x, double y, double z, double w, double u, double v)
{
    return (get(x,y,z,w,u-m_spacing,v)-get(x,y,z,w,u+m_spacing,v))/m_spacing;
}

double CImplicitModuleBase::get_dv(double x, double y, double z, double w, double u, double v)
{
    return (get(x,y,z,w,u,v-m_spacing)-get(x,y,z,w,u,v+m_spacing))/m_spacing;
}

};
