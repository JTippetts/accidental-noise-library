#include "implicitseamlessmapping.h"
#include <cmath>

namespace anl
{
	CImplicitSeamlessMapping::CImplicitSeamlessMapping() : CImplicitModuleBase(), m_source(0), m_seamlessmode(0), m_periodx(1), m_periody(1), m_periodz(1){}
	
	CImplicitSeamlessMapping::CImplicitSeamlessMapping(CImplicitModuleBase *src, int seamlessmode, ANLFloatType periodx, ANLFloatType periody, ANLFloatType periodz) :
		CImplicitModuleBase(), m_source(src), m_seamlessmode(seamlessmode), m_periodx(periodx), m_periody(periody), m_periodz(periodz)
	{
	}
	
	CImplicitSeamlessMapping::~CImplicitSeamlessMapping()
	{
	}
		
	void CImplicitSeamlessMapping::setSource(CImplicitModuleBase *src)
	{
		m_source=src;
	}
	
	void CImplicitSeamlessMapping::setMapping(int seamlessmode)
	{
		m_seamlessmode=seamlessmode;
		if(m_seamlessmode<0) m_seamlessmode=0;
		if(m_seamlessmode>SEAMLESS_XYZ) m_seamlessmode=SEAMLESS_XYZ;
	}
	
	void CImplicitSeamlessMapping::setPeriodX(ANLFloatType p)
	{
		m_periodx=p;
	}
	
	void CImplicitSeamlessMapping::setPeriodY(ANLFloatType p)
	{
		m_periody=p;
	}
	
	void CImplicitSeamlessMapping::setPeriodZ(ANLFloatType p)
	{
		m_periodz=p;
	}
		
	ANLFloatType CImplicitSeamlessMapping::get(ANLFloatType x, ANLFloatType y)
	{
		if(!m_source) return 0;
		ANLFloatType pi2=3.141592*2.0;
		switch(m_seamlessmode)
		{
			case SEAMLESS_NONE: return m_source->get(x,y); break;
			case SEAMLESS_X:
			{
				ANLFloatType p=x/m_periodx*pi2;
				return m_source->get(cos(p)*m_periodx/pi2, sin(p)*m_periodx/pi2, y);
			} break;
			case SEAMLESS_Y:
			{
				ANLFloatType p=y/m_periody*pi2;
				return m_source->get(x, cos(p)*m_periody/pi2, sin(p)*m_periody/pi2);
			} break;
			case SEAMLESS_Z:
			{
				return m_source->get(x,y,cos(0)*m_periodz/pi2, sin(0)*m_periodz/pi2);
			} break;
			case SEAMLESS_XY:
			{
				ANLFloatType p=x/m_periodx*pi2;
				ANLFloatType q=y/m_periody*pi2;
				return m_source->get(cos(p)*m_periodx/pi2, sin(p)*m_periodx/pi2, cos(q)*m_periody/pi2, sin(q)*m_periody/pi2);
			}
			case SEAMLESS_XZ:
			{
				ANLFloatType p=x/m_periodx*pi2;
				ANLFloatType q=0;
				return m_source->get(cos(p)*m_periodx/pi2, sin(p)*m_periodx/pi2, y, cos(q)*m_periodz/pi2, sin(q)*m_periodz/pi2, 0);
			} break;
			case SEAMLESS_YZ:
			{
				ANLFloatType p=y/m_periody*pi2;
				ANLFloatType q=0;
				return m_source->get(x, cos(p)*m_periody/pi2, sin(p)*m_periody/pi2, cos(q)*m_periodz/pi2, sin(1)*m_periodz/pi2, 0);
			} break;
			case SEAMLESS_XYZ:
			{
				ANLFloatType p=x/m_periodx*pi2;
				ANLFloatType q=y/m_periody*pi2;
				ANLFloatType r=0;
				return m_source->get(cos(p)*m_periodx/pi2, sin(p)*m_periodx/pi2, cos(q)*m_periody/pi2, sin(q)*m_periody/pi2, cos(r)*m_periodz/pi2, sin(r)*m_periodz/pi2);
			} break;
			
			default: return m_source->get(x,y); break;
		}
	}
	
	ANLFloatType CImplicitSeamlessMapping::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
	{
		if(!m_source) return 0;
		ANLFloatType pi2=3.141592*2.0;
		switch(m_seamlessmode)
		{
			case SEAMLESS_NONE: return m_source->get(x,y); break;
			case SEAMLESS_X:
			{
				ANLFloatType p=x/m_periodx*pi2;
				return m_source->get(cos(p)*m_periodx/pi2, sin(p)*m_periodx/pi2, y, z);
			} break;
			case SEAMLESS_Y:
			{
				ANLFloatType p=y/m_periody*pi2;
				return m_source->get(x, cos(p)*m_periody/pi2, sin(p)*m_periody/pi2, z);
			} break;
			case SEAMLESS_Z:
			{
				ANLFloatType p=z/m_periodz*pi2;
				return m_source->get(x,y,cos(p)*m_periodz/pi2, sin(p)*m_periodz/pi2);
			} break;
			case SEAMLESS_XY:
			{
				ANLFloatType p=x/m_periodx*pi2;
				ANLFloatType q=y/m_periody*pi2;
				return m_source->get(cos(p)*m_periodx/pi2, sin(p)*m_periodx/pi2, cos(q)*m_periody/pi2, sin(q)*m_periody/pi2, z, 0);
			}
			case SEAMLESS_XZ:
			{
				ANLFloatType p=x/m_periodx*pi2;
				ANLFloatType r=z/m_periodz*pi2;
				return m_source->get(cos(p)*m_periodx/pi2, sin(p)*m_periodx/pi2, y, cos(r)*m_periodz/pi2, sin(r)*m_periodz/pi2, 0);
			} break;
			case SEAMLESS_YZ:
			{
				ANLFloatType q=y/m_periody*pi2;
				ANLFloatType r=z/m_periodz*pi2;
				return m_source->get(x, cos(q)*m_periody/pi2, sin(q)*m_periody/pi2, cos(r)*m_periodz/pi2, sin(r)*m_periodz/pi2, 0);
			} break;
			case SEAMLESS_XYZ:
			{
				ANLFloatType p=x/m_periodx*pi2;
				ANLFloatType q=y/m_periody*pi2;
				ANLFloatType r=z/m_periodz*pi2;
				return m_source->get(cos(p)*m_periodx/pi2, sin(p)*m_periodx/pi2, cos(q)*m_periody/pi2, sin(q)*m_periody/pi2, cos(r)*m_periodz/pi2, sin(r)*m_periodz/pi2);
			} break;
			
			default: return m_source->get(x,y); break;
		}
	}
	
	ANLFloatType CImplicitSeamlessMapping::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
	{
		// Orders higher than 3 fall back to 3
		return get(x,y,z);
	}
	
	ANLFloatType CImplicitSeamlessMapping::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
	{
		return get(x,y,z);
	}
};
