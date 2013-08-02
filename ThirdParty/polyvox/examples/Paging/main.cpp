/*******************************************************************************
Copyright (c) 2005-2009 David Williams

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution. 	
*******************************************************************************/

#include "OpenGLWidget.h"
#include "Perlin.h"

#include "PolyVoxCore/MaterialDensityPair.h"
#include "PolyVoxCore/CubicSurfaceExtractorWithNormals.h"
#include "PolyVoxCore/MarchingCubesSurfaceExtractor.h"
#include "PolyVoxCore/SurfaceMesh.h"
#include "PolyVoxCore/LargeVolume.h"

#include <QApplication>

//Use the PolyVox namespace
using namespace PolyVox;

void createPerlinVolumeSlow(LargeVolume<MaterialDensityPair44>& volData)
{
	Perlin perlin(2,8,1,234);

	for(int z = 1; z < 256-1; z++)
	{
		std::cout << z << std::endl;
		for(int y = 1; y < 256-1; y++)
		{
			for(int x = 1; x < 256-1; x++)
			{							
				float perlinVal = perlin.Get3D(x /static_cast<float>(256-1), (y) / static_cast<float>(256-1), z / static_cast<float>(256-1));

				perlinVal += 1.0f;
				perlinVal *= 0.5f;
				perlinVal *= MaterialDensityPair44::getMaxDensity();

				MaterialDensityPair44 voxel;

				voxel.setMaterial(245);
				voxel.setDensity(perlinVal);

				/*if(perlinVal < 0.0f)
				{
					voxel.setMaterial(245);
					voxel.setDensity(MaterialDensityPair44::getMaxDensity());
				}
				else
				{
					voxel.setMaterial(0);
					voxel.setDensity(MaterialDensityPair44::getMinDensity());
				}*/

				volData.setVoxelAt(x, y, z, voxel);
			}
		}
	}
}

/*void createPerlinVolumeFast(LargeVolume<MaterialDensityPair44>& volData)
{
	Perlin perlin(2,8,1,234);

	for(int blockZ = 0; blockZ < volData.m_uDepthInBlocks; blockZ++)
	{		
		std::cout << blockZ << std::endl;
		for(int blockY = 0; blockY < volData.m_uHeightInBlocks; blockY++)
		{
			for(int blockX = 0; blockX < volData.m_uWidthInBlocks; blockX++)
			{
				for(int offsetz = 0; offsetz < volData.m_uBlockSideLength; offsetz++)
				{
					for(int offsety = 0; offsety < volData.m_uBlockSideLength; offsety++)
					{
						for(int offsetx = 0; offsetx < volData.m_uBlockSideLength; offsetx++) 
						{							
							int x = blockX * volData.m_uBlockSideLength + offsetx;
							int y = blockY * volData.m_uBlockSideLength + offsety;
							int z = blockZ * volData.m_uBlockSideLength + offsetz;

							if((x == 0) || (x == volData.getWidth()-1)) continue;
							if((y == 0) || (y == volData.getHeight()-1)) continue;
							if((z == 0) || (z == volData.getDepth()-1)) continue;

							float perlinVal = perlin.Get3D(x /static_cast<float>(volData.getWidth()-1), (y) / static_cast<float>(volData.getHeight()-1), z / static_cast<float>(volData.getDepth()-1));

							MaterialDensityPair44 voxel;
							if(perlinVal < 0.0f)
							{
								voxel.setMaterial(245);
								voxel.setDensity(MaterialDensityPair44::getMaxDensity());
							}
							else
							{
								voxel.setMaterial(0);
								voxel.setDensity(MaterialDensityPair44::getMinDensity());
							}

							volData.setVoxelAt(x, y, z, voxel);
						}
					}
				}
			}
		}			
	}
}*/

