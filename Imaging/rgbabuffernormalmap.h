#ifndef RGBABUFFERNORMALMAP_H
#define RGBABUFFERNORMALMAP_H

#include "rgbabufferbase.h"
#include "implicitbufferbase.h"

namespace anl
{
	class CRGBABufferNormalMap : public CRGBABufferBase
	{
	public:
		CRGBABufferNormalMap();
		CRGBABufferNormalMap(CImplicitBufferBase *src, float spacing, bool seamless);
		~CRGBABufferNormalMap();
		
		void setSource(CImplicitBufferBase *src);
		void setSpacing(float spacing);
		void get(CArray2Drgba &out);
	private:
		CImplicitBufferBase *source_;
		float spacing_;
		bool seamless_;
	};
};

#endif