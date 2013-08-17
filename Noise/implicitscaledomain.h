#ifndef IMPLICIT_SCALEDOMAIN_H
#define IMPLICIT_SCALEDOMAIN_H
#include "implicitmodulebase.h"

namespace anl
{
class CImplicitScaleDomain : public CImplicitModuleBase
{
    public:
    CImplicitScaleDomain();
    CImplicitScaleDomain(ANLFloatType src, ANLFloatType x, ANLFloatType y, ANLFloatType z=1, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(ANLFloatType src, ANLFloatType x, ANLFloatType y, CImplicitModuleBase * z, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(ANLFloatType src, ANLFloatType x, CImplicitModuleBase * y, ANLFloatType z=1, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(ANLFloatType src, ANLFloatType x, CImplicitModuleBase * y, CImplicitModuleBase * z, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(ANLFloatType src, CImplicitModuleBase * x, ANLFloatType y, ANLFloatType z=1, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(ANLFloatType src, CImplicitModuleBase * x, ANLFloatType y, CImplicitModuleBase * z, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(ANLFloatType src, CImplicitModuleBase * x, CImplicitModuleBase * y, ANLFloatType z=1, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(ANLFloatType src, CImplicitModuleBase * x, CImplicitModuleBase * y, CImplicitModuleBase * z, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, ANLFloatType x, ANLFloatType y, ANLFloatType z=1, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, ANLFloatType x, ANLFloatType y, CImplicitModuleBase * z, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, ANLFloatType x, CImplicitModuleBase * y, ANLFloatType z=1, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, ANLFloatType x, CImplicitModuleBase * y, CImplicitModuleBase * z, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, ANLFloatType y, ANLFloatType z=1, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, ANLFloatType y, CImplicitModuleBase * z, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, CImplicitModuleBase * y, ANLFloatType z=1, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    CImplicitScaleDomain(CImplicitModuleBase * src, CImplicitModuleBase * x, CImplicitModuleBase * y, CImplicitModuleBase * z, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);


    void setScale(ANLFloatType x, ANLFloatType y, ANLFloatType z=1, ANLFloatType w=1, ANLFloatType u=1, ANLFloatType v=1);
    void setXScale(ANLFloatType x);
    void setYScale(ANLFloatType x);
    void setZScale(ANLFloatType x);
    void setWScale(ANLFloatType x);
    void setUScale(ANLFloatType x);
    void setVScale(ANLFloatType x);
    void setXScale(CImplicitModuleBase * x);
    void setYScale(CImplicitModuleBase * y);
    void setZScale(CImplicitModuleBase * z);
    void setWScale(CImplicitModuleBase * w);
    void setUScale(CImplicitModuleBase * u);
    void setVScale(CImplicitModuleBase * v);

    void setSource(CImplicitModuleBase * m);
    void setSource(ANLFloatType v);

    ANLFloatType get(ANLFloatType x, ANLFloatType y);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
    protected:
    //CImplicitModuleBase * m_source;
    CScalarParameter m_source;
    CScalarParameter m_sx, m_sy, m_sz, m_sw, m_su, m_sv;
};
};

#endif