void createPerlinTerrain(LargeVolume<MaterialDensityPair44>& volData)
{
	Perlin perlin(2,2,1,234);

	for(int x = 1; x < 255-1; x++)
	{
		if(x%(255/100) == 0) {
			std::cout << "." << std::flush;
		}
		for(int y = 1; y < 255-1; y++)
		{
			float perlinVal = perlin.Get(x / static_cast<float>(255-1), y / static_cast<float>(255-1));
			perlinVal += 1.0f;
			perlinVal *= 0.5f;
			perlinVal *= 255;
			for(int z = 1; z < 255-1; z++)
			{							
				MaterialDensityPair44 voxel;
				if(z < perlinVal)
				{
					voxel.setMaterial(245);
					voxel.setDensity(MaterialDensityPair44::getMaxDensity());
				}
				else
				{
					voxel.setMaterial(0);
					voxel.setDensity(MaterialDensityPair44::getMinDensity());
				}

				volData.setVoxelAt(x, y, z, voxel);
			}
		}
	}
	std::cout << std::endl;
}

void createSphereInVolume(LargeVolume<MaterialDensityPair44>& volData, Vector3DFloat v3dVolCenter, float fRadius)
{
	//This vector hold the position of the center of the volume
	//Vector3DFloat v3dVolCenter(volData.getWidth() / 2, volData.getHeight() / 2, volData.getDepth() / 2);

	int iRadius = fRadius;

	//This three-level for loop iterates over every voxel in the volume
	for (int z = v3dVolCenter.getZ() - iRadius; z <= v3dVolCenter.getZ() + iRadius; z++)
	{
		for (int y = v3dVolCenter.getY() - iRadius; y <= v3dVolCenter.getY() + iRadius; y++)
		{
			for (int x = v3dVolCenter.getX() - iRadius; x <= v3dVolCenter.getX() + iRadius; x++)
			{
				//Store our current position as a vector...
				Vector3DFloat v3dCurrentPos(x,y,z);	
				//And compute how far the current position is from the center of the volume
				float fDistToCenter = (v3dCurrentPos - v3dVolCenter).length();

				//If the current voxel is less than 'radius' units from the center then we make it solid.
				if(fDistToCenter <= fRadius)
				{
					//Our new density value
					uint8_t uDensity = MaterialDensityPair44::getMaxDensity();

					//Get the old voxel
					MaterialDensityPair44 voxel = volData.getVoxelAt(x,y,z);

					//Modify the density
					voxel.setDensity(uDensity);

					//Wrte the voxel value into the volume	
					volData.setVoxelAt(x, y, z, voxel);
				}
			}
		}
	}
}

void load(const ConstVolumeProxy<MaterialDensityPair44>& volume, const PolyVox::Region& reg)
{
	Perlin perlin(2,2,1,234);

	for(int x = reg.getLowerCorner().getX(); x <= reg.getUpperCorner().getX(); x++)
	{
		for(int y = reg.getLowerCorner().getY(); y <= reg.getUpperCorner().getY(); y++)
		{
			float perlinVal = perlin.Get(x / static_cast<float>(255-1), y / static_cast<float>(255-1));
			perlinVal += 1.0f;
			perlinVal *= 0.5f;
			perlinVal *= 255;
			for(int z = reg.getLowerCorner().getZ(); z <= reg.getUpperCorner().getZ(); z++)
			{
				MaterialDensityPair44 voxel;
				if(z < perlinVal)
				{
					const int xpos = 50;
					const int zpos = 100;
					if((x-xpos)*(x-xpos) + (z-zpos)*(z-zpos) < 200) {
						// tunnel
						voxel.setMaterial(0);
						voxel.setDensity(MaterialDensityPair44::getMinDensity());
					} else {
						// solid
						voxel.setMaterial(245);
						voxel.setDensity(MaterialDensityPair44::getMaxDensity());
					}
				}
				else
				{
					voxel.setMaterial(0);
					voxel.setDensity(MaterialDensityPair44::getMinDensity());
				}

				volume.setVoxelAt(x, y, z, voxel);
			}
		}
	}
}

