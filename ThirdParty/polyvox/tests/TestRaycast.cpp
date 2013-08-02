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

#include "TestRaycast.h"

#include "PolyVoxCore/Density.h"
#include "PolyVoxCore/Raycast.h"
#include "PolyVoxCore/SimpleVolume.h"

#include "PolyVoxCore/Impl/RandomUnitVectors.h"

#include <QtTest>

using namespace PolyVox;

// This is the callback functor which is called by the raycast() function for every voxel it touches.
// It's primary purpose is to tell the raycast whether or not to continue (i.e. it tests whether the
// ray has hit a solid voxel). Because the instance of this class is passed to the raycast() function
// by reference we can also use it to encapsulate some state. We're testing this by counting the total
// number of voxels touched.
class RaycastTestFunctor
{
public:
	RaycastTestFunctor()
		:m_uTotalVoxelsTouched(0)
	{
	}

	bool operator()(const SimpleVolume<int8_t>::Sampler& sampler)
	{
		m_uTotalVoxelsTouched++;

		return sampler.getVoxel() <= 0;
	}

	uint32_t m_uTotalVoxelsTouched;
};

void TestRaycast::testExecute()
{
	const int32_t uVolumeSideLength = 32;

	//Create a hollow volume, with solid sides on x and y but with open ends in z.
	SimpleVolume<int8_t> volData(Region(Vector3DInt32(0,0,0), Vector3DInt32(uVolumeSideLength-1, uVolumeSideLength-1, uVolumeSideLength-1)));
	for (int32_t z = 0; z < uVolumeSideLength; z++)
	{
		for (int32_t y = 0; y < uVolumeSideLength; y++)
		{
			for (int32_t x = 0; x < uVolumeSideLength; x++)
			{
				if((x == 0) || (x == uVolumeSideLength-1) || (y == 0) || (y == uVolumeSideLength-1))
				{
					volData.setVoxelAt(x, y, z, 100);
				}
				else
				{
					volData.setVoxelAt(x, y, z, -100);
				}				
			}
		}
	}

	//Cast rays from the centre. Roughly 2/3 should escape.
	Vector3DFloat start (uVolumeSideLength / 2, uVolumeSideLength / 2, uVolumeSideLength / 2);
	
	// For demonstration purposes we are using the same function object for all raycasts.
	// Therefore, the state it maintains (total voxels touched) is accumulated over all raycsts.
	RaycastTestFunctor raycastTestFunctor;

	// We could have counted the total number of hits in the same way as the total number of voxels
	// touched, but for demonstration and testing purposes we are making use of the raycast return value
	// and counting them seperatly in this variable.
	int hits = 0;

	// Cast a large number of random rays
	for(int ct = 0; ct < 1000000; ct++)
	{
		RaycastResult result = raycastWithDirection(&volData, start, randomUnitVectors[ct % 1024] * 1000.0f, raycastTestFunctor);

		if(result == RaycastResults::Interupted)
		{
			hits++;
		}
	}	

	// Check the number of hits.
	QCOMPARE(hits, 687494);

	// Check the total number of voxels touched
	QCOMPARE(raycastTestFunctor.m_uTotalVoxelsTouched, static_cast<uint32_t>(486219343));
}

QTEST_MAIN(TestRaycast)
