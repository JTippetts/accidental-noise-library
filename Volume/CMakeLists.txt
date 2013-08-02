# Define target name
set (TARGET_NAME Volume)

# Define source files
file (GLOB CPP_FILES *.cpp)
file (GLOB H_FILES *.h)
set (SOURCE_FILES ${CPP_FILES} ${H_FILES})
set (INCLUDE_DIRS_ONLY ../Noise ../RGBA ../Imaging ../ThirdParty/polyvox/library/PolyVoxCore/include ../ThirdParty/polyvox/library/PolyVoxUtil/include)

# Setup target
setup_static_library ()