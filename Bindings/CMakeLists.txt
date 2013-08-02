# Define target name
set (TARGET_NAME Bindings)

# Define source files
file (GLOB CPP_FILES *.cpp)
file (GLOB H_FILES *.h)
set (SOURCE_FILES ${CPP_FILES} ${H_FILES})

# Define generated source files
file (MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated)
file (GLOB_RECURSE PKG_FILES ${CMAKE_CURRENT_SOURCE_DIR}/pkgs/*.pkg)
add_custom_command (OUTPUT generated/Noise.cpp generated/RGBA.cpp generated/Imaging.cpp generated/Builder.cpp generated/Volume.cpp
    COMMAND ${PROJECT_BINARY_DIR}/ThirdParty/Tolua++/src/bin/tolua++ -o ${CMAKE_CURRENT_BINARY_DIR}/generated/Noise.cpp Noise/Noise.pkg DEPENDS ${PKG_FILES}
    COMMAND ${PROJECT_BINARY_DIR}/ThirdParty/Tolua++/src/bin/tolua++ -o ${CMAKE_CURRENT_BINARY_DIR}/generated/RGBA.cpp RGBA/RGBA.pkg
    COMMAND ${PROJECT_BINARY_DIR}/ThirdParty/Tolua++/src/bin/tolua++ -o ${CMAKE_CURRENT_BINARY_DIR}/generated/Imaging.cpp Imaging/Imaging.pkg
	COMMAND ${PROJECT_BINARY_DIR}/ThirdParty/Tolua++/src/bin/tolua++ -o ${CMAKE_CURRENT_BINARY_DIR}/generated/Builder.cpp Builder/Builder.pkg
	COMMAND ${PROJECT_BINARY_DIR}/ThirdParty/Tolua++/src/bin/tolua++ -o ${CMAKE_CURRENT_BINARY_DIR}/generated/Volume.cpp Volume/Volume.pkg
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/pkgs
    COMMENT "Generate Lua API binding on the fly")
set (SOURCE_FILES ${SOURCE_FILES} generated/Noise.cpp generated/RGBA.cpp generated/Imaging.cpp generated/Builder.cpp generated/Volume.cpp)

# Define dependency libs
set (LIBS ../Noise ../RGBA ../Imaging ../Builder ../Volume)
set (LINK_LIBS_ONLY tolua++_static)
set (INCLUDE_DIRS_ONLY . ../Noise ../RGBA ../Imaging ../Builder ../Volume ../ThirdParty/tolua++/include ../ThirdParty/Lua/src)

# Setup target

setup_static_library ()

# For IOS and Android build to be successful, the "tolua++" tool must be present in the "Bin" folder.
# One way to achieve this is to first do a desktop build where all the tools would be generated, then switch to IOS/Android build.
if (NOT IOS AND NOT ANDROID AND NOT RASPI)
    # Add dependency to the "tolua++" bin tool
    add_dependencies(${TARGET_NAME} tolua++)
endif ()
