
#	include "oolua_tests_pch.h"
#	include "oolua.h"

#	include "expose_stub_classes.h"

#	include "common_cppunit_headers.h"
#	include "expose_stub_classes.h"
#	include "cpp_constructor_mock.h"
#	include "expose_class_constructors.h"


class Construct : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(Construct);
	CPPUNIT_TEST(new_luaCreatesInstanceThenReturnsIt_returnIsNoneNull);
	CPPUNIT_TEST(new_luaCreatesInstance_noException);
	
	
	CPPUNIT_TEST(register_noDefaultConstructor_compiles);
	
	
	CPPUNIT_TEST(new_CallingIntParamConstructor_runChunkReturnsTrue);
	CPPUNIT_TEST(new_CallingIntParamConstructorPassingInitialisedValue_InstanceHasIntSetToInitialisedValue);
	CPPUNIT_TEST(new_CallingBoolParamConstructor_runChunkReturnsTrue);
	//To OOLUA there is no difference between a function that takes an int, int*, int& or any variation
	//the first registered constructor which matches will be called.
	//CPPUNIT_TEST(new_CallingIntPtrParamConstructor_runChunkReturnsTrue);
	//CPPUNIT_TEST(new_CallingIntPtrParamConstructorPassingInitialisedValue_InstanceHasIntPtrSetToInitialisedValue);
	CPPUNIT_TEST(new_CallingCharConstPtrParamConstructor_runChunkReturnsTrue);
	CPPUNIT_TEST(new_CallingCharConstPtrParamConstructorPassingInitialisedValue_InstanceHasStringSetToInitialisedValue);
	
	
	CPPUNIT_TEST(new_twoParamConstructorIntAndBool_runChunkReturnsTrue);
	CPPUNIT_TEST(new_twoParamConstructorIntAndBool_InstanceHasIntValueSet);
	CPPUNIT_TEST(new_twoParamConstructorIntAndBool_InstanceHasBoolValueSet);
	

	
	CPPUNIT_TEST(new_oneParamConstructorStub1_callReturnsTrue);
	CPPUNIT_TEST(new_oneParamConstructorStub1_instanceMemberIsSet);

	CPPUNIT_TEST(new_twoParamConstructorStub1AndStub2_callReturnsTrue);

	CPPUNIT_TEST(new_oneParamConstructorStub2ByValue_callReturnsTrue);
	CPPUNIT_TEST(new_oneParamConstructorStub2ByValue_instanceMemberIsSet);
	
	CPPUNIT_TEST(new_oneParamStub3WhichIsConst_callReturnsTrue);
	CPPUNIT_TEST(new_oneParamStub3WhichIsConst_constStub3ConstructorCalled);
	

	
	CPPUNIT_TEST(new_constructorTakesLuaFuncRef_callReturnsTrue);
	CPPUNIT_TEST(new_constructorTakesLuaFuncRef_FuncRefMemberIsValid);
	
	CPPUNIT_TEST(new_constructorTakesLuaTable_callReturnsTrue);
	CPPUNIT_TEST(new_constructorTakesLuaTable_tableMemberIsValid);
	
	CPPUNIT_TEST(new_constructorTakesLuaTableRef_callReturnsTrue);
	
	
	
#if OOLUA_STORE_LAST_ERROR	== 1
	CPPUNIT_TEST(new_twoParamConstructorIntAndBoolPassedStringAsFirstParam_runChunkReturnsFalse);
	CPPUNIT_TEST(new_oneParamConstructorPassingAnInvalidParam_callReturnsFalse);
	CPPUNIT_TEST(new_twoParamConstructorStub1AndInvalid_callReturnsFalse);
	CPPUNIT_TEST(new_callNewOnTypeWithNoPublicConstructors_runChunkReturnsFalse);
	CPPUNIT_TEST(new_CallingDefaultConstructorOnTypeWithOutOne_runChunkReturnsFalse);
	CPPUNIT_TEST(new_constructorTakesLuaTableRefYetPassedNil_callReturnsFalse);
	CPPUNIT_TEST(new_constructorTakesLuaTableYetPassedNil_callReturnsFalse);
#endif
	
	
#if OOLUA_USE_EXCEPTIONS == 1
	CPPUNIT_TEST(new_twoParamConstructorIntAndBoolPassedStringAsFirstParam_throwsRuntimeError);
	CPPUNIT_TEST(new_oneParamConstructorPassingAnInvalidParam_throwsRuntimeError);
	CPPUNIT_TEST(new_twoParamConstructorStub1AndInvalid_throwsRuntimeError);
	CPPUNIT_TEST(new_callNewOnTypeWithNoPublicConstructors_throwsRuntimeError);
	CPPUNIT_TEST(new_CallingDefaultConstructorOnTypeWithOutOne_throwsRuntimeError);
	CPPUNIT_TEST(new_constructorTakesLuaTableRefYetPassedNil_throwsRuntimeError);
	CPPUNIT_TEST(new_constructorTakesLuaTableYetPassedNil_throwsRuntimeError);
