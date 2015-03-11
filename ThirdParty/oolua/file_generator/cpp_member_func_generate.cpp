#include <sstream>
#include "common_generate.h"
#include "cpp_member_func_generate.h"

void print_back_helper_macros(std::ofstream& f,int num);
void print_param_macros(std::ofstream& f,int num);
void print_mem_funcs(std::ofstream& f,int num);
void print_proxy_imps(std::ofstream&f,int num_params);
void print_default_trait_mem_funcs(std::ofstream&f,int num_params);

namespace
{
	char tab[] = "\t";
}
void print_back_helper_macros(std::ofstream& f,int num)
{
	f<<"//param return macros\n";

	f<<"#define OOLUA_BACK_INTERNAL_(NUM)\\\n";
	f<<"MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA \\\n";
	f<<tab<<"if( P ## NUM ## _::out )\\\n";
	f<<tab<<tab<<"OOLUA::INTERNAL::Member_func_helper<P ## NUM ##_,P ## NUM ##_::owner>::push2lua(l,p ## NUM);\\\n";
	f<<"MSC_POP_COMPILER_WARNING_OOLUA\n\n";
	
	f<<"\n//this is for deduced member functions which have no returns\n"
	<<"#define OOLUA_BACK_INTERNAL_0\n";
	
	for(int i = 1; i <=num; ++i)
	{
		f<<"\n#define OOLUA_BACK_INTERNAL_"<<i<<"\\\n";
		if(i>1)f<<tab<<"OOLUA_BACK_INTERNAL_"<<(i-1)<<"\\\n";
		f<<tab<<"OOLUA_BACK_INTERNAL_("<<i<<");\n";
	}
}

void print_param_macros(std::ofstream& f,int num)
{
	f<<"\n//param macros\n"
		<<"#define OOLUA_INTERNAL_PARAM(NUM,PARAM)\\\n"
		<<tab<<"typedef OOLUA::INTERNAL::param_type<PARAM > P ## NUM ##_;\\\n";
	//there is no need for initialising pull parameters
	//yet w-effc++ complains. When string is intregal it is an error to init to 0 which is seen as
	//a null pointer which it is an error to be constructed from
	//<<tab<<"P ## NUM ##_::pull_type p ## NUM( static_cast<P ## NUM ##_::pull_type>(0) );\\\n"
	f<<tab<<"P ## NUM ##_::pull_type p ## NUM;\\\n"
		<<tab<<"MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA\\\n"
		<<tab<<"if( P ## NUM ##_::in )\\\n"
		<<tab<<tab<<"OOLUA::INTERNAL::Member_func_helper<P ## NUM ##_,P ## NUM ##_::owner>::pull2cpp(l,p ## NUM);\\\n"
		<<tab<<"MSC_POP_COMPILER_WARNING_OOLUA\n\n";

	std::string params("OOLUA_PARAMS_INTERNAL_");
	std::string params_define(std::string("#define ") + params);
	std::string param_macro("\tOOLUA_INTERNAL_PARAM");

	for(int i = 1;i<=num;++i)
	{
		std::stringstream ss;
		for(int j = 1; j<=i;++j)
		{
			if(j!=1)ss<<",";
			ss <<"PARAM"<<j;
		}
		f<<params_define<<i<<"("<<ss.str().c_str()<<")\\\n";
		f<<param_macro<<"("<<i<<",PARAM"<<i<<")";
		if(i >1)
		{
			f<<"\\\n\tOOLUA_PARAMS_INTERNAL_"<<(i-1)<<"(";
			std::stringstream ss;
			for(int k = 1;k<i;++k)
			{

				if(k!=1)ss<<",";
				ss <<"PARAM"<<k;
			}
			f<<ss.str().c_str()<<")\n";
		}
		else f<<"\n";
		f<<"\n";
	}
}

