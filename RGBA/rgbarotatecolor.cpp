#include "rgbarotatecolor.h"
#include <math.h>
#include "utility.h"

namespace anl
{
    CRGBARotateColor::CRGBARotateColor() : m_ax(0.0), m_ay(0.0), m_az(1.0), m_angledeg(0.0), m_source(), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(SRGBA src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}

    CRGBARotateColor::CRGBARotateColor(CRGBAModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle) :
        CRGBAModuleBase(), m_ax(ax), m_ay(ay), m_az(az), m_angledeg(angle), m_source(src), m_normalizeaxis(false){}



    void CRGBARotateColor::setAxis(ANLFloatType ax, ANLFloatType ay, ANLFloatType az)
    {
        m_ax.set(ax);
        m_ay.set(ay);
        m_az.set(az);
    }
    void CRGBARotateColor::setAxis(CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az)
    {
        m_ax.set(ax);
        m_ay.set(ay);
        m_az.set(az);
    }
    void CRGBARotateColor::setAxisX(ANLFloatType ax)
    {
        m_ax.set(ax);
    }
    void CRGBARotateColor::setAxisY(ANLFloatType ay)
    {
        m_ay.set(ay);
    }
    void CRGBARotateColor::setAxisZ(ANLFloatType az)
    {
        m_az.set(az);
    }
    void CRGBARotateColor::setAxisX(CImplicitModuleBase * ax)
    {
        m_ax.set(ax);
    }
    void CRGBARotateColor::setAxisY(CImplicitModuleBase * ay)
    {
        m_ay.set(ay);
    }
    void CRGBARotateColor::setAxisZ(CImplicitModuleBase * az)
    {
        m_az.set(az);
    }
    void CRGBARotateColor::setAngle(ANLFloatType a)
    {
        m_angledeg.set(a);
    }
    void CRGBARotateColor::setAngle(CImplicitModuleBase * a)
    {
        m_angledeg.set(a);
    }
    void CRGBARotateColor::setSource(CRGBAModuleBase * m)
    {
        m_source.set(m);
    }
    void CRGBARotateColor::setSource(SRGBA c)
    {
        m_source.set(c);
    }
    SRGBA CRGBARotateColor::get(ANLFloatType x, ANLFloatType y)
    {
        SRGBA s=m_source.get(x,y);
        calculateRotMatrix(x,y);

        s[0]=s[0]*2.0f-1.0f;
        s[1]=s[1]*2.0f-1.0f;
        s[2]=s[2]*2.0f-1.0f;


        s=SRGBA(
            (float)((m_rotmatrix[0][0]*s[0]) + (m_rotmatrix[1][0]*s[1]) + (m_rotmatrix[2][0]*s[2])),
            (float)((m_rotmatrix[0][1]*s[0]) + (m_rotmatrix[1][1]*s[1]) + (m_rotmatrix[2][1]*s[2])),
            (float)((m_rotmatrix[0][2]*s[0]) + (m_rotmatrix[1][2]*s[1]) + (m_rotmatrix[2][2]*s[2])),
            s[3]);

        s[0]=(float)clamp(s[0]*0.5+0.5,0.0,1.0);
        s[1]=(float)clamp(s[1]*0.5+0.5,0.0,1.0);
        s[2]=(float)clamp(s[2]*0.5+0.5,0.0,1.0);

        return s;

    }
    SRGBA CRGBARotateColor::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        SRGBA s=m_source.get(x,y,z);
        calculateRotMatrix(x,y,z);

        s[0]=s[0]*2.0f-1.0f;
        s[1]=s[1]*2.0f-1.0f;
        s[2]=s[2]*2.0f-1.0f;


        s=SRGBA(
            (float)((m_rotmatrix[0][0]*s[0]) + (m_rotmatrix[1][0]*s[1]) + (m_rotmatrix[2][0]*s[2])),
            (float)((m_rotmatrix[0][1]*s[0]) + (m_rotmatrix[1][1]*s[1]) + (m_rotmatrix[2][1]*s[2])),
            (float)((m_rotmatrix[0][2]*s[0]) + (m_rotmatrix[1][2]*s[1]) + (m_rotmatrix[2][2]*s[2])),
            s[3]);

        s[0]=(float)clamp(s[0]*0.5+0.5,0.0,1.0);
        s[1]=(float)clamp(s[1]*0.5+0.5,0.0,1.0);
        s[2]=(float)clamp(s[2]*0.5+0.5,0.0,1.0);

