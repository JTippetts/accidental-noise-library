
#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "common_cppunit_headers.h"
#	include <sstream>
#	include "expose_stub_classes.h"
#	include "expose_functions_with_ref_params.h"

namespace
{
	template<typename T>
	std::string stringify(T const& t)
	{
		std::stringstream ss;
		ss <<t;
		return ss.str();
	}
	template<typename T>
	void table_containing_key_value_pair(OOLUA::Script * lvm,OOLUA::Lua_table* t,std::string const& key,T& value)
	{
		lvm->run_chunk(
			std::string("func = function() ")
				+std::string("t = {} ")
				+std::string("t[\"") + key + std::string("\"]=") + stringify(value)
				+std::string(" return t ")
			+std::string("end") );

		lvm->call("func");
		OOLUA::pull2cpp(*lvm,*t);
	}
	void assign_valid_table(OOLUA::Script* s,OOLUA::Lua_table& t)
	{
		s->register_class<Stub1>();
		lua_getfield(*s, LUA_REGISTRYINDEX,OOLUA::Proxy_class<Stub1>::class_name);
		OOLUA::pull2cpp(*s,t);
	}
	
	int stackNotEmptyCalled = 0;
	void callBackFunc_stackNotEmpty(lua_State*)
	{
		stackNotEmptyCalled = 1;
	}
	
	struct MemberCallBack
	{
		int called;
		MemberCallBack():called(0){}
		void call_back(lua_State* l)
		{
			called += 1;
			lua_pop(l,1);
		}
	};
	}

	
class Table : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(Table);
		CPPUNIT_TEST(at_checkForKeyWhichIsValid_valueComparesEqualToInput);
		CPPUNIT_TEST(safeAt_checkForKeyWhichIsInvalid_returnsFalse);
		CPPUNIT_TEST(safeAt_checkForKeyWhichIsValid_valueComparesEqual);
		CPPUNIT_TEST(safeAt_checkForKeyWhichIsValid_returnsTrue);
	
	CPPUNIT_TEST(safeAt_checkForInvalidKeyWhichIsATableFromADifferentLuaState_returnsFalse);
			
		CPPUNIT_TEST(remove_valueWhichIsValid_safeAtReturnsFalse);
		CPPUNIT_TEST(pull_pullValidTableOffStack_stackIsEmptyAfterCall);
		CPPUNIT_TEST(getTable_pullValidTableOffStackAndCallFunc_stackSizeIsOne);
		CPPUNIT_TEST(valid_pullValidTableOffStackAndCallFunc_resultIsTrue);
		CPPUNIT_TEST(valid_pullValidTableOffStackAndCallFunc_stackIsEmptyAfterCall);
		CPPUNIT_TEST(valid_assignedNullLuaPointer_resultIsFalse);
		CPPUNIT_TEST(valid_defaultConstructed_resultIsFalse);
		CPPUNIT_TEST(valid_constructedWithValidLuaPointAndValidGlobalName_resultIsTrue);
		CPPUNIT_TEST(valid_assignedNullLuaPointer_resultIsFalse);
		CPPUNIT_TEST(valid_assignedValidLuaPointer_resultIsFalse);
		CPPUNIT_TEST(valid_assignedValidLuaPointerAndValidGlobalName_resultIsTrue);
		CPPUNIT_TEST(valid_assignedValidLuaPointerAndValidGlobalName_stackIsEmptyAfterCall);
		
		CPPUNIT_TEST(newTable_callValidOnTable_returnsTrue);
		CPPUNIT_TEST(newTable_checkStack_stackIsEmpty);
		CPPUNIT_TEST(newTable_constructAndCheckStack_afterCallStackIsEmpty);
		CPPUNIT_TEST(newTable_fromCplusplus_validReturnsTrue);
	
		CPPUNIT_TEST(copyConstruct_usingNewTable_copyIsValid);
		CPPUNIT_TEST(copyConstruct_usingNewTable_orginalIsValid);
		CPPUNIT_TEST(copyConstruct_usingInvalidTable_copyIsNotValid);
		
		CPPUNIT_TEST(tableSetValue_tableIsOnTop_storedValueIsCorrect);
		CPPUNIT_TEST(tableSetValue_tableIsOnTop_afterCallStackHasOneEntry);
	
		CPPUNIT_TEST(setValue_valueSetInLua_cppSideRepresentationHasChange);

		CPPUNIT_TEST(table_reference_is_unquie_for_the_instance);
	
		CPPUNIT_TEST(registerClass_memberFunctiontakesTable_compiles);
		CPPUNIT_TEST(callFunction_memberFunctiontakesTable_noErrors);
	
		CPPUNIT_TEST(construct_LuaTableFromLuaTableRef_compiles);
		
		CPPUNIT_TEST(callFunction_memberFunctiontakesTableYetPassedNilReturnsValidityOfTable_returnsFalse);
	
	CPPUNIT_TEST(valid_assignedValidLuaPointerAndInvalidName_resultIsFalse);
	
	CPPUNIT_TEST(valid_assignedValidLuaPointerAndEmptyStringName_resultIsFalse);
	
