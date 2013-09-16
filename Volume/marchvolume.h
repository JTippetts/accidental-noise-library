// Marching Tetrahedra

#ifndef MARCHVOLUME_H
#define MARCHVOLUME_H


#include "volumeadapter.h"
#include "vectortypes.h"
#include "anlmesh.h"

namespace anl
{
	void marchDensityFieldCubeOBJ(CArray3Dd &df, float iso, std::string name);
	void marchDensityFieldSmoothOBJ(CArray3Dd &df, float iso, std::string name);
	
	void marchDensityFieldCube(CArray3Dd &df, float iso, CMesh &mesh);
	void marchDensityFieldSmooth(CArray3Dd &df, float iso, CMesh &mesh);
};

#endif