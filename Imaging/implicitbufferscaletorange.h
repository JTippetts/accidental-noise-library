#ifndef IMPLICITBUFFERSCALETORANGE_H
#define IMPLICITBUFFERSCALETORANGE_H

#include "implicitbufferbase.h"

namespace anl
{
    class CImplicitBufferScaleToRange : public CImplicitBufferBase
    {
    public:
        CImplicitBufferScaleToRange();
        CImplicitBufferScaleToRange(CImplicitBufferBase * src, double low, double high);
        ~CImplicitBufferScaleToRange();

        void setRange(double low, double high);
        void setSource(CImplicitBufferBase * src);

        void get(CArray2Dd &out);

    private:
        CImplicitBufferBase * m_source;
        double m_low, m_high;
    };
};

#endif
