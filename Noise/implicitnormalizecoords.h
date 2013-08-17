#ifndef IMPLICIT_NORMALIZE_COORDS_H
#define IMPLICIT_NORMALIZE_COORDS_H

#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitNormalizeCoords : public CImplicitModuleBase
    {
        public:
        CImplicitNormalizeCoords();
        CImplicitNormalizeCoords(ANLFloatType s, ANLFloatType l);
        CImplicitNormalizeCoords(ANLFloatType s, CImplicitModuleBase *  l);
        CImplicitNormalizeCoords(CImplicitModuleBase * s, ANLFloatType l);
        CImplicitNormalizeCoords(CImplicitModuleBase * s, CImplicitModuleBase * l);

        void setSource(ANLFloatType v);
        void setSource(CImplicitModuleBase * v);

        void setLength(ANLFloatType v);
        void setLength(CImplicitModuleBase * v);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CScalarParameter m_source;
        CScalarParameter m_length;
    };
};

#endif