#endif	
	
	CPPUNIT_TEST(new_constructorTakesLuaState_memberStateEqualsInput);
	CPPUNIT_TEST(new_constructorTakesIntAndLuaState_memberStateEqualsInput);
	CPPUNIT_TEST(new_constructorTakesIntAndLuaState_memberIntEqualsInput);
	
	
	CPPUNIT_TEST_SUITE_END();

	OOLUA::Script * m_lua;
	std::string register_and_create_one_param_constructor()
	{
		m_lua->register_class<ParamConstructor>();
		m_lua->run_chunk("foo = function(i) return ParamConstructor:new(i) end");
		return "foo";
	}
	std::string register_and_create_two_param_constructor()
	{
		m_lua->register_class<ParamConstructor>();
		m_lua->run_chunk("foo = function(i1,i2) return ParamConstructor:new(i1,i2) end");
		return "foo";
	}
	struct ParamConstructorWrapper 
	{
		OOLUA::cpp_acquire_ptr<ParamConstructor*> instance;
		std::auto_ptr<ParamConstructor> auto_delete_instance;
		void set_ptr_to_auto_delete()
		{
			auto_delete_instance = std::auto_ptr<ParamConstructor>(instance.m_ptr);
		}
	};
	void pull_ParamWrapper(ParamConstructorWrapper& wrap)
	{
		OOLUA::pull2cpp(*m_lua,wrap.instance);
		wrap.set_ptr_to_auto_delete();
	}
