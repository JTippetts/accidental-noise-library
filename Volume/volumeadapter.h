#ifndef VOLUME_ADAPTER_H
#define VOLUME_ADAPTER_H

#include "implicitmodulebase.h"
#include "mapping.h"

namespace anl
{
	class CVolumeAdapter
	{
		public:
		CVolumeAdapter();
		CVolumeAdapter(CImplicitModuleBase *src, int seamlessmode, SMappingRanges ranges=SMappingRanges(0,1,0,1,0,1));
		~CVolumeAdapter();
		
		void setSeamlessMode(int mode);
		void setMappingRanges(SMappingRanges ranges);
		void setSource(CImplicitModuleBase *src);
		
		void get(CArray3Dd &a);
		
		private:
		int mode_;
		SMappingRanges ranges_;
		CImplicitModuleBase *src_;
	};
};

#endif