#ifndef HSV_H
#define HSV_H
#include "rgba.h"
#include "../types.h"

// Utility functions to handle HSV to RGB conversions
namespace anl
{
    void HSVtoRGBA(SRGBA &hsv, SRGBA &rgb);
    void RGBAtoHSV(SRGBA &rgb, SRGBA &hsv);
};


#endif
