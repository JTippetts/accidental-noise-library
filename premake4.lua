-- Accidental Noise Library
-- premake5.lua

-- Pull in oolua helper
dofile("ThirdParty/oolua/helper4.lua")

-- Set pat to lua library and headers
-- Alternatively, specify on the command-line
local lualib="C:/Users/Joshua/Documents/Projects/lua-5.1.4/src"
local luaheader="C:/Users/Joshua/Documents/Projects/lua-5.1.4/src"

solution "ANL"
	configurations {"Debug", "Release"}
	--platforms {"x32", "x64"}
	location "../build"
	
	configuration "Debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		defines { "NDEBUG" }
		flags "Optimize"
		
	configuration {}
	
	project "oolua"
		language 'C++'
		kind "StaticLib"
		includepaths = { "ThirdParty/oolua/include" }
		objdir "../build/obj"
		
		configuration("Debug")
			defines { "DEBUG", "_DEBUG" }
			flags {"Symbols", "ExtraWarnings"}
			targetdir "../build/bin/Debug"
		
		configuration("Release")
			defines{ "NDEBUG", "RELEASE"}
			flags {"Optimize", "ExtraWarnings"}
			targetdir "../build/bin/Release"

		configuration { 'Debug','StaticLib or SharedLib' }
			targetsuffix '_d'

		configure_for_os()
		configuration {}
		
		if _ACTION=="gmake" then
			buildoptions "-std=c++11"
		end

		files { "ThirdParty/oolua/include/*.h", "ThirdParty/oolua/src/*.cpp" }
		includedirs 
		{
			"ThirdParty/oolua/include/lua/",
			"ThirdParty/oolua/include/",
		} 
		includedirs(_OPTIONS["luaheader"] or luaheader)
		libdirs(_OPTIONS["lualib"] or lualib)
	
	project "toluapp"
		kind "StaticLib"
		location "../build/toluapp"
		targetdir "../build/toluapp"
		language "C"
		includedirs "ThirdParty/toluapp/include"
		includedirs(_OPTIONS["luaheader"] or luaheader)
		libdirs(_OPTIONS["lualib"] or lualib)
		files {"ThirdParty/toluapp/src/lib/*.h", "ThirdParty/toluapp/src/lib/*.c"}
	
	project "ANLLib"
		kind "StaticLib"
		location "../build/ANL"
		targetdir "../build/ANL"
		language "C++"
		if _ACTION=="gmake" then
			buildoptions "-std=c++11"
		end
		
		files {"VM/*.h", "VM/*.cpp", "Imaging/*.h", "Imaging/*.cpp", "Imaging/*.c", "templates/*.h", "vectortypes.h"}

	project "Framework"
		kind "ConsoleApp"
		location "../build/Bin"
		targetdir "../build/Bin"
		language "C++"
		if _ACTION=="gmake" then
			buildoptions "-std=c++11"
		end
		
		includedirs(_OPTIONS["luaheader"] or luaheader)
		includedirs "ThirdParty/toluapp/include"
		libdirs(_OPTIONS["lualib"] or lualib)
		
		files {"Framework/*.cpp", "Bindings/*.cpp"}
		links {"ANLLib", "toluapp", "oolua"}
		
		if _OPTIONS["usedynamic"] then links "lua51.dll" else links "lua" end
		
		
		