# Define target name
set (TARGET_NAME ANL_RGBA)

# Define source files
file (GLOB CPP_FILES *.cpp)
file (GLOB H_FILES *.h)
set (SOURCE_FILES ${CPP_FILES} ${H_FILES})
set(INCLUDE_DIRS_ONLY ../ANL_Noise)

# Setup target
setup_static_library ()