#ifndef IMPLICITCONSTANT_H
#define IMPLICITCONSTANT_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitConstant : public CImplicitModuleBase
    {
        public:
        CImplicitConstant();
        CImplicitConstant(ANLFloatType c);
        ~CImplicitConstant();

        void setConstant(ANLFloatType c);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        ANLFloatType m_constant;
    };
};

#endif
