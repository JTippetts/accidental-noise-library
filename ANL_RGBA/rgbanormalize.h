#ifndef RGBA_NORMALIZE_H
#define RGBA_NORMALIZE_H
#include "rgbamodulebase.h"

namespace anl
{
    class CRGBANormalize : public CRGBAModuleBase
    {
        public:
        CRGBANormalize();
        CRGBANormalize(SRGBA s);
        CRGBANormalize(std::shared_ptr<CRGBAModuleBase> s);
        ~CRGBANormalize();

        void setSource(std::shared_ptr<CRGBAModuleBase> m);
        void setSource(SRGBA c);

        SRGBA get(double x, double y);
        SRGBA get(double x, double y, double z);
        SRGBA get(double x, double y, double z, double w);
        SRGBA get(double x, double y, double z, double w, double u, double v);
        protected:
        CRGBAParameter m_source;
    };
}


#endif
