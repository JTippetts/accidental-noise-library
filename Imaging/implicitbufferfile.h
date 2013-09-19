#ifndef IMPLICITBUFFERFILE_H
#define IMPLICITBUFFERFILE_H

#include "implicitbufferbase.h"

namespace anl
{
	class CImplicitBufferFile : public CImplicitBufferBase
	{
	public:
		CImplicitBufferFile();
		CImplicitBufferFile(std::string filename);
		CImplicitBufferFile(CArray2Dd *buf);
		~CImplicitBufferFile();
		
		void setFile(std::string filename);
		void setFromBuffer(CArray2Dd *buf);
		void get(CArray2Dd &out);
	private:
		CArray2Dd buffer_;
	};
};

#endif