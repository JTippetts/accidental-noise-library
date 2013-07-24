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
    CImplicitScaleOffset(double source, double scale, std::shared_ptr<CImplicitModuleBase> offset);
    CImplicitScaleOffset(double source, std::shared_ptr<CImplicitModuleBase> scale, double offset);
    CImplicitScaleOffset(double source, std::shared_ptr<CImplicitModuleBase> scale, std::shared_ptr<CImplicitModuleBase> offset);
    CImplicitScaleOffset(std::shared_ptr<CImplicitModuleBase> source, double scale, double offset);
    CImplicitScaleOffset(std::shared_ptr<CImplicitModuleBase> source, double scale, std::shared_ptr<CImplicitModuleBase> offset);
    CImplicitScaleOffset(std::shared_ptr<CImplicitModuleBase> source, std::shared_ptr<CImplicitModuleBase> scale, double offset);
    CImplicitScaleOffset(std::shared_ptr<CImplicitModuleBase> source, std::shared_ptr<CImplicitModuleBase> scale, std::shared_ptr<CImplicitModuleBase> offset);

    ~CImplicitScaleOffset();

    void setSource(std::shared_ptr<CImplicitModuleBase> b);
    void setSource(double v);
    void setScale(double scale);
    void setOffset(double offset);
    void setScale(std::shared_ptr<CImplicitModuleBase> scale);
    void setOffset(std::shared_ptr<CImplicitModuleBase> offset);

    double get(double x, double y);
    double get(double x, double y, double z);
    double get(double x, double y, double z, double w);
    double get(double x, double y, double z, double w, double u, double v);

    protected:
    //std::shared_ptr<CImplicitModuleBase> m_source;
    CScalarParameter m_source;
    //double m_scale, m_offset;
    CScalarParameter m_scale, m_offset;
};
};

#endif

