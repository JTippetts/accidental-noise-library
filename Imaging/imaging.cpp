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
};
