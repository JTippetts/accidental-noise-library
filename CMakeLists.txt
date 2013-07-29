include (CheckIncludeFiles)

# Disable unnecessary build types
set (CMAKE_CONFIGURATION_TYPES "RelWithDebInfo;Debug;Release" CACHE STRING "Configurations" FORCE)

# Set project name
project (ANL)

# Set minimum version
cmake_minimum_required (VERSION 2.6)

if (COMMAND cmake_policy)
    cmake_policy (SET CMP0003 NEW)
endif ()

# Enable 64-bit build. Disabled by default. On Visual Studio, depends on the generator used
if (NOT MSVC)
    # set (ENABLE_64BIT 1)
else ()
    if (CMAKE_GENERATOR MATCHES "Win64")
        set (ENABLE_64BIT 1)
    endif ()
endif ()

if (MSVC)
    # Visual Studio-specific setup
    if (ENABLE_64BIT)
        enable_language (ASM_MASM)
    endif ()
    add_definitions (-D_CRT_SECURE_NO_WARNINGS)
    set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MTd")
    set (CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELEASE} /MT /Zi /GS-")
    set (CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELWITHDEBINFO}")
    set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set (CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE} /MT /Zi /GS- /D _SECURE_SCL=0")
    set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
    
    set (CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /OPT:REF /OPT:ICF /DEBUG")
    set (CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /OPT:REF /OPT:ICF")
else ()
    # GCC-specific setup
    if (NOT IOS)
        set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 ")
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-offsetof -O2 -std=c++11")
        if (ENABLE_64BIT)
            set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
            set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
        else ()
            if (NOT ANDROID)
                set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
                set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
               
            endif ()
        endif ()
        if (WIN32)
            set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")
            set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
        endif ()
    endif ()
    set (CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
    set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
endif ()

# Macro for setting up dependency lib for compilation and linking of a target
macro (setup_target)
    # Include directories
    include_directories (${LIBS} ${INCLUDE_DIRS_ONLY})
    # Link libraries
    string (REGEX REPLACE "\\.\\./|ThirdParty/|ANL/|Framework/|/Include|/include|/src" "" STRIP_LIBS "${LIBS};${LINK_LIBS_ONLY}")
    target_link_libraries (${TARGET_NAME} ${STRIP_LIBS})
endmacro ()

# Macro for setting up a static library target
macro (setup_static_library)
    add_library (${TARGET_NAME} STATIC ${SOURCE_FILES})
    setup_target ()
endmacro ()

macro (setup_shared_library)
	add_library (${TARGET_NAME} SHARED ${SOURCE_FILES})
	setup_target ()
endmacro ()

# Macro for setting up an executable target
macro (setup_executable)
    add_executable (${TARGET_NAME} ${EXE_TYPE} ${SOURCE_FILES})
    setup_target ()
    if (MSVC)
        add_custom_command (TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different \"$(TARGETPATH)\" ${PROJECT_BINARY_DIR}/Bin)
        add_custom_command (TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different \"$(TARGETDIR)$(TARGETNAME).pdb\" ${PROJECT_BINARY_DIR}/Bin)
    elseif (IOS)
        set_target_properties (${TARGET_NAME} PROPERTIES XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY "1,2")
    else ()
        get_target_property (EXECUTABLE_NAME ${TARGET_NAME} LOCATION)
        add_custom_command (TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different ${EXECUTABLE_NAME} ${PROJECT_BINARY_DIR}/Bin)
    endif ()
endmacro ()

# Macro for setting up an executable target with resources to copy
macro (setup_main_executable)
    # Define resource files
    if (APPLE)
        set (RESOURCE_FILES ${PROJECT_BINARY_DIR}/Bin/CoreData ${PROJECT_BINARY_DIR}/Bin/Data)
        set_source_files_properties(${RESOURCE_FILES} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
        set (SOURCE_FILES ${SOURCE_FILES} ${RESOURCE_FILES})
    endif ()

    # Setup target
    if (WIN32)
        set (EXE_TYPE WIN32)
    elseif (IOS)
        set (CMAKE_EXE_LINKER_FLAGS "-framework AudioToolbox -framework CoreAudio -framework CoreGraphics -framework Foundation -framework OpenGLES -framework QuartzCore -framework UIKit")
        set (EXE_TYPE MACOSX_BUNDLE)
    elseif (APPLE)
        set (CMAKE_EXE_LINKER_FLAGS "-framework AudioUnit -framework Carbon -framework Cocoa -framework CoreAudio -framework ForceFeedback -framework IOKit -framework OpenGL -framework CoreServices")
    endif ()
    if (NOT ANDROID)
        setup_executable ()
    else ()
        add_library (${TARGET_NAME} SHARED ${SOURCE_FILES})
        setup_target ()
    endif ()

    # Define a custom target to check for resource modification
    if (IOS)
        get_target_property (TARGET_LOC ${TARGET_NAME} LOCATION)
        string (REGEX REPLACE "/Contents/MacOS" "" TARGET_LOC ${TARGET_LOC})    # The regex replacement is temporary workaround to correct the wrong location caused by CMake/Xcode generator bug
        add_custom_target (RESOURCE_CHECK_${TARGET_NAME} ALL
            \(\( `find ${RESOURCE_FILES} -newer ${TARGET_LOC} 2>/dev/null |wc -l` \)\) && touch -cm ${SOURCE_FILES} || exit 0
            COMMENT "This is a dummy target to check for changes in the Resource folders"
        )
        add_dependencies (${TARGET_NAME} RESOURCE_CHECK_${TARGET_NAME})
    endif ()
endmacro ()

file (MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Bin)

#Add third-party subdirs
add_subdirectory(ThirdParty/Lua)
add_subdirectory(ThirdParty/Tolua++/src/bin)
add_subdirectory(ThirdParty/Tolua++/src/lib)

add_subdirectory(Noise)
add_subdirectory(RGBA)
add_subdirectory(Imaging)
add_subdirectory(Builder)
add_subdirectory(Bindings)
add_subdirectory(Framework)