#if OOLUA_STORE_LAST_ERROR == 1
	CPPUNIT_TEST(callFunction_memberFunctionWhichTakesTableYetPassedInt_callReturnsFalse);
#endif
	
#if OOLUA_USE_EXCEPTIONS == 1
	CPPUNIT_TEST(callFunction_memberFunctionWhichTakesTableYetPassedInt_throwsRuntimeError);
#endif

	CPPUNIT_TEST(bindScript_tableReferenceIsAlreadyValid_validReturnsFalse);
	
	CPPUNIT_TEST(bindScript_tableReferenceIsAlreadyBoundWithThisState_validReturnsTrue);
	
	CPPUNIT_TEST(traverse_stackIsNotEmpty_callBackIsCalled);
	CPPUNIT_TEST(forEachKeyValue_stackIsNotEmpty_callBackIsCalled);

	
	CPPUNIT_TEST(ipairs_stackIsNotEmptyTableHasOneEntry_IterationCountIsOne);
	CPPUNIT_TEST(ipairs_stackIsNotEmptyTableHasFiveEntry_IterationCountIsFive);
	CPPUNIT_TEST(ipairs_stackHasOneEntryTableHasFiveEntry_afterIterationsStackCountIsOne);
	
	CPPUNIT_TEST_SUITE_END();

	OOLUA::Script * m_lua;
	OOLUA::Lua_table* table;
