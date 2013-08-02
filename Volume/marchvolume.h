// Marching Tetrahedra

#ifndef MARCHVOLUME_H
#define MARCHVOLUME_H


#include "volumeadapter.h"
#include "vectortypes.h"

namespace anl
{
	void marchDensityFieldOBJ(CArray3Dd &df, float iso, std::string name);
};

#endif