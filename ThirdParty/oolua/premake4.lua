--oolua premake4 file

dofile("helper4.lua")

if _ACTION == "clean" then
  os.rmdir("obj")
  os.rmdir("bin")
  os.rmdir("ipch")
end

solution("oolua")
   configurations { "Debug", "Release" }


dofile("./oolua4.lua")
dofile("./unit_tests/test.unit.lua")
include("./unit_tests/tests_may_fail/")
include("./file_generator/")
include("./profile/")
include("./unit_tests/string_is_integral/")
dofile("./unit_tests/test.unit.exceptions.lua")
dofile("./unit_tests/test.coverage.lua")

