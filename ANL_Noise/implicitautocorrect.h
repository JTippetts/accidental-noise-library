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
        CImplicitAutoCorrect(double low, double high);
        CImplicitAutoCorrect(std::shared_ptr<CImplicitModuleBase> m, double low, double high);
        ~CImplicitAutoCorrect(){}

        void setSource(std::shared_ptr<CImplicitModuleBase> m);
        void setRange(double low, double high);
        void calculate();

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        std::shared_ptr<CImplicitModuleBase> m_source;
        double m_low, m_high;
        double m_scale2, m_offset2;
        double m_scale3, m_offset3;
        double m_scale4, m_offset4;
        double m_scale6, m_offset6;

    };
};


#endif