public:
    Table():m_lua(0),table(0){}
    Table(Table const&);
    Table& operator =(Table const&);
	void setUp()
	{
		m_lua = new OOLUA::Script;
		table = new OOLUA::Lua_table;
	}
	void tearDown()
	{
		delete table;
		delete m_lua;
	}
	void at_checkForKeyWhichIsValid_valueComparesEqualToInput()
	{
		int input(1);
		int value(0);
		table_containing_key_value_pair(m_lua,table,"key",input);
		table->at("key",value);
		CPPUNIT_ASSERT_EQUAL(input, value);
	}
	void safeAt_checkForKeyWhichIsInvalid_returnsFalse()
	{
		m_lua->run_chunk(
			"func = function()"
				"t = {} "
				"return t "
			"end");
		m_lua->call("func");
		OOLUA::pull2cpp(*m_lua,*table);
		int value(0);
		CPPUNIT_ASSERT_EQUAL(false, table->safe_at("key",value));
	}
	void safeAt_checkForInvalidKeyWhichIsATableFromADifferentLuaState_returnsFalse()
	{
		OOLUA::new_table(*m_lua,*table);
		OOLUA::Script s;
		OOLUA::Lua_table t;
		OOLUA::new_table(s,t);
		int value(0);
		CPPUNIT_ASSERT_EQUAL(false, table->safe_at(t,value));
	}
	
	void safeAt_checkForKeyWhichIsValid_returnsTrue()
	{
		int input(1);
		int value(0);
		table_containing_key_value_pair(m_lua,table,"key",input);
		CPPUNIT_ASSERT_EQUAL(true, table->safe_at("key",value));
	}
	void safeAt_checkForKeyWhichIsValid_valueComparesEqual()
	{
		int input(1);
		int value(0);
		table_containing_key_value_pair(m_lua,table,"key",input);
		table->safe_at("key",value);
		CPPUNIT_ASSERT_EQUAL(input, value);
	}
	void remove_valueWhichIsValid_safeAtReturnsFalse()
	{
		int input(1);
		int value(0);
		table_containing_key_value_pair(m_lua,table,"key",input);
		table->remove_value("key");
		CPPUNIT_ASSERT_EQUAL(false, table->safe_at("key",value) );
	}
	
	void pull_pullValidTableOffStack_stackIsEmptyAfterCall()
	{
		assign_valid_table(m_lua,*table);
		CPPUNIT_ASSERT_EQUAL(int(0), lua_gettop(*m_lua) );
	}
	void getTable_pullValidTableOffStackAndCallFunc_stackSizeIsOne()
	{
		assign_valid_table(m_lua,*table);
		table->push_on_stack(*m_lua);
		CPPUNIT_ASSERT_EQUAL(int(1), lua_gettop(*m_lua) );
	}
	void valid_pullValidTableOffStackAndCallFunc_resultIsTrue()
	{
		assign_valid_table(m_lua,*table);
		CPPUNIT_ASSERT_EQUAL(true, table->valid() );
	}
	void valid_pullValidTableOffStackAndCallFunc_stackIsEmptyAfterCall()
	{
		assign_valid_table(m_lua,*table);
		table->valid();
		CPPUNIT_ASSERT_EQUAL(int(0), lua_gettop(*m_lua) );
	}
	void valid_defaultConstructed_resultIsFalse()
	{
		CPPUNIT_ASSERT_EQUAL(false, table->valid() );
	}
	void valid_constructedWithValidLuaPointAndValidGlobalName_resultIsTrue()
	{
		m_lua->register_class<Stub1>();
		OOLUA::Lua_table t(*m_lua,OOLUA::Proxy_class<Stub1>::class_name);
		CPPUNIT_ASSERT_EQUAL(true, t.valid() );
	}
	void valid_assignedNullLuaPointer_resultIsFalse()
	{
		table->bind_script(0);
		CPPUNIT_ASSERT_EQUAL(false, table->valid() );
	}
	void valid_assignedValidLuaPointer_resultIsFalse()
	{
		table->bind_script(*m_lua);
		CPPUNIT_ASSERT_EQUAL(false, table->valid() );
	}
	void valid_assignedValidLuaPointerAndValidGlobalName_resultIsTrue()
	{
		m_lua->register_class<Stub1>();
		table->bind_script(*m_lua);
		table->set_table(OOLUA::Proxy_class<Stub1>::class_name);
		CPPUNIT_ASSERT_EQUAL(true, table->valid() );
	}
	void valid_assignedValidLuaPointerAndValidGlobalName_stackIsEmptyAfterCall()
	{
		m_lua->register_class<Stub1>();
		table->bind_script(*m_lua);
		table->set_table(OOLUA::Proxy_class<Stub1>::class_name);
		table->valid();
		CPPUNIT_ASSERT_EQUAL(0,lua_gettop(*m_lua) );
	}
	
	void valid_assignedValidLuaPointerAndInvalidName_resultIsFalse()
	{
		table->bind_script(*m_lua);
		table->set_table("Does not exist");
		CPPUNIT_ASSERT_EQUAL(false, table->valid() );
	}
	void valid_assignedValidLuaPointerAndEmptyStringName_resultIsFalse()
	{
		table->bind_script(*m_lua);
		table->set_table("");
		CPPUNIT_ASSERT_EQUAL(false, table->valid() );
	}
	void newTable_callValidOnTable_returnsTrue()
	{
		CPPUNIT_ASSERT_EQUAL(true, OOLUA::new_table(*m_lua).valid() );
	}
	void newTable_checkStack_stackIsEmpty()
	{
		OOLUA::new_table(*m_lua);
		int stackSize = lua_gettop(*m_lua);
		CPPUNIT_ASSERT_EQUAL(0, stackSize );
	}
	void newTable_fromCplusplus_validReturnsTrue()
	{
		OOLUA::Lua_table t;
		OOLUA::new_table(*m_lua,t);
		CPPUNIT_ASSERT_EQUAL(true,t.valid() );
	}
	void newTable_constructAndCheckStack_afterCallStackIsEmpty()
	{
		OOLUA::Lua_table t;
		OOLUA::new_table(*m_lua,t);
		int stackSize = lua_gettop(*m_lua);
		CPPUNIT_ASSERT_EQUAL(0, stackSize );
	}
	void copyConstruct_usingNewTable_orginalIsValid()
	{
		OOLUA::Lua_table orignal;
		OOLUA::new_table(*m_lua,orignal);
		OOLUA::Lua_table copy(orignal);

		CPPUNIT_ASSERT_EQUAL(true, orignal.valid() );
	}
	
	void copyConstruct_usingNewTable_copyIsValid()
	{
		OOLUA::Lua_table copy(OOLUA::new_table(*m_lua));
		CPPUNIT_ASSERT_EQUAL(true, copy.valid() );
	}
	void copyConstruct_usingInvalidTable_copyIsNotValid()
	{
		OOLUA::Lua_table invalid;
		OOLUA::Lua_table copy(invalid);
		CPPUNIT_ASSERT_EQUAL(false, copy.valid() );
	}
	void tableSetValue_tableIsOnTop_storedValueIsCorrect()
	{
		OOLUA::Lua_table t;
		OOLUA::new_table(*m_lua,t);
		t.push_on_stack(*m_lua);
		OOLUA::table_set_value(*m_lua,-1,"a",0);
		int storedValue(1);
		t.at("a",storedValue);
		lua_pop(*m_lua,1);
		CPPUNIT_ASSERT_EQUAL(0,storedValue );
	}

	void tableSetValue_tableIsOnTop_afterCallStackHasOneEntry()
	{
		OOLUA::Lua_table t;
		OOLUA::new_table(*m_lua,t);
		t.push_on_stack(*m_lua);
		OOLUA::table_set_value(*m_lua,-1,"a",1);
		int stackSize = lua_gettop(*m_lua);
		CPPUNIT_ASSERT_EQUAL(1, stackSize );
	}
	void setValue_valueSetInLua_cppSideRepresentationHasChange()
	{
		OOLUA::Lua_table t;
		OOLUA::new_table(*m_lua,t);
		
		m_lua->run_chunk("func = function(t) t[\"a\"]=1; end");
		m_lua->call("func",t);
		
		int storedValue(0);
		t.at("a",storedValue);
		CPPUNIT_ASSERT_EQUAL(1, storedValue );
	}
	
	void table_reference_is_unquie_for_the_instance()
	{		
		lua_newtable(*m_lua);
		int tableRef = luaL_ref(*m_lua, LUA_REGISTRYINDEX);
		lua_rawgeti(*m_lua, LUA_REGISTRYINDEX, tableRef );
		int tableRef2 = luaL_ref(*m_lua, LUA_REGISTRYINDEX);
		
		CPPUNIT_ASSERT_EQUAL(true, tableRef != tableRef2 );
	}
	
	void registerClass_memberFunctiontakesTable_compiles()
	{
		m_lua->register_class<TableMemberFunction>();
		
	}
	void callFunction_memberFunctiontakesTable_noErrors()
	{
		m_lua->register_class<TableMemberFunction>();
		
		OOLUA::Lua_table table_;
		OOLUA::new_table(*m_lua,table_);
		TableMemberFunction obj;
		
		bool res = m_lua->run_chunk("func = function(obj,t) obj:function_which_takes_a_table(t) end");
		CPPUNIT_ASSERT_EQUAL(true, res );
		res =  m_lua->call("func",&obj,table_);
		CPPUNIT_ASSERT_EQUAL(true, res );

	}
	void construct_LuaTableFromLuaTableRef_compiles()
	{
		m_lua->run_chunk("func = function() local t={} return t end");
		m_lua->call("func");
		OOLUA::Lua_table_ref ref;
		OOLUA::pull2cpp(*m_lua,ref);
		OOLUA::Lua_table t(ref);
		
	}
	void callFunction_memberFunctiontakesTableYetPassedNilReturnsValidityOfTable_returnsFalse()
	{
		
		m_lua->register_class<TableMemberFunction>();
		TableMemberFunction obj;
		bool res = m_lua->run_chunk("func = function(obj) "
										"local t = nil "
										"return obj:function_takes_table_returns_result_of_valid(t) "
									"end");
		CPPUNIT_ASSERT_EQUAL(true, res );
		m_lua->call("func",&obj);
		bool tableIsValid(true);
		OOLUA::pull2cpp(*m_lua,tableIsValid);
		CPPUNIT_ASSERT_EQUAL(false, tableIsValid);
	}
	

