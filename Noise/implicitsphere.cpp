#include "implicitsphere.h"

namespace anl
{
    CImplicitSphere::CImplicitSphere() : CImplicitModuleBase(), m_cx(0.0), m_cy(0.0), m_cz(0.0), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(1.0){}

    CImplicitSphere::CImplicitSphere(ANLFloatType radius, ANLFloatType cx, ANLFloatType cy, ANLFloatType cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(ANLFloatType radius, ANLFloatType cx, ANLFloatType cy, CImplicitModuleBase * cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(ANLFloatType radius, ANLFloatType cx, CImplicitModuleBase * cy, ANLFloatType cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(ANLFloatType radius, ANLFloatType cx, CImplicitModuleBase * cy, CImplicitModuleBase * cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(ANLFloatType radius, CImplicitModuleBase * cx, ANLFloatType cy, ANLFloatType cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(ANLFloatType radius, CImplicitModuleBase * cx, ANLFloatType cy, CImplicitModuleBase * cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(ANLFloatType radius, CImplicitModuleBase * cx, CImplicitModuleBase * cy, ANLFloatType cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(ANLFloatType radius, CImplicitModuleBase * cx, CImplicitModuleBase * cy, CImplicitModuleBase * cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(CImplicitModuleBase * radius, ANLFloatType cx, ANLFloatType cy, ANLFloatType cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(CImplicitModuleBase * radius, ANLFloatType cx, ANLFloatType cy, CImplicitModuleBase * cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(CImplicitModuleBase * radius, ANLFloatType cx, CImplicitModuleBase * cy, ANLFloatType cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(CImplicitModuleBase * radius, ANLFloatType cx, CImplicitModuleBase * cy, CImplicitModuleBase * cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(CImplicitModuleBase * radius, CImplicitModuleBase * cx, ANLFloatType cy, ANLFloatType cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(CImplicitModuleBase * radius, CImplicitModuleBase * cx, ANLFloatType cy, CImplicitModuleBase * cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(CImplicitModuleBase * radius, CImplicitModuleBase * cx, CImplicitModuleBase * cy, ANLFloatType cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}
    CImplicitSphere::CImplicitSphere(CImplicitModuleBase * radius, CImplicitModuleBase * cx, CImplicitModuleBase * cy, CImplicitModuleBase * cz) : CImplicitModuleBase(), m_cx(cx), m_cy(cy), m_cz(cz), m_cw(0.0), m_cu(0.0), m_cv(0.0), m_radius(radius){}

    CImplicitSphere::~CImplicitSphere(){}

    void CImplicitSphere::setCenter(ANLFloatType cx,ANLFloatType cy,ANLFloatType cz,ANLFloatType cw,ANLFloatType cu,ANLFloatType cv)
    {
        m_cx=cx; m_cy=cy; m_cz=cz; m_cw=cw; m_cu=cu; m_cv=cv;
    }
    void CImplicitSphere::setCenterX(ANLFloatType cx){m_cx.set(cx);}
    void CImplicitSphere::setCenterY(ANLFloatType cy){m_cy.set(cy);}
    void CImplicitSphere::setCenterZ(ANLFloatType cz){m_cz.set(cz);}
    void CImplicitSphere::setCenterW(ANLFloatType cw){m_cw.set(cw);}
    void CImplicitSphere::setCenterU(ANLFloatType cu){m_cu.set(cu);}
    void CImplicitSphere::setCenterV(ANLFloatType cv){m_cv.set(cv);}
    void CImplicitSphere::setCenterX(CImplicitModuleBase * cx){m_cx.set(cx);}
    void CImplicitSphere::setCenterY(CImplicitModuleBase * cy){m_cy.set(cy);}
    void CImplicitSphere::setCenterZ(CImplicitModuleBase * cz){m_cz.set(cz);}
    void CImplicitSphere::setCenterW(CImplicitModuleBase * cw){m_cw.set(cw);}
    void CImplicitSphere::setCenterU(CImplicitModuleBase * cu){m_cu.set(cu);}
    void CImplicitSphere::setCenterV(CImplicitModuleBase * cv){m_cv.set(cv);}
    void CImplicitSphere::setRadius(ANLFloatType r)
    {
        m_radius.set(r);
    }
    void CImplicitSphere::setRadius(CImplicitModuleBase * r)
    {
        m_radius.set(r);
    }

    ANLFloatType CImplicitSphere::get(ANLFloatType x, ANLFloatType y)
    {
        ANLFloatType dx=x-m_cx.get(x,y), dy=y-m_cy.get(x,y);
        ANLFloatType len=sqrt(dx*dx+dy*dy);
        ANLFloatType radius=m_radius.get(x,y);
        ANLFloatType i=(radius-len)/radius;
        if(i<0) i=0;
        if(i>1) i=1;

        return i;
    }

    ANLFloatType CImplicitSphere::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        ANLFloatType dx=x-m_cx.get(x,y,z), dy=y-m_cy.get(x,y,z), dz=z-m_cz.get(x,y,z);
        ANLFloatType len=sqrt(dx*dx+dy*dy+dz*dz);
        ANLFloatType radius=m_radius.get(x,y,z);
        ANLFloatType i=(radius-len)/radius;
        if(i<0) i=0;
        if(i>1) i=1;

        return i;
    }

    ANLFloatType CImplicitSphere::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        ANLFloatType dx=x-m_cx.get(x,y,z,w), dy=y-m_cy.get(x,y,z,w), dz=z-m_cz.get(x,y,z,w), dw=w-m_cw.get(x,y,z,w);
        ANLFloatType len=sqrt(dx*dx+dy*dy+dz*dz+dw*dw);
        ANLFloatType radius=m_radius.get(x,y,z,w);
        ANLFloatType i=(radius-len)/radius;
        if(i<0) i=0;
        if(i>1) i=1;

        return i;
    }

    ANLFloatType CImplicitSphere::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        ANLFloatType dx=x-m_cx.get(x,y,z,w,u,v), dy=y-m_cy.get(x,y,z,w,u,v), dz=z-m_cz.get(x,y,z,w,u,v), dw=w-m_cw.get(x,y,z,w,u,v),
            du=u-m_cu.get(x,y,z,w,u,v), dv=v-m_cv.get(x,y,z,w,u,v);
        ANLFloatType len=sqrt(dx*dx+dy*dy+dz*dz+dw*dw+du*du+dv*dv);
        ANLFloatType radius=m_radius.get(x,y,z,w,u,v);
        ANLFloatType i=(radius-len)/radius;
        if(i<0) i=0;
        if(i>1) i=1;

        return i;
    }
};
