#!/bin/bash

if [ $EUID != 0 ]; then
    echo  "WARNING:
  	This file is not for general purpose usage and is required to have elevated privileges.
	It will create symlinks for header directories and library names so that it can run
	tests for multiple versions of Lua without modification to the generation files, tests
	and the OOLua library. If you do run this file with the privileges it requires it may 
	well remove the Lua library and headers from your system."
	exit 2
fi

#1: header directory 2: library name
function setup_headers_and_library()
{
	sudo rm /usr/local/include/lua
	sudo ln -s /usr/local/include/${1} /usr/local/include/lua
	sudo rm /usr/local/lib/liblua.a
	sudo ln -s /usr/local/lib/${2} /usr/local/lib/liblua.a
}

time_start=$(date +%s)

setup_headers_and_library lua51 liblua-5.1.4.a
echo "Running Lua 5.1.4 tests"
./xcode_tests.sh

setup_headers_and_library lua52 liblua-5.2.1.a
echo "Running Lua 5.2.1 tests"
./xcode_tests.sh

setup_headers_and_library luajit-2.0 libluajit-5.1.2.0.0.a
#OSX x86_64 executables which use LuaJIT require rebasing so that the JIT allocator can use the lowest 2GB
export LUAJIT_REBASE=1
echo "Running LuaJIT 2.0.0 tests"
./xcode_tests.sh
unset LUAJIT_REBASE

<<ThisRequiresCppUnitAndGoogleMockToBeBuiltForx86
setup_headers_and_library lua51 libluajit-5.1.1.1.8.a
echo "Running LuaJIT 1.1.8 tests"
export LUAJIT_32BIT=1
./xcode_tests.sh
unset LUAJIT_32BIT
ThisRequiresCppUnitAndGoogleMockToBeBuiltForx86

time_end=$(date +%s)
time_diff=$(( $time_end - $time_start ))
minutes=$(( $time_diff / 60 ))
seconds=$(printf %02d $(( $time_diff % 60 )))
echo "Finished tests for multiple versions of Lua in $minutes:$seconds"

#now reset Lua 5.2 as the default for this machine
setup_headers_and_library lua52 liblua-5.2.1.a
