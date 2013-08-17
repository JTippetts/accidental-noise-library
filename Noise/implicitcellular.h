#ifndef IMPLICIT_CELLULAR_H
#define IMPLICIT_CELLULAR_H
#include "implicitmodulebase.h"
#include "cellulargen.h"

namespace anl
{
class CImplicitCellular : public CImplicitModuleBase
{
    public:
    CImplicitCellular();
    CImplicitCellular(ANLFloatType a, ANLFloatType b, ANLFloatType c, ANLFloatType d);
    CImplicitCellular(CCellularGenerator *m, ANLFloatType a=1, ANLFloatType b=0, ANLFloatType c=0, ANLFloatType d=0);
    ~CImplicitCellular(){}

    void setCoefficients(ANLFloatType a, ANLFloatType b, ANLFloatType c, ANLFloatType d);
    void setCellularSource(CCellularGenerator *m);

    ANLFloatType get(ANLFloatType x, ANLFloatType y);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

    protected:
    CCellularGenerator *m_generator;
    ANLFloatType m_coefficients[4];
};

class CImplicitVoronoi : public CImplicitModuleBase
{
public:
    CImplicitVoronoi();
    CImplicitVoronoi(CCellularGenerator *m);
    ~CImplicitVoronoi();

    ANLFloatType get(ANLFloatType x, ANLFloatType y);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

    protected:
    CCellularGenerator *m_generator;
};
};

#endif
