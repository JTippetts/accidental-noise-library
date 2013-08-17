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

        SRGBA get(ANLFloatType x, ANLFloatType y);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        SRGBA m_rgba;
    };
};

#endif
