#ifndef IMPLICIT_BRIGHTCONTRAST_H
#define IMPLICIT_BRIGHTCONTRAST_H

#include "implicitmodulebase.h"
namespace anl
{
    class CImplicitBrightContrast : public CImplicitModuleBase
    {
        public:
        CImplicitBrightContrast();
        CImplicitBrightContrast(double s,double b,double t,double f);
        CImplicitBrightContrast(double s,double b,double t,std::shared_ptr<CImplicitModuleBase>  f);
        CImplicitBrightContrast(double s,double b,std::shared_ptr<CImplicitModuleBase>  t,double f);
        CImplicitBrightContrast(double s,double b,std::shared_ptr<CImplicitModuleBase>  t,std::shared_ptr<CImplicitModuleBase>  f);
        CImplicitBrightContrast(double s,std::shared_ptr<CImplicitModuleBase>  b,double t,double f);
        CImplicitBrightContrast(double s,std::shared_ptr<CImplicitModuleBase>  b,double t,std::shared_ptr<CImplicitModuleBase>  f);
        CImplicitBrightContrast(double s,std::shared_ptr<CImplicitModuleBase>  b,std::shared_ptr<CImplicitModuleBase>  t,double f);
        CImplicitBrightContrast(double s,std::shared_ptr<CImplicitModuleBase>  b,std::shared_ptr<CImplicitModuleBase>  t,std::shared_ptr<CImplicitModuleBase>  f);
        CImplicitBrightContrast(std::shared_ptr<CImplicitModuleBase>  s,double b,double t,double f);
        CImplicitBrightContrast(std::shared_ptr<CImplicitModuleBase>  s,double b,double t,std::shared_ptr<CImplicitModuleBase>  f);
        CImplicitBrightContrast(std::shared_ptr<CImplicitModuleBase>  s,double b,std::shared_ptr<CImplicitModuleBase>  t,double f);
        CImplicitBrightContrast(std::shared_ptr<CImplicitModuleBase>  s,double b,std::shared_ptr<CImplicitModuleBase>  t,std::shared_ptr<CImplicitModuleBase>  f);
        CImplicitBrightContrast(std::shared_ptr<CImplicitModuleBase>  s,std::shared_ptr<CImplicitModuleBase>  b,double t,double f);
        CImplicitBrightContrast(std::shared_ptr<CImplicitModuleBase>  s,std::shared_ptr<CImplicitModuleBase>  b,double t,std::shared_ptr<CImplicitModuleBase>  f);
        CImplicitBrightContrast(std::shared_ptr<CImplicitModuleBase>  s,std::shared_ptr<CImplicitModuleBase>  b,std::shared_ptr<CImplicitModuleBase>  t,double f);
        CImplicitBrightContrast(std::shared_ptr<CImplicitModuleBase>  s,std::shared_ptr<CImplicitModuleBase>  b,std::shared_ptr<CImplicitModuleBase>  t,std::shared_ptr<CImplicitModuleBase>  f);

        ~CImplicitBrightContrast();

        void setSource(std::shared_ptr<CImplicitModuleBase> m);
        void setSource(double v);

        void setBrightness(double b);
        void setContrastThreshold(double t);
        void setContrastFactor(double t);
        void setBrightness(std::shared_ptr<CImplicitModuleBase> m);
        void setContrastThreshold(std::shared_ptr<CImplicitModuleBase> m);
        void setContrastFactor(std::shared_ptr<CImplicitModuleBase> m);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);
        protected:
        CScalarParameter m_source;
        CScalarParameter m_bright, m_threshold, m_factor;
    };
};

#endif
