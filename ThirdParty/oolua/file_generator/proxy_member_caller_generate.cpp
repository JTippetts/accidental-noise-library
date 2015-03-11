

#include "common_generate.h"
#include "proxy_member_caller_generate.h"

std::string proxy_member_caller_convertors(std::ofstream & f,int paramCount);
void member_functions_with_return(std::ofstream &f,int paramCount,std::string& convertor_name);
void member_functions_no_return(std::ofstream &f,int paramCount,std::string& convertor_name);
void undef_defines(std::ofstream & f,int paramCount,std::string convertor_name);

namespace
{
	char tab[] = "\t";
}


std::string proxy_member_caller_convertors(std::ofstream & f,int paramCount)
{
	std::string name("OOLUA_CONVERTER");
	f<<"\n#define "<<name<<"(NUM)\\\n"
		<<tab<<"OOLUA::INTERNAL::Converter<typename P##NUM::pull_type, typename P##NUM::type> p##NUM##_(p##NUM);\n\n";

	f<<"#define "<<name<<"1\\\n"
		<<tab<<name<<"(1)\n\n";

	for(int i = 2; i <= paramCount; ++i)
	{
		f<<"#define "<<name<<i<<"\\\n"
			<<"\t"<<name<<i-1<<"\\\n"
			<<"\t"<<name<<"("<<i<<")\n\n";
	}
	return name;
}

void member_functions_no_return(std::ofstream &f,int paramCount,std::string& convertor_name)
{
	f<<"\ntemplate <typename R, typename C>\n"
		<<"struct Proxy_caller<R,C, 1 >\n" 
		<<"{\n"
		<<tab<<"template<typename FuncType>\n"
		<<tab<<"static void call(lua_State*  const /*l*/,C* m_this, FuncType ptr2mem )\n"
		<<tab<<"{\n"
		<<tab<<tab<<"(m_this->*ptr2mem)();\n"
		<<tab<<"}\n";

	for(int j =1; j<=paramCount ; ++j)
	{
		//template parameters
		f<<tab<<"template<";
		for(int k=1; k<= j; ++k)
		{
			f<<"typename P"<<k;
			if(k !=j )f<<",";
		}
		f<<",typename FuncType>\n";

		f<<tab<<"static void call(lua_State* const  /*l*/,C* m_this,FuncType ptr2mem";
		//params for function
		for(int p = 1; p<=j;++p)
		{
			f<<",typename P"<<p<<"::pull_type&  p"<<p;
		}
		f<<")";

		//function body
		f<<"\n"<<tab<<"{\n";
		f<<tab<<tab<<convertor_name<<j<<"\n";

		//caller
		{
			f<<tab<<tab<<"(m_this->*ptr2mem)(";
			for(int ii = 1;ii<=j;++ii)
			{
				if(ii!=1)f<<",";
				f<<"p"<<ii<<"_";
			}
			f<<");\n";
		}
		//end function
		f<<tab<<"}\n";
	}

	f<<"\n};\n";//end class
}

void member_functions_with_return(std::ofstream &f,int paramCount,std::string& convertor_name)
{
	f<<"\ntemplate <typename R, typename C>\n"
		<<"struct Proxy_caller<R,C, 0 >\n" 
		<<"{\n"
		<<tab<<"template<typename FuncType>\n"
		<<tab<<"static void call(lua_State*  const l,C* m_this, FuncType ptr2mem )\n"
		<<tab<<"{\n"
		<<tab<<tab<<"typename R::type r( (m_this->*ptr2mem)() );\n"
		<<tab<<"\tMember_func_helper<R,R::owner>::push2lua(l,r);\n"
		<<tab<<"}\n";

	for(int j =1; j<=paramCount ; ++j)
	{
		//template parameters
		f<<tab<<"template<";
		for(int k=1; k<= j; ++k)
		{
			f<<"typename P"<<k;
			if(k !=j )f<<",";
		}
		f<<",typename FuncType>\n";

		f<<tab<<"static void call(lua_State* const  l,C* m_this,FuncType ptr2mem";
		//params for function
		for(int p = 1; p<=j;++p)
		{
			f<<",typename P"<<p<<"::pull_type&  p"<<p;
		}
		f<<")";

		//function body
		f<<"\n"<<tab<<"{\n";
		f<<tab<<tab<<convertor_name<<j<<"\n";

		//caller
		{
			f<<tab<<tab<<"typename R::type r( (m_this->*ptr2mem) (";
			for(int ii = 1;ii<=j;++ii)
			{
				if(ii!=1)f<<",";
				f<<"p"<<ii<<"_";
			}
			f<<") );\n";
		}
		//return value
		f<<tab<<tab<<"Member_func_helper<R,R::owner>::push2lua(l,r);\n";
		//end function
		f<<tab<<"}\n";
	}

	f<<"\n};\n";//end class
}

