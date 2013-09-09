# Define target name
set (TARGET_NAME anl)

# Define source files
file (GLOB CPP_FILES *.cpp)
file (GLOB H_FILES *.h)
set (SOURCE_FILES ${CPP_FILES} ${H_FILES})

set (LIBS ../Noise ../RGBA ../Imaging ../Bindings ../Builder ../ThirdParty/Lua)
set (LINK_LIBS_ONLY tolua++_static PolyVoxCore PolyVoxUtil Lua)
set (INCLUDE_DIRS_ONLY . ../Noise ../RGBA ../Imaging ../Bindings ../Builder ../ThirdParty/tolua++/include ../ThirdParty/Lua/src)

# Setup target with resource copying
setup_shared_library ()
