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

#include "PolyVoxCore/Density.h"
#include "PolyVoxCore/MarchingCubesSurfaceExtractor.h"
#include "PolyVoxCore/SurfaceMesh.h"
#include "PolyVoxCore/RawVolume.h"
#include "PolyVoxCore/SimpleVolume.h"
#include "PolyVoxCore/VolumeResampler.h"

#include <QApplication>

//Use the PolyVox namespace
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

				if(fDistToCenter <= fRadius)
				{
					//Our new density value
					//uint8_t uDensity = Density8::getmaxDensity()();
					uint8_t uDensity = std::numeric_limits<uint8_t>::max();

					//Get the old voxel
					//uint8_t voxel = volData.getVoxelAt(x,y,z);

					//Modify the density
					//voxel.setDensity(uDensity);

					//Wrte the voxel value into the volume	
					volData.setVoxelAt(x, y, z, uDensity);
				}

				//144 in the middle, (144 - 32) at the edges. Threshold of 128 is between these
				//volData.setVoxelAt(x, y, z, 144 - fDistToCenter);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	//Create and show the Qt OpenGL window
	QApplication app(argc, argv);
	OpenGLWidget openGLWidget(0);
	openGLWidget.show();

	//Create an empty volume and then place a sphere in it
	SimpleVolume<uint8_t> volData(PolyVox::Region(Vector3DInt32(0,0,0), Vector3DInt32(63, 63, 63)));
	createSphereInVolume(volData, 28);

	//Smooth the data - should reimplement this using LowPassFilter
	//smoothRegion<SimpleVolume, Density8>(volData, volData.getEnclosingRegion());
	//smoothRegion<SimpleVolume, Density8>(volData, volData.getEnclosingRegion());
	//smoothRegion<SimpleVolume, Density8>(volData, volData.getEnclosingRegion());

	RawVolume<uint8_t> volDataLowLOD(PolyVox::Region(Vector3DInt32(0,0,0), Vector3DInt32(15, 31, 31)));

	VolumeResampler< SimpleVolume<uint8_t>, RawVolume<uint8_t> > volumeResampler(&volData, PolyVox::Region(Vector3DInt32(0,0,0), Vector3DInt32(31, 63, 63)), &volDataLowLOD, volDataLowLOD.getEnclosingRegion());
	volumeResampler.execute();

	//Extract the surface
	SurfaceMesh<PositionMaterialNormal> meshLowLOD;
	MarchingCubesSurfaceExtractor< RawVolume<uint8_t> > surfaceExtractor(&volDataLowLOD, volDataLowLOD.getEnclosingRegion(), &meshLowLOD);
	surfaceExtractor.execute();
	meshLowLOD.scaleVertices(/*2.0f*/63.0f / 31.0f);

	//Extract the surface
	SurfaceMesh<PositionMaterialNormal> meshHighLOD;
	MarchingCubesSurfaceExtractor< SimpleVolume<uint8_t> > surfaceExtractorHigh(&volData, PolyVox::Region(Vector3DInt32(30,0,0), Vector3DInt32(63, 63, 63)), &meshHighLOD);
	surfaceExtractorHigh.execute();
	meshHighLOD.translateVertices(Vector3DFloat(30, 0, 0));

	//Pass the surface to the OpenGL window
	openGLWidget.setSurfaceMeshToRender(meshHighLOD);
	openGLWidget.setSurfaceMeshToRenderLowLOD(meshLowLOD);

	//Run the message pump.
	return app.exec();
}
