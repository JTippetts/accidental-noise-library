#ifndef IMPLICIT_SCALEOFFSET_H
#define IMPLICIT_SCALEOFFSET_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitScaleOffset : public CImplicitModuleBase
{
    public:
    CImplicitScaleOffset();
    CImplicitScaleOffset(double source, double scale, double offset);
    CImplicitScaleOffset(double source, double scale, CImplicitModuleBase * offset);
    CImplicitScaleOffset(double source, CImplicitModuleBase * scale, double offset);
    CImplicitScaleOffset(double source, CImplicitModuleBase * scale, CImplicitModuleBase * offset);
    CImplicitScaleOffset(CImplicitModuleBase * source, double scale, double offset);
    CImplicitScaleOffset(CImplicitModuleBase * source, double scale, CImplicitModuleBase * offset);
    CImplicitScaleOffset(CImplicitModuleBase * source, CImplicitModuleBase * scale, double offset);
    CImplicitScaleOffset(CImplicitModuleBase * source, CImplicitModuleBase * scale, CImplicitModuleBase * offset);

    ~CImplicitScaleOffset();

    void setSource(CImplicitModuleBase * b);
    void setSource(double v);
    void setScale(double scale);
    void setOffset(double offset);
    void setScale(CImplicitModuleBase * scale);
    void setOffset(CImplicitModuleBase * offset);

    double get(double x, double y);
    double get(double x, double y, double z);
    double get(double x, double y, double z, double w);
    double get(double x, double y, double z, double w, double u, double v);

    protected:
    //CImplicitModuleBase * m_source;
    CScalarParameter m_source;
    //double m_scale, m_offset;
    CScalarParameter m_scale, m_offset;
};
};

#endif

