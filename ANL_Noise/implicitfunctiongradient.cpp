#include "implicitfunctiongradient.h"

namespace anl
{
    CImplicitFunctionGradient::CImplicitFunctionGradient() : CImplicitModuleBase(), m_source(0.0), m_axis(X_AXIS), m_spacing(0.001){}
    CImplicitFunctionGradient::CImplicitFunctionGradient(double s, int axis, double spacing) : CImplicitModuleBase(), m_source(s), m_axis(axis), m_spacing(spacing){}
    CImplicitFunctionGradient::CImplicitFunctionGradient(std::shared_ptr<CImplicitModuleBase> s, int axis, double spacing) : CImplicitModuleBase(), m_source(s), m_axis(axis), m_spacing(spacing){}
    CImplicitFunctionGradient::~CImplicitFunctionGradient(){}

    void CImplicitFunctionGradient::setSource(double v)
    {
        m_source.set(v);
    }
    void CImplicitFunctionGradient::setSource(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_source.set(m);
    }
    void CImplicitFunctionGradient::setAxis(int axis)
    {
        m_axis=axis;
        if(m_axis<X_AXIS) m_axis=X_AXIS;
        if(m_axis>V_AXIS) m_axis=V_AXIS;
    }
    void CImplicitFunctionGradient::setSpacing(double s)
    {
        m_spacing=s;
    }

    double CImplicitFunctionGradient::get(double x, double y)
    {
        switch(m_axis)
        {
            case X_AXIS: return (m_source.get(x-m_spacing,y)-m_source.get(x+m_spacing,y))/m_spacing; break;
            case Y_AXIS: return (m_source.get(x,y-m_spacing)-m_source.get(x,y+m_spacing))/m_spacing; break;
            case Z_AXIS: return 0.0; break;
            case W_AXIS: return 0.0; break;
            case U_AXIS: return 0.0; break;
            case V_AXIS: return 0.0; break;
        }
        return 0.0;
    }
    double CImplicitFunctionGradient::get(double x, double y, double z)
    {
        switch(m_axis)
        {
            case X_AXIS: return (m_source.get(x-m_spacing,y,z)-m_source.get(x+m_spacing,y,z))/m_spacing; break;
            case Y_AXIS: return (m_source.get(x,y-m_spacing,z)-m_source.get(x,y+m_spacing,z))/m_spacing; break;
            case Z_AXIS: return (m_source.get(x,y,z-m_spacing)-m_source.get(x,y,z+m_spacing))/m_spacing; break;
            case W_AXIS: return 0.0; break;
            case U_AXIS: return 0.0; break;
            case V_AXIS: return 0.0; break;
        }
        return 0.0;
    }
    double CImplicitFunctionGradient::get(double x, double y, double z, double w)
    {
        switch(m_axis)
        {
            case X_AXIS: return (m_source.get(x-m_spacing,y,z,w)-m_source.get(x+m_spacing,y,z,w))/m_spacing; break;
            case Y_AXIS: return (m_source.get(x,y-m_spacing,z,w)-m_source.get(x,y+m_spacing,z,w))/m_spacing; break;
            case Z_AXIS: return (m_source.get(x,y,z-m_spacing,w)-m_source.get(x,y,z+m_spacing,w))/m_spacing; break;
            case W_AXIS: return (m_source.get(x,y,z,w-m_spacing)-m_source.get(x,y,z,w+m_spacing))/m_spacing; break;
            case U_AXIS: return 0.0; break;
            case V_AXIS: return 0.0; break;
        }
        return 0.0;
    }
    double CImplicitFunctionGradient::get(double x, double y, double z, double w, double u, double v)
    {
        switch(m_axis)
        {
            case X_AXIS: return (m_source.get(x-m_spacing,y,z,w,u,v)-m_source.get(x+m_spacing,y,z,w,u,v))/m_spacing; break;
            case Y_AXIS: return (m_source.get(x,y-m_spacing,z,w,u,v)-m_source.get(x,y+m_spacing,z,w,u,v))/m_spacing; break;
            case Z_AXIS: return (m_source.get(x,y,z-m_spacing,w,u,v)-m_source.get(x,y,z+m_spacing,w,u,v))/m_spacing; break;
            case W_AXIS: return (m_source.get(x,y,z,w-m_spacing,u,v)-m_source.get(x,y,z,w+m_spacing,u,v))/m_spacing; break;
            case U_AXIS: return (m_source.get(x,y,z,w,u-m_spacing,v)-m_source.get(x,y,z,w,u+m_spacing,v))/m_spacing; break;
            case V_AXIS: return (m_source.get(x,y,z,w,u,v-m_spacing)-m_source.get(x,y,z,w,u,v+m_spacing))/m_spacing; break;
        }
        return 0.0;
    }
};
