#ifndef IMPLICIT_NORMALIZE_COORDS_H
#define IMPLICIT_NORMALIZE_COORDS_H

#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitNormalizeCoords : public CImplicitModuleBase
    {
        public:
        CImplicitNormalizeCoords();
        CImplicitNormalizeCoords(double s, double l);
        CImplicitNormalizeCoords(double s, std::shared_ptr<CImplicitModuleBase>  l);
        CImplicitNormalizeCoords(std::shared_ptr<CImplicitModuleBase> s, double l);
        CImplicitNormalizeCoords(std::shared_ptr<CImplicitModuleBase> s, std::shared_ptr<CImplicitModuleBase> l);

        void setSource(double v);
        void setSource(std::shared_ptr<CImplicitModuleBase> v);

        void setLength(double v);
        void setLength(std::shared_ptr<CImplicitModuleBase> v);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        CScalarParameter m_source;
        CScalarParameter m_length;
    };
};

#endif
