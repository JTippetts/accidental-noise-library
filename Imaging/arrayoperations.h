#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include "mapping.h"

namespace anl
{

    void calcBumpMap(CArray2Dd *map, CArray2Dd *bump, float light[3], ANLFloatType spacing, bool wrap);
    void calcNormalMap(CArray2Dd *map, CArray2Drgba *normal, ANLFloatType spacing, bool normalize, bool wrap);
    void multRGBAByDouble(CArray2Drgba *rgba, CArray2Dd *map);
};

#endif
