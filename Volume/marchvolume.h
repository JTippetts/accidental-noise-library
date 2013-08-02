// Marching Tetrahedra

#ifndef MARCHVOLUME_H
#define MARCHVOLUME_H


#include "volumeadapter.h"
#include "vectortypes.h"

namespace anl
{
	int marchCube(CArray3Dd &df, unsigned int x, unsigned int y, unsigned int z, float isolevel, anl::CVec3f triangles[15]);
	int marchTetra(CArray3Dd &df,unsigned int x, unsigned int y, unsigned int z, double iso,anl::CVec3f tri[6],int v0,int v1,int v2,int v3);
	void marchDensityFieldSurfaceOBJ(CArray3Dd &df, float iso, std::string name);
	void marchDensityFieldOBJ(CArray3Dd &df, float iso, std::string name);
};

#endif