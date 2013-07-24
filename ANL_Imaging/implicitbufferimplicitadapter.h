#ifndef IMPLICITBUFFERIMPLICITADAPTER_H
#define IMPLICITBUFFERIMPLICITADAPTER_H
#include "implicitbufferbase.h"
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitBufferImplicitAdapter : public CImplicitBufferBase
    {
    public:
        CImplicitBufferImplicitAdapter();
        CImplicitBufferImplicitAdapter(std::shared_ptr<CImplicitModuleBase> src, int mapping=anl::SEAMLESS_NONE, SMappingRanges ranges=SMappingRanges(), bool use_z=false, double zvalue=0.0);
        ~CImplicitBufferImplicitAdapter();

        void setSource(std::shared_ptr<CImplicitModuleBase> src);
        void setMapping(int mapping);
        void setRanges(SMappingRanges &ranges);
        void setUseZ(bool use_z);
        void setZ(double z);

        void get(CArray2Dd &out);
    private:
        std::shared_ptr<CImplicitModuleBase> m_source;
        int m_mapping;
        SMappingRanges m_ranges;
        bool m_use_z;
        double m_z;
    };
};

#endif
