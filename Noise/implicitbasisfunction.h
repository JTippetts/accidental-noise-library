#ifndef IMPLICIT_BASIS_FUNCTION_H
#define IMPLICIT_BASIS_FUNCTION_H
#include "noise_gen.h"
#include "implicitmodulebase.h"

namespace anl
{

    enum EBasisTypes
    {
        VALUE,
        GRADIENT,
        GRADVAL,
        SIMPLEX,
        WHITE
    };

    enum EInterpTypes
    {
        NONE,
        LINEAR,
        CUBIC,
        QUINTIC
    };


    class CImplicitBasisFunction : public CImplicitModuleBase
    {
        public:
        CImplicitBasisFunction();
        CImplicitBasisFunction(int type, int interp, bool rotatedomain=true);

        void setType(int type);
        void setInterp(int interp);
        void setRotationAngle(double ax, double ay, double az, double angle);
        void setNoRotation();

        void setSeed(unsigned int seed);

        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);


        protected:

        double m_scale[4], m_offset[4];
        interp_func m_interp;
        noise_func2 m_2d;
        noise_func3 m_3d;
        noise_func4 m_4d;
        noise_func6 m_6d;
        unsigned int m_seed;

        double m_rotmatrix[3][3];
        double cos2d,sin2d;
        bool m_rotatedomain;

        void setMagicNumbers(int type);

    };

};

#endif
