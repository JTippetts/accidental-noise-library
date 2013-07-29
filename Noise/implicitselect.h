#ifndef IMPLICIT_SELECT_H
#define IMPLICIT_SELECT_H
#include "implicitmodulebase.h"

namespace anl
{
class CImplicitSelect : public CImplicitModuleBase
{
public:
	CImplicitSelect();
	CImplicitSelect(double low, double high, double control, double threshold, double falloff);
	CImplicitSelect(double low, double high, double control, double threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(double low, double high, double control, CImplicitModuleBase * threshold, double falloff);
	CImplicitSelect(double low, double high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(double low, double high, CImplicitModuleBase * control, double threshold, double falloff);
	CImplicitSelect(double low, double high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(double low, double high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff);
	CImplicitSelect(double low, double high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(double low, CImplicitModuleBase * high, double control, double threshold, double falloff);
	CImplicitSelect(double low, CImplicitModuleBase * high, double control, double threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(double low, CImplicitModuleBase * high, double control, CImplicitModuleBase * threshold, double falloff);
	CImplicitSelect(double low, CImplicitModuleBase * high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(double low, CImplicitModuleBase * high, CImplicitModuleBase * control, double threshold, double falloff);
	CImplicitSelect(double low, CImplicitModuleBase * high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(double low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff);
	CImplicitSelect(double low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, double high, double control, double threshold, double falloff);
	CImplicitSelect(CImplicitModuleBase * low, double high, double control, double threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, double high, double control, CImplicitModuleBase * threshold, double falloff);
	CImplicitSelect(CImplicitModuleBase * low, double high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, double high, CImplicitModuleBase * control, double threshold, double falloff);
	CImplicitSelect(CImplicitModuleBase * low, double high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, double high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff);
	CImplicitSelect(CImplicitModuleBase * low, double high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, double control, double threshold, double falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, double control, double threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, double control, CImplicitModuleBase * threshold, double falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, double control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, double threshold, double falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, double threshold, CImplicitModuleBase * falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, double falloff);
	CImplicitSelect(CImplicitModuleBase * low, CImplicitModuleBase * high, CImplicitModuleBase * control, CImplicitModuleBase * threshold, CImplicitModuleBase * falloff);

	~CImplicitSelect();

	void setLowSource(CImplicitModuleBase * b);
	void setHighSource(CImplicitModuleBase * b);
	void setControlSource(CImplicitModuleBase * b);
	void setLowSource(double v);
	void setHighSource(double v);
	void setControlSource(double v);
	void setThreshold(double t);
	void setFalloff(double f);
	void setThreshold(CImplicitModuleBase * m);
	void setFalloff(CImplicitModuleBase * m);
	double get(double x, double y);
    double get(double x, double y, double z);
	double get(double x, double y, double z, double w);
	double get(double x, double y, double z, double w, double u, double v);

    protected:
	CScalarParameter m_low, m_high, m_control;
	CScalarParameter m_threshold, m_falloff;

};
};
#endif
