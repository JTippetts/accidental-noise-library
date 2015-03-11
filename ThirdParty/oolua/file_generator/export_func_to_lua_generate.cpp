
#include "common_generate.h"
#include "export_func_to_lua_generate.h"

void export_func_to_lua_header(std::string & save_directory,int amount)
{
	std::string macro_start("LUA_MEMBER_FUNC_");
	std::string fileName("export_func_to_lua.h");
	std::string file = save_directory + fileName;
	std::ofstream f( file.c_str() ,std::ios_base::out | std::ios::trunc);
	include_guard_top(f,"EXPORT_FUNC_TO_LUA_H_");
	add_file_header(f,"export_func_to_lua.h");

	f<<"#define "<<macro_start<<1<<"(class,func"<<1<<") " <<"{#func"<<1<<", &class::func"<<1<<"}," <<std::endl;
	for(int i = 2; i <=amount;++i)
	{
		f<<"#define " <<macro_start<<i<<"(class";
		for(int j = 1;j<=i;++j)
		{
			f<<",func"<<j;
		}
		f<<") "<<macro_start <<i-1<<"(class";
		for(int j =1;j<i;++j)
		{
			f<<",func"<<j;
		}
		f<<")";
		f<<macro_start<<1<<"(class,func" <<i<<")" <<std::endl;
	}
	f<<std::endl <<std::endl;
	f<<"/// @def end the assigning of functions to the array\n"
		<<"#define CLASS_LIST_MEMBERS_END {0,0}};}\n\n"
		<<"/// @def define the constants in the class, which are the the class name and the member function array\n"
		<<"#define CLASS_LIST_MEMBERS_START_OOLUA_NON_CONST(Class)\\" <<std::endl
		<<"namespace OOLUA { \\" <<std::endl
		<<"char const OOLUA::Proxy_class< Class >::class_name[] = #Class;\\" <<std::endl
		<<"int const OOLUA::Proxy_class< Class >::name_size = sizeof(#Class)-1; \\" <<std::endl
		<<"OOLUA::Proxy_class< Class >::Reg_type OOLUA::Proxy_class< Class >::class_methods[]={" <<std::endl
		<<std::endl
		<<"#define CLASS_LIST_MEMBERS_START_OOLUA_CONST(Class)\\" <<std::endl
		<<"namespace OOLUA { \\" <<std::endl
		<<"char const OOLUA::Proxy_class< Class >::class_name_const[] = #Class \"_const\";\\" <<std::endl
		<<"OOLUA::Proxy_class< Class >::Reg_type_const OOLUA::Proxy_class< Class >::class_methods_const[]={"<<std::endl<<std::endl;


	f<<"///  \\addtogroup EXPORT_OOLUA_FUNCTIONS_X\n"
		<<"///  @{\n"
		<<"///  Makes functions available to Lua, where X is the number of functions to register\n\n\n";
	f<<"#define EXPORT_OOLUA_FUNCTIONS_0_(mod,Class)\\"<<std::endl
		<<"CLASS_LIST_MEMBERS_START_ ##mod (Class)\\" <<std::endl
		<<"CLASS_LIST_MEMBERS_END" <<std::endl<<std::endl;
	/*
	#define EXPORT_OOLUA_FUNCTIONS_4_(mod,Class,p1,p2,p3,p4)
	CLASS_LIST_MEMBERS_START_##mod(Class)
	LUA_MEMBER_FUNC_4(OOLUA::Proxy_class< Class > ,p1,p2,p3,p4)
	CLASS_LIST_MEMBERS_END
	*/
	for(int i = 1;i <=amount; ++i)
	{
		f<<"#define EXPORT_OOLUA_FUNCTIONS_" <<i<<"_(mod,Class";
		for(int j = 1; j <=i; ++j)
		{
			f<<",p"<<j;
		}
		f<<")\\"<<std::endl
			<<"CLASS_LIST_MEMBERS_START_ ##mod(Class)\\" <<std::endl
			<<"LUA_MEMBER_FUNC_"<<i <<"(OOLUA::Proxy_class< Class > ";
		for(int j = 1; j <=i; ++j)
		{
			f<<",p"<<j;
		}
		f<<")\\" <<std::endl
			<<"CLASS_LIST_MEMBERS_END" <<std::endl<<std::endl;

	}



	f<<"#define EXPORT_OOLUA_FUNCTIONS_0_CONST(Class)\\" <<std::endl
		<<"EXPORT_OOLUA_FUNCTIONS_0_(OOLUA_CONST,Class)" <<std::endl<<std::endl;
	f<<"#define EXPORT_OOLUA_FUNCTIONS_0_NON_CONST(Class)\\" <<std::endl
		<<"EXPORT_OOLUA_FUNCTIONS_0_(OOLUA_NON_CONST,Class)" <<std::endl<<std::endl;

	for(int i = 1;i <=amount; ++i)
	{
		for(int k = 0; k<2; ++k)
		{
			f<<"#define EXPORT_OOLUA_FUNCTIONS_" <<i ;
			if(k == 0)f<<"_CONST";
			else f<<"_NON_CONST";

			f<<"(Class";
			for(int j = 1; j <=i; ++j)
			{
				f<<",p"<<j;
			}
			f<<")\\"<<std::endl
				<<"EXPORT_OOLUA_FUNCTIONS_"<<i <<"_(";

			if(k == 0)f<<"OOLUA_CONST";
			else f<<"OOLUA_NON_CONST";
			f<<",Class";	

			for(int j = 1; j <=i; ++j)
			{
				f<<",p"<<j;
			}
			f<<")" <<std::endl<<std::endl;

		}
	}
	f<<"#define EXPORT_OOLUA_NO_FUNCTIONS(Class)\\"<<std::endl
	<<"EXPORT_OOLUA_FUNCTIONS_0_NON_CONST(Class)\\"<<std::endl
	<<"EXPORT_OOLUA_FUNCTIONS_0_CONST(Class)"<<std::endl;

	f<<"///  @}\n\n";
	include_guard_bottom(f);
}