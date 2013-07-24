#include "rgbaconstant.h"

namespace anl
{
    CRGBAConstant::CRGBAConstant() : m_rgba(0){}
    CRGBAConstant::CRGBAConstant(SRGBA &r) : m_rgba(r){}
    CRGBAConstant::CRGBAConstant(float r, float g, float b, float a) : m_rgba(r,g,b,a){}
    CRGBAConstant::~CRGBAConstant(){}
    void CRGBAConstant::set(float r, float g, float b, float a)
    {
        m_rgba=SRGBA(r,g,b,a);
    }
    void CRGBAConstant::set(SRGBA &r)
    {
        m_rgba=SRGBA(r);
    }
    SRGBA CRGBAConstant::get(double x, double y)
    {
        return m_rgba;
    }
    SRGBA CRGBAConstant::get(double x, double y, double z)
    {
        return m_rgba;
    }
    SRGBA CRGBAConstant::get(double x, double y, double z, double w)
    {
        return m_rgba;
    }
    SRGBA CRGBAConstant::get(double x, double y, double z, double w, double u, double v)
    {
        return m_rgba;
    }
};
