#ifndef IMPLICIT_SAWTOOTH_H
#define IMPLICIT_SAWTOOTH_H
#include "implicitmodulebase.h"

namespace anl
{
class CImplicitSawtooth : public CImplicitModuleBase
{
    public:
    CImplicitSawtooth();
    CImplicitSawtooth(double source, double period);
    CImplicitSawtooth(double source, std::shared_ptr<CImplicitModuleBase> period);
    CImplicitSawtooth(std::shared_ptr<CImplicitModuleBase> source, double period);
    CImplicitSawtooth(std::shared_ptr<CImplicitModuleBase> source, std::shared_ptr<CImplicitModuleBase> period);
    ~CImplicitSawtooth();

    void setSource(std::shared_ptr<CImplicitModuleBase> s);
    void setSource(double s);
    void setPeriod(std::shared_ptr<CImplicitModuleBase> p);
    void setPeriod(double p);

    double get(double x, double y);
    double get(double x, double y, double z);
    double get(double x, double y, double z, double w);
    double get(double x, double y, double z, double w, double u, double v);

    protected:
    CScalarParameter m_source;
    CScalarParameter m_period;

};
};
#endif
