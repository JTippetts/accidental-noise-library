--OOLua test.unit.using_exceptions
local root = "../"
local name = "test.unit.using_exceptions"
create_package(name,root,"ConsoleApp")


configuration {}

files 
{ 
    	root .. "/src/*.cpp",
    	root .. "/include/*.h",
    	root .. "unit_tests/test_classes/common_cppunit_headers.h",
    	root .. "unit_tests/main.cpp",
    	root .. "unit_tests/bind_classes/*.h",
    	root .. "unit_tests/bind_classes/*.cpp",
		root .. "unit_tests/cpp_classes/*.h",
		root .. "unit_tests/cpp_classes/*.cpp",
		root .. "unit_tests/test_classes/*h",
		root .. "unit_tests/test_classes/*.cpp"
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
	root .. "unit_tests/test_classes",
--	"/usr/local/include/lua52",
} 


defines 
{
	"OOLUA_RUNTIME_CHECKS_ENABLED=1",
	"OOLUA_STD_STRING_IS_INTEGRAL=0",
	"OOLUA_SAFE_ID_COMPARE=1",
	
	"OOLUA_STORE_LAST_ERROR=0",
	"OOLUA_USE_EXCEPTIONS=1",
	"OOLUA_USE_PRECOMPILED_HEADER"
}


configuration{"gmake"}
	pchheader("unit_tests/test_classes/oolua_tests_pch.h")
configuration{"not gmake","not vs*"}
	pchheader(root .. "unit_tests/test_classes/oolua_tests_pch.h")
configuration{"vs*"}
	pchheader(root .. "unit_tests/test_classes/oolua_tests_pch.h")
	pchsource(root .. "unit_tests/test_classes/oolua_tests_pch.cpp")
	buildoptions {"/FI oolua_tests_pch.h"}

unit_test_config(root,name)


