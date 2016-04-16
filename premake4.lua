-- Accidental Noise Library
-- premake4.lua

-- Path to Lua source
-- 

 local luapath="ThirdParty/lua-5.1.4/"

local usethread=true 

solution "ANL"
	configurations {"Debug", "Release"}
	platforms {"x32", "x64"}
	location "../build"
	
	if usethread then defines { "USETHREAD" } end
	
	configuration "Debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		defines { "NDEBUG" }
		flags "Optimize"
		
	configuration {}
	
	project "toluapp"
		kind "StaticLib"
		location "../build/toluapp"
		targetdir "../build/toluapp"
		language "C"
		includedirs "ThirdParty/toluapp/include"
		includedirs(luapath.."src")
		files {"ThirdParty/toluapp/src/lib/*.h", "ThirdParty/toluapp/src/lib/*.c"}
		
	project "lua"
		kind "StaticLib"
		location "../build/lua"
		targetdir "../build/lua"
		language "C"
		includedirs(luapath.."src")
		files({luapath.."src/*.c"})
		excludes({luapath.."src/lua.c", luapath.."src/luac.c"})
	
	project "ANLLib"
		kind "StaticLib"
		location "../build/ANL"
		targetdir "../build/ANL"
		language "C++"
		if _ACTION=="gmake" then
			buildoptions "-std=c++11"
		end
		
		files {"VM/*.h", "VM/*.cpp", "Imaging/*.h", "Imaging/*.cpp", "Expression/*.h", "Expression/*.cpp", "Processing/*.h", "Processing/*.cpp", "templates/*.h", "vectortypes.h"}
		
	--[[project "toluaexe"
		kind "ConsoleApp"
		location "../build/Bin"
		targetdir "../build/Bin"
		language "C"
		includedirs "ThirdParty/tolua-5.2/include"
		includedirs(luapath.."src")
		files {"ThirdParty/tolua-5.2/src/bin/*.h", "ThirdParty/tolua-5.2/src/bin/*.c"}
		links {"tolua", "lua"}]]

	project "Framework"
		kind "ConsoleApp"
		location "../build/Bin"
		targetdir "../build/Bin"
		language "C++"
		if _ACTION=="gmake" then
			buildoptions "-std=c++11"
		end
		
		--includedirs "ThirdParty/tolua-5.2/include"
		includedirs "ThirdParty/toluapp/include"
		includedirs(luapath.."src")
		
		files {"Framework/*.cpp", "Bindings/bind_anl.cpp"}
		links {"ANLLib", "toluapp", "lua"}

		
		
		