#include "implicitbasisfunction.h"
#include <cmath>
#include "random_gen.h"

using namespace anl;

CImplicitBasisFunction::CImplicitBasisFunction() : CImplicitModuleBase()
{
    m_rotatedomain=true;
	setType(GRADIENT);
	setInterp(QUINTIC);
	setSeed(1000);

}
CImplicitBasisFunction::CImplicitBasisFunction(int type, int interp, bool rotatedomain) :  CImplicitModuleBase()
{
    m_rotatedomain=rotatedomain;
	setType(type);
	setInterp(interp);
	setSeed(1000);
}

void CImplicitBasisFunction::setSeed(unsigned int seed)
{
    m_seed=seed;
    LCG lcg;
    lcg.setSeed(seed);

    if(m_rotatedomain)
    {
        ANLFloatType ax,ay,az;
        ANLFloatType len;

        ax=lcg.get01();
        ay=lcg.get01();
        az=lcg.get01();
        len=sqrt(ax*ax+ay*ay+az*az);
        ax/=len;
        ay/=len;
        az/=len;
        setRotationAngle(ax,ay,az,lcg.get01()*3.141592*2.0);
        ANLFloatType angle=lcg.get01()*3.14159265*2.0;
        cos2d=cos(angle);
        sin2d=sin(angle);
    }
    else
    {
        setNoRotation();
    }
}

void CImplicitBasisFunction::setType(int type)
{
	switch(type)
	{
	case VALUE: m_2d=value_noise2D; m_3d=value_noise3D; m_4d=value_noise4D; m_6d=value_noise6D; break;
	case GRADIENT: m_2d=gradient_noise2D; m_3d=gradient_noise3D; m_4d=gradient_noise4D; m_6d=gradient_noise6D; break;
	case GRADVAL: m_2d=gradval_noise2D; m_3d=gradval_noise3D; m_4d=gradval_noise4D; m_6d=gradval_noise6D; break;
	case WHITE: m_2d=white_noise2D; m_3d=white_noise3D; m_4d=white_noise4D; m_6d=white_noise6D; break;
	case SIMPLEX: m_2d=simplex_noise2D; m_3d=simplex_noise3D; m_4d=simplex_noise4D; m_6d=simplex_noise6D; break;
	default: m_2d=gradient_noise2D; m_3d=gradient_noise3D; m_4d=gradient_noise4D; m_6d=gradient_noise6D; break;
	}
	setMagicNumbers(type);
}

void CImplicitBasisFunction::setInterp(int interp)
{
	switch(interp)
	{
	case NONE: m_interp=noInterp; break;
	case LINEAR: m_interp=linearInterp; break;
	case CUBIC: m_interp=hermiteInterp; break;
	default: m_interp=quinticInterp; break;
	}
}

ANLFloatType CImplicitBasisFunction::get(ANLFloatType x, ANLFloatType y)
{
	ANLFloatType nx,ny;
    nx = x*cos2d-y*sin2d;
    ny = y*cos2d+x*sin2d;
	return m_2d(nx,ny,m_seed,m_interp);
}
ANLFloatType CImplicitBasisFunction::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    ANLFloatType nx, ny, nz;
    nx = (m_rotmatrix[0][0]*x) + (m_rotmatrix[1][0]*y) + (m_rotmatrix[2][0]*z);
    ny = (m_rotmatrix[0][1]*x) + (m_rotmatrix[1][1]*y) + (m_rotmatrix[2][1]*z);
    nz = (m_rotmatrix[0][2]*x) + (m_rotmatrix[1][2]*y) + (m_rotmatrix[2][2]*z);
    return m_3d(nx,ny,nz,m_seed,m_interp);
}
ANLFloatType CImplicitBasisFunction::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
	ANLFloatType nx, ny, nz;
    nx = (m_rotmatrix[0][0]*x) + (m_rotmatrix[1][0]*y) + (m_rotmatrix[2][0]*z);
    ny = (m_rotmatrix[0][1]*x) + (m_rotmatrix[1][1]*y) + (m_rotmatrix[2][1]*z);
    nz = (m_rotmatrix[0][2]*x) + (m_rotmatrix[1][2]*y) + (m_rotmatrix[2][2]*z);
	return m_4d(nx,ny,nz,w,m_seed,m_interp);
}
ANLFloatType CImplicitBasisFunction::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
	ANLFloatType nx, ny, nz;
    nx = (m_rotmatrix[0][0]*x) + (m_rotmatrix[1][0]*y) + (m_rotmatrix[2][0]*z);
    ny = (m_rotmatrix[0][1]*x) + (m_rotmatrix[1][1]*y) + (m_rotmatrix[2][1]*z);
    nz = (m_rotmatrix[0][2]*x) + (m_rotmatrix[1][2]*y) + (m_rotmatrix[2][2]*z);
	return m_6d(nx,ny,nz,w,u,v,m_seed,m_interp);
}

