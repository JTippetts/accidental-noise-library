#ifndef IMPLICIT_ROTATEDOMAIN_H
#define IMPLICIT_ROTATEDOMAIN_H
#include "implicitmodulebase.h"

namespace anl
{
    /*
Given angle r in radians and unit vector u = ai + bj + ck or [a,b,c]', define:

q0 = cos(r/2),  q1 = sin(r/2) a,  q2 = sin(r/2) b,  q3 = sin(r/2) c

and construct from these values the rotation matrix:

     (q0² + q1² - q2² - q3²)      2(q1q2 - q0q3)          2(q1q3 + q0q2)

Q  =      2(q2q1 + q0q3)     (q0² - q1² + q2² - q3²)      2(q2q3 - q0q1)

          2(q3q1 - q0q2)          2(q3q2 + q0q1)     (q0² - q1² - q2² + q3²)

Multiplication by Q then effects the desired rotation, and in particular:

Q u = u
*/

class CImplicitRotateDomain : public CImplicitModuleBase
{
    public:
    CImplicitRotateDomain(ANLFloatType src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle_deg);
    CImplicitRotateDomain(ANLFloatType src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(ANLFloatType src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle_deg);
    CImplicitRotateDomain(ANLFloatType src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(ANLFloatType src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle_deg);
    CImplicitRotateDomain(ANLFloatType src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(ANLFloatType src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle_deg);
    CImplicitRotateDomain(ANLFloatType src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(ANLFloatType src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle_deg);
    CImplicitRotateDomain(ANLFloatType src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(ANLFloatType src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle_deg);
    CImplicitRotateDomain(ANLFloatType src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(ANLFloatType src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle_deg);
    CImplicitRotateDomain(ANLFloatType src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(ANLFloatType src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle_deg);
    CImplicitRotateDomain(ANLFloatType src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, ANLFloatType ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, ANLFloatType ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, ANLFloatType az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, ANLFloatType angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, CImplicitModuleBase * ax, ANLFloatType ay, CImplicitModuleBase * az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, ANLFloatType angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, ANLFloatType az, CImplicitModuleBase * angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, ANLFloatType angle_deg);
    CImplicitRotateDomain(CImplicitModuleBase * src, CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az, CImplicitModuleBase * angle_deg);

    ~CImplicitRotateDomain();
    void setSource(CImplicitModuleBase * m);
    void setSource(ANLFloatType v);
    void setAxis(ANLFloatType ax, ANLFloatType ay, ANLFloatType az);
    void setAxis(CImplicitModuleBase * ax, CImplicitModuleBase * ay, CImplicitModuleBase * az);
    void setAxisX(ANLFloatType ax);
    void setAxisY(ANLFloatType ay);
    void setAxisZ(ANLFloatType az);
    void setAxisX(CImplicitModuleBase * ax);
    void setAxisY(CImplicitModuleBase * ay);
    void setAxisZ(CImplicitModuleBase * az);

    void setAngle(ANLFloatType a);
    void setAngle(CImplicitModuleBase * a);

    ANLFloatType get(ANLFloatType x, ANLFloatType y);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

    protected:
    ANLFloatType m_rotmatrix[3][3];
    CScalarParameter m_ax,m_ay,m_az, m_angledeg;
    CScalarParameter m_source;

    void calculateRotMatrix(ANLFloatType x, ANLFloatType y);
    void calculateRotMatrix(ANLFloatType x, ANLFloatType y, ANLFloatType z);
    void calculateRotMatrix(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
    void calculateRotMatrix(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
};
};

#endif
