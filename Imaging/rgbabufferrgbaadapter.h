#ifndef RGBABUFFERRGBAADAPTER_H
#define RGBABUFFERRGBAADAPTER_H

#include "rgbabufferbase.h"

namespace anl
{
    class CRGBABufferRGBAAdapter : public CRGBABufferBase
    {
    public:
        CRGBABufferRGBAAdapter();
        CRGBABufferRGBAAdapter(CRGBAModuleBase * src, int mapping=anl::SEAMLESS_NONE, SMappingRanges ranges=SMappingRanges(), bool use_z=false, ANLFloatType zvalue=0.0);
        ~CRGBABufferRGBAAdapter();

        void setSource(CRGBAModuleBase * src);
        void setMapping(int mapping);
        void setRanges(SMappingRanges &ranges);
        void setUseZ(bool use_z);
        void setZ(ANLFloatType z);

        void get(CArray2Drgba &out);
    private:
        CRGBAModuleBase * m_source;
        int m_mapping;
        SMappingRanges m_ranges;
        bool m_use_z;
        ANLFloatType m_z;
    };
};

#endif
