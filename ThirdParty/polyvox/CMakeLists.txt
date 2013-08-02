# Copyright (c) 2007-2012 Matt Williams
# Copyright (c) 2007-2012 David Williams
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

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)

PROJECT(PolyVox)

SET(POLYVOX_VERSION_MAJOR "0")
SET(POLYVOX_VERSION_MINOR "2")
SET(POLYVOX_VERSION_PATCH "1")
SET(POLYVOX_VERSION "${POLYVOX_VERSION_MAJOR}.${POLYVOX_VERSION_MINOR}.${POLYVOX_VERSION_PATCH}" CACHE STRING "PolyVox version")
MARK_AS_ADVANCED(FORCE POLYVOX_VERSION)

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
include(FeatureSummary)

FIND_PACKAGE(Doxygen)
OPTION(ENABLE_EXAMPLES "Should the examples be built" ON)

SET(LIBRARY_TYPE "DYNAMIC" CACHE STRING "Should the library be STATIC or DYNAMIC")
SET_PROPERTY(CACHE LIBRARY_TYPE PROPERTY STRINGS DYNAMIC STATIC)
IF(WIN32)
	SET(LIBRARY_TYPE "STATIC")
ENDIF()

# Qt is required for building the tests, the example and optionally for bundling the documentation
FIND_PACKAGE(Qt4 COMPONENTS QtCore QtGui QtOpenGL QtTest)
INCLUDE(${QT_USE_FILE})
if(CMAKE_VERSION VERSION_LESS "2.8.6")
	set_package_info(Doxygen "API documentation generator" http://www.doxygen.org "Building the API documentation")
	set_package_info(Qt4 "C++ framework" http://qt-project.org "Building the examples and tests")
else()
	set_package_properties(Doxygen PROPERTIES URL http://www.doxygen.org DESCRIPTION "API documentation generator" TYPE OPTIONAL PURPOSE "Building the API documentation")
	set_package_properties(Qt4 PROPERTIES DESCRIPTION "C++ framework" URL http://qt-project.org)
	set_package_properties(Qt4 PROPERTIES TYPE RECOMMENDED PURPOSE "Building the examples")
	set_package_properties(Qt4 PROPERTIES TYPE OPTIONAL PURPOSE "Building the tests")
endif()

if(MSVC AND (MSVC_VERSION LESS 1600))
	# Require boost for older (pre-vc2010) Visual Studio compilers
	# See library/include/polyvoxcore/impl/TypeDef.h
	find_package(Boost REQUIRED)
	include_directories(${Boost_INCLUDE_DIRS})
endif()

IF(CMAKE_COMPILER_IS_GNUCXX) #Maybe "OR MINGW"
	ADD_DEFINITIONS(-std=c++0x) #Enable C++0x mode
ENDIF()
if(CMAKE_CXX_COMPILER MATCHES "clang")
	ADD_DEFINITIONS(-std=c++0x) #Enable C++0x mode
endif()

ADD_SUBDIRECTORY(library)

OPTION(ENABLE_EXAMPLES "Should the examples be built" ON)
IF(ENABLE_EXAMPLES AND QT_QTOPENGL_FOUND)
	ADD_SUBDIRECTORY(examples/Basic)
	ADD_SUBDIRECTORY(examples/Paging)
	ADD_SUBDIRECTORY(examples/OpenGL)
	ADD_SUBDIRECTORY(examples/SmoothLOD)
	SET(BUILD_EXAMPLES ON)
ELSE()
	SET(BUILD_EXAMPLES OFF)
ENDIF()

INCLUDE(Packaging.cmake)

OPTION(ENABLE_TESTS "Should the tests be built" ON)
IF(ENABLE_TESTS AND QT_QTTEST_FOUND)
	INCLUDE(CTest)
	MARK_AS_ADVANCED(FORCE DART_TESTING_TIMEOUT) #This is only needed to hide the variable in the GUI (CMake bug) until 2.8.5
	MARK_AS_ADVANCED(FORCE BUILD_TESTING)
	ADD_SUBDIRECTORY(tests)
	SET(BUILD_TESTS ON)
ELSE()
	SET(BUILD_TESTS OFF)
ENDIF()

#Check if we will building _and_ bundling the docs
IF(DOXYGEN_FOUND AND QT_QCOLLECTIONGENERATOR_EXECUTABLE)
	SET(BUILD_AND_BUNDLE_DOCS ON)
ELSE()
	SET(BUILD_AND_BUNDLE_DOCS OFF)
ENDIF()

ADD_SUBDIRECTORY(documentation)

add_feature_info("Examples" BUILD_EXAMPLES "Examples of PolyVox usage")
add_feature_info("Tests" BUILD_TESTS "Unit tests")
add_feature_info("Bindings" BUILD_BINDINGS "SWIG bindings")
add_feature_info("API docs" DOXYGEN_FOUND "HTML documentation of the API")
add_feature_info("Qt Help" BUILD_AND_BUNDLE_DOCS "API docs in Qt Help format")
add_feature_info("Manual" BUILD_MANUAL "HTML user's manual")

feature_summary(WHAT ALL)

# Option summary
MESSAGE(STATUS "")
MESSAGE(STATUS "Summary")
MESSAGE(STATUS "-------")
MESSAGE(STATUS "Library type:        " ${LIBRARY_TYPE})
MESSAGE(STATUS "Build examples:      " ${BUILD_EXAMPLES})
MESSAGE(STATUS "Build tests:         " ${BUILD_TESTS})
MESSAGE(STATUS "Build bindings:      " ${BUILD_BINDINGS})
MESSAGE(STATUS "API Docs available:  " ${DOXYGEN_FOUND})
MESSAGE(STATUS " - Qt Help bundling: " ${BUILD_AND_BUNDLE_DOCS})
MESSAGE(STATUS "Build manual:        " ${BUILD_MANUAL})
MESSAGE(STATUS "")
