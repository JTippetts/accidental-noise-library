# Copyright (c) 2009-2012 Matt Williams
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

#INCLUDE(InstallRequiredSystemLibraries)

SET(CPACK_PACKAGE_NAME "PolyVox SDK")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "PolyVox SDK")
SET(CPACK_PACKAGE_VENDOR "Thermite 3D Team")
#SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ReadMe.txt")
#SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/Copyright.txt")
SET(CPACK_PACKAGE_VERSION_MAJOR ${POLYVOX_VERSION_MAJOR})
SET(CPACK_PACKAGE_VERSION_MINOR ${POLYVOX_VERSION_MINOR})
SET(CPACK_PACKAGE_VERSION_PATCH ${POLYVOX_VERSION_PATCH})
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "PolyVox SDK ${POLYVOX_VERSION}")
IF(WIN32 AND NOT UNIX)
  # There is a bug in NSIS that does not handle full unix paths properly.
  # Make sure there is at least one set of four backslashes.
  #SET(CPACK_PACKAGE_ICON "${CMake_SOURCE_DIR}/Utilities/Release\\\\InstallIcon.bmp")
  #SET(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\MyExecutable.exe")
  SET(CPACK_NSIS_DISPLAY_NAME "PolyVox SDK ${POLYVOX_VERSION}")
  SET(CPACK_NSIS_HELP_LINK "http:\\\\\\\\thermite3d.org/phpBB/")
  SET(CPACK_NSIS_URL_INFO_ABOUT "http:\\\\\\\\thermite3d.org")
  SET(CPACK_NSIS_CONTACT "matt@milliams.com")
  SET(CPACK_NSIS_MODIFY_PATH ON)
ELSE(WIN32 AND NOT UNIX)
  #SET(CPACK_STRIP_FILES "bin/MyExecutable")
  #SET(CPACK_SOURCE_STRIP_FILES "")
ENDIF(WIN32 AND NOT UNIX)
#SET(CPACK_PACKAGE_EXECUTABLES "MyExecutable" "My Executable")

INCLUDE(CPack)

CPACK_ADD_COMPONENT(library DISPLAY_NAME "Library" DESCRIPTION "The runtime libraries" REQUIRED)
CPACK_ADD_COMPONENT(development DISPLAY_NAME "Development" DESCRIPTION "Files required for developing with PolyVox" DEPENDS library)
CPACK_ADD_COMPONENT(example DISPLAY_NAME "OpenGL Example" DESCRIPTION "A PolyVox example application using OpenGL" DEPENDS library)
cpack_add_component_group(bindings DISPLAY_NAME "Bindings" DESCRIPTION "Language bindings")
CPACK_ADD_COMPONENT(python DISPLAY_NAME "Python Bindings" DESCRIPTION "PolyVox bindings for the Python language" DISABLED GROUP bindings DEPENDS library)