#if OOLUA_STORE_LAST_ERROR == 1
	void callFunction_memberFunctionWhichTakesTableYetPassedInt_callReturnsFalse()
	{
		
		m_lua->register_class<TableMemberFunction>();
		TableMemberFunction obj;
		m_lua->run_chunk("func = function(obj) "
							"return obj:function_which_takes_a_table(1) "
						"end");
		bool res =m_lua->call("func",&obj);
		CPPUNIT_ASSERT_EQUAL(false, res);
	}
	
#endif

#if OOLUA_USE_EXCEPTIONS == 1
	void callFunction_memberFunctionWhichTakesTableYetPassedInt_throwsRuntimeError()
	{
		m_lua->register_class<TableMemberFunction>();
		TableMemberFunction obj;
		m_lua->run_chunk("func = function(obj) "
							"return obj:function_which_takes_a_table(1) "
						 "end");

		CPPUNIT_ASSERT_THROW(m_lua->call("func",&obj), OOLUA::Runtime_error);
	}
#endif
	
	/*
	 table references are only valid for there own vm
	 */
	void bindScript_tableReferenceIsAlreadyValid_validReturnsFalse()
	{
		OOLUA::Lua_table table_;
		OOLUA::new_table(*m_lua,table_);
		OOLUA::Script another_lua_instance;
		table_.bind_script(another_lua_instance);
		CPPUNIT_ASSERT_EQUAL(false,table_.valid());
	}
	void bindScript_tableReferenceIsAlreadyBoundWithThisState_validReturnsTrue()
	{
		OOLUA::Lua_table table_;
		OOLUA::new_table(*m_lua,table_);
		table_.bind_script(*m_lua);
		CPPUNIT_ASSERT_EQUAL(true,table_.valid());
	}
	
	void traverse_stackIsNotEmpty_callBackIsCalled()
	{
		OOLUA::push2lua(*m_lua,1);
		
		OOLUA::Lua_table table_;
		OOLUA::new_table(*m_lua,table_);
		table_.set_value(1, 1);
		stackNotEmptyCalled = 0;
		table_.traverse(callBackFunc_stackNotEmpty);
		CPPUNIT_ASSERT_EQUAL(int(1),stackNotEmptyCalled);
	}
	
	void forEachKeyValue_stackIsNotEmpty_callBackIsCalled()
	{
		OOLUA::push2lua(*m_lua,1);
		OOLUA::Lua_table table_;
		OOLUA::new_table(*m_lua,table_);
		table_.set_value(1, 1);
		
		MemberCallBack l;
		OOLUA::for_each_key_value(table_, &l, &MemberCallBack::call_back );
		CPPUNIT_ASSERT_EQUAL(int(1),l.called);
	}
	
	void ipairs_stackIsNotEmptyTableHasOneEntry_IterationCountIsOne()
	{
		OOLUA::push2lua(*m_lua,1);
		OOLUA::Lua_table table_;
		OOLUA::new_table(*m_lua,table_);
		table_.set_value(1, 1);
		
		int count = 0;
		oolua_ipairs(table_)
		{
			count += 1;
		}
		oolua_ipairs_end()
		CPPUNIT_ASSERT_EQUAL(int(1),count);
	}
	
	void ipairs_stackIsNotEmptyTableHasFiveEntry_IterationCountIsFive()
	{
		OOLUA::push2lua(*m_lua,1);
		OOLUA::Lua_table table_;
		OOLUA::new_table(*m_lua,table_);
		
		for(int i=1;i<6;++i) table_.set_value(i, i);
		
		int count = 0;
		oolua_ipairs(table_)
		{
			count += 1;
		}
		oolua_ipairs_end()
		CPPUNIT_ASSERT_EQUAL(int(5),count);
	}
	
	void ipairs_stackHasOneEntryTableHasFiveEntry_afterIterationsStackCountIsOne()
	{
		OOLUA::push2lua(*m_lua,1);
		OOLUA::Lua_table table_;
		OOLUA::new_table(*m_lua,table_);
		
		for(int i=1;i<6;++i) table_.set_value(i, i);
		
		oolua_ipairs(table_)
		{
			//nop
		}
		oolua_ipairs_end()
		CPPUNIT_ASSERT_EQUAL(int(1),lua_gettop(*m_lua));
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( Table );
