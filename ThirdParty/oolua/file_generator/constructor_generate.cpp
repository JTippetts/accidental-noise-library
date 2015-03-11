
#include "constructor_generate.h"
#include "common_generate.h"
namespace
{
	char tab[] = "\t";
	char macro_new_line[] ="\\\n";
}

void write_constructor_with_parameters(std::ofstream& f, int param)
{
	std::string ParamStart = "Param";
	std::string ParamEnd = "WithTraits";
	
	f<<"template<typename Class,";
	for(int i = 1; i <= param;++i)
	{
		f<<"typename " <<ParamStart << i <<ParamEnd;
		if(i<param)f<<", ";
	}
	//close template
	f<<" >\n";
	
	f<<"struct Constructor" <<param <<"\n";
	f<<"{\n";
	f<<tab<<"static int construct(lua_State* l) \n";
	f<<tab<<"{\n";
    f<<tab<<tab<<"int index(1);\n";
	f<<tab<<tab<<"if(";
	
	for(int i = 1; i<=param;++i)
	{
        f<<"Param_helper<"<<ParamStart<<i<<ParamEnd<<" >::param_is_of_type(l,index)";
		if (i < param) {
			f<<"\n"<<tab<<tab<<tab<<"&& ";
		}
	}
	//close if and start scope
	f<<")\n"<<tab<<tab<<"{\n";
	f<<tab<<tab<<tab<<"valid_construct(l);\n";
	f<<tab<<tab<<tab<<"return 1;\n";
	f<<tab<<tab<<"}\n";
	f<<tab<<tab<<"return 0;\n";
	f<<tab<<"}\n";

	f<<tab<<"static void valid_construct(lua_State* l)\n";
	f<<tab<<"{\n";
	
	for (int i = param; i >= 1; --i)
	{
		f<<tab<<tab<<"typename " <<ParamStart <<i <<ParamEnd <<"::pull_type p"<<i <<";\n";
		f<<tab<<tab<<"Member_func_helper<"
						<<ParamStart <<i <<ParamEnd <<","
						<<ParamStart <<i <<ParamEnd <<"::owner>::pull2cpp(l,p"<<i<<");\n";
		f<<tab<<tab<<"Converter<typename "
					<<ParamStart <<i <<ParamEnd <<"::pull_type,typename "
					<<ParamStart <<i <<ParamEnd <<"::type> p" <<i <<"_(p"<<i<<");\n";
	}
	f<<tab<<tab<<"Class* obj = new Class( ";
	for(int i =1; i <=param;++i)
	{
		f<<"p"<<i<<"_";
		if(i <param)f<<",";
	}
					f<<");\n";
    f<<tab<<tab<<"add_and_set_gc(l,obj);\n";
	f<<tab<<"}\n";

	f<<"};\n";
}

