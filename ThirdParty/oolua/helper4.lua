
--sets options for the different os's
function configure_for_os()
				
	configuration { "windows" }
		defines{ "PLATFORM_CHECKED", "WINDOWS_BUILD" }
					
	configuration { "vs*" }
		defines{ "WIN32" }
		flags { "No64BitChecks"}
	
	configuration{"vs*","Debug"}
		buildoptions {"/Gm","/Zi"}

--[[		
	configuration { "vs2008" }
		buildoptions {"/analyze"}

		configuration { "vs2010" }
		buildoptions {"/analyze"}

--]]

	configuration { "windows","codeblocks" }
		buildoptions{ "-W -Wall -pedantic"}

	configuration { "macosx" }
		defines{ "PLATFORM_CHECKED" , "MAC_BUILD" }

	configuration { "linux" }
		defines{ "PLATFORM_CHECKED" , "UNIX_BUILD" }	
		
	configuration { "codeblocks", "linux or macosx" }
		buildoptions { "-W -Wall -ansi -pedantic -std=c++98" }
		
	configuration("xcode3 or xcode4 or gmake")
		buildoptions { "-W -Wall -ansi -pedantic -std=c++98" }
--[[		
	if os.getenv('LUAJIT_32BIT') then
		configuration('*')
			platforms{"x32"}
	end
--]]

end

function create_package(name,path_to_root,prj_kind)
	local root = path_to_root or "./"
	local proj = project(name)
	
	project (name)
		language 'C++'
		kind( prj_kind or 'SharedLib')
		includepaths = { root.."include" }
		objdir(root.. "obj/")
		
	configuration("Debug")
		defines { "DEBUG", "_DEBUG" }
		flags {"Symbols", "ExtraWarnings"}
		targetdir(root.. "bin/Debug")
		
	configuration("Release")
		defines{ "NDEBUG", "RELEASE"}
		flags {"Optimize", "ExtraWarnings"}
		targetdir(root.. "bin/Release")

	configuration { 'Debug','StaticLib or SharedLib' }
		targetsuffix '_d'

	configure_for_os()
end


unit_test_config = function()

	configuration { "vs*"}
		postbuildcommands { "\"$(TargetPath)\"" }
		links{"lua51"}

	configuration { "vs*","Debug"}
		links{ "cppunitd" , "gmockd" }
		
	configuration { "vs*","Release"}
		links{ "cppunit" , "gmock" }
		buildoptions {"/MP"}
		
	configuration {"codeblocks" }
		postbuildcommands { "$(TARGET_OUTPUT_FILE)"}
				

	configuration {"gmake or codeblocks","linux or macosx" }
		libdirs {"usr/local/lib","usr/lib"}
		links{ "cppunit", "lua" }
		linkoptions{"`gmock-config --cxxflags --ldflags --libs`"}

	configuration {"xcode3 or xcode4" }
		libdirs {"usr/local/lib","usr/lib"}
		links{ "gmock","gtest","cppunit", "lua" }
		postbuildcommands {"$TARGET_BUILD_DIR/$TARGET_NAME"}

	--64bit LuaJIT rebasing
	if os.getenv('LUAJIT_REBASE') then
		configuration{'xcode*'}
			linkoptions{'-pagezero_size 10000 -image_base 100000000'}
			--this is required to stop a test which should call lua_atpanic and instead
			--makes it a nop, as LuaJIT will throw an exception on OSX x86_64
			defines{"LUAJIT_VERSION_NUM=20000"}
	end
	
--[[	
	if os.getenv('LUAJIT_32BIT') then
		configuration{'xcode*'}
			platforms{"x32"}
	end
--]]

	configuration {"windows","codeblocks","Debug" }
		links{ "lua", "cppunitd" , "gmockd" }
		
	configuration {"windows","codeblocks","Release" }	
		links{ "lua", "cppunit" , "gmock" }
		
	configuration {"gmake"}
		postbuildcommands  { "$(TARGET)" }

	configuration {"linux" }
		links{ "dl" }
		
end

coverage = function()
	configuration{"xcode3 or xcode4 or gmake"}
		links{ "gcov" }
		buildoptions {"-fprofile-arcs -ftest-coverage"}
end
