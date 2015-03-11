--OOLua test.unit.string_is_integral
local root = "../../"
local name = "string_is_integral"
create_package(name,root,"ConsoleApp")


configuration {}

files 
{ 
    	"**.h",
    	"**.cpp",
    	root .. "src/*.cpp",
    	root .. "include/*.h",
    	root .. "unit_tests/test_classes/common_cppunit_headers.h",
    	root .. "unit_tests/main.cpp"
}
includedirs 
{
	"include/cppunit",
	"include/gmock",
	"include/lua",
	"include/",
	root .. "include/",
	"/usr/local/include",
	"/usr/include",
	root .. "unit_tests/bind_classes",
	root .. "unit_tests/cpp_classes",
	root .. "unit_tests/test_classes"
} 
					
defines 
{	
	"OOLUA_RUNTIME_CHECKS_ENABLED=1",
	"OOLUA_STD_STRING_IS_INTEGRAL=1",
	"OOLUA_SAFE_ID_COMPARE=0",
	"OOLUA_STORE_LAST_ERROR=1",
	"OOLUA_USE_EXCEPTIONS=0"
}

--[[
links
{
	"oolua"
}
--]]

unit_test_config(root,name)

