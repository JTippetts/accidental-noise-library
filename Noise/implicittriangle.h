#ifndef IMPLICIT_TRIANGLE_H
#define IMPLICIT_TRIANGLE_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitTriangle : public CImplicitModuleBase
    {
        public:
        CImplicitTriangle();
        CImplicitTriangle(ANLFloatType source, ANLFloatType period, ANLFloatType offset);
        CImplicitTriangle(ANLFloatType source, ANLFloatType period, CImplicitModuleBase * offset);
        CImplicitTriangle(ANLFloatType source, CImplicitModuleBase * period, ANLFloatType offset);
        CImplicitTriangle(ANLFloatType source, CImplicitModuleBase * period, CImplicitModuleBase * offset);
        CImplicitTriangle(CImplicitModuleBase * source, ANLFloatType period, ANLFloatType offset);
        CImplicitTriangle(CImplicitModuleBase * source, ANLFloatType period, CImplicitModuleBase * offset);
        CImplicitTriangle(CImplicitModuleBase * source, CImplicitModuleBase * period, ANLFloatType offset);
        CImplicitTriangle(CImplicitModuleBase * source, CImplicitModuleBase * period, CImplicitModuleBase * offset);

        ~CImplicitTriangle();

        void setSource(ANLFloatType s);
        void setSource(CImplicitModuleBase * s);
        void setPeriod(ANLFloatType p);
        void setPeriod(CImplicitModuleBase * p);
        void setOffset(ANLFloatType o);
        void setOffset(CImplicitModuleBase * o);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CScalarParameter m_source, m_period, m_offset;
    };
};

#endif
