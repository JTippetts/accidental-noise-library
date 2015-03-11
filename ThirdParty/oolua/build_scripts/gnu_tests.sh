#!/bin/bash 
function failed()
{
    echo "Failed: $@" >&1
    echo build_logs/${1}_gnu_${2}.log
    exit 1
}

function failing_may_not_be_an_error()
{
	echo "Failed: $@. For details of the error and how to correct it, see the log file " >&1 
	echo build_logs/${1}_gnu_${2}.log
}

cd ..
premake4 clean
premake4 gmake linux

function_to_call_on_error=failed

if [ ! -d build_logs ]; then 
	mkdir build_logs
fi

#1: test_name 2:config
function run_test() 
{
timeStartLocal=$(date +%s)
	echo running $1 $2  
	make config=${2} ${1} >  ./build_logs/${1}_gnu_${2}.log || $function_to_call_on_error ${1} ${2}
timeEndLocal=$(date +%s)
timeDiffLocal=$(( $timeEndLocal - $timeStartLocal ))
	echo "$timeDiffLocal seconds"
}

timeStart=$(date +%s)

run_test test.unit debug
run_test test.unit release

run_test test.unit.using_exceptions debug
run_test test.unit.using_exceptions release

run_test string_is_integral debug
run_test string_is_integral release

function_to_call_on_error=failing_may_not_be_an_error
run_test tests_may_fail debug
run_test tests_may_fail release

timeEnd=$(date +%s)
timeDiff=$(( $timeEnd - $timeStart ))
echo "Time to compile and run all tests was $timeDiff seconds"

premake4 clean
cd build_scripts
