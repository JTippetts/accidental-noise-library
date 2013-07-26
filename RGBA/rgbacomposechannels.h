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
        CRGBACompositeChannels(double r, double g, double b, std::shared_ptr<CImplicitModuleBase> a, int mode);
        CRGBACompositeChannels(double r, double g, std::shared_ptr<CImplicitModuleBase> b, double a, int mode);
        CRGBACompositeChannels(double r, double g, std::shared_ptr<CImplicitModuleBase> b, std::shared_ptr<CImplicitModuleBase> a, int mode);
        CRGBACompositeChannels(double r, std::shared_ptr<CImplicitModuleBase> g, double b, double a, int mode);
        CRGBACompositeChannels(double r, std::shared_ptr<CImplicitModuleBase> g, double b, std::shared_ptr<CImplicitModuleBase> a, int mode);
        CRGBACompositeChannels(double r, std::shared_ptr<CImplicitModuleBase> g, std::shared_ptr<CImplicitModuleBase> b, double a, int mode);
        CRGBACompositeChannels(double r, std::shared_ptr<CImplicitModuleBase> g, std::shared_ptr<CImplicitModuleBase> b, std::shared_ptr<CImplicitModuleBase> a, int mode);
        CRGBACompositeChannels(std::shared_ptr<CImplicitModuleBase> r, double g, double b, double a, int mode);
        CRGBACompositeChannels(std::shared_ptr<CImplicitModuleBase> r, double g, double b, std::shared_ptr<CImplicitModuleBase> a, int mode);
        CRGBACompositeChannels(std::shared_ptr<CImplicitModuleBase> r, double g, std::shared_ptr<CImplicitModuleBase> b, double a, int mode);
        CRGBACompositeChannels(std::shared_ptr<CImplicitModuleBase> r, double g, std::shared_ptr<CImplicitModuleBase> b, std::shared_ptr<CImplicitModuleBase> a, int mode);
        CRGBACompositeChannels(std::shared_ptr<CImplicitModuleBase> r, std::shared_ptr<CImplicitModuleBase> g, double b, double a, int mode);
        CRGBACompositeChannels(std::shared_ptr<CImplicitModuleBase> r, std::shared_ptr<CImplicitModuleBase> g, double b, std::shared_ptr<CImplicitModuleBase> a, int mode);
        CRGBACompositeChannels(std::shared_ptr<CImplicitModuleBase> r, std::shared_ptr<CImplicitModuleBase> g, std::shared_ptr<CImplicitModuleBase> b, double a, int mode);
        CRGBACompositeChannels(std::shared_ptr<CImplicitModuleBase> r, std::shared_ptr<CImplicitModuleBase> g, std::shared_ptr<CImplicitModuleBase> b, std::shared_ptr<CImplicitModuleBase> a, int mode);

        ~CRGBACompositeChannels();

        void setMode(int mode){m_mode=mode;}

        void setRedSource(std::shared_ptr<CImplicitModuleBase> m);
        void setGreenSource(std::shared_ptr<CImplicitModuleBase> m);
        void setBlueSource(std::shared_ptr<CImplicitModuleBase> m);
        void setHueSource(std::shared_ptr<CImplicitModuleBase> m);
        void setSatSource(std::shared_ptr<CImplicitModuleBase> m);
        void setValSource(std::shared_ptr<CImplicitModuleBase> m);
        void setAlphaSource(std::shared_ptr<CImplicitModuleBase> m);

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
