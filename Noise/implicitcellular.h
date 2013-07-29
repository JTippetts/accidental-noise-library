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
    CImplicitCellular(double a, double b, double c, double d);
    CImplicitCellular(CCellularGenerator *m, double a=1, double b=0, double c=0, double d=0);
    ~CImplicitCellular(){}

    void setCoefficients(double a, double b, double c, double d);
    void setCellularSource(CCellularGenerator *m);

    double get(double x, double y);
    double get(double x, double y, double z);
    double get(double x, double y, double z, double w);
    double get(double x, double y, double z, double w, double u, double v);

    protected:
    CCellularGenerator *m_generator;
    double m_coefficients[4];
};

class CImplicitVoronoi : public CImplicitModuleBase
{
public:
    CImplicitVoronoi();
    CImplicitVoronoi(CCellularGenerator *m);
    ~CImplicitVoronoi();

    double get(double x, double y);
    double get(double x, double y, double z);
    double get(double x, double y, double z, double w);
    double get(double x, double y, double z, double w, double u, double v);

    protected:
    CCellularGenerator *m_generator;
};
};

#endif
