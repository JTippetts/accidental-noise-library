#!/bin/bash 


if [ ! -d ../build_logs ]; then
	mkdir ../build_logs
fi

cppcheck --verbose --enable=all -I ../include/ ../src/  2> ../build_logs/oolua_cppcheck.txt
#following tests everything including unit test code. Note this will generate false errors and false style errors
#cppcheck --verbose --enable=all -I ../include/ ../src/ ../unit_tests/  2> ../build_logs/oolua_cppcheck.txt
