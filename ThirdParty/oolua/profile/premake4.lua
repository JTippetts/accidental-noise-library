--OOLua compare tests
local root = "../"
create_package("profile",root,"ConsoleApp")

configuration {}

files 
{ 
	"*.h",
	"*.cpp",
--	"luabind/**.hpp",
--	"src/**.cpp"
}

includedirs 
{
	root .. "profile/"
	,root .. "include/"
	,"./"
	,"include/lua"
--	,"include/boost"
} 


defines 
{
--	"OOLUA_STORE_ERROR",
--	"OOLUA_SWIG_COMPARE", [[modified to work with 5.2--]]
--broken 5.1 and 5.2	"OOLUA_LUABRIDGE_COMPARE",
--no official 5.2 support	"OOLUA_LUABIND_COMPARE",
	"LUABIND_NO_ERROR_CHECKING",
	"LUABIND_DONT_COPY_STRINGS",
-- 	'OOLUA_RUNTIME_CHECKS_ENABLED=1',
--	'OOLUA_USERDATA_OPTIMISATION=1',
--	'OOLUA_USE_EXCEPTIONS',
--	'OOLUA_STORE_LAST_ERROR',
}

links
{
	"oolua"
}

	configuration { "vs*"}
		links{"lua51"}

	configuration { "gmake or linux or macosx or xcode3 or codeblocks"}
		links{"lua"}

--[[
	--64bit luaJIT rebasing
	configuration{'xcode*'}
		linkoptions{'-pagezero_size 10000 -image_base 100000000'}
--]]