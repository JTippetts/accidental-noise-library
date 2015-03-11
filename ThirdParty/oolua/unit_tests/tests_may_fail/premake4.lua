--OOLua tests_may_fail
local root = "../../"
local name = "tests_may_fail"
create_package(name,root,"ConsoleApp")


configuration {}

files 
{ 
    	"**.h",
    	"**.cpp",
    	--root .. "unit_tests/main.cpp", fails soft by returning 1 for own main function
    	root .. "unit_tests/test_classes/common_cppunit_headers.h"
}
includedirs 
{
	"include/cppunit",
	"include/lua",
	"include/",
	root .. "include/",
	"/usr/local/include",
	"/usr/include",
	root .. "unit_tests/test_classes"
} 
					
defines 
{

}

links
{
	"oolua"
}

unit_test_config(root,name)