void print_default_trait_param_macros(std::ofstream& f,int num)
{
	std::string macro_endl("\\\n");
	f<<"\n//macros for when using default traits and deducing the function signature\n"
	<<"#define OOLUA_INTERNAL_PARAM_T(NUM) "<<macro_endl
	<<tab<<"typedef OOLUA::INTERNAL::param_type<P ## NUM > P ## NUM ##_; "<<macro_endl
	<<tab<<"typename P ## NUM ##_::pull_type p ## NUM; "<<macro_endl
	<<tab<<"MSC_PUSH_DISABLE_CONDITIONAL_CONSTANT_OOLUA "<<macro_endl
	<<tab<<"if( P ## NUM ##_::in ) "<<macro_endl
	<<tab<<tab<<"OOLUA::INTERNAL::Member_func_helper<P ## NUM ##_,P ## NUM ##_::owner>::pull2cpp(l,p ## NUM); "<<macro_endl
	<<tab<<"MSC_POP_COMPILER_WARNING_OOLUA\n";
	
	f<<"\n//we need to generate a 0 entry so that a function with no parameters will compile\n"
	<<"#define OOLUA_PARAMS_T_INTERNAL_0\n\n";
	
	for(int i =1; i<=num;++i)
	{
		f
		<<"#define OOLUA_PARAMS_T_INTERNAL_"<<i <<macro_endl
		<<tab<<"OOLUA_INTERNAL_PARAM_T("<<i<<")";
		if(i>1)
			f <<macro_endl <<tab<<"OOLUA_PARAMS_T_INTERNAL_"<<i-1;
		f<<"\n\n";
	}
}
void print_mem_funcs(std::ofstream& f,int num)
{
	std::string mem_func_macro_start("#define OOLUA_MEM_FUNC_");
	std::string macro_class_member("LUA_CLASS_MEMBER_FUNCTION_");
	std::string macro_endl("\\\n");

	f<<"//member function macros\n";
	for(int i = 0;i<=num;++i)
	{
		std::stringstream  params;
		for(int j = 1; j <= i;++j)
		{
			params <<",P"<<j;
		}
		f<<mem_func_macro_start<<i/*<<"_NON"*/<<"(return_value,func"<<params.str().c_str()<<")"<<macro_endl
			<<tab<<macro_class_member<<i<<"(func,return_value,func"<<params.str().c_str()<<",OOLUA_NON_CONST_FUNC)\n"

			<<mem_func_macro_start<<i<<"_CONST"<<"(return_value,func"<<params.str().c_str()<<")"<<macro_endl
			<<tab<<macro_class_member<<i<<"(func,return_value,func"<<params.str().c_str()<<",OOLUA_CONST_FUNC)\n"

			<<mem_func_macro_start<<i<<"_RENAME"<<"(name,return_value,func"<<params.str().c_str()<<")"<<macro_endl
			<<tab<<macro_class_member<<i<<"(name,return_value,func"<<params.str().c_str()<<",OOLUA_NON_CONST_FUNC)\n"

			<<mem_func_macro_start<<i<<"_CONST_RENAME"<<"(name,return_value,func"<<params.str().c_str()<<")"<<macro_endl
			<<tab<<macro_class_member<<i<<"(name,return_value,func"<<params.str().c_str()<<",OOLUA_CONST_FUNC)\n";
		f <<std::endl <<std::endl;

	}
}

