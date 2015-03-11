///////////////////////////////////////////////////////////////////////////////
///  @file lua_table.h
///  Wrapper around a table in Lua which allows quick and easy access.
///  @author Liam Devine
///  @email
///  See http://www.liamdevine.co.uk for contact details.
///  @licence
///  See licence.txt for more details. \n 
///////////////////////////////////////////////////////////////////////////////
#ifndef LUA_TABLE_H_
#	define LUA_TABLE_H_

#	include "lua_includes.h"
#	include <string>
#	include "fwd_push_pull.h"
#	include "lua_ref.h"
#	include "oolua_config.h"
#	include "oolua_error.h"


namespace OOLUA
{
	///////////////////////////////////////////////////////////////////////////////
	///  @class Lua_table
	///  Wrapper around a table in Lua which allows quick and easy access.
	///
	///  @remarks
	///  Any value can be retrieved or set from the table via the use of the template
	///  member function. If the value asked for is not the correct type located
	///  in the position then the functions used throw an error.
    ///  at: 
    ///  runs no checks on the table. Undefined if Lua instance is null or 
    ///  (table or key is invalid) or value is not correct type.
    ///  safe_at:
    ///  returns a bool to indicate for success.
    ///  try_at:
    ///  Function is only defined when exceptions are enabled.
    ///  throws Runtime_error when the key is not in the table
    ///
	///  The functions guarantee that the Lua stack after operations is restored
	///  to the state when entered.
    ///
    ///  See Unit Tests or CheatSheet for usage of constructor.
	///////////////////////////////////////////////////////////////////////////////
	class Lua_table
	{
	public:
		Lua_table();
		explicit Lua_table(Lua_table_ref const& ref);
		~Lua_table()OOLUA_DEFAULT;
		Lua_table(lua_State*  const lua,std::string const& name);
		void bind_script(lua_State*  const lua);
		void set_table(std::string const& name);
		Lua_table& operator =(Lua_table const& /*rhs*/);//unimplemented
		Lua_table(Lua_table const& rhs);
#if OOLUA_USE_EXCEPTIONS ==1 
		template<typename T,typename T1>void try_at(T const& key,T1& value);
#endif
		template<typename T,typename T1>bool safe_at(T const& key,T1& value);
		//no error checking
		//undefined if lua is null or (table or key is invalid) or value is not correct type
		template<typename T,typename T1>T1& at(T const& key,T1& value);
		template<typename T,typename T1>void set_value(T const& key,T1 const& value);
		template<typename T>void remove_value(T const& key);
		
		bool valid()const;
		void set_ref(lua_State* const lua,int const& ref);
		typedef void(*traverse_do_function)(lua_State*);
		void traverse(traverse_do_function do_);
		
		bool push_on_stack(lua_State* l)const;
		void swap(Lua_table & rhs);
		bool pull_from_stack(lua_State* l);
		void lua_pull_from_stack(lua_State* l);
		lua_State* state() const { return m_table_ref.m_lua; }
	private:
		bool get_table()const;
		void restore_stack(int const & init_stack_size)const;
		int initial_stack_size()const;
		Lua_table_ref m_table_ref;
	};

	inline Lua_table::~Lua_table(){}
	
	
	//no error checking
	//undefined if lua is null or (table or key is invalid) or value is not correct type
	template<typename T,typename T1>
	inline T1& Lua_table::at(T const& key,T1& value)
	{
		get_table();//table
		push2lua(m_table_ref.m_lua,key);//table key
		lua_gettable(m_table_ref.m_lua, -2);//table value
		pull2cpp(m_table_ref.m_lua, value);//table
		lua_pop(m_table_ref.m_lua,1);
		return value;
	}
	
	template<typename T,typename T1>
	inline void Lua_table::set_value(T const& key,T1 const& value)
	{
		//record the stack size as we want to put the stack into the 
		//same state that it was before entering here
		//int init_stack_size = lua_gettop(m_lua);
		int const init_stack_size = initial_stack_size();
		if(!get_table())return;
		push2lua(m_table_ref.m_lua,key);
		//table is now at -2 (key is at -1). 
		//push the new value onto the stack
		push2lua(m_table_ref.m_lua,value);
		//table is not at -3 set the table
		lua_settable(m_table_ref.m_lua,-3);
		
		restore_stack(init_stack_size);
	}
	
	template<typename T>
	inline void Lua_table::remove_value(T const& key)
	{
		//record the stack size as we want to put the stack into the 
		//same state that it was before entering here
		//int init_stack_size = lua_gettop(m_lua);
		int const init_stack_size = initial_stack_size();
		if(!get_table())return;
		push2lua(m_table_ref.m_lua,key);
		//table is now at -2 (key is at -1). 
		//push the new value onto the stack
		lua_pushnil(m_table_ref.m_lua);
		//table is not at -3 set the table
		lua_settable(m_table_ref.m_lua,-3);
		
		restore_stack(init_stack_size);
	}
	
	
#if OOLUA_USE_EXCEPTIONS ==1 
	template<typename T,typename T1>
	inline void Lua_table::try_at(T const& key,T1& value)
	{
		int const init_stack_size = initial_stack_size();
		try 
		{
			if(!get_table())throw OOLUA::Runtime_error("Table is invalid");
			push2lua(m_table_ref.m_lua,key);
			lua_gettable(m_table_ref.m_lua, -2);
			if(lua_type(m_table_ref.m_lua,-1) == LUA_TNIL )
			{
				throw OOLUA::Runtime_error("key is not present in table");
			}
			pull2cpp(m_table_ref.m_lua, value);
			restore_stack(init_stack_size);
		}
		
		catch (...) 
		{
			restore_stack(init_stack_size);
			throw;
		}
		
		
	}
	template<typename T,typename T1>
	inline bool Lua_table::safe_at(T const& key,T1& value)
	{
		try
		{
			try_at(key, value);
		}
		catch (...)
		{
			return false;
		}
		return true;
	}
#else
	
