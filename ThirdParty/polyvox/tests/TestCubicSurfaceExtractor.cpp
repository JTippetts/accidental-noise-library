/*******************************************************************************
Copyright (c) 2010 Matt Williams

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

#include "TestCubicSurfaceExtractor.h"

#include "PolyVoxCore/Density.h"
#include "PolyVoxCore/Material.h"
#include "PolyVoxCore/MaterialDensityPair.h"
#include "PolyVoxCore/SimpleVolume.h"
#include "PolyVoxCore/CubicSurfaceExtractorWithNormals.h"

#include <QtTest>

using namespace PolyVox;


// These 'writeDensityValueToVoxel' functions provide a unified interface for writting densities to primative and class voxel types.
// They are conceptually the inverse of the 'convertToDensity' function used by the MarchingCubesSurfaceExtractor. They probably shouldn't be part
// of PolyVox, but they might be useful to other tests so we cold move them into a 'Tests.h' or something in the future.
template<typename VoxelType>
void writeDensityValueToVoxel(int valueToWrite, VoxelType& voxel)
{
	voxel = valueToWrite;
}

template<>
void writeDensityValueToVoxel(int valueToWrite, Density8& voxel)
{
	voxel.setDensity(valueToWrite);
}

template<>
void writeDensityValueToVoxel(int valueToWrite, MaterialDensityPair88& voxel)
{
	voxel.setDensity(valueToWrite);
}

template<typename VoxelType>
void writeMaterialValueToVoxel(int valueToWrite, VoxelType& voxel)
{
	//Most types don't have a material
	return;
}

template<>
void writeMaterialValueToVoxel(int valueToWrite, MaterialDensityPair88& voxel)
{
	voxel.setMaterial(valueToWrite);
}

// Runs the surface extractor for a given type. 
template <typename VoxelType>
void testForType(SurfaceMesh<PositionMaterialNormal>& result)
{
	const int32_t uVolumeSideLength = 32;

	//Create empty volume
	SimpleVolume<VoxelType> volData(Region(Vector3DInt32(0,0,0), Vector3DInt32(uVolumeSideLength-1, uVolumeSideLength-1, uVolumeSideLength-1)));

	for (int32_t z = 0; z < uVolumeSideLength; z++)
	{
		for (int32_t y = 0; y < uVolumeSideLength; y++)
		{
			for (int32_t x = 0; x < uVolumeSideLength; x++)
			{
				if(x + y + z > uVolumeSideLength)
				{
					VoxelType voxelValue;
					writeDensityValueToVoxel<VoxelType>(100, voxelValue);
					writeMaterialValueToVoxel<VoxelType>(42, voxelValue);
					volData.setVoxelAt(x, y, z, voxelValue);
				}
			}
		}
	}

	CubicSurfaceExtractorWithNormals< SimpleVolume<VoxelType> > extractor(&volData, volData.getEnclosingRegion(), &result);
	extractor.execute();
}

void TestCubicSurfaceExtractor::testExecute()
{
	const static uint32_t uExpectedVertices = 6624;
	const static uint32_t uExpectedIndices = 9936;
	const static uint32_t uMaterialToCheck = 3000;
	const static float fExpectedMaterial = 42.0f;
	const static uint32_t uIndexToCheck = 2000;
	const static uint32_t uExpectedIndex = 1334;

	SurfaceMesh<PositionMaterialNormal> mesh;

	/*testForType<int8_t>(mesh);
	QCOMPARE(mesh.getNoOfVertices(), uExpectedVertices);
	QCOMPARE(mesh.getNoOfIndices(), uExpectedIndices);
	QCOMPARE(mesh.getVertices()[uMaterialToCheck].getMaterial(), fNoMaterial);

	testForType<uint8_t>(mesh);
	QCOMPARE(mesh.getNoOfVertices(), uExpectedVertices);
	QCOMPARE(mesh.getNoOfIndices(), uExpectedIndices);
	QCOMPARE(mesh.getVertices()[uMaterialToCheck].getMaterial(), fNoMaterial);

	testForType<int16_t>(mesh);
	QCOMPARE(mesh.getNoOfVertices(), uExpectedVertices);
	QCOMPARE(mesh.getNoOfIndices(), uExpectedIndices);
	QCOMPARE(mesh.getVertices()[uMaterialToCheck].getMaterial(), fNoMaterial);

	testForType<uint16_t>(mesh);
	QCOMPARE(mesh.getNoOfVertices(), uExpectedVertices);
	QCOMPARE(mesh.getNoOfIndices(), uExpectedIndices);
	QCOMPARE(mesh.getVertices()[uMaterialToCheck].getMaterial(), fNoMaterial);

	testForType<int32_t>(mesh);
	QCOMPARE(mesh.getNoOfVertices(), uExpectedVertices);
	QCOMPARE(mesh.getNoOfIndices(), uExpectedIndices);
	QCOMPARE(mesh.getVertices()[uMaterialToCheck].getMaterial(), fNoMaterial);

	testForType<uint32_t>(mesh);
	QCOMPARE(mesh.getNoOfVertices(), uExpectedVertices);
	QCOMPARE(mesh.getNoOfIndices(), uExpectedIndices);
	QCOMPARE(mesh.getVertices()[uMaterialToCheck].getMaterial(), fNoMaterial);

	testForType<float>(mesh);
	QCOMPARE(mesh.getNoOfVertices(), uExpectedVertices);
	QCOMPARE(mesh.getNoOfIndices(), uExpectedIndices);
	QCOMPARE(mesh.getVertices()[uMaterialToCheck].getMaterial(), fNoMaterial);

	testForType<double>(mesh);
	QCOMPARE(mesh.getNoOfVertices(), uExpectedVertices);
	QCOMPARE(mesh.getNoOfIndices(), uExpectedIndices);
	QCOMPARE(mesh.getVertices()[uMaterialToCheck].getMaterial(), fNoMaterial);*/

	/*testForType<Material8>(mesh);
	QCOMPARE(mesh.getNoOfVertices(), uExpectedVertices);
	QCOMPARE(mesh.getNoOfIndices(), uExpectedIndices);
	QCOMPARE(mesh.getVertices()[uMaterialToCheck].getMaterial(), fNoMaterial);*/

	QBENCHMARK {
		testForType<MaterialDensityPair88>(mesh);
	}
	QCOMPARE(mesh.getNoOfVertices(), uExpectedVertices);
	QCOMPARE(mesh.getNoOfIndices(), uExpectedIndices);
	QCOMPARE(mesh.getVertices()[uMaterialToCheck].getMaterial(), fExpectedMaterial);
	QCOMPARE(mesh.getIndices()[uIndexToCheck], uExpectedIndex);
}

QTEST_MAIN(TestCubicSurfaceExtractor)
