#ifndef IMPLICITBUFFERSCALETORANGE_H
#define IMPLICITBUFFERSCALETORANGE_H

#include "implicitbufferbase.h"

namespace anl
{
    class CImplicitBufferScaleToRange : public CImplicitBufferBase
    {
    public:
        CImplicitBufferScaleToRange();
        CImplicitBufferScaleToRange(std::shared_ptr<CImplicitBufferBase> src, double low, double high);
        ~CImplicitBufferScaleToRange();

        void setRange(double low, double high);
        void setSource(std::shared_ptr<CImplicitBufferBase> src);

        void get(CArray2Dd &out);

    private:
        std::shared_ptr<CImplicitBufferBase> m_source;
        double m_low, m_high;
    };
};

#endif
