#include "implicitrotatedomain.h"
#include <cmath>

namespace anl
{

    CImplicitRotateDomain::CImplicitRotateDomain(double src, double ax, double ay, double az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, double ax, double ay, double az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, double ax, double ay, std::shared_ptr<CImplicitModuleBase> az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, double ax, double ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, double ax, std::shared_ptr<CImplicitModuleBase> ay, double az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, double ax, std::shared_ptr<CImplicitModuleBase> ay, double az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, double ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, double ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, std::shared_ptr<CImplicitModuleBase> ax, double ay, double az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, std::shared_ptr<CImplicitModuleBase> ax, double ay, double az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, std::shared_ptr<CImplicitModuleBase> ax, double ay, std::shared_ptr<CImplicitModuleBase> az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, std::shared_ptr<CImplicitModuleBase> ax, double ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, double az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, double az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(double src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, double ax, double ay, double az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, double ax, double ay, double az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, double ax, double ay, std::shared_ptr<CImplicitModuleBase> az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, double ax, double ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, double ax, std::shared_ptr<CImplicitModuleBase> ay, double az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, double ax, std::shared_ptr<CImplicitModuleBase> ay, double az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, double ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, double ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, double ay, double az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, double ay, double az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, double ay, std::shared_ptr<CImplicitModuleBase> az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, double ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, double az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, double az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, double angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }

    CImplicitRotateDomain::CImplicitRotateDomain(std::shared_ptr<CImplicitModuleBase> src, std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az, std::shared_ptr<CImplicitModuleBase> angle_deg) :
        CImplicitModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle_deg), m_source(src)
    {
    }


    CImplicitRotateDomain::~CImplicitRotateDomain(){}

    void CImplicitRotateDomain::setSource(std::shared_ptr<CImplicitModuleBase> m){m_source.set(m);}
    void CImplicitRotateDomain::setSource(double v){m_source.set(v);}

    void CImplicitRotateDomain::calculateRotMatrix(double x, double y)
    {
        double angle=m_angledeg.get(x,y)*360.0 * 3.14159265/180.0;
        double ax=m_ax.get(x,y);
        double ay=m_ay.get(x,y);
        double az=m_az.get(x,y);

        double cosangle=cos(angle);
        double sinangle=sin(angle);

        m_rotmatrix[0][0] = 1.0 + (1.0-cosangle)*(ax*ax-1.0);
        m_rotmatrix[1][0] = -az*sinangle+(1.0-cosangle)*ax*ay;
        m_rotmatrix[2][0] = ay*sinangle+(1.0-cosangle)*ax*az;

        m_rotmatrix[0][1] = az*sinangle+(1.0-cosangle)*ax*ay;
        m_rotmatrix[1][1] = 1.0 + (1.0-cosangle)*(ay*ay-1.0);
        m_rotmatrix[2][1] = -ax*sinangle+(1.0-cosangle)*ay*az;

        m_rotmatrix[0][2] = -ay*sinangle+(1.0-cosangle)*ax*az;
        m_rotmatrix[1][2] = ax*sinangle+(1.0-cosangle)*ay*az;
        m_rotmatrix[2][2] = 1.0 + (1.0-cosangle)*(az*az-1.0);
    }

    void CImplicitRotateDomain::calculateRotMatrix(double x, double y, double z)
    {
        double angle=m_angledeg.get(x,y,z)*360.0 * 3.14159265/180.0;
        double ax=m_ax.get(x,y,z);
        double ay=m_ay.get(x,y,z);
        double az=m_az.get(x,y,z);

        double cosangle=cos(angle);
        double sinangle=sin(angle);

        m_rotmatrix[0][0] = 1.0 + (1.0-cosangle)*(ax*ax-1.0);
        m_rotmatrix[1][0] = -az*sinangle+(1.0-cosangle)*ax*ay;
        m_rotmatrix[2][0] = ay*sinangle+(1.0-cosangle)*ax*az;

        m_rotmatrix[0][1] = az*sinangle+(1.0-cosangle)*ax*ay;
        m_rotmatrix[1][1] = 1.0 + (1.0-cosangle)*(ay*ay-1.0);
        m_rotmatrix[2][1] = -ax*sinangle+(1.0-cosangle)*ay*az;

        m_rotmatrix[0][2] = -ay*sinangle+(1.0-cosangle)*ax*az;
        m_rotmatrix[1][2] = ax*sinangle+(1.0-cosangle)*ay*az;
        m_rotmatrix[2][2] = 1.0 + (1.0-cosangle)*(az*az-1.0);
    }
    void CImplicitRotateDomain::calculateRotMatrix(double x, double y, double z, double w)
    {
        double angle=m_angledeg.get(x,y,z,w)*360.0 * 3.14159265/180.0;
        double ax=m_ax.get(x,y,z,w);
        double ay=m_ay.get(x,y,z,w);
        double az=m_az.get(x,y,z,w);

        double cosangle=cos(angle);
        double sinangle=sin(angle);

        m_rotmatrix[0][0] = 1.0 + (1.0-cosangle)*(ax*ax-1.0);
        m_rotmatrix[1][0] = -az*sinangle+(1.0-cosangle)*ax*ay;
        m_rotmatrix[2][0] = ay*sinangle+(1.0-cosangle)*ax*az;

        m_rotmatrix[0][1] = az*sinangle+(1.0-cosangle)*ax*ay;
        m_rotmatrix[1][1] = 1.0 + (1.0-cosangle)*(ay*ay-1.0);
        m_rotmatrix[2][1] = -ax*sinangle+(1.0-cosangle)*ay*az;

        m_rotmatrix[0][2] = -ay*sinangle+(1.0-cosangle)*ax*az;
        m_rotmatrix[1][2] = ax*sinangle+(1.0-cosangle)*ay*az;
        m_rotmatrix[2][2] = 1.0 + (1.0-cosangle)*(az*az-1.0);
    }
    void CImplicitRotateDomain::calculateRotMatrix(double x, double y, double z, double w, double u, double v)
    {
        double angle=m_angledeg.get(x,y,z,w,u,v)*360.0 * 3.14159265/180.0;
        double ax=m_ax.get(x,y,z,w,u,v);
        double ay=m_ay.get(x,y,z,w,u,v);
        double az=m_az.get(x,y,z,w,u,v);

        double cosangle=cos(angle);
        double sinangle=sin(angle);

        m_rotmatrix[0][0] = 1.0 + (1.0-cosangle)*(ax*ax-1.0);
        m_rotmatrix[1][0] = -az*sinangle+(1.0-cosangle)*ax*ay;
        m_rotmatrix[2][0] = ay*sinangle+(1.0-cosangle)*ax*az;

        m_rotmatrix[0][1] = az*sinangle+(1.0-cosangle)*ax*ay;
        m_rotmatrix[1][1] = 1.0 + (1.0-cosangle)*(ay*ay-1.0);
        m_rotmatrix[2][1] = -ax*sinangle+(1.0-cosangle)*ay*az;

        m_rotmatrix[0][2] = -ay*sinangle+(1.0-cosangle)*ax*az;
        m_rotmatrix[1][2] = ax*sinangle+(1.0-cosangle)*ay*az;
        m_rotmatrix[2][2] = 1.0 + (1.0-cosangle)*(az*az-1.0);
    }
    void CImplicitRotateDomain::setAxis(double ax, double ay, double az)
    {
        m_ax.set(ax);
        m_ay.set(ay);
        m_az.set(az);
    }

