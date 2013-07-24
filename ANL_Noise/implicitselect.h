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
	CImplicitSelect(double low, double high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(double low, double high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
	CImplicitSelect(double low, double high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(double low, double high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff);
	CImplicitSelect(double low, double high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(double low, double high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
	CImplicitSelect(double low, double high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(double low, std::shared_ptr<CImplicitModuleBase> high, double control, double threshold, double falloff);
	CImplicitSelect(double low, std::shared_ptr<CImplicitModuleBase> high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(double low, std::shared_ptr<CImplicitModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
	CImplicitSelect(double low, std::shared_ptr<CImplicitModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(double low, std::shared_ptr<CImplicitModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff);
	CImplicitSelect(double low, std::shared_ptr<CImplicitModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(double low, std::shared_ptr<CImplicitModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
	CImplicitSelect(double low, std::shared_ptr<CImplicitModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, double high, double control, double threshold, double falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, double high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, double high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, double high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, double high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, double high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, double high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, double high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high, double control, double threshold, double falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high, double control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high, double control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, double falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, double threshold, std::shared_ptr<CImplicitModuleBase> falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, double falloff);
	CImplicitSelect(std::shared_ptr<CImplicitModuleBase> low, std::shared_ptr<CImplicitModuleBase> high, std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CImplicitModuleBase> threshold, std::shared_ptr<CImplicitModuleBase> falloff);

	~CImplicitSelect();

	void setLowSource(std::shared_ptr<CImplicitModuleBase> b);
	void setHighSource(std::shared_ptr<CImplicitModuleBase> b);
	void setControlSource(std::shared_ptr<CImplicitModuleBase> b);
	void setLowSource(double v);
	void setHighSource(double v);
	void setControlSource(double v);
	void setThreshold(double t);
	void setFalloff(double f);
	void setThreshold(std::shared_ptr<CImplicitModuleBase> m);
	void setFalloff(std::shared_ptr<CImplicitModuleBase> m);
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