public:
    Construct():m_lua(0){}
    LVD_NOCOPY(Construct)
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<Stub1>();
	}
	void tearDown()
	{
		delete m_lua;
	}

	void new_luaCreatesInstanceThenReturnsIt_returnIsNoneNull()
	{
		createAndReturnStub(m_lua);
		OOLUA::cpp_acquire_ptr<Stub1*> res;
		OOLUA::pull2cpp(*m_lua,res);
		CPPUNIT_ASSERT_EQUAL(true, res.m_ptr != 0);
		delete res.m_ptr;
	}
	void new_luaCreatesInstance_noException()
	{
		std::string foo("Stub1:new()");
		CPPUNIT_ASSERT_NO_THROW( m_lua->run_chunk(foo) );
	}

	void createAndReturnStub(OOLUA::Script *lua)
	{
		std::string foo(\
			"createAndReturn = function() \n"
				"return Stub1:new() \n"
			"end");
		lua->run_chunk(foo);
		CPPUNIT_ASSERT_NO_THROW( lua->call("createAndReturn") );
	}

	void register_noDefaultConstructor_compiles()
	{
		m_lua->register_class<ParamConstructor>();
	}
	void new_CallingIntParamConstructor_runChunkReturnsTrue()
	{
		m_lua->register_class<ParamConstructor>();
		bool result = m_lua->run_chunk("ParamConstructor:new(1)");
		CPPUNIT_ASSERT_EQUAL(true,result);

	}
	void new_CallingIntParamConstructorPassingInitialisedValue_InstanceHasIntSetToInitialisedValue()
	{
		m_lua->call(register_and_create_one_param_constructor(),ParamValues::int_set);
		ParamConstructorWrapper wrap;
		pull_ParamWrapper(wrap);
		CPPUNIT_ASSERT_EQUAL(ParamValues::int_set,wrap.instance.m_ptr->m_int);
	}
	void new_CallingBoolParamConstructor_runChunkReturnsTrue()
	{
		m_lua->register_class<ParamConstructor>();
		bool result = m_lua->run_chunk("ParamConstructor:new(true)");
		CPPUNIT_ASSERT_EQUAL(true,result);
		
	}
	
	void new_CallingBoolParamConstructorPassingInitialisedValue_InstanceHasBoolSetToInitialisedValue()
	{
		m_lua->call(register_and_create_one_param_constructor(),ParamValues::bool_set);
		ParamConstructorWrapper wrap;
		pull_ParamWrapper(wrap);
		CPPUNIT_ASSERT_EQUAL(ParamValues::bool_set,wrap.instance.m_ptr->m_bool);
	}
	
	void new_CallingIntPtrParamConstructor_runChunkReturnsTrue()
	{
		m_lua->register_class<ParamConstructor>();
		bool result = m_lua->run_chunk("ParamConstructor:new(1)");
		CPPUNIT_ASSERT_EQUAL(true,result);
		
	}
	void new_CallingIntPtrParamConstructorPassingInitialisedValue_InstanceHasIntPtrSetToInitialisedValue()
	{
		m_lua->call(register_and_create_one_param_constructor(),ParamValues::int_set);
		ParamConstructorWrapper wrap;
		pull_ParamWrapper(wrap);
		CPPUNIT_ASSERT_EQUAL(ParamValues::int_set,wrap.instance.m_ptr->m_int_ptr);
	}
	
	
	
	
	void new_CallingCharConstPtrParamConstructor_runChunkReturnsTrue()
	{
		m_lua->register_class<ParamConstructor>();
		bool result = m_lua->run_chunk("ParamConstructor:new(\"do not care\")");
		CPPUNIT_ASSERT_EQUAL(true,result);
	}
	void new_CallingCharConstPtrParamConstructorPassingInitialisedValue_InstanceHasStringSetToInitialisedValue()
	{
		m_lua->call(register_and_create_one_param_constructor(),ParamValues::c_string_set);
		ParamConstructorWrapper wrap;
		pull_ParamWrapper(wrap);
		CPPUNIT_ASSERT_EQUAL(ParamValues::string_set,wrap.instance.m_ptr->m_string);
	}
	void new_twoParamConstructorIntAndBool_runChunkReturnsTrue()
	{
		m_lua->register_class<ParamConstructor>();
		bool result = m_lua->run_chunk("ParamConstructor:new(1,true)");
		CPPUNIT_ASSERT_EQUAL(true,result);
	}
	void new_twoParamConstructorIntAndBool_InstanceHasIntValueSet()
	{
		m_lua->call(register_and_create_two_param_constructor(),ParamValues::int_set,ParamValues::bool_set);
		ParamConstructorWrapper wrap;
		pull_ParamWrapper(wrap);
		CPPUNIT_ASSERT_EQUAL(ParamValues::int_set,wrap.instance.m_ptr->m_int);
	}
	void new_twoParamConstructorIntAndBool_InstanceHasBoolValueSet()
	{
		m_lua->call(register_and_create_two_param_constructor(),ParamValues::int_set,ParamValues::bool_set);
		ParamConstructorWrapper wrap;
		pull_ParamWrapper(wrap);
		CPPUNIT_ASSERT_EQUAL(ParamValues::bool_set,wrap.instance.m_ptr->m_bool);
	}

	
	void new_oneParamConstructorStub1_callReturnsTrue()
	{
		m_lua->register_class<Stub1>();
		Stub1 stub1;
		bool result = m_lua->call(register_and_create_one_param_constructor(),&stub1);
		CPPUNIT_ASSERT_EQUAL(true,result);
	}
	void new_oneParamConstructorStub1_instanceMemberIsSet()
	{
		m_lua->register_class<Stub1>();
		Stub1 stub;
		m_lua->call(register_and_create_one_param_constructor(),&stub);
		ParamConstructorWrapper wrap;
		pull_ParamWrapper(wrap);
		CPPUNIT_ASSERT_EQUAL(&stub,wrap.instance.m_ptr->m_stub1);
	}
	
	void new_twoParamConstructorStub1AndStub2_callReturnsTrue()
	{
		m_lua->register_class<Stub1>();
		m_lua->register_class<Stub2>();
		Stub1 stub1;
		Stub2 stub2;
		bool result = m_lua->call(register_and_create_two_param_constructor(),&stub1,&stub2);
		CPPUNIT_ASSERT_EQUAL(true,result);
	}
	

	
	void new_oneParamConstructorStub2ByValue_callReturnsTrue()
	{
		m_lua->register_class<Stub2>();
		Stub2 stub;
		bool result = m_lua->call(register_and_create_one_param_constructor(),&stub);
		CPPUNIT_ASSERT_EQUAL(true,result);
	}
	
	void new_oneParamConstructorStub2ByValue_instanceMemberIsSet()
	{
		m_lua->register_class<Stub2>();
		Stub2 stub;
		m_lua->call(register_and_create_one_param_constructor(),&stub);
		ParamConstructorWrapper wrap;
		pull_ParamWrapper(wrap);
		CPPUNIT_ASSERT_EQUAL(ParamValues::bool_set,wrap.instance.m_ptr->m_stub_passed_by_value);
	}
	void new_oneParamStub3WhichIsConst_callReturnsTrue()
	{
		m_lua->register_class<Stub3>();
		Stub3 stub;
		bool result = m_lua->call(register_and_create_one_param_constructor(),(Stub3 const*)&stub);
		CPPUNIT_ASSERT_EQUAL(true,result);
	}
	void new_oneParamStub3WhichIsConst_constStub3ConstructorCalled()
	{
		m_lua->register_class<Stub3>();
		Stub3 stub;
		m_lua->call(register_and_create_one_param_constructor(),(Stub3 const*)&stub);
		ParamConstructorWrapper wrap;
		pull_ParamWrapper(wrap);
		CPPUNIT_ASSERT_EQUAL(ParamValues::bool_set,wrap.instance.m_ptr->m_const_stub3);
	}


	
	void new_constructorTakesLuaFuncRef_callReturnsTrue()
	{
		m_lua->register_class<ParamConstructor>();
		m_lua->run_chunk("foo = function() "
							"local f = function() end "
							"ParamConstructor:new(f) "
						 "end");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(true,result);
	}
	void new_constructorTakesLuaFuncRef_FuncRefMemberIsValid()
	{
		m_lua->register_class<ParamConstructor>();
		m_lua->run_chunk("foo = function() "
						 "local f = function() end "
						 " return ParamConstructor:new(f) "
						 "end");
		m_lua->call("foo");
		ParamConstructorWrapper p;
		pull_ParamWrapper(p);
		bool isValid = p.instance.m_ptr->m_func_ref.valid();
		CPPUNIT_ASSERT_EQUAL(true,isValid);	
	}
	void new_constructorTakesLuaTable_callReturnsTrue()
	{
		m_lua->register_class<ParamConstructor>();
		m_lua->run_chunk("foo = function() "
						 "local t = {} "
						 "ParamConstructor:new(t) "
						 "end");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(true,result);
	}

	void new_constructorTakesLuaTable_tableMemberIsValid()
	{
		m_lua->register_class<ParamConstructor>();
		m_lua->run_chunk("foo = function(obj) "
						 "local t = {} "
						 "return ParamConstructor:new(t) "
						 "end");
		m_lua->call("foo");
		ParamConstructorWrapper wrap;
		pull_ParamWrapper(wrap);
		CPPUNIT_ASSERT_EQUAL(true,wrap.instance.m_ptr->m_table.valid() );
	}
	void new_constructorTakesLuaTableRef_callReturnsTrue()
	{
		m_lua->register_class<TableRefConstructor>();
		m_lua->run_chunk("foo = function() "
						 "local t = {} "
						 "TableRefConstructor:new(t) "
						 "end");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(true,result);
	}
	
	
	
