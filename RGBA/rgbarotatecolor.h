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
        CRGBARotateColor(SRGBA src, double ax, double ay, double az, double angle);
        CRGBARotateColor(SRGBA src, double ax, double ay, double az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, double ax, double ay, CImplicitModuleBase * az, double angle);
        CRGBARotateColor(SRGBA src, double ax, double ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, double ax, CImplicitModuleBase * ay, double az, double angle);
        CRGBARotateColor(SRGBA src, double ax, CImplicitModuleBase * ay, double az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, double ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, double angle);
        CRGBARotateColor(SRGBA src, double ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, double ay, double az, double angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, double ay, double az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, double ay, CImplicitModuleBase * az, double angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, double ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, double az, double angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, double az, CImplicitModuleBase * angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, double angle);
        CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, double ax, double ay, double az, double angle);
        CRGBARotateColor(CRGBAModuleBase * src, double ax, double ay, double az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, double ax, double ay, CImplicitModuleBase * az, double angle);
        CRGBARotateColor(CRGBAModuleBase * src, double ax, double ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, double ax, CImplicitModuleBase * ay, double az, double angle);
        CRGBARotateColor(CRGBAModuleBase * src, double ax, CImplicitModuleBase * ay, double az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, double ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, double angle);
        CRGBARotateColor(CRGBAModuleBase * src, double ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, double ay, double az, double angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, double ay, double az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, double ay, CImplicitModuleBase * az, double angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, double ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, double az, double angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, double az, CImplicitModuleBase * angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, double angle);
        CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle);


        void setAxis(double ax, double ay, double az);
        void setAxis(CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az);
        void setAxisX(double ax);
        void setAxisY(double ay);
        void setAxisZ(double az);
        void setAxisX(CImplicitModuleBase * ax);
        void setAxisY(CImplicitModuleBase * ay);
        void setAxisZ(CImplicitModuleBase * az);

        void setNormalizeAxis(bool n){m_normalizeaxis=n;}

        void setAngle(double a);
        void setAngle(CImplicitModuleBase * a);

        void setSource(CRGBAModuleBase * m);
        void setSource(SRGBA c);

        SRGBA get(double x, double y);
        SRGBA get(double x, double y, double z);
        SRGBA get(double x, double y, double z, double w);
        SRGBA get(double x, double y, double z, double w, double u, double v);

        protected:
        CScalarParameter m_ax, m_ay, m_az, m_angledeg;
        CRGBAParameter m_source;
        bool m_normalizeaxis;
        double m_rotmatrix[3][3];
        void calculateRotMatrix(double x, double y);
        void calculateRotMatrix(double x, double y, double z);
        void calculateRotMatrix(double x, double y, double z, double w);
        void calculateRotMatrix(double x, double y, double z, double w, double u, double v);
    };
};

#endif
