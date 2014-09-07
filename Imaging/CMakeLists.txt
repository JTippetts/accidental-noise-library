# Define target name
set (TARGET_NAME Imaging)

# Define source files
file (GLOB CPP_FILES *.cpp)
file (GLOB H_FILES *.h)
file (GLOB C_FILES *.c)
set (SOURCE_FILES ${CPP_FILES} ${C_FILES} ${H_FILES})

set(INCLUDE_DIRS_ONLY ../ ../templates)

# Setup target
setup_static_library ()