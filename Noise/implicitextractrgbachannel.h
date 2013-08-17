#ifndef IMPLICIT_EXTRACTRGBACHANNEL_H
#define IMPLICIT_EXTRACTRGBACHANNEL_H
#include "implicitmodulebase.h"
#include "rgbamodulebase.h"

namespace anl
{
    enum EExtractChannel
    {
        RED,
        GREEN,
        BLUE,
        ALPHA
    };

    class CImplicitExtractRGBAChannel : public CImplicitModuleBase
    {
        public:
        CImplicitExtractRGBAChannel();
        CImplicitExtractRGBAChannel(int channel);

        void setSource(CRGBAModuleBase * m);
        void setSource(SRGBA c);

        void setChannel(int channel);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CRGBAParameter m_source;
        int m_channel;
    };
};

#endif