void undef_defines(std::ofstream & f,int paramCount,std::string convertor_name)
{
	f<<"#undef "<<convertor_name <<"\n";
	for(int i = 1;i<=paramCount; ++i)
		f<<"#undef "<<convertor_name <<i<<"\n";
}

void c_functions_no_return(std::ofstream &f,int paramCount,std::string& convertor_name)
{
	f<<"\ntemplate <typename R >\n"
		<<"struct Proxy_none_member_caller<R, 1 >\n" 
		<<"{\n"
		<<tab<<"template<typename FuncType>\n"
		<<tab<<"static void call(lua_State*  const /*l*/, FuncType ptr2func )\n"
		<<tab<<"{\n"
		<<tab<<tab<<"(*ptr2func)();\n"
		<<tab<<"}\n";

	for(int j =1; j<=paramCount ; ++j)
	{
		//template parameters
		f<<tab<<"template<";
		for(int k=1; k<= j; ++k)
		{
			f<<"typename P"<<k;
			if(k !=j )f<<",";
		}
		f<<",typename FuncType>\n";

		f<<tab<<"static void call(lua_State* const  /*l*/,FuncType ptr2func";
		//params for function
		for(int p = 1; p<=j;++p)
		{
			f<<",typename P"<<p<<"::pull_type&  p"<<p;
		}
		f<<")";

		//function body
		f<<"\n"<<tab<<"{\n";
		f<<tab<<tab<<convertor_name<<j<<"\n";

		//caller
		{
			f<<tab<<tab<<"(*ptr2func)(";
			for(int ii = 1;ii<=j;++ii)
			{
				if(ii!=1)f<<",";
				f<<"p"<<ii<<"_";
			}
			f<<");\n";
		}
		//end function
		f<<tab<<"}\n";
	}

	f<<"\n};\n";//end class
}
void c_functions_with_return(std::ofstream &f,int paramCount,std::string& convertor_name)
{
	f<<"template <typename Return, int ReturnIsVoid>struct Proxy_none_member_caller;\n\n"

	<<"template <typename R> \n"
	<<"struct Proxy_none_member_caller<R,0 > \n"
	<<"{\n"
	<<tab<<"template<typename FuncType> \n"
	<<tab<<"static void call(lua_State*  const l,FuncType ptr2func ) \n"
	<<tab<<"{\n"
	<<tab<<tab<<"typename R::type r( (*ptr2func)() );\n"
	<<tab<<tab<<"Member_func_helper<R,R::owner>::push2lua(l,r);\n"
	<<tab<<"}\n";

	for(int j =1; j<=paramCount ; ++j)
	{
		//template parameters
		f<<tab<<"template<";
		for(int k=1; k<= j; ++k)
		{
			f<<"typename P"<<k;
			if(k !=j )f<<",";
		}
		f<<",typename FuncType>\n";

		f<<tab<<"static void call(lua_State* const  l,FuncType ptr2func";
		//params for function
		for(int p = 1; p<=j;++p)
		{
			f<<",typename P"<<p<<"::pull_type&  p"<<p;
		}
		f<<")";

		//function body
		f<<"\n"<<tab<<"{\n";
		f<<tab<<tab<<convertor_name<<j<<"\n";

		//caller
		{
			f<<tab<<tab<<"typename R::type r( (*ptr2func) (";
			for(int ii = 1;ii<=j;++ii)
			{
				if(ii!=1)f<<",";
				f<<"p"<<ii<<"_";
			}
			f<<") );\n";
		}
		//return value
		f<<tab<<tab<<"Member_func_helper<R,R::owner>::push2lua(l,r);\n";
		//end function
		f<<tab<<"}\n";
	}



	f<<"};\n"; //end class
}
void proxy_member_caller_header(std::string & save_directory,int paramCount)
{
	std::string fileName("proxy_caller.h");
	std::string file = save_directory + fileName;
	std::ofstream f( file.c_str() );
	include_guard_top(f,"PROXY_CALLER_H_");
	add_file_header(f,fileName);

	include_header(f,"member_func_helper.h");
	include_header(f,"param_traits.h");
	include_header(f,"oolua_converters.h");

	std::string convertor_name = proxy_member_caller_convertors(f,paramCount);

	f<<"namespace OOLUA\n{\n"
	<<"\tnamespace INTERNAL\n\t{\n"; 

	f<<"template <typename Return, typename Class, int ReturnIsVoid>struct Proxy_caller;\n"; 	

	member_functions_with_return(f,paramCount,convertor_name);
	member_functions_no_return(f,paramCount,convertor_name);

	c_functions_with_return(f,paramCount,convertor_name);
	c_functions_no_return(f,paramCount,convertor_name);
	
	f<<"\t}//end INTERNAL namespace\n";
	f<<"\n}//end OOLUA namespace\n";

	undef_defines(f,paramCount,convertor_name);

	include_guard_bottom(f);

}