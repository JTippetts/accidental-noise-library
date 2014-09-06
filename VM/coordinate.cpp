#include "coordinate.h"

namespace anl
{
    CCoordinate::CCoordinate()
    {
        set(0,0);
    }

    CCoordinate::CCoordinate(ANLFloatType x, ANLFloatType y)
    {
        set(x,y);
    }

    CCoordinate::CCoordinate(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        set(x,y,z);
    }

    CCoordinate::CCoordinate(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        set(x,y,z,w);
    }

    CCoordinate::CCoordinate(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        set(x,y,z,w,u,v);
    }

    void CCoordinate::set(ANLFloatType x, ANLFloatType y)
    {
        dimension_=2;
        x_=x;
        y_=y;
        z_=0;
        w_=0;
        u_=0;
        v_=0;
    }

    void CCoordinate::set(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        dimension_=3;
        x_=x;
        y_=y;
        z_=z;
        w_=0;
        u_=0;
        v_=0;
    }

    void CCoordinate::set(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        dimension_=4;
        x_=x;
        y_=y;
        z_=z;
        w_=w;
        u_=0;
        v_=0;
    }

    void CCoordinate::set(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        dimension_=6;
        x_=x;
        y_=y;
        z_=z;
        w_=w;
        u_=u;
        v_=v;
    }

    CCoordinate CCoordinate::operator *(ANLFloatType rhs)
    {
        CCoordinate ret(0,0);
        ret.dimension_=dimension_;
        ret.x_=x_*rhs;
        ret.y_=y_*rhs;
        ret.z_=z_*rhs;
        ret.w_=w_*rhs;
        ret.u_=u_*rhs;
        ret.v_=v_*rhs;
        return ret;
    }

    CCoordinate CCoordinate::operator *(CCoordinate &rhs)
    {
        CCoordinate ret(0,0);
        ret.dimension_=dimension_;
        ret.x_=x_*rhs.x_;
        ret.y_=y_*rhs.y_;
        ret.z_=z_*rhs.z_;
        ret.w_=w_*rhs.w_;
        ret.u_=u_*rhs.u_;
        ret.v_=v_*rhs.v_;
        return ret;
    }

    CCoordinate CCoordinate::operator +(CCoordinate &rhs)
    {
        CCoordinate ret(0,0);
        ret.dimension_=dimension_;
        ret.x_=x_+rhs.x_;
        ret.y_=y_+rhs.y_;
        ret.z_=z_+rhs.z_;
        ret.w_=w_+rhs.w_;
        ret.u_=u_+rhs.u_;
        ret.v_=v_+rhs.v_;
        return ret;
    }
};
