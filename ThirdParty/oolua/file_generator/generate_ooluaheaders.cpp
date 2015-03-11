
#include "common_generate.h"
#include "proxy_member_caller_generate.h"
#include "export_func_to_lua_generate.h"
#include "cpp_member_func_generate.h"
#include "lua_function_generate.h"
#include "constructor_generate.h"
#include "options.h"

bool default_options(EXECUTABLE::Options& opt)
{
	const int num = 11;
	char* values[num]  =
	{
		"file_generator"
		,"--classFunctions","15"
		,"--cppParams","8"
		,"--luaParams","10"
		,"--saveDir","../include/"
		,"--constructorParams", "5"
	};

	return opt.process(num,values);
}
int main(int argc, char** argv)
{

	EXECUTABLE::Options options;
	{
		using namespace EXECUTABLE;

		options.add("--classFunctions"
			,Option_value<int>(
				"Maximum number of member functions a class can register."
				,15)
			);

		options.add("--cppParams"
			,Option_value<int>(
				"Maximum parameters an OOLua registered C++ member function can have."
				,8)
			);
		options.add("--luaParams"
			,Option_value<int>(
				"Maximum parameters an OOLUA::Lua_function has."
				,10)
			);

		options.add("--saveDir"
			,Option_value<std::string>(
				"Relative directory to save headers to. Required to be slash postfixed."
				,"./")
			);
		options.add("--constructorParams"
			,Option_value<int>(
				"Maximum parameters an OOLua registered C++ constructor can have."
				,5)
			);
	}
	
	if( argc == 1)
	{
		std::cout <<"No options passed via the command line\n";
		if( !default_options(options) ) return 1;
		options.help();
	}
	else if(! options.process(argc,argv) ) return 1;

	int max_params_for_cpp_function = options.value<int>("--cppParams");
	int max_amount_of_member_functions_a_class_can_register = options.value<int>("--classFunctions");
	int max_params_for_a_lua_function = options.value<int>("--luaParams");
	std::string save_directory = options.value<std::string>("--saveDir");
	int max_params_for_constructor = options.value<int>("--constructorParams");

	export_func_to_lua_header(save_directory,max_amount_of_member_functions_a_class_can_register);
	cpp_member_func_header(save_directory,max_params_for_cpp_function);
	proxy_member_caller_header(save_directory,max_params_for_cpp_function);
	lua_function_header(save_directory,max_params_for_a_lua_function);
	constructor_header(save_directory,max_params_for_constructor);
}


