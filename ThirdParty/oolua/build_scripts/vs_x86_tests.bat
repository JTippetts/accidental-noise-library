@echo OFF
cd ..

if not exist .\build_logs  md .\build_logs

CALL premake4 clean
CALL premake4 vs%1 windows


call .\build_scripts\vs_run_test.bat debug test.unit test_unit %1
call .\build_scripts\vs_run_test.bat release test.unit test_unit %1

call .\build_scripts\vs_run_test.bat debug test.unit.using_exceptions test_unit_exceptions %1
call .\build_scripts\vs_run_test.bat release test.unit.using_exceptions test_unit_exceptions %1

call .\build_scripts\vs_run_test.bat debug tests_may_fail\tests_may_fail tests_may_fail %1
call .\build_scripts\vs_run_test.bat release tests_may_fail\tests_may_fail tests_may_fail %1

call .\build_scripts\vs_run_test.bat debug  string_is_integral\string_is_integral string_is_integral %1
call .\build_scripts\vs_run_test.bat release  string_is_integral\string_is_integral string_is_integral %1

call premake4 clean
cd build_scripts


