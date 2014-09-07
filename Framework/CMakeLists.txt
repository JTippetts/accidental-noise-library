# Define target name
file (GLOB CPP_FILES *.cpp)
file (GLOB C_FILES *.c)
file (GLOB H_FILES *.h)
set (SOURCE_FILES ${CPP_FILES} ${C_FILES} ${H_FILES})
set (TARGET_NAME Framework)

set(INCLUDE_DIRS_ONLY ./ ../templates ../VM ../Imaging)

#Add third-party subdirs

set(LIBS VM Imaging)
setup_executable()