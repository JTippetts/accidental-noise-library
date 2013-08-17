#ifndef RGBA_ROTATECOLOR_H
#define RGBA_ROTATECOLOR_H
#include "rgbamodulebase.h"
#include "../Noise/implicitmodulebase.h"

namespace anl
{
    class CRGBARotateColor : public CRGBAModuleBase
    {
        public:
        CRGBARotateColor();
        CRGBARotateColor(SRGBA src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CRGBARotateColor(SRGBA src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle);
        CRGBARotateColor(SRGBA src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle);
        CRGBARotateColor(SRGBA src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle);
        CRGBARotateColor(SRGBA src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle);
        CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle);
        CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle);
        CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);


        void setAxis(ANLFloatType ax, ANLFloatType ay, ANLFloatType az);
        void setAxis(CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az);
        void setAxisX(ANLFloatType ax);
        void setAxisY(ANLFloatType ay);
        void setAxisZ(ANLFloatType az);
        void setAxisX(CImplicitModuleBase * ax);
        void setAxisY(CImplicitModuleBase * ay);
        void setAxisZ(CImplicitModuleBase * az);

        void setNormalizeAxis(bool n){m_normalizeaxis=n;}

        void setAngle(ANLFloatType a);
        void setAngle(CImplicitModuleBase * a);

        void setSource(CRGBAModuleBase * m);
        void setSource(SRGBA c);

        SRGBA get(ANLFloatType x, ANLFloatType y);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CScalarParameter m_ax, m_ay, m_az, m_angledeg;
        CRGBAParameter m_source;
        bool m_normalizeaxis;
        ANLFloatType m_rotmatrix[3][3];
        void calculateRotMatrix(ANLFloatType x, ANLFloatType y);
        void calculateRotMatrix(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        void calculateRotMatrix(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        void calculateRotMatrix(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
    };
};

#endif
