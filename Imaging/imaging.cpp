#include "imaging.h"

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#include "stb_image.h"
#include "stb_image_write.h"

namespace anl
{
    void saveDoubleArray(std::string filename, TArray2D<ANLFloatType> *array)
	{
		if(!array) return;
		int width=array->width();
		int height=array->height();

		unsigned char *data=new unsigned char[width*height*4];
		for(int x=0; x<width; ++x)
		{
			for(int y=0; y<height; ++y)
			{
				unsigned char *c=&data[y*width*4+x*4];
				ANLFloatType v=array->get(x,y);
				c[0]=c[1]=c[2]=(unsigned char)(v*255.0);
				c[3]=255;
			}
		}

		std::string ext=filename.substr(filename.size()-3, std::string::npos);
		struct convert {
			void operator()(char& c) { c = toupper((unsigned char)c); }
		};

		std::for_each(ext.begin(), ext.end(), convert());

		if(ext=="TGA")
		{
			stbi_write_tga(filename.c_str(), width, height, 4, data);
		}
		else
		{
			stbi_write_png(filename.c_str(), width, height, 4, data, width*4);
		}


		delete[] data;
	}


	void saveRGBAArray(std::string filename, TArray2D<anl::SRGBA> *array)
	{
		if(!array) return;
		int width=array->width();
		int height=array->height();

		unsigned char *data=new unsigned char[width*height*4];
		for(int x=0; x<width; ++x)
		{
			for(int y=0; y<height; ++y)
			{
				unsigned char *c=&data[y*width*4+x*4];
				SRGBA color=array->get(x,y);
				c[0]=(unsigned char)(color.x()*255.0);
				c[1]=(unsigned char)(color.y()*255.0);
				c[2]=(unsigned char)(color.z()*255.0);
				c[3]=(unsigned char)(color.w()*255.0);
			}
		}

		std::string ext=filename.substr(filename.size()-3, std::string::npos);
		struct convert {
			void operator()(char& c) { c = toupper((unsigned char)c); }
		};

		std::for_each(ext.begin(), ext.end(), convert());

		if(ext=="TGA")
		{
			stbi_write_tga(filename.c_str(), width, height, 4, data);
		}
		else
		{
			stbi_write_png(filename.c_str(), width, height, 4, data, width*4);
		}
		delete[] data;
	}
	