	template<typename T,typename T1>
	inline bool Lua_table::safe_at(T const& key,T1& value)
	{
		//record the stack size as we want to put the stack into the 
		//same state that it was before entering here
		//int init_stack_size = lua_gettop(m_lua);
		int const init_stack_size = initial_stack_size();
		if(!get_table())return false;
		if(! push2lua(m_table_ref.m_lua,key) )
		{
			restore_stack(init_stack_size);
			return false;
		}
		//table is now at -2 (key is at -1). lua_gettable now pops the key off
		//the stack and then puts the data found at the key location on the stack
		lua_gettable(m_table_ref.m_lua, -2);
		if(lua_type(m_table_ref.m_lua,-1) == LUA_TNIL )
		{
			restore_stack(init_stack_size);
			return false;
		}
		pull2cpp(m_table_ref.m_lua, value);
		restore_stack(init_stack_size);
		
		return true;
	}
#endif
	
	
	//the table is at table_index which can be either absolute or pseudo in the stack
	//table is left at the index.
	template<typename T,typename T1>
	inline void table_set_value(lua_State* lua,int table_index,T const& key,T1 const& value)
	{
		push2lua(lua,key);
		push2lua(lua,value);
		lua_settable(lua,table_index < 0 ? table_index-2 : table_index);
	}

    template<typename T,typename T1>
	inline bool table_at(lua_State* lua, int const table_index, T const& key,T1& value)
	{
		push2lua(lua,key);//table key
		lua_gettable(lua, table_index < 0 ? table_index-1 : table_index);//table value
		return pull2cpp(lua, value);//table
	}
    
	//stack is the same on exit as entry
	void new_table(lua_State* l,OOLUA::Lua_table& t);
	OOLUA::Lua_table new_table(lua_State* l);
	
	
	/*
	 oolua_ipairs
	 Helper for iterating over the array part of a table
	 declares 
	 _i_index_				: current index into the array
	 _oolua_array_index_	: stack index at which table is located
	 lvm					: the table's lua_State
	 
	 NOTE: Returning from inside of the loop will not leave the stack clean
	 unless you reset it.
	 usage:
	 oolua_ipairs(table)
	 {
		if(_i_index_ == 99) 
		{
			lua_settop(lvm,_oolua_array_index-1);
			return red_balloons;
		}
	 }
	 oolua_ipairs_end()
	 */
#	define oolua_ipairs(table) \
	if( table.valid() ) \
	{ \
		lua_State* lvm = table.state(); \
		lua_checkstack(lvm, 2);\
		OOLUA::push2lua(lvm,table); \
		int const _oolua_array_index_ = lua_gettop(lvm); \
		int _i_index_ = 1; \
		lua_rawgeti(lvm, _oolua_array_index_,_i_index_); \
		while (lua_type(lvm, -1)  != LUA_TNIL) \
		{ \

#	define oolua_ipairs_end()\
			lua_settop(lvm, _oolua_array_index_); \
			lua_rawgeti(lvm, _oolua_array_index_,++_i_index_); \
		} \
		lua_settop(lvm,_oolua_array_index_-1); \
	}

	
	
	/*
	 oolua_pairs
	 Helper for iterating over a table.
	 declares
	 _oolua_table_index_	: stack index at which table is located
	 lvm					: the table's lua_State
	 
	 usage
	 oolua_pairs(table)
	 {
		do what ever
		lua_pop(value);leaving key at the top of stack
	 }
	 oolua_pairs_end()
	 */
	
#	define oolua_pairs(table) \
	if( table.valid() ) \
	{ \
		lua_State* lvm = table.state(); \
		OOLUA::push2lua(lvm,table); \
		int	const _oolua_table_index_ = lua_gettop(lvm); \
		lua_pushnil(lvm); \
		while (lua_next(lvm, _oolua_table_index_) != 0) 
	
#	define oolua_pairs_end() \
		lua_pop(lvm, 1); \
	}
	
	
	/*
	 you must remove the value from the stack and leave the key
	 do not call anything which may call tostring on the actual key
	 duplicate it instead with lua_pushvalue then call the operation on the copy
	 */
	template<typename ClassType>
	inline void for_each_key_value(OOLUA::Lua_table& table, ClassType* instance, void(ClassType::*func)(lua_State*) )
	{
		oolua_pairs(table)
		{
			(instance->*(func))(lvm);
		}
		oolua_pairs_end()
	}
}

#endif


