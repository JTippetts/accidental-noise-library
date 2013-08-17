#ifndef IMPLICIT_SELECT_H
#define IMPLICIT_SELECT_H
#include "implicitmodulebase.h"

namespace anl
{
class CImplicitSelect : public CImplicitModuleBase
{
public:
	CImplicitSelect();
	CImplicitSelect(ANLFloatType low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
	CImplicitSelect(ANLFloatType low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(ANLFloatType low, ANLFloatType high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff);
	CImplicitSelect(ANLFloatType low, ANLFloatType high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(ANLFloatType low, ANLFloatType high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff);
	CImplicitSelect(ANLFloatType low, ANLFloatType high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(ANLFloatType low, ANLFloatType high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff);
	CImplicitSelect(ANLFloatType low, ANLFloatType high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
	CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff);
	CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff);
	CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff);
	CImplicitSelect(ANLFloatType low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
	CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff);
	CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff);
	CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff);
	CImplicitSelect(CImplicitModuleBase * low, ANLFloatType high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, ANLFloatType control, ANLFloatType threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, ANLFloatType falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, ANLFloatType control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, ANLFloatType falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, ANLFloatType threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, ANLFloatType falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);

	~CImplicitSelect();

	void setLowSource(CImplicitModuleBase * b);
	void setHighSource(CImplicitModuleBase * b);
	void setControlSource(CImplicitModuleBase * b);
	void setLowSource(ANLFloatType v);
	void setHighSource(ANLFloatType v);
	void setControlSource(ANLFloatType v);
	void setThreshold(ANLFloatType t);
	void setFalloff(ANLFloatType f);
	void setThreshold(CImplicitModuleBase * m);
	void setFalloff(CImplicitModuleBase * m);
	ANLFloatType get(ANLFloatType x, ANLFloatType y);
    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
	ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
	ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

    protected:
	CScalarParameter m_low, m_high, m_control;
	CScalarParameter m_threshold, m_falloff;

};
};
#endif
