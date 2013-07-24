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
    CImplicitSphere(double radius, double cx, double cy, double cz);
    CImplicitSphere(double radius, double cx, double cy, std::shared_ptr<CImplicitModuleBase> cz);
    CImplicitSphere(double radius, double cx, std::shared_ptr<CImplicitModuleBase> cy, double cz);
    CImplicitSphere(double radius, double cx, std::shared_ptr<CImplicitModuleBase> cy, std::shared_ptr<CImplicitModuleBase> cz);
    CImplicitSphere(double radius, std::shared_ptr<CImplicitModuleBase> cx, double cy, double cz);
    CImplicitSphere(double radius, std::shared_ptr<CImplicitModuleBase> cx, double cy, std::shared_ptr<CImplicitModuleBase> cz);
    CImplicitSphere(double radius, std::shared_ptr<CImplicitModuleBase> cx, std::shared_ptr<CImplicitModuleBase> cy, double cz);
    CImplicitSphere(double radius, std::shared_ptr<CImplicitModuleBase> cx, std::shared_ptr<CImplicitModuleBase> cy, std::shared_ptr<CImplicitModuleBase> cz);
    CImplicitSphere(std::shared_ptr<CImplicitModuleBase> radius, double cx, double cy, double cz);
    CImplicitSphere(std::shared_ptr<CImplicitModuleBase> radius, double cx, double cy, std::shared_ptr<CImplicitModuleBase> cz);
    CImplicitSphere(std::shared_ptr<CImplicitModuleBase> radius, double cx, std::shared_ptr<CImplicitModuleBase> cy, double cz);
    CImplicitSphere(std::shared_ptr<CImplicitModuleBase> radius, double cx, std::shared_ptr<CImplicitModuleBase> cy, std::shared_ptr<CImplicitModuleBase> cz);
    CImplicitSphere(std::shared_ptr<CImplicitModuleBase> radius, std::shared_ptr<CImplicitModuleBase> cx, double cy, double cz);
    CImplicitSphere(std::shared_ptr<CImplicitModuleBase> radius, std::shared_ptr<CImplicitModuleBase> cx, double cy, std::shared_ptr<CImplicitModuleBase> cz);
    CImplicitSphere(std::shared_ptr<CImplicitModuleBase> radius, std::shared_ptr<CImplicitModuleBase> cx, std::shared_ptr<CImplicitModuleBase> cy, double cz);
    CImplicitSphere(std::shared_ptr<CImplicitModuleBase> radius, std::shared_ptr<CImplicitModuleBase> cx, std::shared_ptr<CImplicitModuleBase> cy, std::shared_ptr<CImplicitModuleBase> cz);

    ~CImplicitSphere();
    void setCenter(double cx,double cy,double cz=0,double cw=0,double cu=0,double cv=0);
    void setCenterX(double cx);
    void setCenterY(double cy);
    void setCenterZ(double cz);
    void setCenterW(double cw);
    void setCenterU(double cu);
    void setCenterV(double cv);
    void setCenterX(std::shared_ptr<CImplicitModuleBase> cx);
    void setCenterY(std::shared_ptr<CImplicitModuleBase> cy);
    void setCenterZ(std::shared_ptr<CImplicitModuleBase> cz);
    void setCenterW(std::shared_ptr<CImplicitModuleBase> cw);
    void setCenterU(std::shared_ptr<CImplicitModuleBase> cu);
    void setCenterV(std::shared_ptr<CImplicitModuleBase> cv);

    void setRadius(double r);
    void setRadius(std::shared_ptr<CImplicitModuleBase> r);

    double get(double x, double y);
    double get(double x, double y, double z);
    double get(double x, double y, double z, double w);
    double get(double x, double y, double z, double w, double u, double v);

    protected:
    CScalarParameter m_cx, m_cy, m_cz, m_cw, m_cu, m_cv;
    CScalarParameter m_radius;

};
};

#endif
