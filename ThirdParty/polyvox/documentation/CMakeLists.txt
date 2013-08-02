# Copyright (c) 2010-2012 Matt Williams
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

find_program(SPHINXBUILD_EXECUTABLE sphinx-build DOC "The location of the sphinx-build executable")

#if(SPHINXBUILD_EXECUTABLE AND QT_QCOLLECTIONGENERATOR_EXECUTABLE)
if(SPHINXBUILD_EXECUTABLE)
	message(STATUS "Found `sphinx-build` at ${SPHINXBUILD_EXECUTABLE}")
	set(BUILD_MANUAL ON PARENT_SCOPE)
	
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/conf.in.py ${CMAKE_CURRENT_BINARY_DIR}/conf.py @ONLY)
	#Generates the HTML docs and the Qt help file which can be opened with "assistant -collectionFile thermite.qhc"
	#add_custom_target(manual ${SPHINXBUILD_EXECUTABLE} -b qthelp ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} COMMAND ${QT_QCOLLECTIONGENERATOR_EXECUTABLE} polyvox.qhcp -o polyvox.qhc)
	add_custom_target(manual 
		${SPHINXBUILD_EXECUTABLE} -b html
		-c ${CMAKE_CURRENT_BINARY_DIR} #Load the conf.py from the binary dir
		${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Building PolyVox manual"
	)
	add_dependencies(manual doc)
	set_target_properties(manual PROPERTIES PROJECT_LABEL "Manual") #Set label seen in IDE
	SET_PROPERTY(TARGET manual PROPERTY FOLDER "Documentation")
else()
	if(NOT SPHINXBUILD_EXECUTABLE)
		message(STATUS "`sphinx-build` was not found. Try setting SPHINXBUILD_EXECUTABLE to its location.")
	endif()
	if(NOT QT_QCOLLECTIONGENERATOR_EXECUTABLE)
		message(STATUS "`qhelpgenerator` was not found. Try setting QT_QCOLLECTIONGENERATOR_EXECUTABLE to its location.")
	endif()
	set(BUILD_MANUAL OFF PARENT_SCOPE)
endif()
