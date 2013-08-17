#ifndef RGBA_CURVE_H
#define RGBA_CURVE_H
#include "rgbamodulebase.h"
#include "../Noise/implicitmodulebase.h"
#include "../Noise/implicitbasisfunction.h"
#include "../Imaging/templates/tcurve.h"

namespace anl
{
    class CRGBACurve : public CRGBAModuleBase
    {
        public:
        CRGBACurve();
		CRGBACurve(CImplicitModuleBase *src, int interp);
        ~CRGBACurve();

        void pushPoint(ANLFloatType t, float r, float g, float b, float a);
        void clearCurve();
        void setSource(ANLFloatType t);
        void setSource(CImplicitModuleBase * m);
        void setInterpType(int type);

        SRGBA get(ANLFloatType x, ANLFloatType y);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        TCurve<SRGBA> m_curve;
        CScalarParameter m_source;
        int m_type;
    };
};

#endif
