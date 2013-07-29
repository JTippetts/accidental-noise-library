#ifndef IMPLICIT_MODULE_BASE_H
#define IMPLICIT_MODULE_BASE_H

#include <memory>

// Base class of implicit (2D, 4D, 6D) noise functions
#define MaxSources 20
namespace anl
{

class CImplicitModuleBase
{
public:
	CImplicitModuleBase() : m_spacing(0.0001){}
	virtual ~CImplicitModuleBase(){}
	void setDerivSpacing(double s){m_spacing=s;}
	virtual void setSeed(unsigned int seed){}

	virtual double get(double x, double y)=0;
	virtual double get(double x, double y, double z)=0;
	virtual double get(double x, double y, double z, double w)=0;
	virtual double get(double x, double y, double z, double w, double u, double v)=0;

	double get_dx(double x, double y);
	double get_dy(double x, double y);

	double get_dx(double x, double y, double z);
	double get_dy(double x, double y, double z);
	double get_dz(double x, double y, double z);

	double get_dx(double x, double y, double z, double w);
	double get_dy(double x, double y, double z, double w);
	double get_dz(double x, double y, double z, double w);
	double get_dw(double x, double y, double z, double w);

	double get_dx(double x, double y, double z, double w, double u, double v);
	double get_dy(double x, double y, double z, double w, double u, double v);
	double get_dz(double x, double y, double z, double w, double u, double v);
	double get_dw(double x, double y, double z, double w, double u, double v);
	double get_du(double x, double y, double z, double w, double u, double v);
	double get_dv(double x, double y, double z, double w, double u, double v);

protected:
	double m_spacing;
};

// Scalar parameter class
class CScalarParameter
{
    public:
    CScalarParameter(double v) : m_val(v), m_source(0){}
    CScalarParameter(CImplicitModuleBase * b) : m_val(0), m_source(b){}
    CScalarParameter(const CScalarParameter &p) {m_source=p.m_source; m_val=p.m_val;}
    ~CScalarParameter(){}

    void set(double v)
    {
        m_source=0;
        m_val=v;
    }

    void set(CImplicitModuleBase * m)
    {
        m_source=m;
    }

    double get(double x, double y)
    {
        if(m_source) return m_source->get(x,y);
        else return m_val;
    }

    double get(double x, double y, double z)
    {
        if(m_source) return m_source->get(x,y,z);
        else return m_val;
    }

    double get(double x, double y, double z, double w)
    {
        if(m_source) return m_source->get(x,y,z,w);
        else return m_val;
    }

    double get(double x, double y, double z, double w, double u, double v)
    {
        if(m_source) return m_source->get(x,y,z,w,u,v);
        else return m_val;
    }

    protected:
    double m_val;
    CImplicitModuleBase * m_source;
};
};
#endif
