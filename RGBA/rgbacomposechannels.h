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
        CRGBACompositeChannels(double r, double g, double b, double a, int mode);
        CRGBACompositeChannels(double r, double g, double b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(double r, double g, CImplicitModuleBase * b, double a, int mode);
        CRGBACompositeChannels(double r, double g, CImplicitModuleBase * b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(double r, CImplicitModuleBase * g, double b, double a, int mode);
        CRGBACompositeChannels(double r, CImplicitModuleBase * g, double b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(double r, CImplicitModuleBase * g, CImplicitModuleBase * b, double a, int mode);
        CRGBACompositeChannels(double r, CImplicitModuleBase * g, CImplicitModuleBase * b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, double g, double b, double a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, double g, double b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, double g, CImplicitModuleBase * b, double a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, double g, CImplicitModuleBase * b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, CImplicitModuleBase * g, double b, double a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, CImplicitModuleBase * g, double b, CImplicitModuleBase * a, int mode);
        CRGBACompositeChannels(CImplicitModuleBase * r, CImplicitModuleBase * g, CImplicitModuleBase * b, double a, int mode);
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

        void setRedSource(double r);
        void setGreenSource(double g);
        void setBlueSource(double b);
        void setAlphaSource(double a);
        void setHueSource(double h);
        void setSatSource(double s);
        void setValSource(double v);

        SRGBA get(double x, double y);
        SRGBA get(double x, double y, double z);
        SRGBA get(double x, double y, double z, double w);
        SRGBA get(double x, double y, double z, double w, double u, double v);

        protected:
        CScalarParameter m_c1, m_c2, m_c3, m_c4;
        int m_mode;
    };
};

#endif