	void map2D(int seamlessmode, CArray2Dd &a, CNoiseExecutor &m, SMappingRanges &ranges, unsigned int index, ANLFloatType z)
   {
        int w=a.width();
        int h=a.height();
        static ANLFloatType pi2=3.141592*2.0;

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                ANLFloatType p=(ANLFloatType)x / (ANLFloatType)(w-1);
                ANLFloatType q=(ANLFloatType)y / (ANLFloatType)(h-1);
                ANLFloatType r;
                ANLFloatType nx,ny,nz,nw,nu,nv,val=0.0;
                ANLFloatType dx, dy, dz;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
                        nz=z;
						CCoordinate coord(nx,ny,nz);
                        val=m.evaluateAt(coord,index).outfloat_;
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
                        CCoordinate coord(nx,ny,nz,nw);
                        val=m.evaluateAt(coord,index).outfloat_;
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
                        CCoordinate coord(nx,ny,nz,nw);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_Z:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.mapy0 + p*dx;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        ANLFloatType zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nz=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nw=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw);
                        val=m.evaluateAt(coord,index).outfloat_;
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
						CCoordinate coord(nx,ny,nz,nw,nu,0);
                        val=m.evaluateAt(coord,index).outfloat_;
           
                    } break;
                    case SEAMLESS_XZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        ANLFloatType zval=r*(ranges.mapx1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) *dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_YZ:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        ANLFloatType zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0+p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_XYZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        ANLFloatType zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                        nu=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nv=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,nv);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;

                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

   void map2DNoZ(int seamlessmode, CArray2Dd &a, CNoiseExecutor &m, SMappingRanges &ranges, unsigned int index)
   {
        int w=a.width();
        int h=a.height();
        static ANLFloatType pi2=3.141592*2.0;

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                ANLFloatType p=(ANLFloatType)x / (ANLFloatType)w;
                ANLFloatType q=(ANLFloatType)y / (ANLFloatType)h;
                ANLFloatType nx,ny,nz,nw,val=0.0;
                ANLFloatType dx, dy;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
						CCoordinate coord(nx,ny);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_X:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        CCoordinate coord(nx,ny,nz);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_Y:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        CCoordinate coord(nx,ny,nz);
                        val=m.evaluateAt(coord,index).outfloat_;
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
                        CCoordinate coord(nx,ny,nz,nw);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

    void map3D(int seamlessmode, CArray3Dd &a, CNoiseExecutor &m, SMappingRanges &ranges, unsigned int index)
    {
        int w=a.width();
        int h=a.height();
        int d=a.depth();

        int x,y,z;
        static ANLFloatType pi2=3.14159265 * 2.0;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                for(z=0; z<d; ++z)
                {
                    ANLFloatType p=(ANLFloatType)x/(ANLFloatType)w;
                    ANLFloatType q=(ANLFloatType)y/(ANLFloatType)h;
                    ANLFloatType r=(ANLFloatType)z/(ANLFloatType)d;
                    ANLFloatType nx,ny,nz,nw,nu,nv;
                    ANLFloatType dx,dy,dz;
                    ANLFloatType val=0.0;

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
                            CCoordinate coord(nx,ny,nz);
							val=m.evaluateAt(coord,index).outfloat_;
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
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outfloat_;
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
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outfloat_;
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
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outfloat_;
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
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outfloat_;
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
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outfloat_;
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
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outfloat_;
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
                            CCoordinate coord(nx,ny,nz,nw,nu,nv);
							val=m.evaluateAt(coord,index).outfloat_;
                        } break;
                        default: break;
                    }
                    a.set(x,y,z,val);
                }
            }
        }
    }




    void mapRGBA2D(int seamlessmode, CArray2Drgba &a, CNoiseExecutor &m, SMappingRanges &ranges, unsigned int index, ANLFloatType z)
   {
        int w=a.width();
        int h=a.height();
        static ANLFloatType pi2=3.141592*2.0;

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                ANLFloatType p=(ANLFloatType)x / (ANLFloatType)w;
                ANLFloatType q=(ANLFloatType)y / (ANLFloatType)h;
                ANLFloatType r;
                ANLFloatType nx,ny,nz,nw,nu,nv=0.0;
                SRGBA val;
                ANLFloatType dx, dy, dz;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
                        nz=z;
                        CCoordinate coord(nx,ny,nz);
						val=m.evaluateAt(coord,index).outrgba_;
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
                        CCoordinate coord(nx,ny,nz,nw);
						val=m.evaluateAt(coord,index).outrgba_;
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
                        CCoordinate coord(nx,ny,nz,nw);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_Z:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.mapy0 + p*dx;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        ANLFloatType zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nz=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nw=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw);
						val=m.evaluateAt(coord,index).outrgba_;
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
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_XZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        ANLFloatType zval=r*(ranges.mapx1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) *dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_YZ:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        ANLFloatType zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0+p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_XYZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        ANLFloatType zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                        nu=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nv=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,nv);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;

                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

   void mapRGBA2DNoZ(int seamlessmode, CArray2Drgba &a, CNoiseExecutor &m, SMappingRanges &ranges, unsigned int index)
   {
        int w=a.width();
        int h=a.height();
        static ANLFloatType pi2=3.141592*2.0;

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                ANLFloatType p=(ANLFloatType)x / (ANLFloatType)w;
                ANLFloatType q=(ANLFloatType)y / (ANLFloatType)h;
                ANLFloatType nx,ny,nz,nw=0.0;
                SRGBA val;
                ANLFloatType dx, dy;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
                        CCoordinate coord(nx,ny);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_X:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        CCoordinate coord(nx,ny,nz);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_Y:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        CCoordinate coord(nx,ny,nz);
						val=m.evaluateAt(coord,index).outrgba_;
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
                        CCoordinate coord(nx,ny,nz,nw);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

    void mapRGBA3D(int seamlessmode, CArray3Drgba &a, CNoiseExecutor &m, SMappingRanges &ranges, unsigned int index)
    {
        int w=a.width();
        int h=a.height();
        int d=a.depth();

        int x,y,z;
        static ANLFloatType pi2=3.14159265 * 2.0;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                for(z=0; z<d; ++z)
                {
                    ANLFloatType p=(ANLFloatType)x/(ANLFloatType)w;
                    ANLFloatType q=(ANLFloatType)y/(ANLFloatType)h;
                    ANLFloatType r=(ANLFloatType)z/(ANLFloatType)d;
                    ANLFloatType nx,ny,nz,nw,nu,nv;
                    ANLFloatType dx,dy,dz;
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
                            CCoordinate coord(nx,ny,nz);
							val=m.evaluateAt(coord,index).outrgba_;
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
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outrgba_;
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
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outrgba_;
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
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outrgba_;
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
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outrgba_;
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
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outrgba_;
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
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outrgba_;
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
                            CCoordinate coord(nx,ny,nz,nw,nu,nv);
							val=m.evaluateAt(coord,index).outrgba_;
                        } break;
                        default: break;
                    }
                    a.set(x,y,z,val);
                }
            }
        }
    }
};
