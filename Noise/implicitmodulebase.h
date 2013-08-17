#ifndef IMPLICIT_MODULE_BASE_H
#define IMPLICIT_MODULE_BASE_H

#include <memory>
#include "../types.h"

// Base class of implicit (2D, 4D, 6D) noise functions
#define MaxSources 20
namespace anl
{

class CImplicitModuleBase
{
public:
	CImplicitModuleBase() : m_spacing(0.0001){}
	virtual ~CImplicitModuleBase(){}
	void setDerivSpacing(ANLFloatType s){m_spacing=s;}
	virtual void setSeed(unsigned int seed){}

	virtual ANLFloatType get(ANLFloatType x, ANLFloatType y)=0;
	virtual ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z)=0;
	virtual ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)=0;
	virtual ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)=0;

	ANLFloatType get_dx(ANLFloatType x, ANLFloatType y);
	ANLFloatType get_dy(ANLFloatType x, ANLFloatType y);

	ANLFloatType get_dx(ANLFloatType x, ANLFloatType y, ANLFloatType z);
	ANLFloatType get_dy(ANLFloatType x, ANLFloatType y, ANLFloatType z);
	ANLFloatType get_dz(ANLFloatType x, ANLFloatType y, ANLFloatType z);

	ANLFloatType get_dx(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
	ANLFloatType get_dy(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
	ANLFloatType get_dz(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
	ANLFloatType get_dw(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);

	ANLFloatType get_dx(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
	ANLFloatType get_dy(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
	ANLFloatType get_dz(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
	ANLFloatType get_dw(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
	ANLFloatType get_du(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
	ANLFloatType get_dv(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

protected:
	ANLFloatType m_spacing;
};

// Scalar parameter class
class CScalarParameter
{
    public:
    CScalarParameter(ANLFloatType v) : m_val(v), m_source(0){}
    CScalarParameter(CImplicitModuleBase * b) : m_val(0), m_source(b){}
    CScalarParameter(const CScalarParameter &p) {m_source=p.m_source; m_val=p.m_val;}
    ~CScalarParameter(){}

    void set(ANLFloatType v)
    {
        m_source=0;
        m_val=v;
    }

    void set(CImplicitModuleBase * m)
    {
        m_source=m;
    }

    ANLFloatType get(ANLFloatType x, ANLFloatType y)
    {
        if(m_source) return m_source->get(x,y);
        else return m_val;
    }

    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
    {
        if(m_source) return m_source->get(x,y,z);
        else return m_val;
    }

    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
    {
        if(m_source) return m_source->get(x,y,z,w);
        else return m_val;
    }

    ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
    {
        if(m_source) return m_source->get(x,y,z,w,u,v);
        else return m_val;
    }

    protected:
    ANLFloatType m_val;
    CImplicitModuleBase * m_source;
};
};
#endif
