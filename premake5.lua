-- Accidental Noise Library
-- premake5.lua

solution "ANL"
	configurations {"Debug", "Release"}
	platforms {"x32", "x64"}
	location "../build"
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
	
	filter {}
	
	if _ACTION=="gmake" then
		buildoptions "-std=c++11"
		filter "platforms:x32"
			buildoptions "-m32"
		filter "platforms:x64"
			buildoptions "-m64"
		filter {}
	end
	
	project "ANLLib"
		kind "StaticLib"
		location "../build/ANL"
		language "C++"
		
		files {"VM/*.h", "VM/*.cpp", "Imaging/*.h", "Imaging/*.cpp", "templates/*.h", "vectortypes.h"}

	project "Framework"
		kind "ConsoleApp"
		location "../build/Bin"
		language "C++"
		
		files {"Framework/*.cpp"}
		links {"ANLLib"}