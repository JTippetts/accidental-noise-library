#ifndef IMPLICITCONSTANT_H
#define IMPLICITCONSTANT_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitConstant : public CImplicitModuleBase
    {
        public:
        CImplicitConstant();
        CImplicitConstant(double c);
        ~CImplicitConstant();

        void setConstant(double c);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        double m_constant;
    };
};

#endif
