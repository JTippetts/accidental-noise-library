#ifndef C_IMPLICIT_MAGNITUDE_H
#define C_IMPLICIT_MAGNITUDE_H

#include "implicitmodulebase.h"
#include <cmath>
namespace anl
{
class CImplicitMagnitude : public CImplicitModuleBase
{
    public:
    CImplicitMagnitude();
    ~CImplicitMagnitude();

    void setX(ANLFloatType f);
    void setY(ANLFloatType f);
    void setZ(ANLFloatType f);
    void setW(ANLFloatType f);
    void setU(ANLFloatType f);
    void setV(ANLFloatType f);

    void setX(CImplicitModuleBase * f);
    void setY(CImplicitModuleBase * f);
    void setZ(CImplicitModuleBase * f);
    void setW(CImplicitModuleBase * f);
    void setU(CImplicitModuleBase * f);
    void setV(CImplicitModuleBase * f);

    ANLFloatType get(ANLFloatType x, ANLFloatType y);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

    private:
    CScalarParameter m_x, m_y, m_z, m_w, m_u, m_v;
};
};
#endif

