#include "volumeadapter.h"

namespace anl
{
	CVolumeAdapter::CVolumeAdapter() : mode_(SEAMLESS_NONE), ranges_(), src_(0)
	{
	}
	
	CVolumeAdapter::CVolumeAdapter(CImplicitModuleBase *src, int seamlessmode, SMappingRanges ranges) :
		mode_(seamlessmode), ranges_(ranges), src_(src)
	{
	}
	
	CVolumeAdapter::~CVolumeAdapter()
	{
	}
		
	void CVolumeAdapter::setSeamlessMode(int mode)
	{
		mode_=mode;
		if(mode_<SEAMLESS_NONE) mode_=SEAMLESS_NONE;
		if(mode_>SEAMLESS_XYZ) mode_=SEAMLESS_XYZ;
	}
	
	void CVolumeAdapter::setMappingRanges(SMappingRanges ranges)
	{
		ranges_=ranges;
	}
	
	void CVolumeAdapter::setSource(CImplicitModuleBase *src)
	{
		src_=src;
	}
		
	void CVolumeAdapter::get(CArray3Dd &a)
	{
		if(!src_) return;
		unsigned int w=a.width(), h=a.height(), d=a.depth();
		double pi2=3.141592*2.0;
		
		for(unsigned int x=0; x<w; ++x)
		{
			for(unsigned int y=0; y<h; ++y)
			{
				for(unsigned int z=0; z<d; ++z)
				{
					double p=(double)x / (double)w;
					double q=(double)y / (double)h;
					double r=(double)z / (double)d;
					double nx,ny,nz,nw,nu,nv,val=0.0;
					double dx, dy, dz;
					switch(mode_)
					{
						case SEAMLESS_NONE:
						{
							nx=ranges_.mapx0 + p*(ranges_.mapx1-ranges_.mapx0);
							ny=ranges_.mapy0 + q*(ranges_.mapy1-ranges_.mapy0);
							nz=ranges_.mapz0 + r*(ranges_.mapz1-ranges_.mapz0);
							val=src_->get(nx,ny,nz);
							break;
						}
						case SEAMLESS_X:
						{
							dx=ranges_.loopx1-ranges_.loopx0;
							dy=ranges_.mapy1-ranges_.mapy0;
							dz=ranges_.mapz1-ranges_.mapz0;
							p=p*(ranges_.mapx1-ranges_.mapx0)/(ranges_.loopx1-ranges_.loopx0);
							nx=ranges_.loopx0 + cos(p*pi2) * dx/pi2;
							ny=ranges_.loopx0 + sin(p*pi2) * dx/pi2;
							nz=ranges_.mapy0 + q*dy;
							nw=ranges_.mapz0 + r*dz;
							val=src_->get(nx,ny,nz,nw);
							break;
						}
						case SEAMLESS_Y:
						{
							dx=ranges_.mapx1-ranges_.mapx0;
							dy=ranges_.loopy1-ranges_.loopy0;
							dz=ranges_.mapz1-ranges_.mapz0;
							q=q*(ranges_.mapy1-ranges_.mapy0)/(ranges_.loopy1-ranges_.loopy0);
							nx=ranges_.mapx0 + p*dx;
							ny=ranges_.loopy0 + cos(q*pi2) * dy/pi2;
							nz=ranges_.loopy0 + sin(q*pi2) * dy/pi2;
							nw=ranges_.mapz0 + r*dz;
							val=src_->get(nx,ny,nz,nw);
							break;
						}
						case SEAMLESS_Z:
						{
							dx=ranges_.mapx1-ranges_.mapx0;
							dy=ranges_.mapy1-ranges_.mapy0;
							dz=ranges_.loopz1-ranges_.loopz0;
							nx=ranges_.mapx0 + p*dx;
							ny=ranges_.mapy0 + p*dx;
							r=r*(ranges_.mapz1-ranges_.mapz0)/(ranges_.loopz1-ranges_.loopz0);
							nz=ranges_.loopz0 + cos(r*pi2) * dz/pi2;
							nw=ranges_.loopz0 + sin(r*pi2) * dz/pi2;
							val=src_->get(nx,ny,nz,nw);
							break;
						}
						case SEAMLESS_XY:
						{
							dx=ranges_.loopx1-ranges_.loopx0;
							dy=ranges_.loopy1-ranges_.loopy0;
							dz=ranges_.mapz1-ranges_.mapz0;
							p=p*(ranges_.mapx1-ranges_.mapx0)/(ranges_.loopx1-ranges_.loopx0);
							q=q*(ranges_.mapy1-ranges_.mapy0)/(ranges_.loopy1-ranges_.loopy0);
							nx=ranges_.loopx0 + cos(p*pi2) * dx/pi2;
							ny=ranges_.loopx0 + sin(p*pi2) * dx/pi2;
							nz=ranges_.loopy0 + cos(q*pi2) * dy/pi2;
							nw=ranges_.loopy0 + sin(q*pi2) * dy/pi2;
							nu=ranges_.mapz0 + r*dz;
							val=src_->get(nx,ny,nz,nw,nu,0);
							break;
						}
						case SEAMLESS_XZ:
						{
							dx=ranges_.loopx1-ranges_.loopx0;
							dy=ranges_.mapy1-ranges_.mapy0;
							dz=ranges_.loopz1-ranges_.loopz0;
							p=p*(ranges_.mapx1-ranges_.mapx0)/(ranges_.loopx1-ranges_.loopx0);
							r=r*(ranges_.mapz1-ranges_.mapz0)/(ranges_.loopz1-ranges_.loopz0);
							nx=ranges_.loopx0 + cos(p*pi2) * dx/pi2;
							ny=ranges_.loopx0 + sin(p*pi2) * dx/pi2;
							nz=ranges_.mapy0 + q*dy;
							nw=ranges_.loopz0 + cos(r*pi2) * dz/pi2;
							nu=ranges_.loopz0 + sin(r*pi2) * dz/pi2;
							val=src_->get(nx,ny,nz,nw,nu,0);
							break;
						}
						case SEAMLESS_YZ:
						{
							dx=ranges_.mapx1-ranges_.mapx0;
							dy=ranges_.loopy1-ranges_.loopy0;
							dz=ranges_.loopz1-ranges_.loopz0;
							q=q*(ranges_.mapy1-ranges_.mapy0)/(ranges_.loopy1-ranges_.loopy0);
							r=r*(ranges_.mapz1-ranges_.mapz0)/(ranges_.loopz1-ranges_.loopz0);
							nx=ranges_.mapx0 + p*dx;
							ny=ranges_.loopy0 + cos(q*pi2)*dy/pi2;
							nz=ranges_.loopy0 + sin(q*pi2)*dy/pi2;
							nw=ranges_.loopz0 + cos(r*pi2)*dz/pi2;
							nu=ranges_.loopz0 + sin(r*pi2)*dz/pi2;
							val=src_->get(nx,ny,nz,nw,nu,0);
							break;
						}
						default:
						{
							dx=ranges_.loopx1-ranges_.loopx0;
							dy=ranges_.loopy1-ranges_.loopy0;
							dz=ranges_.loopz1-ranges_.loopz0;
							p=p*(ranges_.mapx1-ranges_.mapx0)/(ranges_.loopx1-ranges_.loopx0);
							q=q*(ranges_.mapy1-ranges_.mapy0)/(ranges_.loopy1-ranges_.loopy0);
							r=r*(ranges_.mapz1-ranges_.mapz0)/(ranges_.loopz1-ranges_.loopz0);
							nx=ranges_.loopx0 + cos(p*pi2) * dx/pi2;
							ny=ranges_.loopx0 + sin(p*pi2) * dx/pi2;
							nz=ranges_.loopy0 + cos(q*pi2)*dy/pi2;
							nw=ranges_.loopy0 + sin(q*pi2)*dy/pi2;
							nu=ranges_.loopz0 + cos(r*pi2)*dz/pi2;
							nv=ranges_.loopz0 + sin(r*pi2)*dz/pi2;
							val=src_->get(nx,ny,nz,nw,nu,nv);
							break;
						}
					};
					a.set(x,y,z,val);
				}
			}
		}
	}
};