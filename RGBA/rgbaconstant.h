#ifndef RGBA_CONSTANT_H
#define RGBA_CONSTANT_H
#include "rgbamodulebase.h"

namespace anl
{
    class CRGBAConstant : public CRGBAModuleBase
    {
        public:
        CRGBAConstant();
        CRGBAConstant(SRGBA &r);
        CRGBAConstant(float r, float g, float b, float a);
        ~CRGBAConstant();

        void set(float r, float g, float b, float a);
        void set(SRGBA &r);

        SRGBA get(double x, double y);
        SRGBA get(double x, double y, double z);
        SRGBA get(double x, double y, double z, double w);
        SRGBA get(double x, double y, double z, double w, double u, double v);

        protected:
        SRGBA m_rgba;
    };
};

#endif