void unload(const ConstVolumeProxy<MaterialDensityPair44>& /*vol*/, const PolyVox::Region& reg)
{
	std::cout << "warning unloading region: " << reg.getLowerCorner() << " -> " << reg.getUpperCorner() << std::endl;
}

int main(int argc, char *argv[])
{
	//Create and show the Qt OpenGL window
	QApplication app(argc, argv);
	OpenGLWidget openGLWidget(0);
	openGLWidget.show();

	//If these lines don't compile, please try commenting them out and using the two lines after
	//(you will need Boost for this). If you have to do this then please let us know in the forums as
	//we rely on community feedback to keep the Boost version running.
	LargeVolume<MaterialDensityPair44> volData(&load, &unload, 256);
	//LargeVolume<MaterialDensityPair44> volData(polyvox_bind(&load, polyvox_placeholder_1, polyvox_placeholder_2),
	//	polyvox_bind(&unload, polyvox_placeholder_1, polyvox_placeholder_2), 256);
	volData.setMaxNumberOfBlocksInMemory(4096);
	volData.setMaxNumberOfUncompressedBlocks(64);

	//volData.dataRequiredHandler = &load;
	//volData.dataOverflowHandler = &unload;

	//volData.setMaxNumberOfUncompressedBlocks(4096);
	//createSphereInVolume(volData, 30);
	//createPerlinTerrain(volData);
	//createPerlinVolumeSlow(volData);
	std::cout << "Memory usage: " << (volData.calculateSizeInBytes()/1024.0/1024.0) << "MB" << std::endl;
	std::cout << "Compression ratio: 1 to " << (1.0/(volData.calculateCompressionRatio())) << std::endl;
	//volData.setBlockCacheSize(64);
	PolyVox::Region reg(Vector3DInt32(-255,0,0), Vector3DInt32(255,255,255));
	std::cout << "Prefetching region: " << reg.getLowerCorner() << " -> " << reg.getUpperCorner() << std::endl;
	volData.prefetch(reg);
	std::cout << "Memory usage: " << (volData.calculateSizeInBytes()/1024.0/1024.0) << "MB" << std::endl;
	std::cout << "Compression ratio: 1 to " << (1.0/(volData.calculateCompressionRatio())) << std::endl;
	PolyVox::Region reg2(Vector3DInt32(0,0,0), Vector3DInt32(255,255,255));
	std::cout << "Flushing region: " << reg2.getLowerCorner() << " -> " << reg2.getUpperCorner() << std::endl;
	volData.flush(reg2);
	std::cout << "Memory usage: " << (volData.calculateSizeInBytes()/1024.0/1024.0) << "MB" << std::endl;
	std::cout << "Compression ratio: 1 to " << (1.0/(volData.calculateCompressionRatio())) << std::endl;
	std::cout << "Flushing entire volume" << std::endl;
	volData.flushAll();
	std::cout << "Memory usage: " << (volData.calculateSizeInBytes()/1024.0/1024.0) << "MB" << std::endl;
	std::cout << "Compression ratio: 1 to " << (1.0/(volData.calculateCompressionRatio())) << std::endl;

	//Extract the surface
	SurfaceMesh<PositionMaterialNormal> mesh;
	CubicSurfaceExtractorWithNormals< LargeVolume<MaterialDensityPair44> > surfaceExtractor(&volData, reg, &mesh);
	//MarchingCubesSurfaceExtractor< LargeVolume<MaterialDensityPair44> > surfaceExtractor(&volData, reg, &mesh);
	//CubicSurfaceExtractorWithNormals<MaterialDensityPair44> surfaceExtractor(&volData, reg, &mesh);
	surfaceExtractor.execute();
	std::cout << "#vertices: " << mesh.getNoOfVertices() << std::endl;

	//Pass the surface to the OpenGL window
	openGLWidget.setSurfaceMeshToRender(mesh);

	//Run the message pump.
	return app.exec();
} 
