#ifndef RGBA_COMPOSE_CHANNELS_H
#define RGBA_COMPOSE_CHANNELS_H
#include "rgbamodulebase.h"
#include "../Noise/implicitmodulebase.h"

namespace anl
{
    enum CompositeChannelsMode
    {
        RGB,
        HSV
    };

    class CRGBACompositeChannels : public CRGBAModuleBase
    {
        public:
        CRGBACompositeChannels();
        CRGBACompositeChannels(ANLFloatType r, ANLFloatType g, ANLFloatType b, ANLFloatType a, int mode);
        CRGBACompositeChannels(ANLFloatType r, ANLFloatType g, ANLFloatType b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(ANLFloatType r, ANLFloatType g, CImplicitModuleBase * b, ANLFloatType a, int mode);
        CRGBACompositeChannels(ANLFloatType r, ANLFloatType g, CImplicitModuleBase * b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(ANLFloatType r, CImplicitModuleBase * g, ANLFloatType b, ANLFloatType a, int mode);
        CRGBACompositeChannels(ANLFloatType r, CImplicitModuleBase * g, ANLFloatType b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(ANLFloatType r, CImplicitModuleBase * g, CImplicitModuleBase * b, ANLFloatType a, int mode);
        CRGBACompositeChannels(ANLFloatType r, CImplicitModuleBase * g, CImplicitModuleBase * b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, ANLFloatType g, ANLFloatType b, ANLFloatType a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, ANLFloatType g, ANLFloatType b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, ANLFloatType g, CImplicitModuleBase * b, ANLFloatType a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, ANLFloatType g, CImplicitModuleBase * b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, CImplicitModuleBase * g, ANLFloatType b, ANLFloatType a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, CImplicitModuleBase * g, ANLFloatType b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, CImplicitModuleBase * g, CImplicitModuleBase * b, ANLFloatType a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, CImplicitModuleBase * g, CImplicitModuleBase * b, CImplicitModuleBase * a, int mode);

        ~CRGBACompositeChannels();

        void setMode(int mode){m_mode=mode;}

        void setRedSource(CImplicitModuleBase * m);
        void setGreenSource(CImplicitModuleBase * m);
        void setBlueSource(CImplicitModuleBase * m);
        void setHueSource(CImplicitModuleBase * m);
        void setSatSource(CImplicitModuleBase * m);
        void setValSource(CImplicitModuleBase * m);
        void setAlphaSource(CImplicitModuleBase * m);

        void setRedSource(ANLFloatType r);
        void setGreenSource(ANLFloatType g);
        void setBlueSource(ANLFloatType b);
        void setAlphaSource(ANLFloatType a);
        void setHueSource(ANLFloatType h);
        void setSatSource(ANLFloatType s);
        void setValSource(ANLFloatType v);

        SRGBA get(ANLFloatType x, ANLFloatType y);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        CScalarParameter m_c1, m_c2, m_c3, m_c4;
        int m_mode;
    };
};

#endif
