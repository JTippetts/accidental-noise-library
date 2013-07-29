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

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        CRGBAParameter m_source;
        int m_channel;
    };
};

#endif
