#!/bin/bash 
cd ..
premake4 clean
premake4 gmake linux

if [ -d build_logs ]; then 
	rm -rf build_logs
fi

mkdir build_logs
	
if [ -d local_install ]; then 
	rm -rf local_install
fi

mkdir local_install
mkdir local_install/oolua

make config=debug oolua | tee ./build_logs/oolua_gnu_debug.log
make config=release oolua | tee ./build_logs/oolua_gnu_release.log

cp -r ./include/*.h ./local_install/oolua
cp ./bin/Debug/*.a ./local_install/
cp ./bin/Release/*.a ./local_install/

premake4 clean

cd build_scripts


