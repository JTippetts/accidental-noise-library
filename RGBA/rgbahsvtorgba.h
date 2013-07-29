#ifndef RGBA_HSVTORGBA_H
#define RGBA_HSVTORGBA_H
#include "rgbamodulebase.h"

namespace anl
{
    class CRGBAHSVToRGBA :public CRGBAModuleBase
    {
        public:
        CRGBAHSVToRGBA();
        CRGBAHSVToRGBA(SRGBA s);
        CRGBAHSVToRGBA(CRGBAModuleBase * s);

        void setSource(CRGBAModuleBase * m);
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

