#ifndef IMPLICIT_RGBADOTPRODUCT_H
#define IMPLICIT_RGBADOTPRODUCT_H
#include "implicitmodulebase.h"
#include "rgbamodulebase.h"

namespace anl
{
    class CImplicitRGBADotProduct : public CImplicitModuleBase
    {
        public:
        CImplicitRGBADotProduct();
        ~CImplicitRGBADotProduct();

        void setSource1(std::shared_ptr<CRGBAModuleBase> m);
        void setSource1(SRGBA c);
        void setSource2(std::shared_ptr<CRGBAModuleBase> m);
        void setSource2(SRGBA c);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        CRGBAParameter m_source1, m_source2;
    };
};

#endif
