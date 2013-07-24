#ifndef IMPLICIT_TIERS_H
#define IMPLICIT_TIERS_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitTiers : public CImplicitModuleBase
    {
        public:
        CImplicitTiers();
        CImplicitTiers(double src, int numtiers, bool smooth);
        CImplicitTiers(std::shared_ptr<CImplicitModuleBase> src, int numtiers, bool smooth);
        ~CImplicitTiers();

        void setSource(double v);
        void setSource(std::shared_ptr<CImplicitModuleBase> m);
        void setNumTiers(int numtiers);
        void setSmooth(bool smooth);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        CScalarParameter m_source;
        int m_numtiers;
        bool m_smooth;
    };
};

#endif