#if OOLUA_STORE_LAST_ERROR ==1	
	void new_twoParamConstructorIntAndBoolPassedStringAsFirstParam_runChunkReturnsFalse()
	{
		m_lua->register_class<ParamConstructor>();
		bool result = m_lua->run_chunk("ParamConstructor:new(\"dont care\",true)");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}
	
	void new_oneParamConstructorPassingAnInvalidParam_callReturnsFalse()
	{
		m_lua->register_class<InvalidStub>();
		InvalidStub stub;
		bool result = m_lua->call(register_and_create_one_param_constructor(),&stub);
		CPPUNIT_ASSERT_EQUAL(false,result);
	}
	
	void new_twoParamConstructorStub1AndInvalid_callReturnsFalse()
	{
		m_lua->register_class<Stub1>();
		m_lua->register_class<InvalidStub>();
		Stub1 stub1;
		InvalidStub stub2;
		bool result = m_lua->call(register_and_create_two_param_constructor(),&stub1,&stub2);
		CPPUNIT_ASSERT_EQUAL(false,result);
	}

	void new_callNewOnTypeWithNoPublicConstructors_runChunkReturnsFalse()
	{
		m_lua->register_class<WithOutConstructors>();
		bool result = m_lua->run_chunk("WithOutConstructors::new()");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}
	
	void new_CallingDefaultConstructorOnTypeWithOutOne_runChunkReturnsFalse()
	{
		m_lua->register_class<ParamConstructor>();
		bool result = m_lua->run_chunk("ParamConstructor:new()");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}
	
	//nil is not convertable to a type in a constructor
	void new_constructorTakesLuaTableRefYetPassedNil_callReturnsFalse()
	{
		m_lua->register_class<TableRefConstructor>();
		m_lua->run_chunk("foo = function() "
						 "local t = nil "
						 "TableRefConstructor:new(t) "
						 "end");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}
	
	void new_constructorTakesLuaTableYetPassedNil_callReturnsFalse()
	{
		m_lua->register_class<ParamConstructor>();
		m_lua->run_chunk("foo = function() "
						 "local t = nil "
						 "ParamConstructor:new(t) "
						 "end");
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}
#endif
	
	
#if OOLUA_USE_EXCEPTIONS == 1	
	
	void new_twoParamConstructorIntAndBoolPassedStringAsFirstParam_throwsRuntimeError()
	{
		m_lua->register_class<ParamConstructor>();
		CPPUNIT_ASSERT_THROW ( (m_lua->run_chunk("ParamConstructor:new(\"dont care\",true)"))
							  ,OOLUA::Runtime_error);
	}
	
	void new_oneParamConstructorPassingAnInvalidParam_throwsRuntimeError()
	{
		m_lua->register_class<InvalidStub>();
		InvalidStub stub;
		CPPUNIT_ASSERT_THROW( (m_lua->call(register_and_create_one_param_constructor(),&stub))
							 ,OOLUA::Runtime_error);
	}
	
	void new_twoParamConstructorStub1AndInvalid_throwsRuntimeError()
	{
		m_lua->register_class<Stub1>();
		m_lua->register_class<InvalidStub>();
		Stub1 stub1;
		InvalidStub stub2;
		CPPUNIT_ASSERT_THROW( (m_lua->call(register_and_create_two_param_constructor(),&stub1,&stub2) )
							 ,OOLUA::Runtime_error);
	}
	
	void new_callNewOnTypeWithNoPublicConstructors_throwsRuntimeError()
	{
		m_lua->register_class<WithOutConstructors>();
		CPPUNIT_ASSERT_THROW( (m_lua->run_chunk("WithOutConstructors:new()")), OOLUA::Runtime_error);
	}
	
	void new_CallingDefaultConstructorOnTypeWithOutOne_throwsRuntimeError()
	{
		m_lua->register_class<ParamConstructor>();
		CPPUNIT_ASSERT_THROW( (m_lua->run_chunk("ParamConstructor:new()"))
							 ,OOLUA::Runtime_error);
	}
	
	//nil is not convertable to a type in a constructor
	void new_constructorTakesLuaTableRefYetPassedNil_throwsRuntimeError()
	{
		m_lua->register_class<TableRefConstructor>();
		m_lua->run_chunk("foo = function() "
						 "local t = nil "
						 "TableRefConstructor:new(t) "
						 "end");
		CPPUNIT_ASSERT_THROW((m_lua->call("foo")),OOLUA::Runtime_error);
	}
	void new_constructorTakesLuaTableYetPassedNil_throwsRuntimeError()
	{
		m_lua->register_class<ParamConstructor>();
		m_lua->run_chunk("foo = function() "
						 "local t = nil "
						 "ParamConstructor:new(t) "
						 "end");
		CPPUNIT_ASSERT_THROW((m_lua->call("foo")),OOLUA::Runtime_error);
	}
	