    void CImplicitRotateDomain::setAxis(std::shared_ptr<CImplicitModuleBase> ax, std::shared_ptr<CImplicitModuleBase> ay, std::shared_ptr<CImplicitModuleBase> az)
    {
        m_ax.set(ax);
        m_ay.set(ay);
        m_az.set(az);
    }
    void CImplicitRotateDomain::setAxisX(double ax)
    {
        m_ax.set(ax);
    }
    void CImplicitRotateDomain::setAxisY(double ay)
    {
        m_ay.set(ay);
    }
    void CImplicitRotateDomain::setAxisZ(double az)
    {
        m_az.set(az);
    }
    void CImplicitRotateDomain::setAxisX(std::shared_ptr<CImplicitModuleBase> ax)
    {
        m_ax.set(ax);
    }
    void CImplicitRotateDomain::setAxisY(std::shared_ptr<CImplicitModuleBase> ay)
    {
        m_ay.set(ay);
    }
    void CImplicitRotateDomain::setAxisZ(std::shared_ptr<CImplicitModuleBase> az)
    {
        m_az.set(az);
    }

    void CImplicitRotateDomain::setAngle(double a)
    {
        m_angledeg.set(a);
    }
    void CImplicitRotateDomain::setAngle(std::shared_ptr<CImplicitModuleBase> a)
    {
        m_angledeg.set(a);
    }

    double CImplicitRotateDomain::get(double x, double y)
    {
        double nx,ny;
        double angle=m_angledeg.get(x,y)*360.0 * 3.14159265/180.0;
        double cos2d=cos(angle);
        double sin2d=sin(angle);
        nx = x*cos2d-y*sin2d;
        ny = y*cos2d+x*sin2d;
        return m_source.get(nx,ny);
    }

    double CImplicitRotateDomain::get(double x, double y, double z)
    {
        calculateRotMatrix(x,y,z);
        double nx, ny, nz;
        nx = (m_rotmatrix[0][0]*x) + (m_rotmatrix[1][0]*y) + (m_rotmatrix[2][0]*z);
        ny = (m_rotmatrix[0][1]*x) + (m_rotmatrix[1][1]*y) + (m_rotmatrix[2][1]*z);
        nz = (m_rotmatrix[0][2]*x) + (m_rotmatrix[1][2]*y) + (m_rotmatrix[2][2]*z);
        return m_source.get(nx,ny,nz);
    }
    double CImplicitRotateDomain::get(double x, double y, double z, double w)
    {

        calculateRotMatrix(x,y,z,w);
        double nx, ny, nz;
        nx = (m_rotmatrix[0][0]*x) + (m_rotmatrix[1][0]*y) + (m_rotmatrix[2][0]*z);
        ny = (m_rotmatrix[0][1]*x) + (m_rotmatrix[1][1]*y) + (m_rotmatrix[2][1]*z);
        nz = (m_rotmatrix[0][2]*x) + (m_rotmatrix[1][2]*y) + (m_rotmatrix[2][2]*z);
        return m_source.get(nx,ny,nz,w);
    }
    double CImplicitRotateDomain::get(double x, double y, double z, double w, double u, double v)
    {

        calculateRotMatrix(x,y,z,w,u,v);
        double nx, ny, nz;
        nx = (m_rotmatrix[0][0]*x) + (m_rotmatrix[1][0]*y) + (m_rotmatrix[2][0]*z);
        ny = (m_rotmatrix[0][1]*x) + (m_rotmatrix[1][1]*y) + (m_rotmatrix[2][1]*z);
        nz = (m_rotmatrix[0][2]*x) + (m_rotmatrix[1][2]*y) + (m_rotmatrix[2][2]*z);
        return m_source.get(nx,ny,nz,w,u,v);
    }
};