void print_proxy_imps(std::ofstream&f,int num_params)
{
	f<<"//proxy implementations\n";
	std::string macro_endl("\\\n");

	for(int i = 0; i <=num_params;++i)
	{

		f<<"#define LUA_CLASS_MEMBER_FUNCTION_"<<i<<"(func_name,return_value,func";
		std::stringstream  params;
		for(int j = 1; j <= i;++j)
		{
			if(j>1)params<<",";
			params <<"P"<<j;
		}
		if(i>0)f<<","<<params.str().c_str();
		f<<",mod)"<<macro_endl
			<<"int func_name(lua_State* const l)mod"<<macro_endl
			<<"{"<<macro_endl
			<<tab<<"assert(m_this);"<<macro_endl;
		if(i!=0)f<<tab<<"OOLUA_PARAMS_INTERNAL_"<<i<<"("<<params.str().c_str()<<")"<<macro_endl;
		f<<tab<<"typedef INTERNAL::return_type_traits<return_value > R;"<<macro_endl;
		std::stringstream types;
		std::stringstream template_types;
		std::stringstream param_types;
		for(int ii=1; ii<=i;++ii)
		{
			if(ii>1)
			{
				types<<",";
				template_types<<",";
			}
			types<<"P"<<ii<<"_::type";
			template_types<<"P"<<ii<<"_";
			param_types<<",p"<<ii;
		}
		f<<tab<<"typedef R::type (class_::*funcType )("<<types.str().c_str()<<")mod ;"<<macro_endl
	//	f<<tab<<"static R::type (class_::*f )("<<types.str().c_str()<<")mod  = &class_::func;"<<macro_endl
			<<tab<<"OOLUA::INTERNAL::Proxy_caller<R,class_,LVD::is_void< R::type >::value >::call";
		if(i>0)
		{
			f<<"<"<<template_types.str().c_str()<<",funcType>";
		}
		else
		{
			f<<"<funcType>";
		}
		f<<"(l,m_this,&class_::func"<<param_types.str().c_str()<<");"<<macro_endl;
		if(i>0)f<<tab<<"OOLUA_BACK_INTERNAL_"<<i<<macro_endl;
		f<<tab<<"return INTERNAL::lua_return_count< Type_list<R ";
		if(i>0)f<<","<<template_types.str().c_str();
		f<<" >::type> ::out;"<<macro_endl;
		f<<"}\n";
	}
}
void print_c_proxy_imps(std::ofstream&f,int num_params)
{
	f<<"//proxy implementations\n";
	std::string macro_endl("\\\n");
	/*
	#define OOLUA_C_FUNCTION_0(return_value,func) \
	typedef OOLUA::param_type<return_value > R; \
	typedef R::type (*func_ptr)(); \
	OOLUA::Proxy_none_member_caller<R,LVD::is_void<R::type>::value >::call<func_ptr>(l,func); \
	return OOLUA::total_out_params< Type_list<OOLUA::out_p<R::type > >::type> ::out;

	*/
	for(int i = 0; i <=num_params;++i)
	{

		f<<"#define OOLUA_C_FUNCTION_"<<i<<"(return_value,func";
		std::stringstream  params;
		for(int j = 1; j <= i;++j)
		{
			if(j>1)params<<",";
			params <<"P"<<j;
		}
		if(i>0)f<<","<<params.str().c_str();
		f<<") "<<macro_endl;
		if(i!=0)f<<tab<<"OOLUA_PARAMS_INTERNAL_"<<i<<"("<<params.str().c_str()<<")"<<macro_endl;
		f<<tab<<"typedef OOLUA::INTERNAL::return_type_traits<return_value > R;"<<macro_endl;
		std::stringstream types;
		std::stringstream template_types;
		std::stringstream param_types;
		for(int ii=1; ii<=i;++ii)
		{
			if(ii>1)
			{
				types<<",";
				template_types<<",";
			}
			types<<"P"<<ii<<"_::type";
			template_types<<"P"<<ii<<"_";
			param_types<<",p"<<ii;
		}
		f<<tab<<"typedef R::type (funcType)("<<types.str().c_str()<<") ;"<<macro_endl
			<<tab<<"OOLUA::INTERNAL::Proxy_none_member_caller<R,LVD::is_void< R::type >::value >::call";
		if(i>0)
		{
			f<<"<"<<template_types.str().c_str()<<",funcType>";
		}
		else
		{
			f<<"<funcType>";
		}
		f<<"(l,&func"<<param_types.str().c_str()<<");"<<macro_endl;
		if(i>0)f<<tab<<"OOLUA_BACK_INTERNAL_"<<i<<macro_endl;
		f<<tab<<"return OOLUA::INTERNAL::lua_return_count< Type_list<R ";
		if(i>0)f<<","<<template_types.str().c_str();
		f<<" >::type> ::out;"<<macro_endl;
		f<<"\n";
	}
}
void print_uses_params(std::ofstream&f,int num_params)
{
	std::string const oolua_params("OOLUA_USES_PARAMS_");
	f<<"#define " <<oolua_params <<0 <<"\n";
	if(num_params == 0) {f<<"\n\n";return;}
	f<<"#define " <<oolua_params <<1 <<" typename P1,\n";

	for(int i = 2;i<= num_params;++i)
	{
		f<<"#define " <<oolua_params <<i <<" " <<oolua_params <<(i-1)<<" typename P"<<i <<",\n";
	}
	f<<"\n\n";
}
void print_function_params(std::ofstream&f,int num_params)
{
	std::string const oolua_params("OOLUA_FUNCTION_PARAMS_");
	f<<"#define " <<oolua_params <<0 <<"\n";
	if(num_params == 0) {f<<"\n\n";return;}
	f<<"#define " <<oolua_params <<1 <<" P1\n";
	
	for(int i = 2;i<= num_params;++i)
	{
		f<<"#define " <<oolua_params <<i <<" " <<oolua_params <<(i-1)<<" , P"<<i <<"\n";
	}
	f<<"\n\n";
}

