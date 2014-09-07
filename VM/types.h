#ifndef TYPES_H
#define TYPES_H

#define ANL_DOUBLE_PRECISION

#ifdef ANL_DOUBLE_PRECISION
    #define ANLFloatType double
#else
    #define ANLFloatType float
#endif

namespace anl
{
    struct RGBA
    {
        float r,g,b,a;
    };
};

#endif
