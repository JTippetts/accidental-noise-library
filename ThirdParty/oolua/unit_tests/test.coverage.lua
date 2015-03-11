--OOlua test.unit
local root = "../"
local name = "test.coverage"

create_package(name,root,"ConsoleApp")

configuration {}
	files 
	{ 
    	root .. "include/*.h", 
    	root .. "src/*.cpp",
    	root .. "unit_tests/main.cpp",
    	root .. "unit_tests/bind_classes/*.h",
    	root .. "unit_tests/bind_classes/*.cpp",
		root .. "unit_tests/cpp_classes/*.h",
		root .. "unit_tests/cpp_classes/*.cpp",
		root .. "unit_tests/test_classes/*h",
		root .. "unit_tests/test_classes/*.cpp",
		root .. "unit_tests/string_is_integral/string_as_integral.cpp",
	}
	includedirs 
	{
		"include/cppunit",
		"include/gmock",
		"include/lua",
		"include/",
		"/usr/local/include",
		"/usr/include",
		root .. "include",
		root .. "unit_tests/bind_classes",
		root .. "unit_tests/cpp_classes",
		root .. "unit_tests/test_classes"
	} 
	 
unit_test_config(root,name)
coverage()

configuration("Release")
	defines 
	{
		"OOLUA_RUNTIME_CHECKS_ENABLED=1",
		"OOLUA_STD_STRING_IS_INTEGRAL=1",
		"OOLUA_SAFE_ID_COMPARE=1",
		
		"OOLUA_STORE_LAST_ERROR=0",
		"OOLUA_USE_EXCEPTIONS=1"
	}

