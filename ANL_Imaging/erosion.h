#ifndef EROSION_H
#define EROSION_H

#include "../ANL_Noise/anl_noise.h"
#include "../ANL_RGBA/anl_rgba.h"
#include "../ANL_Imaging/anl_imaging.h"

void simpleErode(anl::CArray2Dd &map, unsigned int numdrops, float power);
void simpleRainfall(anl::CArray2Dd &map, anl::CArray2Dd &depth, int iterations);

#endif
