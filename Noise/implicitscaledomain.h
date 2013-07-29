#ifndef IMPLICIT_SCALEDOMAIN_H
#define IMPLICIT_SCALEDOMAIN_H
#include "implicitmodulebase.h"

namespace anl
{
class CImplicitScaleDomain : public CImplicitModuleBase
{
    public:
    CImplicitScaleDomain();
    CImplicitScaleDomain(double src, double x, double y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, double x, double y, CImplicitModuleBase * z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, double x, CImplicitModuleBase * y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, double x, CImplicitModuleBase * y, CImplicitModuleBase * z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, CImplicitModuleBase * x, double y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, CImplicitModuleBase * x, double y, CImplicitModuleBase * z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, CImplicitModuleBase * x, CImplicitModuleBase * y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, CImplicitModuleBase * x, CImplicitModuleBase * y, CImplicitModuleBase * z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, double x, double y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, double x, double y, CImplicitModuleBase * z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, double x, CImplicitModuleBase * y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, double x, CImplicitModuleBase * y, CImplicitModuleBase * z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, double y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, double y, CImplicitModuleBase * z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, CImplicitModuleBase * y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, CImplicitModuleBase * y, CImplicitModuleBase * z, double w=1, double u=1, double v=1);


    void setScale(double x, double y, double z=1, double w=1, double u=1, double v=1);
    void setXScale(double x);
    void setYScale(double x);
    void setZScale(double x);
    void setWScale(double x);
    void setUScale(double x);
    void setVScale(double x);
    void setXScale(CImplicitModuleBase * x);
    void setYScale(CImplicitModuleBase * y);
    void setZScale(CImplicitModuleBase * z);
    void setWScale(CImplicitModuleBase * w);
    void setUScale(CImplicitModuleBase * u);
    void setVScale(CImplicitModuleBase * v);

    void setSource(CImplicitModuleBase * m);
    void setSource(double v);

    double get(double x, double y);
    double get(double x, double y, double z);
    double get(double x, double y, double z, double w);
    double get(double x, double y, double z, double w, double u, double v);
    protected:
    //CImplicitModuleBase * m_source;
    CScalarParameter m_source;
    CScalarParameter m_sx, m_sy, m_sz, m_sw, m_su, m_sv;
};
};

#endif
