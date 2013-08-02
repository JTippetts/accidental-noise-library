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

#include "testvector.h"

#include "PolyVoxCore/Vector.h"

#include <QtTest>

using namespace PolyVox;

void TestVector::testLength()
{
	Vector3DInt8 vec(3, 4, 5);
	QCOMPARE(vec.lengthSquared(), double(3*3+4*4+5*5));
}

void TestVector::testDotProduct()
{
	Vector3DInt8 vecxy(3, 4, 0);
	Vector3DInt8 vecz(0, 0, 1);
	
	QCOMPARE(vecxy.dot(vecz), int8_t(0)); //QCOMPARE is very strict on the types matching
}

void TestVector::testEquality()
{
	Vector3DInt8 vecxy(3, 4, 0);
	Vector3DInt8 vecz(0, 0, 1);
	
	QCOMPARE(vecxy != vecz, true);
}

QTEST_MAIN(TestVector)
