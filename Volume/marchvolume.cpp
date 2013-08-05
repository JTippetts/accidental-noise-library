#include "marchvolume.h"

#include <cmath>
#include <vector>
#include <deque>
#include <fstream>
#include <iostream>

#include "PolyVoxCore/CubicSurfaceExtractorWithNormals.h"
#include "PolyVoxCore/MarchingCubesSurfaceExtractor.h"
#include "PolyVoxCore/SurfaceMesh.h"
#include "PolyVoxCore/SimpleVolume.h"

using namespace PolyVox;
void createSphereInVolume(SimpleVolume<uint8_t>& volData, float fRadius)
{
	//This vector hold the position of the center of the volume
	Vector3DFloat v3dVolCenter(volData.getWidth() / 2, volData.getHeight() / 2, volData.getDepth() / 2);

	//This three-level for loop iterates over every voxel in the volume
	for (int z = 0; z < volData.getDepth(); z++)
	{
		for (int y = 0; y < volData.getHeight(); y++)
		{
			for (int x = 0; x < volData.getWidth(); x++)
			{
				//Store our current position as a vector...
				Vector3DFloat v3dCurrentPos(x,y,z);	
				//And compute how far the current position is from the center of the volume
				float fDistToCenter = (v3dCurrentPos - v3dVolCenter).length();

				uint8_t uVoxelValue = 0;

				//If the current voxel is less than 'radius' units from the center then we make it solid.
				if(fDistToCenter <= fRadius)
				{
					//Our new voxel value
					uVoxelValue = 255;
				}

				//Wrte the voxel value into the volume	
				volData.setVoxelAt(x, y, z, uVoxelValue);
			}
		}
	}
}

namespace anl
{
	void marchDensityFieldOBJ(CArray3Dd &df, float iso, std::string name)
	{
		SimpleVolume<uint8_t> volData(PolyVox::Region(Vector3DInt32(0,0,0), Vector3DInt32(df.width(), df.height(), df.depth())));
		//createSphereInVolume(volData, 30);
		
		// Copy df into volData
		for(unsigned int x=0; x<df.width(); ++x)
		{
			for(unsigned int y=0; y<df.height(); ++y)
			{
				for(unsigned int z=0; z<df.depth(); ++z)
				{
					volData.setVoxelAt(x,y,z, df.get(x,y,z) >= iso ? 255 : 0);
				}
			}
		}
		
		volData.setBorderValue(0);

		//A mesh object to hold the result of surface extraction
		SurfaceMesh<PositionMaterialNormal> mesh;

		//Create a surface extractor. Comment out one of the following two lines to decide which type gets created.
		//CubicSurfaceExtractorWithNormals< SimpleVolume<uint8_t> > surfaceExtractor(&volData, volData.getEnclosingRegion(), &mesh);
		MarchingCubesSurfaceExtractor< SimpleVolume<uint8_t> > surfaceExtractor(&volData, volData.getEnclosingRegion(), &mesh);

		//Execute the surface extractor.
		surfaceExtractor.execute();
		
		mesh.removeDegenerateTris();
		mesh.removeUnusedVertices();
		
		// DUmp to obj
		std::fstream outfile(name,std::ios::out);
		const std::vector<uint32_t>& faces=mesh.getIndices();
		const std::vector<PositionMaterialNormal>& verts=mesh.getVertices();
		
		for(int c=0; c<verts.size(); ++c)
		{
			const Vector3DFloat& v=verts[c].getPosition();
			outfile << "v " << v.getX() << " " << v.getY() << " " << v.getZ() << std::endl;
		}	

		for(int c=0; c<faces.size(); c+=3)
		{
			outfile << "f " << faces[c]+1 << " " << faces[c+1]+1 << " " << faces[c+2]+1 << std::endl;
		}

		outfile.close();
		
	}
};