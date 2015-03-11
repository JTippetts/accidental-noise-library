#ifndef CPP_CONSTRUCTOR_MOCK_OOLUA_H_
# define CPP_CONSTRUCTOR_MOCK_OOLUA_H_


#include "cpp_stub_classes.h"
#include "oolua.h"


namespace ParamValues
{
	extern const int int_not_set;
	extern const int int_set;
	extern const bool bool_not_set;
	extern const bool bool_set;
	extern const std::string string_not_set;
	extern const std::string string_set;
	extern const char* c_string_not_set;
	extern const char*  c_string_set;

}

class ParamConstructor 
{
public:
	ParamConstructor(int i)
	:m_int(i)
	,m_bool(ParamValues::bool_not_set)
	,m_int_ptr(ParamValues::int_not_set)
	,m_string(ParamValues::string_not_set)
	,m_stub1(0)
	,m_stub2(0)
	,m_stub_passed_by_value(ParamValues::bool_not_set){}
	
	ParamConstructor(bool b)
	:m_int(ParamValues::int_not_set)
	,m_bool(b)
	,m_int_ptr(ParamValues::int_not_set)
	,m_string(ParamValues::string_not_set)
	,m_stub1(0)
	,m_stub2(0)
	,m_stub_passed_by_value(ParamValues::bool_not_set){}
	
	
	ParamConstructor(int *  i)
	:m_int(ParamValues::int_not_set)
	,m_bool(ParamValues::bool_not_set)
	,m_int_ptr(*i)
	,m_string(ParamValues::string_not_set)
	,m_stub1(0)
	,m_stub2(0)
	,m_stub_passed_by_value(ParamValues::bool_not_set){}
	
	ParamConstructor(char const *  str)
	:m_int(ParamValues::int_not_set)
	,m_bool(ParamValues::bool_not_set)
	,m_int_ptr(ParamValues::int_not_set)
	,m_string(str)
	,m_stub1(0)
	,m_stub2(0)
	,m_stub_passed_by_value(ParamValues::bool_not_set){}
	
	
	ParamConstructor(int i,bool b)
	:m_int(i)
	,m_bool(b)
	,m_int_ptr(ParamValues::int_not_set)
	,m_string(ParamValues::string_not_set)
	,m_stub1(0)
	,m_stub2(0)
	,m_stub_passed_by_value(ParamValues::bool_not_set){}
	
	
	ParamConstructor(Stub1* stub)
	:m_int(ParamValues::int_not_set)
	,m_bool(ParamValues::bool_not_set)
	,m_int_ptr(ParamValues::int_not_set)
	,m_string(ParamValues::string_not_set)
	,m_stub1(stub)
	,m_stub2(0)
	,m_stub_passed_by_value(ParamValues::bool_not_set){}
	
	
	ParamConstructor(Stub1* stub1,Stub2 * stub2)
	:m_int(ParamValues::int_not_set)
	,m_bool(ParamValues::bool_not_set)
	,m_int_ptr(ParamValues::int_not_set)
	,m_string(ParamValues::string_not_set)
	,m_stub1(stub1)
	,m_stub2(stub2)
	,m_stub_passed_by_value(ParamValues::bool_not_set){}
	
	ParamConstructor(Stub2 /*stub2*/)
	:m_int(ParamValues::int_not_set)
	,m_bool(ParamValues::bool_not_set)
	,m_int_ptr(ParamValues::int_not_set)
	,m_string(ParamValues::string_not_set)
	,m_stub1(0)
	,m_stub_passed_by_value(ParamValues::bool_set){}
	
	ParamConstructor(Stub3 const * /*stub3*/)
	:m_int(ParamValues::int_not_set)
	,m_bool(ParamValues::bool_not_set)
	,m_int_ptr(ParamValues::int_not_set)
	,m_string(ParamValues::string_not_set)
	,m_stub1(0)
	,m_stub_passed_by_value(ParamValues::bool_not_set)
	,m_const_stub3(ParamValues::bool_set)
	,m_stub3(ParamValues::bool_not_set){}
	
	ParamConstructor(Stub3 * /*stub3*/)
	:m_int(ParamValues::int_not_set)
	,m_bool(ParamValues::bool_not_set)
	,m_int_ptr(ParamValues::int_not_set)
	,m_string(ParamValues::string_not_set)
	,m_stub1(0)
	,m_stub_passed_by_value(ParamValues::bool_not_set)
	,m_const_stub3(ParamValues::bool_not_set)
	,m_stub3(ParamValues::bool_set){}
	
	
	ParamConstructor(OOLUA::Lua_func_ref ref)
	:m_int(ParamValues::int_not_set)
	,m_bool(ParamValues::bool_not_set)
	,m_int_ptr(ParamValues::int_not_set)
	,m_string(ParamValues::string_not_set)
	,m_stub1(0)
	,m_stub2(0)
	,m_stub_passed_by_value(ParamValues::bool_not_set)
	,m_func_ref(ref){}
	
	ParamConstructor(OOLUA::Lua_table ref)
	:m_int(ParamValues::int_not_set)
	,m_bool(ParamValues::bool_not_set)
	,m_int_ptr(ParamValues::int_not_set)
	,m_string(ParamValues::string_not_set)
	,m_stub1(0)
	,m_stub2(0)
	,m_stub_passed_by_value(ParamValues::bool_not_set)
	,m_func_ref()
	,m_table(ref){}
	
	int m_int;
	bool m_bool;
	int m_int_ptr;
	std::string m_string;
	Stub1* m_stub1;
	Stub2* m_stub2;
	bool m_stub_passed_by_value;
	bool m_const_stub3;
	bool m_stub3;
	OOLUA::Lua_func_ref m_func_ref;
	OOLUA::Lua_table m_table;
};

class WithOutConstructors
{
public:
	static WithOutConstructors* create()
	{
		return new WithOutConstructors;
	}
private:
	WithOutConstructors(){}
	WithOutConstructors(WithOutConstructors const&);
};

class TableRefConstructor
{
public:
	TableRefConstructor(OOLUA::Lua_table_ref ref)
	:m_table_ref(ref){}
	OOLUA::Lua_table_ref m_table_ref;
};
/*
Order can not be differentiated between 
(lua_State*, int) or (int, lua_State*)


(int, int lua_State)
	or (int, lua_State, int)
	or (lua_State, int, int)
	or (lua_State, int, float)
...
*/
struct LuaStateConstructors
{
	LuaStateConstructors(lua_State* l):lua(l),m_int(ParamValues::int_not_set){}
	LuaStateConstructors(int i,lua_State*l):lua(l),m_int(i){}
	lua_State* lua;
	int m_int;
};




#endif
