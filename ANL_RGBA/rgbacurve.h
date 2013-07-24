#ifndef RGBA_CURVE_H
#define RGBA_CURVE_H
#include "rgbamodulebase.h"
#include "../ANL_Noise/implicitmodulebase.h"
#include "../ANL_Noise/implicitbasisfunction.h"
#include "../ANL_Noise/templates/tcurve.h"

namespace anl
{
    class CRGBACurve : public CRGBAModuleBase
    {
        public:
        CRGBACurve();
        ~CRGBACurve();

        void pushPoint(double t, float r, float g, float b, float a);
        void clearCurve();
        void setSource(double t);
        void setSource(std::shared_ptr<CImplicitModuleBase> m);
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
