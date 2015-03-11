--
-- OOLua binding premake script
--
create_package("oolua","./","StaticLib")

configuration {}

files { "include/*.h", "src/*.cpp" }
includedirs 
					{
						"include/lua/",
						"include/",
						"/usr/local/include",
						"/usr/include"
					} 
	
