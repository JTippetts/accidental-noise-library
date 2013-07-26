#ifndef RGBA_RGBATOHSV_H
#define RGBA_RGBATOHSV_H
#include "rgbamodulebase.h"

namespace anl
{
    class CRGBARGBAToHSV :public CRGBAModuleBase
    {
        public:
        CRGBARGBAToHSV();
        CRGBARGBAToHSV(SRGBA s);
        CRGBARGBAToHSV(std::shared_ptr<CRGBAModuleBase> s);

        ~CRGBARGBAToHSV(){}

        void setSource(std::shared_ptr<CRGBAModuleBase> m);
        void setSource(SRGBA c);

        SRGBA get(double x, double y);
        SRGBA get(double x, double y, double z);
        SRGBA get(double x, double y, double z, double w);
        SRGBA get(double x, double y, double z, double w, double u, double v);

        protected:
        CRGBAParameter m_source;
    };
};

#endif
