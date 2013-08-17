#ifndef IMPLICIT_SAWTOOTH_H
#define IMPLICIT_SAWTOOTH_H
#include "implicitmodulebase.h"

namespace anl
{
class CImplicitSawtooth : public CImplicitModuleBase
{
    public:
    CImplicitSawtooth();
    CImplicitSawtooth(ANLFloatType source, ANLFloatType period);
    CImplicitSawtooth(ANLFloatType source, CImplicitModuleBase * period);
    CImplicitSawtooth(CImplicitModuleBase * source, ANLFloatType period);
    CImplicitSawtooth(CImplicitModuleBase * source, CImplicitModuleBase * period);
    ~CImplicitSawtooth();

    void setSource(CImplicitModuleBase * s);
    void setSource(ANLFloatType s);
    void setPeriod(CImplicitModuleBase * p);
    void setPeriod(ANLFloatType p);

    ANLFloatType get(ANLFloatType x, ANLFloatType y);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

    protected:
    CScalarParameter m_source;
    CScalarParameter m_period;

};
};
#endif
