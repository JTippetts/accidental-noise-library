premake4.exe clean
cd ..
premake4.exe codeblocks windows

if not exist .\build_logs  md .\build_logs

CALL "C:\Program Files\CodeBlocks\codeblocks.exe" --build oolua.cbp --target="Debug" > .\build_logs\oolua_codeblocks_debug.log
CALL "C:\Program Files\CodeBlocks\codeblocks.exe" --build oolua.cbp --target="Release" > .\build_logs\oolua_codeblocks_release.log

CALL "C:\Program Files\CodeBlocks\codeblocks.exe" --build .\unit_tests\test.unit.cbp --target="Debug" > .\build_logs\unit_codeblocks_debug.log
CALL "C:\Program Files\CodeBlocks\codeblocks.exe" --build .\unit_tests\test.unit.cbp --target="Release" > .\build_logs\unit_codeblocks_release.log
CALL "C:\Program Files\CodeBlocks\codeblocks.exe" --build .\unit_tests\tests_may_fail\tests_may_fail.cbp --target="Debug" > .\build_logs\may_fail_codeblocks_debug.log
CALL "C:\Program Files\CodeBlocks\codeblocks.exe" --build .\unit_tests\tests_may_fail\tests_may_fail.cbp --target="Release" > .\build_logs\may_fail_codeblocks_release.log

CALL "C:\Program Files\CodeBlocks\codeblocks.exe" --build .\unit_tests\test.unit.using_exceptions.cbp --target="Debug" > .\build_logs\using_exceptions_codeblocks_debug.log
CALL "C:\Program Files\CodeBlocks\codeblocks.exe" --build .\unit_tests\test.unit.using_exceptions.cbp --target="Release" > .\build_logs\using_exceptions_codeblocks_release.log

CALL "C:\Program Files\CodeBlocks\codeblocks.exe" --build .\unit_tests\string_is_integral\string_is_integral.cbp --target="Debug" > .\build_logs\string_is_integral_codeblocks_debug.log
CALL "C:\Program Files\CodeBlocks\codeblocks.exe" --build .\unit_tests\string_is_integral\string_is_integral.cbp --target="Release" > .\build_logs\string_is_integral_codeblocks_release.log

premake4.exe clean
cd build_scripts
