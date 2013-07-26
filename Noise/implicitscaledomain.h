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
    CImplicitScaleDomain(double src, double x, double y, std::shared_ptr<CImplicitModuleBase> z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, double x, std::shared_ptr<CImplicitModuleBase> y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, double x, std::shared_ptr<CImplicitModuleBase> y, std::shared_ptr<CImplicitModuleBase> z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, std::shared_ptr<CImplicitModuleBase> x, double y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, std::shared_ptr<CImplicitModuleBase> x, double y, std::shared_ptr<CImplicitModuleBase> z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, std::shared_ptr<CImplicitModuleBase> x, std::shared_ptr<CImplicitModuleBase> y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(double src, std::shared_ptr<CImplicitModuleBase> x, std::shared_ptr<CImplicitModuleBase> y, std::shared_ptr<CImplicitModuleBase> z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(std::shared_ptr<CImplicitModuleBase> src, double x, double y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(std::shared_ptr<CImplicitModuleBase> src, double x, double y, std::shared_ptr<CImplicitModuleBase> z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(std::shared_ptr<CImplicitModuleBase> src, double x, std::shared_ptr<CImplicitModuleBase> y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(std::shared_ptr<CImplicitModuleBase> src, double x, std::shared_ptr<CImplicitModuleBase> y, std::shared_ptr<CImplicitModuleBase> z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> x, double y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> x, double y, std::shared_ptr<CImplicitModuleBase> z, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> x, std::shared_ptr<CImplicitModuleBase> y, double z=1, double w=1, double u=1, double v=1);
    CImplicitScaleDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> x, std::shared_ptr<CImplicitModuleBase> y, std::shared_ptr<CImplicitModuleBase> z, double w=1, double u=1, double v=1);


    void setScale(double x, double y, double z=1, double w=1, double u=1, double v=1);
    void setXScale(double x);
    void setYScale(double x);
    void setZScale(double x);
    void setWScale(double x);
    void setUScale(double x);
    void setVScale(double x);
    void setXScale(std::shared_ptr<CImplicitModuleBase> x);
    void setYScale(std::shared_ptr<CImplicitModuleBase> y);
    void setZScale(std::shared_ptr<CImplicitModuleBase> z);
    void setWScale(std::shared_ptr<CImplicitModuleBase> w);
    void setUScale(std::shared_ptr<CImplicitModuleBase> u);
    void setVScale(std::shared_ptr<CImplicitModuleBase> v);

    void setSource(std::shared_ptr<CImplicitModuleBase> m);
    void setSource(double v);

    double get(double x, double y);
    double get(double x, double y, double z);
    double get(double x, double y, double z, double w);
    double get(double x, double y, double z, double w, double u, double v);
    protected:
    //std::shared_ptr<CImplicitModuleBase> m_source;
    CScalarParameter m_source;
    CScalarParameter m_sx, m_sy, m_sz, m_sw, m_su, m_sv;
};
};

#endif
