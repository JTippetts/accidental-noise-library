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

    void setX(double f);
    void setY(double f);
    void setZ(double f);
    void setW(double f);
    void setU(double f);
    void setV(double f);

    void setX(std::shared_ptr<CImplicitModuleBase> f);
    void setY(std::shared_ptr<CImplicitModuleBase> f);
    void setZ(std::shared_ptr<CImplicitModuleBase> f);
    void setW(std::shared_ptr<CImplicitModuleBase> f);
    void setU(std::shared_ptr<CImplicitModuleBase> f);
    void setV(std::shared_ptr<CImplicitModuleBase> f);

    double get(double x, double y);
    double get(double x, double y, double z);
    double get(double x, double y, double z, double w);
    double get(double x, double y, double z, double w, double u, double v);

    private:
    CScalarParameter m_x, m_y, m_z, m_w, m_u, m_v;
};
};
#endif

