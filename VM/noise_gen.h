#ifndef NOISE_GEN_H
#define NOISE_GEN_H
#include "types.h"

namespace anl
{

    typedef ANLFloatType (*interp_func)(ANLFloatType);
    typedef ANLFloatType (*noise_func2)(ANLFloatType, ANLFloatType, unsigned int, interp_func);
    typedef ANLFloatType (*noise_func3)(ANLFloatType,ANLFloatType,ANLFloatType,unsigned int, interp_func);
    typedef ANLFloatType (*noise_func4)(ANLFloatType,ANLFloatType,ANLFloatType,ANLFloatType,unsigned int, interp_func);
    typedef ANLFloatType (*noise_func6)(ANLFloatType,ANLFloatType,ANLFloatType,ANLFloatType,ANLFloatType,ANLFloatType,unsigned int,interp_func);
    typedef ANLFloatType (*dist_func2)(ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType);
    typedef ANLFloatType (*dist_func3)(ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType);
    typedef ANLFloatType (*dist_func4)(ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType);
    typedef ANLFloatType (*dist_func6)(ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType, ANLFloatType);

    // Interpolation functions
    ANLFloatType noInterp(ANLFloatType t);
    ANLFloatType linearInterp(ANLFloatType t);
    ANLFloatType hermiteInterp(ANLFloatType t);
    ANLFloatType quinticInterp(ANLFloatType t);

    // Distance functions
    ANLFloatType distEuclid2(ANLFloatType x1, ANLFloatType y1, ANLFloatType x2, ANLFloatType y2);
    ANLFloatType distEuclid3(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2);
    ANLFloatType distEuclid4(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2);
    ANLFloatType distEuclid6(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType u1, ANLFloatType v1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2, ANLFloatType u2, ANLFloatType v2);

    ANLFloatType distManhattan2(ANLFloatType x1, ANLFloatType y1, ANLFloatType x2, ANLFloatType y2);
    ANLFloatType distManhattan3(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2);
    ANLFloatType distManhattan4(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2);
    ANLFloatType distManhattan6(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType u1, ANLFloatType v1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2, ANLFloatType u2, ANLFloatType v2);

    ANLFloatType distGreatestAxis2(ANLFloatType x1, ANLFloatType y1, ANLFloatType x2, ANLFloatType y2);
    ANLFloatType distGreatestAxis3(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2);
    ANLFloatType distGreatestAxis4(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2);
    ANLFloatType distGreatestAxis6(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType u1, ANLFloatType v1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2, ANLFloatType u2, ANLFloatType v2);

    ANLFloatType distLeastAxis2(ANLFloatType x1, ANLFloatType y1, ANLFloatType x2, ANLFloatType y2);
    ANLFloatType distLeastAxis3(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2);
    ANLFloatType distLeastAxis4(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2);
    ANLFloatType distLeastAxis6(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType u1, ANLFloatType v1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2, ANLFloatType u2, ANLFloatType v2);


    // Noise generators
    ANLFloatType value_noise2D(ANLFloatType x, ANLFloatType y, unsigned int seed, interp_func interp);
    ANLFloatType value_noise3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, interp_func interp);
    ANLFloatType value_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp);
    ANLFloatType value_noise6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, interp_func interp);

    ANLFloatType gradient_noise2D(ANLFloatType x, ANLFloatType y, unsigned int seed, interp_func interp);
    ANLFloatType gradient_noise3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, interp_func interp);
    ANLFloatType gradient_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp);
    ANLFloatType gradient_noise6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, interp_func interp);

    ANLFloatType gradval_noise2D(ANLFloatType x, ANLFloatType y, unsigned int seed, interp_func interp);
    ANLFloatType gradval_noise3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, interp_func interp);
    ANLFloatType gradval_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp);
    ANLFloatType gradval_noise6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, interp_func interp);

    ANLFloatType white_noise2D(ANLFloatType x, ANLFloatType y, unsigned int seed, interp_func interp);
    ANLFloatType white_noise3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, interp_func interp);
    ANLFloatType white_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp);
    ANLFloatType white_noise6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, interp_func interp);

    ANLFloatType simplex_noise2D(ANLFloatType x, ANLFloatType y, unsigned int seed, interp_func interp);
    ANLFloatType simplex_noise3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, interp_func interp);
    ANLFloatType simplex_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp);
    ANLFloatType simplex_noise6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, interp_func interp);
    ANLFloatType new_simplex_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp);

    void cellular_function2D(ANLFloatType x, ANLFloatType y, unsigned int seed, ANLFloatType *f, ANLFloatType *disp, dist_func2 dist);
    void cellular_function3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, ANLFloatType *f, ANLFloatType *disp, dist_func3 dist);
    void cellular_function4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, ANLFloatType *f, ANLFloatType *disp, dist_func4 dist);
    void cellular_function6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, ANLFloatType *f, ANLFloatType *disp, dist_func6 dist);
    // Hash
    unsigned int FNV1A_3d(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed);

};
#endif