void print_template_param_types(std::ofstream&f,int num_params)
{
	std::string const oolua_params("OOLUA_TPARAMS_");
	f<<"#define " <<oolua_params <<0 <<"\n";
	if(num_params == 0) {f<<"\n\n";return;}
	f<<"#define " <<oolua_params <<1 <<" P1_,\n";

	for(int i = 2;i<= num_params;++i)
	{
		f<<"#define " <<oolua_params <<i <<" " <<oolua_params <<(i-1)<<" P"<<i <<"_,\n";
	}
	f<<"\n\n";
}

void print_returns(std::ofstream&f,int num_params)
{
	std::string const oolua_params("OOLUA_RETURNS_");
	f<<"#define " <<oolua_params <<0 <<"\n";
	if(num_params == 0) {f<<"\n\n";return;};
	f<<"#define " <<oolua_params <<1 <<" ,P1_\n";
	
	for(int i = 2;i<= num_params;++i)
	{
		f<<"#define " <<oolua_params <<i <<" " <<oolua_params <<(i-1)<<" ,P"<<i <<"_\n";
	}
	f<<"\n\n";
}

void print_pparams(std::ofstream&f,int num_params)
{
	std::string const oolua_params("OOLUA_PPARAMS_");
	f<<"#define " <<oolua_params <<0 <<"\n";
	if(num_params == 0) {f<<"\n\n";return;}
	f<<"#define " <<oolua_params <<1 <<" ,p1\n";
	
	for(int i = 2;i<= num_params;++i)
	{
		f<<"#define " <<oolua_params <<i <<" " <<oolua_params <<(i-1)<<" ,p"<<i <<"\n";
	}
	f<<"\n\n";
}

void print_default_trait_mem_func_fwd(std::ofstream&f)
{
	f<<"namespace OOLUA\n"
	<<"{\n"
	<<tab<<"namespace INTERNAL\n"
	<<tab<<"{\n"
	<<tab<<tab<<"/*Two structures are used here instead of one and specialising so that compile \n"
	<<tab<<tab<<"errors are forced instead of a runtime error when an incorrect macro is used */\n"
	<<tab<<tab<<"template<typename func_type, typename type = func_type>\n"
	<<tab<<tab<<"struct default_traits_caller;\n"
	<<tab<<tab<<"template<typename func_type, typename type = func_type>\n"
	<<tab<<tab<<"struct default_traits_const_caller;\n"
	<<tab<<"}\n"
	<<"}\n"
	<<"\n\n";
}

