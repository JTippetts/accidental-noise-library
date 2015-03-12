-- Accidental Noise Library
-- premake4.lua

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
	
	--[[project "toluapp"
		kind "StaticLib"
		location "../build/toluapp"
		targetdir "../build/toluapp"
		language "C"
		includedirs "ThirdParty/toluapp/include"
		includedirs(_OPTIONS["luaheader"] or luaheader)
		libdirs(_OPTIONS["lualib"] or lualib)
		files {"ThirdParty/toluapp/src/lib/*.h", "ThirdParty/toluapp/src/lib/*.c"} ]]
		
	project "lua"
		kind "StaticLib"
		location "../build/lua"
		targetdir "../build/lua"
		language "C"
		includedirs "ThirdParty/lua-5.2.4/src"
		files {"ThirdParty/lua-5.2.4/src/*.c"}
		excludes { "ThirdParty/lua-5.2.4/src/lua.c", "ThirdParty/lua-5.2.4/src/luac.c"}
		
		
	project "tolua"
		kind "StaticLib"
		location "../build/tolua"
		targetdir "../build/tolua"
		language "C"
		includedirs "ThirdParty/tolua-5.2/include"
		includedirs("ThirdParty/lua-5.2.4/src")
		files {"ThirdParty/tolua-5.2/src/lib/*.h", "ThirdParty/tolua-5.2/src/lib/*.c"}
	
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
		
		includedirs "ThirdParty/tolua-5.2/include"
		includedirs "ThirdParty/lua-5.2.4/src"
		
		files {"Framework/*.cpp", "Bindings/bind_anl.cpp"}
		links {"ANLLib", "tolua", "lua"}

		
		
		