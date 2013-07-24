#ifndef IMPLICIT_TRIANGLE_H
#define IMPLICIT_TRIANGLE_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitTriangle : public CImplicitModuleBase
    {
        public:
        CImplicitTriangle();
        CImplicitTriangle(double source, double period, double offset);
        CImplicitTriangle(double source, double period, std::shared_ptr<CImplicitModuleBase> offset);
        CImplicitTriangle(double source, std::shared_ptr<CImplicitModuleBase> period, double offset);
        CImplicitTriangle(double source, std::shared_ptr<CImplicitModuleBase> period, std::shared_ptr<CImplicitModuleBase> offset);
        CImplicitTriangle(std::shared_ptr<CImplicitModuleBase> source, double period, double offset);
        CImplicitTriangle(std::shared_ptr<CImplicitModuleBase> source, double period, std::shared_ptr<CImplicitModuleBase> offset);
        CImplicitTriangle(std::shared_ptr<CImplicitModuleBase> source, std::shared_ptr<CImplicitModuleBase> period, double offset);
        CImplicitTriangle(std::shared_ptr<CImplicitModuleBase> source, std::shared_ptr<CImplicitModuleBase> period, std::shared_ptr<CImplicitModuleBase> offset);

        ~CImplicitTriangle();

        void setSource(double s);
        void setSource(std::shared_ptr<CImplicitModuleBase> s);
        void setPeriod(double p);
        void setPeriod(std::shared_ptr<CImplicitModuleBase> p);
        void setOffset(double o);
        void setOffset(std::shared_ptr<CImplicitModuleBase> o);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        CScalarParameter m_source, m_period, m_offset;
    };
};

#endif
