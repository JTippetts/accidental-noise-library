#include "implicitconstant.h"

namespace anl
{
    CImplicitConstant::CImplicitConstant() : CImplicitModuleBase(), m_constant(0){}
    CImplicitConstant::CImplicitConstant(ANLFloatType c) : CImplicitModuleBase(), m_constant(c){}
	CImplicitConstant::~CImplicitConstant(){}

	void CImplicitConstant::setConstant(ANLFloatType c){m_constant=c;}

	ANLFloatType CImplicitConstant::get(ANLFloatType x, ANLFloatType y){return m_constant;}
	ANLFloatType CImplicitConstant::get(ANLFloatType x, ANLFloatType y, ANLFloatType z){return m_constant;}
	ANLFloatType CImplicitConstant::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w){return m_constant;}
	ANLFloatType CImplicitConstant::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v){return m_constant;}
};
