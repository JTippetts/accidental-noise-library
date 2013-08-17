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
    SRGBA CRGBAConstant::get(ANLFloatType x, ANLFloatType y)
    {
        return m_rgba;
    }
    SRGBA CRGBAConstant::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        return m_rgba;
    }
    SRGBA CRGBAConstant::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        return m_rgba;
    }
    SRGBA CRGBAConstant::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        return m_rgba;
    }
};