void param_type_string(std::ofstream& f,int const i)
{
    for (int j =1; j <= i; ++j) 
    {
        f<<"param"<<j<<"Type";
        if(j<i)f<<",";
    }
}
void write_macros(std::ofstream& f, int paramCount)
{
	f<<"#define OOLUA_CONSTRUCTORS_BEGIN "<<macro_new_line
	<<"static int oolua_factory_function(lua_State* l) "<<macro_new_line
	<<"{ "<<macro_new_line
	<<tab<<"lua_remove(l, 1);/*remove class type*/ "<<macro_new_line
	<<tab<<"int const stack_count = lua_gettop(l);\n";
	
	for (int i = 1; i <= paramCount; ++i)
	{

		f<<"#define OOLUA_CONSTRUCTOR_"<<i<<"(";
        param_type_string(f,i);
		f<<") "<<macro_new_line;
        f<<tab<<"MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA "<<macro_new_line;
        f<<tab<<"if( (stack_count == "<<i<<" && TYPELIST::IndexOf<Type_list<";
                                                        param_type_string(f,i); 
                                                    f<<">::type, calling_lua_state>::value == -1) " <<macro_new_line
        <<tab<<tab<<"|| (stack_count == "<<i-1<<" && TYPELIST::IndexOf<Type_list<";
                                                        param_type_string(f,i);
                                                    f<<">::type, calling_lua_state>::value != -1) ) " <<macro_new_line
		<<tab<<"{ "<<macro_new_line;
		
		f<<tab<<tab<<"if(INTERNAL::Constructor"<<i<<"<class_,";
		for (int j =1; j <= i; ++j) 
		{
			f<<"INTERNAL::param_type<param"<<j<<"Type >";
			if(j<i)f<<",";
		}
		f<<" >::construct(l) ) return 1; "<<macro_new_line
		<<tab<<"} "<<macro_new_line
		<<tab<<"MSC_POP_COMPILER_WARNING_OOLUA\n\n";
	}

	
	f<<"#define OOLUA_CONSTRUCTORS_END "<<macro_new_line
    <<tab<<"if(stack_count == 0 ) "<<macro_new_line
	<<tab<<"{ "<<macro_new_line
	<<tab<<tab<<"return INTERNAL::Constructor<class_,INTERNAL::has_typedef<this_type, No_default_constructor>::Result>::construct(l); "<<macro_new_line
	<<tab<<"} "<<macro_new_line
	<<tab<<"luaL_error(l,\"%s %d %s %s\",\"Could not match\",stack_count,\"parameter constructor for type\",class_name); "<<macro_new_line
	<<tab<<"return 0;/*required by function sig yet luaL_error never returns*/  "<<macro_new_line
	<<"}\n\n";
	
	f<<"#define OOLUA_ONLY_DEFAULT_CONSTRUCTOR "<<macro_new_line
	<<"OOLUA_CONSTRUCTORS_BEGIN "<<macro_new_line
	<<"OOLUA_CONSTRUCTORS_END\n\n";
}
void write_default_constructor(std::ofstream &f )
{
	f<<"template<typename Type,int HasNoDefaultTypedef>\n"
	<<"struct Constructor\n"
	<<"{\n"
	<<tab<<"static int construct(lua_State * l)\n"
	<<tab<<"{\n"
	<<tab<<tab<<"Type* obj = new Type;\n"
    <<tab<<tab<<"add_and_set_gc(l,obj);\n"
	<<tab<<tab<<"return 1;\n"
	<<tab<<"}\n"
	<<"};\n";
	
	f<<"template<typename Type>\n"
	<<"struct Constructor<Type,1>\n"
	<<"{\n"
	<<tab<<"static int construct(lua_State * l)\n"
	<<tab<<"{\n"
	<<tab<<tab<<"luaL_error(l,\"%s %s %s\",\"No parameters passed to the constructor of the type\"\n"
	<<tab<<tab<<tab<<",OOLUA::Proxy_class<Type>::class_name\n"
	<<tab<<tab<<tab<<",\"which does not have a default constructor.\");\n"
	<<tab<<tab<<"return 0;//required by function sig yet luaL_error never returns\n"
	<<tab<<"}\n"
	<<"};\n";
}
void constructor_header(std::string & save_directory,int paramCount)
{
	std::string fileName("cpp_constructor.h");
	std::string file = save_directory + fileName;
	std::ofstream f( file.c_str() );
	include_guard_top(f,"OOLUA_CPP_CONSTRUCTOR_H_");
	add_file_header(f,fileName);
	
	include_header(f,"lua_includes.h");
	include_header(f,"oolua_storage.h");
	include_header(f,"param_traits.h");
	include_header(f,"oolua_userdata.h");
	include_header(f,"member_func_helper.h");
	include_header(f,"oolua_parameter_helper.h");
	include_header(f,"oolua_converters.h");
	
	f<<"namespace OOLUA\n{\nnamespace INTERNAL\n{\n";
	
    f<<"template<typename ObjType>\n"
	<<"void add_and_set_gc(lua_State* l,ObjType obj)\n"
	<<"{\n"
	<<tab<<"Lua_ud* ud = add_ptr(l,obj,false);\n"
	<<tab<<"userdata_gc_value(ud,true);\n"
	<<"}\n\n";
    
	write_default_constructor(f);
	
	for(int i = 1;i <= paramCount; ++i)
		write_constructor_with_parameters(f,i);
	
	f<<"\n}\n}\n";//end namespace
	
	write_macros(f,paramCount);
	
	include_guard_bottom(f);
}