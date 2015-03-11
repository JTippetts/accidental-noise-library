#!/bin/bash 
function failed()
{
    echo "Failed: $@" >&2
    echo build_logs/${1}_xcode_${2}.log
    exit 1
}

function failing_may_not_be_an_error()
{
	echo "Failed: $@. For details of the error and how to correct it, see the log file." >&1 
	echo build_logs/${1}_xcode_${2}.log
}
set -e

call_this_function_on_failure=failed

#1: test_name 2:config
function run_test()
{
	echo building $1 $2;
timeStartLocal=$(date +%s)
	xcodebuild  -project ${1}.xcodeproj -configuration $2 > ${root_dir}build_logs/${1}_xcode_${2}.log  || $call_this_function_on_failure $1 $2
timeEndLocal=$(date +%s)
timeDiffLocal=$(( $timeEndLocal - $timeStartLocal ))
	echo "$timeDiffLocal seconds"
}

cd ..
premake4 clean
premake4 xcode3 macosx

if [ ! -d build_logs ]; then
	mkdir build_logs
fi


cd unit_tests
root_dir="../"

timeStart=$(date +%s)

run_test test.unit Debug
run_test test.unit Release

run_test test.unit.using_exceptions Debug
run_test test.unit.using_exceptions Release

cd string_is_integral
root_dir="../../"
run_test string_is_integral Debug
run_test string_is_integral Release
cd ..

cd tests_may_fail
root_dir="../../"
call_this_function_on_failure=failing_may_not_be_an_error
run_test tests_may_fail Debug
run_test tests_may_fail Release
call_this_function_on_failure=failed
cd ../..

timeEnd=$(date +%s)
timeDiff=$(( $timeEnd - $timeStart ))
echo "Time to compile and run all tests was $timeDiff seconds"

premake4 clean
cd build_scripts