void print_default_traits_func(std::ofstream&f,std::string const& name,std::string const& mod)
{
	std::string macro_endl("\\\n");
	f
	<<tab<<tab<<"template <class class_type, typename return_type, OOLUA_USES_PARAMS_##num typename func_type> "<<macro_endl
	<<tab<<tab<<"struct " <<name <<"<return_type (class_type::*) (OOLUA_FUNCTION_PARAMS_##num)"<<mod<<",func_type> "<<macro_endl
	<<tab<<tab<<"{ "<<macro_endl
	<<tab<<tab<<tab<<"typedef OOLUA::INTERNAL::return_type_traits<return_type > R; "<<macro_endl
	<<tab<<tab<<tab<<"static int call (lua_State* l, class_type* this_, func_type mfptr) "<<macro_endl
	<<tab<<tab<<tab<<"{ "<<macro_endl
	<<tab<<tab<<tab<<tab<<"assert(this_); "<<macro_endl
	<<tab<<tab<<tab<<tab<<"OOLUA_PARAMS_T_INTERNAL_##num "<<macro_endl
	<<tab<<tab<<tab<<tab<<"OOLUA::INTERNAL::Proxy_caller< R, class_type, LVD::is_void<return_type >::value >:: template call<OOLUA_TPARAMS_##num func_type>(l,this_,mfptr OOLUA_PPARAMS_##num); "<<macro_endl
	<<tab<<tab<<tab<<tab<<"OOLUA_BACK_INTERNAL_ ##num "<<macro_endl
	<<tab<<tab<<tab<<tab<<"return OOLUA::INTERNAL::lua_return_count<typename Type_list<R OOLUA_RETURNS_##num >::type> ::out; "<<macro_endl
	<<tab<<tab<<tab<<"} "<<macro_endl
	<<tab<<tab<<"}; " <<macro_endl;
}
void print_generate_and_do(std::ofstream&f,int num_params)
{
	std::string macro_endl("\\\n");
	f<<"\n\n"
	<<"#define OOLUA_GENERATE_DEFAULT_TRAIT_CALLER(num) " <<macro_endl
	<<"namespace OOLUA " <<macro_endl
	<<"{ " <<macro_endl
	<<tab<<"namespace INTERNAL " <<macro_endl
	<<tab<<"{ " <<macro_endl;

	
	print_default_traits_func(f,"default_traits_caller","");
	print_default_traits_func(f,"default_traits_const_caller","const");

	f
	<<tab<<"} " <<macro_endl
	<<"}\n"
	<<"\n\n";
	
	for(int i = 0;i <= num_params;++i)
	{
		f<<"OOLUA_GENERATE_DEFAULT_TRAIT_CALLER("<<i<<")\n";
	}
	f<<"\n\n";
}
void print_default_trait_member_function_macros(std::ofstream&f,int num_params)
{
	f<<"\n\n//member functions using default traits\n";
	//write out the macros needed for the default traits caller macro
	print_uses_params(f,num_params);
	print_function_params(f,num_params);
	print_template_param_types(f,num_params);
	print_returns(f,num_params);
	print_pparams(f,num_params);
	
	print_default_trait_mem_func_fwd(f);
	print_generate_and_do(f,num_params);
	
	f
	<<"namespace OOLUA\n"
	<<"{\n"
	<<tab<<"namespace INTERNAL\n"
	<<tab<<"{\n"
	<<tab<<tab<<"template<typename this_type,typename func_type>\n"
	<<tab<<tab<<"int proxy_member_function_with_default_traits(lua_State* l,this_type* this_,func_type mfptr)\n"
	<<tab<<tab<<"{\n"
	<<tab<<tab<<tab<<"return default_traits_caller<func_type>::call(l,this_,mfptr);\n"
	<<tab<<tab<<"}\n"
	<<tab<<tab<<"template<typename this_type,typename func_type>\n"
	<<tab<<tab<<"int proxy_const_member_function_with_default_traits(lua_State* l,this_type* this_,func_type mfptr)\n"
	<<tab<<tab<<"{\n"
	<<tab<<tab<<tab<<"return default_traits_const_caller<func_type>::call(l,this_,mfptr);\n"
	<<tab<<tab<<"}\n"
	<<tab<<"}\n"
	<<"}\n\n";
	
	//finally define the macros for the user
	std::string macro_endl("\\\n");
	f
	<<"#define OOLUA_DEDUCE_FUNC(Name) "<<macro_endl
	<<"int Name(lua_State* l) "<<macro_endl
	<<"{ "<<macro_endl
	<<tab<<"return OOLUA::INTERNAL::proxy_member_function_with_default_traits(l, m_this, &class_::Name); "<<macro_endl
	<<"}\n\n"
	
	<<"#define OOLUA_DEDUCE_FUNC_CONST(Name) "<<macro_endl
	<<"int Name(lua_State* l)const "<<macro_endl
	<<"{ "<<macro_endl
	<<tab<<"return OOLUA::INTERNAL::proxy_const_member_function_with_default_traits(l, m_this, &class_::Name); "<<macro_endl
	<<"}\n";
}