#endif
	
	void new_constructorTakesLuaState_memberStateEqualsInput()
	{
		m_lua->register_class<LuaStateConstructors>();
		m_lua->run_chunk("foo = function() "
						 "return LuaStateConstructors:new() "
						 "end");
		OOLUA::cpp_acquire_ptr<LuaStateConstructors*> stateCtor;
		m_lua->call("foo");
		OOLUA::pull2cpp(*m_lua,stateCtor);
		CPPUNIT_ASSERT_EQUAL(m_lua->get_ptr() ,stateCtor.m_ptr->lua);
		delete stateCtor.m_ptr;
	}
	
	void new_constructorTakesIntAndLuaState_memberStateEqualsInput()
	{
		m_lua->register_class<LuaStateConstructors>();
		m_lua->run_chunk("foo = function() "
						 "return LuaStateConstructors:new(1) "
						 "end");
		OOLUA::cpp_acquire_ptr<LuaStateConstructors*> stateCtor;
		m_lua->call("foo");
		OOLUA::pull2cpp(*m_lua,stateCtor);
		CPPUNIT_ASSERT_EQUAL(m_lua->get_ptr(),stateCtor.m_ptr->lua);
		delete stateCtor.m_ptr;
	}
	
	void new_constructorTakesIntAndLuaState_memberIntEqualsInput()
	{
		m_lua->register_class<LuaStateConstructors>();
		m_lua->run_chunk("foo = function(i) "
						 "return LuaStateConstructors:new(i) "
						 "end");
		OOLUA::cpp_acquire_ptr<LuaStateConstructors*> stateCtor;
		m_lua->call("foo",ParamValues::int_set);
		OOLUA::pull2cpp(*m_lua,stateCtor);
		CPPUNIT_ASSERT_EQUAL(ParamValues::int_set,stateCtor.m_ptr->m_int);
		delete stateCtor.m_ptr;
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( Construct );

