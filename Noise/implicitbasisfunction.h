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
        void setRotationAngle(ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        void setNoRotation();

        void setSeed(unsigned int seed);

        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);


        protected:

        ANLFloatType m_scale[4], m_offset[4];
        interp_func m_interp;
        noise_func2 m_2d;
        noise_func3 m_3d;
        noise_func4 m_4d;
        noise_func6 m_6d;
        unsigned int m_seed;

        ANLFloatType m_rotmatrix[3][3];
        ANLFloatType cos2d,sin2d;
        bool m_rotatedomain;

        void setMagicNumbers(int type);

    };

};

#endif
