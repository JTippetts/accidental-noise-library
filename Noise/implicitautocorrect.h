#ifndef IMPLICIT_AUTOCORRECT_H
#define IMPLICIT_AUTOCORRECT_H
#include "implicitmodulebase.h"
/*************************************************
CImplicitAutoCorrect

    Define a function that will attempt to correct the range of its input to fall within a desired output
range.
    Operates by sampling the input function a number of times across an section of the domain, and using the
calculated min/max values to generate scale/offset pair to apply to the input. The calculate() function performs
this sampling and calculation, and is called automatically whenever a source is set, or whenever the desired output
ranges are set. Also, the function may be called manually, if desired.
***************************************************/

namespace anl
{
    class CImplicitAutoCorrect : public CImplicitModuleBase
    {
        public:
        CImplicitAutoCorrect();
        CImplicitAutoCorrect(ANLFloatType low, ANLFloatType high);
        CImplicitAutoCorrect(CImplicitModuleBase * m, ANLFloatType low, ANLFloatType high);
        ~CImplicitAutoCorrect(){}

        void setSource(CImplicitModuleBase * m);
        void setRange(ANLFloatType low, ANLFloatType high);
        void calculate();

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CImplicitModuleBase * m_source;
        ANLFloatType m_low, m_high;
        ANLFloatType m_scale2, m_offset2;
        ANLFloatType m_scale3, m_offset3;
        ANLFloatType m_scale4, m_offset4;
        ANLFloatType m_scale6, m_offset6;

    };
};


#endif
