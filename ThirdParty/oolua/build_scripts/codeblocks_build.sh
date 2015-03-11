#!/bin/bash 
cd ..
premake4 clean
premake4 codeblocks linux

if [ -d build_logs ]; then 
	rm -rf build_logs
fi

mkdir build_logs
	
if [ -d local_install ]; then 
	rm -rf local_install
fi

mkdir local_install
mkdir local_install/oolua

codeblocks --build oolua.cbp --target="Debug" | tee ./build_logs/oolua_codeblocks_debug.log
codeblocks --build oolua.cbp --target="Release" | tee ./build_logs/oolua_codeblocks_release.log


cp -r ./include/*.h ./local_install/oolua
cp ./bin/Debug/*.a ./local_install/
cp ./bin/Release/*.a ./local_install/

premake4 clean

cd build_scripts
