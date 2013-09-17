#ifndef IMPLICIT_SEAMLESS_MAPPING_H
#define IMPLICIT_SEAMLESS_MAPPING_H

#include "implicitmodulebase.h"
#include "../Imaging/mapping.h"

namespace anl
{
	class CImplicitSeamlessMapping : public CImplicitModuleBase
	{
	public:
		CImplicitSeamlessMapping();
		CImplicitSeamlessMapping(CImplicitModuleBase *src, int seamlessmode, ANLFloatType periodx=1, ANLFloatType periody=1, ANLFloatType periodz=1);
		~CImplicitSeamlessMapping();
		
		void setSource(CImplicitModuleBase *src);
		void setMapping(int seamlessmode);
		void setPeriodX(ANLFloatType p);
		void setPeriodY(ANLFloatType p);
		void setPeriodZ(ANLFloatType p);
		
		ANLFloatType get(ANLFloatType x, ANLFloatType y);
		ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
		ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
		ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
	private:
		CImplicitModuleBase *m_source;
		ANLFloatType m_periodx, m_periody, m_periodz;
		int m_seamlessmode;
	};
};

#endif