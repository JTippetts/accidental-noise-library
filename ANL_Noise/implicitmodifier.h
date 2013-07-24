#ifndef IMPLICIT_MODIFIER_H
#define IMPLICIT_MODIFIER_H
#include "implicitmodulebase.h"
#include "../utility.h"
#include "../curvetypes.h"

// Modules that modify the output of a function

class CImplicitCurve : public CImplicitModuleBase
{
public:
	CImplicitCurve() : m_source(0){}
	~CImplicitCurve(){}

	void setSource(CImplicitModuleBase *b)
	{
		m_source=b;
	}

	void setControlPoint(double v, double p)
	{
		m_curve.pushPoint(v,p);
	}

	void clearControlPoints()
	{
		m_curve.clear();
	}

	double get(double x, double y)
	{
		if(!m_source) return 0.0;

		double v=m_source->get(x,y);
		// Should clamp; make sure inputs are in range
		//v=(v+1.0 ) * 0.5;
		v=clamp(v,0.0,1.0);
		return m_curve.linearInterp(v);
	}

	double get(double x, double y, double z)
	{
	    if(!m_source) return 0;
	    double v=m_source->get(x,y,z);
	    //v=(v+1)*0.5;
	    v=clamp(v,0.0,1.0);
	    return m_curve.linearInterp(v);
	}

	double get(double x, double y, double z, double w)
	{
		if(!m_source) return 0.0;

		double v=m_source->get(x,y,z,w);
		// Should clamp; make sure inputs are in range
		//v=(v+1.0 ) * 0.5;
		v=clamp(v,0.0,1.0);
		return m_curve.linearInterp(v);
	}

	double get(double x, double y, double z, double w, double u, double v)
	{
		if(!m_source) return 0.0;

		double val=m_source->get(x,y,z,w,u,v);
		// Should clamp; make sure inputs are in range
		//val=(val+1.0 ) * 0.5;
		val=clamp(val,0.0,1.0);
		return m_curve.linearInterp(val);
	}



protected:
	CImplicitModuleBase *m_source;
	CCurved m_curve;

};


#endif