void paramater_helper_macros(std::string & save_directory,int noOfParams)
{
	std::string fileName("oolua_paramater_macros.h");
	std::string file = save_directory + fileName;
	std::ofstream f( file.c_str() );
	add_file_header(f,fileName);
	include_guard_top(f,"OOLUA_PARAMETER_MACROS_H_");
	
	include_header(f,"oolua_config.h");

	print_back_helper_macros(f,noOfParams);
	print_param_macros(f,noOfParams);
	print_default_trait_param_macros(f,noOfParams);
	include_guard_bottom(f);

}

void c_function_header(std::string & save_directory,int noOfParams)
{
	std::string fileName("oolua_c_func.h");
	std::string file = save_directory + fileName;
	std::ofstream f( file.c_str() );
	add_file_header(f,fileName);
	include_guard_top(f,"OOLUA_C_FUNC_H_");

	include_header(f,"param_traits.h");
	include_header(f,"oolua_paramater_macros.h");
	include_header(f, "proxy_caller.h");

	print_c_proxy_imps(f,noOfParams);
	include_guard_bottom(f);
}
void cpp_member_func_header(std::string & save_directory,int noOfParams)
{
	std::string fileName("cpp_member_func.h");
	std::string file = save_directory + fileName;
	std::ofstream f( file.c_str() );
	add_file_header(f,fileName);
	include_guard_top(f,"CPP_MEMBER_FUNC_H_");

	include_header(f,"param_traits.h");
	include_header(f,"oolua_paramater_macros.h");
	include_header(f,"proxy_caller.h");
	f<<"#\tinclude <cassert>\n";
	
	/*
	f<<"#ifdef _MSC_VER \n"
		<<"#"<<tab<<"define MSC_PUSH_DISABLE_CONDTIONAL_CONSTANT \\\n"
		<<tab<<"__pragma(warning(push)) \\\n"
		<<tab<<"__pragma(warning(disable : 4127)) \n"
		<<"#"<<tab<<"define MSC_POP_COMPILER_WARNING \\\n"
		<<tab<<"__pragma(warning(pop)) \n"
		<<"#else\n"
		<<"#"<<tab<<"define MSC_PUSH_DISABLE_CONDTIONAL_CONSTANT \n"
		<<"#"<<tab<<"define MSC_POP_COMPILER_WARNING \n"
		<<"#endif\n";


	*/

	f<<"#define OOLUA_CONST_FUNC const\n"
	<<"#define OOLUA_NON_CONST_FUNC\n";
	f<<"\n";

	print_mem_funcs(f,noOfParams);
	//print_back_helper_macros(f,noOfParams);
	//print_param_macros(f,noOfParams);
	print_proxy_imps(f,noOfParams);

	print_default_trait_member_function_macros(f,noOfParams);
	//print_c_proxy_imps(f,noOfParams);

	include_guard_bottom(f);

	paramater_helper_macros(save_directory,noOfParams);
	c_function_header(save_directory,noOfParams);
}

