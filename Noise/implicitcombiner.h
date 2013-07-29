#ifndef IMPLICIT_COMBINER_H
#define IMPLICIT_COMBINER_H
#include "implicitmodulebase.h"

namespace anl
{
    enum ECombinerTypes
    {
        ADD,
        MULT,
        MAX,
        MIN,
        AVG
    };

    class CImplicitCombiner : public CImplicitModuleBase
    {
        public:
        CImplicitCombiner(unsigned int type);
        void setType(unsigned int type);
        void clearAllSources();
        void setSource(int which, CImplicitModuleBase * b);
        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        CImplicitModuleBase * m_sources[MaxSources];
        unsigned int m_type;

        double Add_get(double x, double y);
        double Add_get(double x, double y, double z);
        double Add_get(double x, double y, double z, double w);
        double Add_get(double x, double y, double z, double w, double u, double v);
        double Mult_get(double x, double y);
        double Mult_get(double x, double y, double z);
        double Mult_get(double x, double y, double z, double w);
        double Mult_get(double x, double y, double z, double w, double u, double v);
        double Min_get(double x, double y);
        double Min_get(double x, double y, double z);
        double Min_get(double x, double y, double z, double w);
        double Min_get(double x, double y, double z, double w, double u, double v);
        double Max_get(double x, double y);
        double Max_get(double x, double y, double z);
        double Max_get(double x, double y, double z, double w);
        double Max_get(double x, double y, double z, double w, double u, double v);
        double Avg_get(double x, double y);
        double Avg_get(double x, double y, double z);
        double Avg_get(double x, double y, double z, double w);
        double Avg_get(double x, double y, double z, double w, double u, double v);
    };
};

#endif
