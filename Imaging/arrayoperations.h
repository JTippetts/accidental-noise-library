#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include "mapping.h"

namespace anl
{

    void calcBumpMap(CArray2Dd *map, CArray2Dd *bump, double light[3], double spacing, bool wrap);
    void calcNormalMap(CArray2Dd *map, CArray2Drgba *normal, double spacing, bool normalize, bool wrap);
    void multRGBAByDouble(CArray2Drgba *rgba, CArray2Dd *map);
};

#endif
