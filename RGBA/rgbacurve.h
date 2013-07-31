#ifndef RGBA_CURVE_H
#define RGBA_CURVE_H
#include "rgbamodulebase.h"
#include "../Noise/implicitmodulebase.h"
#include "../Noise/implicitbasisfunction.h"
#include "../Noise/templates/tcurve.h"

namespace anl
{
    class CRGBACurve : public CRGBAModuleBase
    {
        public:
        CRGBACurve();
		CRGBACurve(CImplicitModuleBase *src, int interp);
        ~CRGBACurve();

        void pushPoint(double t, float r, float g, float b, float a);
        void clearCurve();
        void setSource(double t);
        void setSource(CImplicitModuleBase * m);
        void setInterpType(int type);

        SRGBA get(double x, double y);
        SRGBA get(double x, double y, double z);
        SRGBA get(double x, double y, double z, double w);
        SRGBA get(double x, double y, double z, double w, double u, double v);

        protected:
        TCurve<SRGBA> m_curve;
        CScalarParameter m_source;
        int m_type;
    };
};

#endif
