# Copyright (c) 2010-2012 Matt Williams
# Copyright (c) 2010-2012 David Williams
# 
# This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
# 
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
# 
# 1. The origin of this software must not be misrepresented; you must not
# claim that you wrote the original software. If you use this software
# in a product, an acknowledgment in the product documentation would be
# appreciated but is not required.
# 
# 2. Altered source versions must be plainly marked as such, and must not be
# misrepresented as being the original software.
# 
# 3. This notice may not be removed or altered from any source
# distribution.

# Creates a test from the inputs
#
# Also sets LATEST_TEST to point to the output executable of the test for easy
# ADD_TEST()ing
MACRO(CREATE_TEST headerfile sourcefile executablename)
	UNSET(test_moc_SRCS) #clear out the MOCs from previous tests
	QT4_WRAP_CPP(test_moc_SRCS ${headerfile})
	LINK_DIRECTORIES(${PolyVoxCore_BINARY_DIR} ${PolyVoxUtil_BINARY_DIR})
	ADD_EXECUTABLE(${executablename} ${sourcefile} ${test_moc_SRCS})
	TARGET_LINK_LIBRARIES(${executablename} PolyVoxCore PolyVoxUtil ${QT_QTTEST_LIBRARY} ${QT_QTCORE_LIBRARY})
	#HACK. This is needed since everything is built in the base dir in Windows. As of 2.8 we should change this.
	IF(WIN32)
		SET(LATEST_TEST ${EXECUTABLE_OUTPUT_PATH}/${executablename})
	ELSE(WIN32)
		SET(LATEST_TEST ${CMAKE_CURRENT_BINARY_DIR}/${executablename})
	ENDIF(WIN32)
	SET_PROPERTY(TARGET ${executablename} PROPERTY FOLDER "Tests")
ENDMACRO(CREATE_TEST)

INCLUDE_DIRECTORIES(${PolyVox_SOURCE_DIR}/PolyVoxCore/include ${CMAKE_CURRENT_BINARY_DIR})
REMOVE_DEFINITIONS(-DQT_GUI_LIB) #Make sure the tests don't link to the QtGui

# Test Template. Copy and paste this template for consistant naming.
# # ClassName tests
# CREATE_TEST(TestClassName.h TestClassName.cpp TestClassName)
# ADD_TEST(ClassNameFeature1Test ${LATEST_TEST} testFeature1)
# ADD_TEST(ClassNameFeature2Test ${LATEST_TEST} testFeature2)

# Python tests
IF(BUILD_BINDINGS)
	ADD_TEST(PythonSurfaceExtractorTest python ${CMAKE_CURRENT_SOURCE_DIR}/TestSurfaceExtractor.py)
ENDIF()

# AmbientOcclusionGenerator tests
CREATE_TEST(TestAmbientOcclusionGenerator.h TestAmbientOcclusionGenerator.cpp TestAmbientOcclusionGenerator)
ADD_TEST(AmbientOcclusionGeneratorExecuteTest ${LATEST_TEST} testExecute)

# Array tests
CREATE_TEST(TestArray.h TestArray.cpp TestArray)
ADD_TEST(ArrayReadWriteTest ${LATEST_TEST} testReadWrite)

# AStarPathfinder tests
CREATE_TEST(TestAStarPathfinder.h TestAStarPathfinder.cpp TestAStarPathfinder)
ADD_TEST(AStarPathfinderExecuteTest ${LATEST_TEST} testExecute)

CREATE_TEST(TestCubicSurfaceExtractor.h TestCubicSurfaceExtractor.cpp TestCubicSurfaceExtractor)
ADD_TEST(CubicSurfaceExtractorExecuteTest ${LATEST_TEST} testExecute)

# Low pass filter tests
CREATE_TEST(TestLowPassFilter.h TestLowPassFilter.cpp TestLowPassFilter)
ADD_TEST(LowPassFilterExecuteTest ${LATEST_TEST} testExecute)

# LargeVolume tests
CREATE_TEST(testvolume.h testvolume.cpp testvolume)
ADD_TEST(VolumeSizeTest ${LATEST_TEST} testSize)

# Material tests
CREATE_TEST(testmaterial.h testmaterial.cpp testmaterial)
ADD_TEST(MaterialTestCompile ${LATEST_TEST} testCompile)

# Raycast tests
CREATE_TEST(TestRaycast.h TestRaycast.cpp TestRaycast)
ADD_TEST(RaycastExecuteTest ${LATEST_TEST} testExecute)

# Region tests
CREATE_TEST(TestRegion.h TestRegion.cpp TestRegion)
ADD_TEST(RegionEqualityTest ${LATEST_TEST} testEquality)

CREATE_TEST(TestSurfaceExtractor.h TestSurfaceExtractor.cpp TestSurfaceExtractor)
ADD_TEST(SurfaceExtractorExecuteTest ${LATEST_TEST} testExecute)

#Vector tests
CREATE_TEST(testvector.h testvector.cpp testvector)
ADD_TEST(VectorLengthTest ${LATEST_TEST} testLength)
ADD_TEST(VectorDotProductTest ${LATEST_TEST} testDotProduct)
ADD_TEST(VectorEqualityTest ${LATEST_TEST} testEquality)

# Volume subclass tests
CREATE_TEST(TestVolumeSubclass.h TestVolumeSubclass.cpp TestVolumeSubclass)
ADD_TEST(VolumeSubclassExtractSurfaceTest ${LATEST_TEST} testExtractSurface)
