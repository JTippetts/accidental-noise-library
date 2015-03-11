#include "common_generate.h"
#include "lua_function_generate.h"

namespace
{
	char tab[] = "\t";
}
void operator_create(std::ofstream &f,int params)
{
	f<<tab<<"template<typename FUNC_TYPE";
	for(int i = 1; i<=params;++i)
	{
		f<<",typename P"<<i;
	}
	f<<">\n";

	f<<tab<<"bool operator()(FUNC_TYPE const& func";
	for(int j = 1;j<=params;++j)
	{
		f<<",P"<<j<<" p"<<j;
	}
	f<<")\n";

	f<<tab<<"{\n" 
	<<tab<<tab<<"int error_index(0);\n"
	<<tab<<tab<<"const int top = get_top();\n"
	<<tab<<tab<<"OOLUA_CALLER_TRY\n";

	f<<tab<<tab<<"if( prep_function(func,"<<params<<",error_index) ";
	if(params == 0)
	{
		f<<") return call(0,error_index);\n";
	}
	else
	{
		f<<"\n";
		for(int k=1;k<=params;++k)
		{
			f<<tab<<tab<<tab<<"&& push2lua(m_lua,p"<<k<<")\n";
		}
		f<<tab<<tab<<")\n"
		<<tab<<tab<<tab<<"return call("<<params<<",error_index);\n";

	}

	f<<tab<<tab<<"OOLUA_CALLER_HANDLE_FAIL\n"
	<<tab<<"}\n";
}
void rest_of_struct_body(std::ofstream&f)
{
	f<<tab<<"void bind_script(lua_State* const lua);\n"
	<<"private:\n"
	<<tab<<"int get_top();\n"
	<<tab<<"bool call(int const nparams, int const error_index);\n"
	<<tab<<"bool prep_function(Lua_func_ref const& func,int const nparams, int& error_index);\n"
	<<tab<<"bool prep_function(std::string const& func,int const nparams, int& error_index);\n"
	<<tab<<"bool prep_function(int const func,int const nparams, int& error_index);\n"
	<<tab<<"lua_State* m_lua;\n";
}
void lua_function_header(std::string & save_directory,int maxParams)
{
	std::string fileName("lua_function.h");
	std::string file = save_directory + fileName;
	std::ofstream f( file.c_str() );
	include_guard_top(f,"LUA_FUNCTION_H_");
	add_file_header(f,fileName);


	include_header(f,"lua_includes.h");
	include_header(f,"fwd_push_pull.h");
	include_header(f,"lua_ref.h");
	//include_header(f,"oolua_exception.h");

	f<<"namespace OOLUA\n{\n";	

	f<<
"///////////////////////////////////////////////////////////////////////////////\n\
///  Lua_function\n\
///  Struct which is used to call a lua function.\n\
///  @remarks\n\
///  The Lua function can either be called by name(std::string) or with the\n\
///  use a Lua reference which is stored in a Lua_func.\n\
///////////////////////////////////////////////////////////////////////////////\n";
	
f <<"#if OOLUA_USE_EXCEPTIONS ==1 \n"
  <<"#"<<tab<<"define OOLUA_CALLER_TRY \\\n"
		<<tab<<"try \\\n"
		<<tab<<"{\n"
	
	<<"#"<<tab<<"define OOLUA_CALLER_HANDLE_FAIL \\\n"
	<<tab<<"} \\\n"
	<<tab<<"catch (...) \\\n"
	<<tab<<"{ \\\n"
	<<tab<<tab<<"lua_settop(m_lua, top); \\\n"
	<<tab<<tab<<"throw; \\\n"
	<<tab<<"} \\\n"
	<<tab<<"return false; /*Shhhhhhhhhh*/\n"
	
<<"#else\n"
	<<"#"<<tab<<"define OOLUA_CALLER_TRY \n"
	<<"#"<<tab<<"define OOLUA_CALLER_HANDLE_FAIL \\\n"
	<<tab<<"lua_settop(m_lua, top); \\\n"
	<<tab<<"return false; \n"
<<"#endif\n";
	
	f<<"struct Lua_function\n"
	<<"{\n"
	<<"\tLua_function();\n"
	<<"\tLua_function(lua_State* l);\n";

	for(int i = 0; i<=maxParams; ++i)
	{
		operator_create(f,i);
	}
	rest_of_struct_body(f);

	f<<"\n};";//end struct
	f<<"\n}\n";//end namespace
	
	f<<"#undef OOLUA_CALLER_TRY\n"
	<<"#undef OOLUA_CALLER_HANDLE_FAIL\n";

	include_guard_bottom(f);
}