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
		~CImplicitBufferFile();
		
		void setFile(std::string filename);
		void get(CArray2Dd &out);
	private:
		CArray2Dd buffer_;
	};
};

#endif