#include "implicitbufferfile.h"
#include "mapping.h"

namespace anl
{
	CImplicitBufferFile::CImplicitBufferFile()
	{
	}
	
	CImplicitBufferFile::CImplicitBufferFile(std::string filename)
	{
		loadDoubleArray(filename, &buffer_);
	}
	
	CImplicitBufferFile::CImplicitBufferFile(CArray2Dd *buf)
	{
		setFromBuffer(buf);
	}
	
	CImplicitBufferFile::~CImplicitBufferFile()
	{
	}
		
	void CImplicitBufferFile::setFile(std::string filename)
	{
		loadDoubleArray(filename, &buffer_);
	}
	
	void CImplicitBufferFile::setFromBuffer(CArray2Dd *buf)
	{
		if(!buf) return;
		int w=buf->width(), h=buf->height();
		buffer_.resize(w,h);
		for(int x=0; x<w; ++x)
		{
			for(int y=0; y<h; ++y)
			{
				buffer_.set(x,y,buf->get(x,y));
			}
		}
	}
	
	void CImplicitBufferFile::get(CArray2Dd &out)
	{
		int w=out.width();
		int h=out.height();
		
		if(w==buffer_.width() && h==buffer_.height())
		{
			for(int x=0; x<w; ++x)
			{
				for(int y=0; y<h; ++y)
				{
					out.set(x,y,buffer_.get(x,y));
				}
			}
		}
		else
		{
			for(int x=0; x<w; ++x)
			{
				for(int y=0; y<h; ++y)
				{
					float nx=(float)x/(float)w;
					float ny=(float)y/(float)h;
					nx*=(float)buffer_.width();
					ny*=(float)buffer_.height();
					out.set(x,y,buffer_.get(nx,ny));
				}
			}
		}
	}
};