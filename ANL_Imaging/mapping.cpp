#include "mapping.h"
#include <cmath>
#include <fstream>
#include <iostream>

namespace anl
{
   void map2D(int seamlessmode, CArray2Dd &a, CImplicitModuleBase &m, SMappingRanges &ranges, double z)
   {
        int w=a.width();
        int h=a.height();
        static double pi2=3.141592*2.0;

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                double p=(double)x / (double)w;
                double q=(double)y / (double)h;
                double r;
                double nx,ny,nz,nw,nu,nv,val=0.0;
                double dx, dy, dz;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
                        nz=z;
                        val=m.get(nx,ny,nz);
                    } break;
                    case SEAMLESS_X:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=z;
                        val=m.get(nx,ny,nz,nw);
                    } break;
                    case SEAMLESS_Y:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=z;
                        val=m.get(nx,ny,nz,nw);
                    } break;
                    case SEAMLESS_Z:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.mapy0 + p*dx;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nz=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nw=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        val=m.get(nx,ny,nz,nw);
                    } break;
                    case SEAMLESS_XY:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nu=z;
                        val=m.get(nx,ny,nz,nw,nu,0);
                    } break;
                    case SEAMLESS_XZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapx1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) *dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        val=m.get(nx,ny,nz,nw,nu,0);
                    } break;
                    case SEAMLESS_YZ:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0+p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        val=m.get(nx,ny,nz,nw,nu,0);
                    } break;
                    case SEAMLESS_XYZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                        nu=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nv=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        val=m.get(nx,ny,nz,nw,nu,nv);
                    } break;

                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

   void map2DNoZ(int seamlessmode, CArray2Dd &a, CImplicitModuleBase &m, SMappingRanges &ranges)
   {
        int w=a.width();
        int h=a.height();
        static double pi2=3.141592*2.0;

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                double p=(double)x / (double)w;
                double q=(double)y / (double)h;
                double nx,ny,nz,nw,val=0.0;
                double dx, dy;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
                        val=m.get(nx,ny);
                    } break;
                    case SEAMLESS_X:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        val=m.get(nx,ny,nz);
                    } break;
                    case SEAMLESS_Y:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        val=m.get(nx,ny,nz);
                    } break;

                    case SEAMLESS_XY:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        val=m.get(nx,ny,nz,nw);
                    } break;
                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

    void map3D(int seamlessmode, CArray3Dd &a, CImplicitModuleBase &m, SMappingRanges &ranges)
    {
        int w=a.width();
        int h=a.height();
        int d=a.depth();

        int x,y,z;
        static double pi2=3.14159265 * 2.0;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                for(z=0; z<d; ++z)
                {
                    double p=(double)x/(double)w;
                    double q=(double)y/(double)h;
                    double r=(double)z/(double)d;
                    double nx,ny,nz,nw,nu,nv;
                    double dx,dy,dz;
                    double val=0.0;

                    switch(seamlessmode)
                    {
                        case SEAMLESS_NONE:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.mapy0 + q*dy;
                            nz=ranges.mapz0 + r*dz;
                            val=m.get(nx,ny,nz);
                        } break;
                        case SEAMLESS_X:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.mapy0 + q*dy;
                            nw=ranges.mapz0 + d*dz;
                            val=m.get(nx,ny,nz,nw);
                        }
                        case SEAMLESS_Y:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nz=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nw=ranges.mapz0 + r*dz;
                            val=m.get(nx,ny,nz,nw);
                        } break;
                        case SEAMLESS_Z:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.mapy0 + q*dy;
                            nz=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nw=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            val=m.get(nx,ny,nz,nw);
                        } break;
                        case SEAMLESS_XY:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nu=ranges.mapz0 + r*dz;
                            val=m.get(nx,ny,nz,nw,nu,0);
                        } break;
                        case SEAMLESS_XZ:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.mapy0 + q*dy;
                            nw=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nu=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            val=m.get(nx,ny,nz,nw,nu,0);
                        } break;
                        case SEAMLESS_YZ:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nz=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nw=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nu=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            val=m.get(nx,ny,nz,nw,nu,0);
                        } break;
                        case SEAMLESS_XYZ:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nu=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nv=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            val=m.get(nx,ny,nz,nw,nu,nv);
                        } break;
                        default: break;
                    }
                    a.set(x,y,z,val);
                }
            }
        }
    }




    void mapRGBA2D(int seamlessmode, CArray2Drgba &a, CRGBAModuleBase &m, SMappingRanges &ranges, double z)
   {
        int w=a.width();
        int h=a.height();
        static double pi2=3.141592*2.0;

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                double p=(double)x / (double)w;
                double q=(double)y / (double)h;
                double r;
                double nx,ny,nz,nw,nu,nv=0.0;
                SRGBA val;
                double dx, dy, dz;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
                        nz=z;
                        val=m.get(nx,ny,nz);
                    } break;
                    case SEAMLESS_X:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=z;
                        val=m.get(nx,ny,nz,nw);
                    } break;
                    case SEAMLESS_Y:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=z;
                        val=m.get(nx,ny,nz,nw);
                    } break;
                    case SEAMLESS_Z:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.mapy0 + p*dx;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nz=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nw=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        val=m.get(nx,ny,nz,nw);
                    } break;
                    case SEAMLESS_XY:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nu=z;
                        val=m.get(nx,ny,nz,nw,nu,0);
                    } break;
                    case SEAMLESS_XZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapx1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) *dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        val=m.get(nx,ny,nz,nw,nu,0);
                    } break;
                    case SEAMLESS_YZ:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0+p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        val=m.get(nx,ny,nz,nw,nu,0);
                    } break;
                    case SEAMLESS_XYZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                        nu=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nv=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        val=m.get(nx,ny,nz,nw,nu,nv);
                    } break;

                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

   void mapRGBA2DNoZ(int seamlessmode, CArray2Drgba &a, CRGBAModuleBase &m, SMappingRanges &ranges)
   {
        int w=a.width();
        int h=a.height();
        static double pi2=3.141592*2.0;

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                double p=(double)x / (double)w;
                double q=(double)y / (double)h;
                double nx,ny,nz,nw=0.0;
                SRGBA val;
                double dx, dy;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
                        val=m.get(nx,ny);
                    } break;
                    case SEAMLESS_X:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        val=m.get(nx,ny,nz);
                    } break;
                    case SEAMLESS_Y:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        val=m.get(nx,ny,nz);
                    } break;

                    case SEAMLESS_XY:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        val=m.get(nx,ny,nz,nw);
                    } break;
                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

    void mapRGBA3D(int seamlessmode, CArray3Drgba &a, CRGBAModuleBase &m, SMappingRanges &ranges)
    {
        int w=a.width();
        int h=a.height();
        int d=a.depth();

        int x,y,z;
        static double pi2=3.14159265 * 2.0;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                for(z=0; z<d; ++z)
                {
                    double p=(double)x/(double)w;
                    double q=(double)y/(double)h;
                    double r=(double)z/(double)d;
                    double nx,ny,nz,nw,nu,nv;
                    double dx,dy,dz;
                    SRGBA val;

                    switch(seamlessmode)
                    {
                        case SEAMLESS_NONE:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.mapy0 + q*dy;
                            nz=ranges.mapz0 + r*dz;
                            val=m.get(nx,ny,nz);
                        } break;
                        case SEAMLESS_X:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.mapy0 + q*dy;
                            nw=ranges.mapz0 + d*dz;
                            val=m.get(nx,ny,nz,nw);
                        }
                        case SEAMLESS_Y:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nz=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nw=ranges.mapz0 + r*dz;
                            val=m.get(nx,ny,nz,nw);
                        } break;
                        case SEAMLESS_Z:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.mapy0 + q*dy;
                            nz=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nw=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            val=m.get(nx,ny,nz,nw);
                        } break;
                        case SEAMLESS_XY:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nu=ranges.mapz0 + r*dz;
                            val=m.get(nx,ny,nz,nw,nu,0);
                        } break;
                        case SEAMLESS_XZ:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.mapy0 + q*dy;
                            nw=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nu=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            val=m.get(nx,ny,nz,nw,nu,0);
                        } break;
                        case SEAMLESS_YZ:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nz=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nw=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nu=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            val=m.get(nx,ny,nz,nw,nu,0);
                        } break;
                        case SEAMLESS_XYZ:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nu=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nv=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            val=m.get(nx,ny,nz,nw,nu,nv);
                        } break;
                        default: break;
                    }
                    a.set(x,y,z,val);
                }
            }
        }
    }





    void saveDoubleArray(char *filename, TArray2D<double> *array)
{
    if(!array) return;
    int width=array->width();
    int height=array->height();

    int Depth = 24;
	int TempWidth1 = int (width / 256);
	int TempHeight1 = int (height / 256);

	int TempWidth2 = width - (256 * TempWidth1);
	int TempHeight2 = height - (256 * TempHeight1);

	unsigned char Head[6] = {(unsigned char)TempWidth2,(unsigned char)TempWidth1,(unsigned char)TempHeight2,(unsigned char)TempHeight1,(unsigned char)Depth,0};
	unsigned char TgaHead[12] = {0,0,2,0,0,0,0,0,0,0,0,0};

	std::ofstream File (filename,std::ios::binary);

	if (!File.is_open ())
	{
	    std::cout << "Could not open file " << filename << std::endl;
	    return;
	}
	File.write ( (char *)TgaHead,sizeof (TgaHead));
	File.write ( (char *)Head,sizeof (Head));

	for(int y=height-1; y>=0; --y)
	{
	    for(int x=0; x<width; ++x)
	    {
	        double val=array->get(x,y);
	        val=std::max(0.0,std::min(1.0,val));
	        unsigned char col[3];
	        col[0]=col[1]=col[2]=(unsigned char)(val*255.0);
	        File.write((char *) &col, 3);
	    }
	}

	File.close ();
	return;
}

