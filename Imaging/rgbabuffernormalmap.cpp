#include "rgbabuffernormalmap.h"
#include "arrayoperations.h"

namespace anl
{
	CRGBABufferNormalMap::CRGBABufferNormalMap() : source_(0), spacing_(1), seamless_(false){}
	
	CRGBABufferNormalMap::CRGBABufferNormalMap(CImplicitBufferBase *src, float spacing, bool seamless) : source_(src), spacing_(spacing), seamless_(seamless){}
	
	CRGBABufferNormalMap::~CRGBABufferNormalMap(){}
	
	void CRGBABufferNormalMap::setSource(CImplicitBufferBase *src)
	{
		source_=src;
	}
	
	void CRGBABufferNormalMap::setSpacing(float spacing)
	{
		spacing_=spacing;
	}
	
	void CRGBABufferNormalMap::get(CArray2Drgba &out)
	{
		if(!source_) return;
		CArray2Dd temp;
		temp.resize(out.width(), out.height());
		source_->get(temp);
		
		calcNormalMap(&temp, &out, spacing_, true, seamless_);
		
	}
};