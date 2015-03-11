OOLua Cross platform C++ and Lua binding framework
===================================================
http://code.google.com/p/oolua/

Bug reports are welcome. Please use the GoogleCode bug tracking system at 
http://code.google.com/p/oolua/issues/list

Library Help
------------
Basic usage can be seen : http://code.google.com/p/oolua/wiki/CheatSheet
Mailing List : http://groups.google.com/group/oolua-user
Twitter Account : http://twitter.com/OOLua


Requirements
------------
Makefiles, IDE Projects and use of Build Scripts
(version 4.4) http://industriousone.com/premake 

Additionaly for Unit Tests or use of Test Unit Scripts
http://sourceforge.net/apps/mediawiki/cppunit/
http://code.google.com/p/googlemock/

Compile Scripts
---------------
Two type of scripts are present test unit scripts and build scripts.
Test Unit Scripts:
Naming is of the format

[make or IDE]_tests.[sh or bat]

When run from the test_unit directory these will produce compiler and test unit output saved to 
disk located in a directory create named "../build_logs". These scripts clean up any other files 
produced during there running.  

Build Scripts:
Naming is of the format

[make of IDE]_build.[sh or bat]

When run in the test_unit directory it compiles the library debug and release versions. 
These static libraries can be found in the "local_install" directory along with copies of the
header files in a directory below this named "oolua". All other files created during the running 
are deleted. 



Building Makefiles or IDE projects.
-----------------------------------
OOLua's source and header files can added to your project or be compiled as a static library.
To compile as a static library or to run the UnitTests, Premake version 4.4 is the recommended 
method to generate make files/IDE projects. This can either be accomplish using the following 
details or using the pre-existing bash or bat files( see Compile Scripts). 


Premake Format
--------------
premake4 [make or IDE] [target operation system]

==Makefile==

premake4 gmake []

    * macosx
    * linux 

==Xcode==

premake4 xcode3 macosx

macosx is required


==Visual Studio==

premake4 vs[] windows

windows is required

    * 2005
    * 2008
    * 2010


==CodeBlocks==

premake4 codeblocks []

    * windows
    * linux
    * macosx 


Config

A configuration header is now included to control what features are present in the library, 
see oolua_config.h for more information. To turn a feature on, define it to have a default value 
of 1 in config or predefine it to have this value.

Macro	                 Default value	Description
OOLUA_RUNTIME_CHECKS_ENABLED 	1 	Checks that a type being pulled off the stack is of the correct type. 
                                    If this is a proxy type, it also checks the userdata on the stack was 
                                    created by OOLua
OOLUA_STD_STRING_IS_INTEGRAL	1	If 1 Allows std::string to be a parameter or a return type for a function.
                                    NOTE: This is always by value.

OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA
                                1   When set to one, everytime a userdata is encountered and it is expected to
                                    have been created by OOLua it is checked and an error occurs if it was not.
                                    
OOLUA_USERDATA_OPTIMISATION     1   Userdata optimisation which checks for a magic cookie to try and ensure it 
                                    was created by OOLua, by default this is on when userdata checking is on. 
                                    Turning this off by setting it to zero will use a slower yet fully correct
                                    method.

OOLUA_USE_EXCEPTIONS	        0	If 1 Throws exceptions from C++ code. This could be the return 
                                    of a pcall when pulling an incorrect type of the stack if.
                                    See [Error_Note]
OOLUA_STORE_LAST_ERROR	        1	When an error occurs, the error is stored in the Lua registry 
                                    and is retrievable via OOLUA::get_last_error(lua);
                                    See [Error_Note]
OOLUA_DEBUG_CHECKS	            1	Checks for null pointers adds a stack trace to messages called within pcall.
                                    Note: Default value is when complied as a debug version of the library.
Error Note

It is an error to have both OOLUA_USE_EXCEPTIONS and OOLUA_STORE_LAST_ERROR set to 1
File generator

The library comes with a file generator project which when compiled is a command line executable. 
Running it allows you to easily generate C++ source files with new limits set via the command line.
Name	  Default value if not defined	    Description
--classFunctions	15	Maximum number of member functions a class can register.
--cppParams	        8	Maximum parameters an OOLua registered C++ member function can have.
--luaParams	       10	Maximum parameters an OOLUA::Lua_function has.
--saveDir	       ./	Relative directory to save headers to. Required to be slash postfixed.
--constructorParams	5	Maximum parameters an OOLua registered C++ constructor can have.