void saveRGBAArray(char *filename, TArray2D<anl::SRGBA> *array)
{
    if(!array)
    {
        std::cout << "Error" << std::endl;
        return;
    }
    int width=array->width();
    int height=array->height();

    int Depth = 32;
	int TempWidth1 = int (width / 256);
	int TempHeight1 = int (height / 256);

	int TempWidth2 = width - (256 * TempWidth1);
	int TempHeight2 = height - (256 * TempHeight1);

	unsigned char Head[6] = {(unsigned char)TempWidth2,(unsigned char)TempWidth1,(unsigned char)TempHeight2,(unsigned char)TempHeight1,(unsigned char)Depth,0};
	unsigned char TgaHead[12] = {0,0,2,0,0,0,0,0,0,0,0,0};

	std::ofstream File (filename,std::ios::binary);

	if (!File.is_open ())
	{
	    std::cout << "Could not open file " << filename << std::endl;
	    return;
	}
	File.write ( (char *)TgaHead,sizeof (TgaHead));
	File.write ( (char *)Head,sizeof (Head));

	for(int y=height-1; y>=0; --y)
	{
	    for(int x=0; x<width; ++x)
	    {
	        anl::SRGBA val=array->get(x,y);
	        //val=std::max(0.0,std::min(1.0,val));
	        unsigned char col[4];
	        //col[0]=col[1]=col[2]=(unsigned char)(val*255.0);
	        col[2]=(unsigned char)(val[0]*255.0f);
	        col[1]=(unsigned char)(val[1]*255.0f);
	        col[0]=(unsigned char)(val[2]*255.0f);
	        col[3]=(unsigned char)(val[3]*255.0f);
	        File.write((char *) &col, 4);
	    }
	}

	File.close ();
	return;
}
};