        return s;
    }
    SRGBA CRGBARotateColor::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        SRGBA s=m_source.get(x,y,z,w);
        calculateRotMatrix(x,y,z,w);

        s[0]=s[0]*2.0f-1.0f;
        s[1]=s[1]*2.0f-1.0f;
        s[2]=s[2]*2.0f-1.0f;


        s=SRGBA(
            (float)((m_rotmatrix[0][0]*s[0]) + (m_rotmatrix[1][0]*s[1]) + (m_rotmatrix[2][0]*s[2])),
            (float)((m_rotmatrix[0][1]*s[0]) + (m_rotmatrix[1][1]*s[1]) + (m_rotmatrix[2][1]*s[2])),
            (float)((m_rotmatrix[0][2]*s[0]) + (m_rotmatrix[1][2]*s[1]) + (m_rotmatrix[2][2]*s[2])),
            s[3]);

        s[0]=(float)clamp(s[0]*0.5+0.5,0.0,1.0);
        s[1]=(float)clamp(s[1]*0.5+0.5,0.0,1.0);
        s[2]=(float)clamp(s[2]*0.5+0.5,0.0,1.0);

        return s;
    }
    SRGBA CRGBARotateColor::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        SRGBA s=m_source.get(x,y,z,w,u,v);
        calculateRotMatrix(x,y,z,w,u,v);

        s[0]=s[0]*2.0f-1.0f;
        s[1]=s[1]*2.0f-1.0f;
        s[2]=s[2]*2.0f-1.0f;


        s=SRGBA(
            (float)((m_rotmatrix[0][0]*s[0]) + (m_rotmatrix[1][0]*s[1]) + (m_rotmatrix[2][0]*s[2])),
            (float)((m_rotmatrix[0][1]*s[0]) + (m_rotmatrix[1][1]*s[1]) + (m_rotmatrix[2][1]*s[2])),
            (float)((m_rotmatrix[0][2]*s[0]) + (m_rotmatrix[1][2]*s[1]) + (m_rotmatrix[2][2]*s[2])),
            s[3]);

        s[0]=(float)clamp(s[0]*0.5+0.5,0.0,1.0);
        s[1]=(float)clamp(s[1]*0.5+0.5,0.0,1.0);
        s[2]=(float)clamp(s[2]*0.5+0.5,0.0,1.0);

        return s;
    }

    void CRGBARotateColor::calculateRotMatrix(ANLFloatType x, ANLFloatType y)
    {
        ANLFloatType angle=m_angledeg.get(x,y)*360.0 * 3.14159265/180.0;
        ANLFloatType ax=m_ax.get(x,y);
        ANLFloatType ay=m_ay.get(x,y);
        ANLFloatType az=m_az.get(x,y);

        if(m_normalizeaxis)
        {
            ANLFloatType len=sqrt(ax*ax+ay*ay+az*az);
            ax/=len;
            ay/=len;
            az/=len;
        }

        ANLFloatType cosangle=cos(angle);
        ANLFloatType sinangle=sin(angle);

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

    void CRGBARotateColor::calculateRotMatrix(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        ANLFloatType angle=m_angledeg.get(x,y,z)*360.0 * 3.14159265/180.0;
        ANLFloatType ax=m_ax.get(x,y,z);
        ANLFloatType ay=m_ay.get(x,y,z);
        ANLFloatType az=m_az.get(x,y,z);
        if(m_normalizeaxis)
        {
            ANLFloatType len=sqrt(ax*ax+ay*ay+az*az);
            ax/=len;
            ay/=len;
            az/=len;
        }

        ANLFloatType cosangle=cos(angle);
        ANLFloatType sinangle=sin(angle);

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

    void CRGBARotateColor::calculateRotMatrix(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        ANLFloatType angle=m_angledeg.get(x,y,z,w)*360.0 * 3.14159265/180.0;
        ANLFloatType ax=m_ax.get(x,y,z,w);
        ANLFloatType ay=m_ay.get(x,y,z,w);
        ANLFloatType az=m_az.get(x,y,z,w);
        if(m_normalizeaxis)
        {
            ANLFloatType len=sqrt(ax*ax+ay*ay+az*az);
            ax/=len;
            ay/=len;
            az/=len;
        }

        ANLFloatType cosangle=cos(angle);
        ANLFloatType sinangle=sin(angle);

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
    void CRGBARotateColor::calculateRotMatrix(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        ANLFloatType angle=m_angledeg.get(x,y,z,w,u,v)*360.0 * 3.14159265/180.0;
        ANLFloatType ax=m_ax.get(x,y,z,w,u,v);
        ANLFloatType ay=m_ay.get(x,y,z,w,u,v);
        ANLFloatType az=m_az.get(x,y,z,w,u,v);
        if(m_normalizeaxis)
        {
            ANLFloatType len=sqrt(ax*ax+ay*ay+az*az);
            ax/=len;
            ay/=len;
            az/=len;
        }

        ANLFloatType cosangle=cos(angle);
        ANLFloatType sinangle=sin(angle);

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
};