void CImplicitBasisFunction::setNoRotation()
{
    m_rotatedomain=false;
     m_rotmatrix[0][0] = 1;
    m_rotmatrix[1][0] = 0;
    m_rotmatrix[2][0] = 0;

    m_rotmatrix[0][1] = 0;
    m_rotmatrix[1][1] = 1;
    m_rotmatrix[2][1] = 0;

    m_rotmatrix[0][2] = 0;
    m_rotmatrix[1][2] = 0;
    m_rotmatrix[2][2] = 1;

    cos2d=1;
	sin2d=0;
}

void CImplicitBasisFunction::setRotationAngle(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType angle)
{
    m_rotatedomain=true;
    m_rotmatrix[0][0] = 1 + (1-cos(angle))*(x*x-1);
    m_rotmatrix[1][0] = -z*sin(angle)+(1-cos(angle))*x*y;
    m_rotmatrix[2][0] = y*sin(angle)+(1-cos(angle))*x*z;

    m_rotmatrix[0][1] = z*sin(angle)+(1-cos(angle))*x*y;
    m_rotmatrix[1][1] = 1 + (1-cos(angle))*(y*y-1);
    m_rotmatrix[2][1] = -x*sin(angle)+(1-cos(angle))*y*z;

    m_rotmatrix[0][2] = -y*sin(angle)+(1-cos(angle))*x*z;
    m_rotmatrix[1][2] = x*sin(angle)+(1-cos(angle))*y*z;
    m_rotmatrix[2][2] = 1 + (1-cos(angle))*(z*z-1);

    cos2d=cos(angle);
	sin2d=sin(angle);
}

void CImplicitBasisFunction::setMagicNumbers(int type)
{
    // This function is a damned hack.
    // The underlying noise functions don't return values in the range [-1,1] cleanly, and the ranges vary depending
    // on basis type and dimensionality. There's probably a better way to correct the ranges, but for now I'm just
    // setting he magic numbers m_scale and m_offset manually to empirically determined magic numbers.
    switch(type)
    {
        case VALUE:
        {
            m_scale[0]=1.0; m_offset[0]=0.0;
            m_scale[1]=1.0; m_offset[1]=0.0;
            m_scale[2]=1.0; m_offset[2]=0.0;
            m_scale[3]=1.0; m_offset[3]=0.0;
        } break;

        case GRADIENT:
        {
            m_scale[0]=1.86848; m_offset[0]=-0.000118;
            m_scale[1]=1.85148; m_offset[1]=-0.008272;
            m_scale[2]=1.64127; m_offset[2]=-0.01527;
            m_scale[3]=1.92517; m_offset[3]=0.03393;
        } break;

        case GRADVAL:
        {
            m_scale[0]=0.6769; m_offset[0]=-0.00151;
            m_scale[1]=0.6957; m_offset[1]=-0.133;
            m_scale[2]=0.74622; m_offset[2]=0.01916;
            m_scale[3]=0.7961; m_offset[3]=-0.0352;
        } break;

        case WHITE:
        {
            m_scale[0]=1.0; m_offset[0]=0.0;
            m_scale[1]=1.0; m_offset[1]=0.0;
            m_scale[2]=1.0; m_offset[2]=0.0;
            m_scale[3]=1.0; m_offset[3]=0.0;
        } break;

        default:
        {
            m_scale[0]=1.0; m_offset[0]=0.0;
            m_scale[1]=1.0; m_offset[1]=0.0;
            m_scale[2]=1.0; m_offset[2]=0.0;
            m_scale[3]=1.0; m_offset[3]=0.0;
        } break;
    };
}
