#ifndef IMPLICITBUFFERSCALETORANGE_H
#define IMPLICITBUFFERSCALETORANGE_H

#include "implicitbufferbase.h"

namespace anl
{
    class CImplicitBufferScaleToRange : public CImplicitBufferBase
    {
    public:
        CImplicitBufferScaleToRange();
        CImplicitBufferScaleToRange(CImplicitBufferBase * src, ANLFloatType low, ANLFloatType high);
        ~CImplicitBufferScaleToRange();

        void setRange(ANLFloatType low, ANLFloatType high);
        void setSource(CImplicitBufferBase * src);

        void get(CArray2Dd &out);

    private:
        CImplicitBufferBase * m_source;
        ANLFloatType m_low, m_high;
    };
};

#endif
