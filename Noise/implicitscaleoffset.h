#ifndef IMPLICIT_SCALEOFFSET_H
#define IMPLICIT_SCALEOFFSET_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitScaleOffset : public CImplicitModuleBase
{
    public:
    CImplicitScaleOffset();
    CImplicitScaleOffset(ANLFloatType source, ANLFloatType scale, ANLFloatType offset);
    CImplicitScaleOffset(ANLFloatType source, ANLFloatType scale, CImplicitModuleBase * offset);
    CImplicitScaleOffset(ANLFloatType source, CImplicitModuleBase * scale, ANLFloatType offset);
    CImplicitScaleOffset(ANLFloatType source, CImplicitModuleBase * scale, CImplicitModuleBase * offset);
    CImplicitScaleOffset(CImplicitModuleBase * source, ANLFloatType scale, ANLFloatType offset);
    CImplicitScaleOffset(CImplicitModuleBase * source, ANLFloatType scale, CImplicitModuleBase * offset);
    CImplicitScaleOffset(CImplicitModuleBase * source, CImplicitModuleBase * scale, ANLFloatType offset);
    CImplicitScaleOffset(CImplicitModuleBase * source, CImplicitModuleBase * scale, CImplicitModuleBase * offset);

    ~CImplicitScaleOffset();

    void setSource(CImplicitModuleBase * b);
    void setSource(ANLFloatType v);
    void setScale(ANLFloatType scale);
    void setOffset(ANLFloatType offset);
    void setScale(CImplicitModuleBase * scale);
    void setOffset(CImplicitModuleBase * offset);

    ANLFloatType get(ANLFloatType x, ANLFloatType y);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

    protected:
    //CImplicitModuleBase * m_source;
    CScalarParameter m_source;
    //ANLFloatType m_scale, m_offset;
    CScalarParameter m_scale, m_offset;
};
};

#endif

