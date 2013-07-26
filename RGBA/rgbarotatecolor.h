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
        CRGBARotateColor(SRGBA src, double ax, double ay, double az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(SRGBA src, double ax, double ay, std::shared_ptr<CImplicitModuleBase> az, double angle);
        CRGBARotateColor(SRGBA src, double ax, double ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(SRGBA src, double ax, std::shared_ptr<CImplicitModuleBase> ay, double az, double angle);
        CRGBARotateColor(SRGBA src, double ax, std::shared_ptr<CImplicitModuleBase> ay, double az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(SRGBA src, double ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, double angle);
        CRGBARotateColor(SRGBA src, double ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(SRGBA src, std::shared_ptr<CImplicitModuleBase> ax, double ay, double az, double angle);
        CRGBARotateColor(SRGBA src, std::shared_ptr<CImplicitModuleBase> ax, double ay, double az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(SRGBA src, std::shared_ptr<CImplicitModuleBase> ax, double ay, std::shared_ptr<CImplicitModuleBase> az, double angle);
        CRGBARotateColor(SRGBA src, std::shared_ptr<CImplicitModuleBase> ax, double ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(SRGBA src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, double az, double angle);
        CRGBARotateColor(SRGBA src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, double az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(SRGBA src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, double angle);
        CRGBARotateColor(SRGBA src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, double ax, double ay, double az, double angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, double ax, double ay, double az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, double ax, double ay, std::shared_ptr<CImplicitModuleBase> az, double angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, double ax, double ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, double ax, std::shared_ptr<CImplicitModuleBase> ay, double az, double angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, double ax, std::shared_ptr<CImplicitModuleBase> ay, double az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, double ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, double angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, double ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, double ay, double az, double angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, double ay, double az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, double ay, std::shared_ptr<CImplicitModuleBase> az, double angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, double ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, double az, double angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, double az, std::shared_ptr<CImplicitModuleBase> angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, double angle);
        CRGBARotateColor(std::shared_ptr<CRGBAModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle);


        void setAxis(double ax, double ay, double az);
        void setAxis(std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az);
        void setAxisX(double ax);
        void setAxisY(double ay);
        void setAxisZ(double az);
        void setAxisX(std::shared_ptr<CImplicitModuleBase> ax);
        void setAxisY(std::shared_ptr<CImplicitModuleBase> ay);
        void setAxisZ(std::shared_ptr<CImplicitModuleBase> az);

        void setNormalizeAxis(bool n){m_normalizeaxis=n;}

        void setAngle(double a);
        void setAngle(std::shared_ptr<CImplicitModuleBase> a);

        void setSource(std::shared_ptr<CRGBAModuleBase> m);
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
