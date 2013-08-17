#ifndef IMPLICIT_SPHERE_H
#define IMPLICIT_SPHERE_H
#include "implicitmodulebase.h"
#include <cmath>

namespace anl
{
class CImplicitSphere : public CImplicitModuleBase
{
    public:
    CImplicitSphere();
    CImplicitSphere(ANLFloatType radius, ANLFloatType cx, ANLFloatType cy, ANLFloatType cz);
    CImplicitSphere(ANLFloatType radius, ANLFloatType cx, ANLFloatType cy, CImplicitModuleBase * cz);
    CImplicitSphere(ANLFloatType radius, ANLFloatType cx, CImplicitModuleBase * cy, ANLFloatType cz);
    CImplicitSphere(ANLFloatType radius, ANLFloatType cx, CImplicitModuleBase * cy, CImplicitModuleBase * cz);
    CImplicitSphere(ANLFloatType radius, CImplicitModuleBase * cx, ANLFloatType cy, ANLFloatType cz);
    CImplicitSphere(ANLFloatType radius, CImplicitModuleBase * cx, ANLFloatType cy, CImplicitModuleBase * cz);
    CImplicitSphere(ANLFloatType radius, CImplicitModuleBase * cx, CImplicitModuleBase * cy, ANLFloatType cz);
    CImplicitSphere(ANLFloatType radius, CImplicitModuleBase * cx, CImplicitModuleBase * cy, CImplicitModuleBase * cz);
    CImplicitSphere(CImplicitModuleBase * radius, ANLFloatType cx, ANLFloatType cy, ANLFloatType cz);
    CImplicitSphere(CImplicitModuleBase * radius, ANLFloatType cx, ANLFloatType cy, CImplicitModuleBase * cz);
    CImplicitSphere(CImplicitModuleBase * radius, ANLFloatType cx, CImplicitModuleBase * cy, ANLFloatType cz);
    CImplicitSphere(CImplicitModuleBase * radius, ANLFloatType cx, CImplicitModuleBase * cy, CImplicitModuleBase * cz);
    CImplicitSphere(CImplicitModuleBase * radius, CImplicitModuleBase * cx, ANLFloatType cy, ANLFloatType cz);
    CImplicitSphere(CImplicitModuleBase * radius, CImplicitModuleBase * cx, ANLFloatType cy, CImplicitModuleBase * cz);
    CImplicitSphere(CImplicitModuleBase * radius, CImplicitModuleBase * cx, CImplicitModuleBase * cy, ANLFloatType cz);
    CImplicitSphere(CImplicitModuleBase * radius, CImplicitModuleBase * cx, CImplicitModuleBase * cy, CImplicitModuleBase * cz);

    ~CImplicitSphere();
    void setCenter(ANLFloatType cx,ANLFloatType cy,ANLFloatType cz=0,ANLFloatType cw=0,ANLFloatType cu=0,ANLFloatType cv=0);
    void setCenterX(ANLFloatType cx);
    void setCenterY(ANLFloatType cy);
    void setCenterZ(ANLFloatType cz);
    void setCenterW(ANLFloatType cw);
    void setCenterU(ANLFloatType cu);
    void setCenterV(ANLFloatType cv);
    void setCenterX(CImplicitModuleBase * cx);
    void setCenterY(CImplicitModuleBase * cy);
    void setCenterZ(CImplicitModuleBase * cz);
    void setCenterW(CImplicitModuleBase * cw);
    void setCenterU(CImplicitModuleBase * cu);
    void setCenterV(CImplicitModuleBase * cv);

    void setRadius(ANLFloatType r);
    void setRadius(CImplicitModuleBase * r);

    ANLFloatType get(ANLFloatType x, ANLFloatType y);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

    protected:
    CScalarParameter m_cx, m_cy, m_cz, m_cw, m_cu, m_cv;
    CScalarParameter m_radius;

};
};

#endif
