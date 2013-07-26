#include "implicitconstant.h"

namespace anl
{
    CImplicitConstant::CImplicitConstant() : CImplicitModuleBase(), m_constant(0){}
    CImplicitConstant::CImplicitConstant(double c) : CImplicitModuleBase(), m_constant(c){}
	CImplicitConstant::~CImplicitConstant(){}

	void CImplicitConstant::setConstant(double c){m_constant=c;}

	double CImplicitConstant::get(double x, double y){return m_constant;}
	double CImplicitConstant::get(double x, double y, double z){return m_constant;}
	double CImplicitConstant::get(double x, double y, double z, double w){return m_constant;}
	double CImplicitConstant::get(double x, double y, double z, double w, double u, double v){return m_constant;}
};
