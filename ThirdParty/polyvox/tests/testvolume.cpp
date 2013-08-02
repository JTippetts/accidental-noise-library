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

#include "testvolume.h"

#include "PolyVoxCore/LargeVolume.h"

#include <QtTest>

using namespace PolyVox;

void TestVolume::testSize()
{
	const int32_t g_uVolumeSideLength = 128;
	LargeVolume<uint8_t> volData(Region(Vector3DInt32(0,0,0), Vector3DInt32(g_uVolumeSideLength-1, g_uVolumeSideLength-1, g_uVolumeSideLength-1)));

	for (int32_t z = 0; z < g_uVolumeSideLength; z++)
	{
		for (int32_t y = 0; y < g_uVolumeSideLength; y++)
		{
			for (int32_t x = 0; x < g_uVolumeSideLength; x++)
			{
				volData.setVoxelAt(x,y,z,255);
			}
		}
	}
	
	QCOMPARE(volData.getWidth(), g_uVolumeSideLength);
	QCOMPARE(volData.getHeight(), g_uVolumeSideLength);
	QCOMPARE(volData.getDepth(), g_uVolumeSideLength);
}

QTEST_MAIN(TestVolume)
