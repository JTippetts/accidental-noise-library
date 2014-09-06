#ifndef IMAGING_H
#define IMAGING_H

#include "templates/tarrays.h"

namespace anl
{
    void saveDoubleArray(std::string filename, TArray2D<ANLFloatType> *array);
    void saveRGBAArray(std::string filename, TArray2D<anl::SRGBA> *array);
};

#endif
