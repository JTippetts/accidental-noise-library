::usage
::config pathFromTestDirectoryAndProjectName projectNameForLogFile visualStudioVersion (2008,2010)
@echo off
set passIfStringFound=", 0 failed,"

set projectExtension=vcproj
set visualStudioVersion=9

if (%4) == (2010) (
set projectExtension=vcxproj
set visualStudioVersion=10
)

set build_log="%cd%\build_logs\%3_vs%4_%1.log"
call "C:\Program Files\Microsoft Visual Studio %visualStudioVersion%.0\VC\vcvarsall.bat" x86
@echo building %2 %1
::devenv  "%cd%\oolua.sln" /build %1 /project "%cd%\unit_tests\%2.%projectExtension%" /out %build_log%
devenv  "%cd%\oolua.sln" /build %1 /project "%cd%\unit_tests\%2.%projectExtension%" > %build_log%

@find %passIfStringFound% %build_log% > NUL
if %ERRORLEVEL% EQU 0 (
	@echo Success 
	@exit /B 0
) else (
	@echo Test Failure see log file for details %build_log%
	@exit /B 1
)
