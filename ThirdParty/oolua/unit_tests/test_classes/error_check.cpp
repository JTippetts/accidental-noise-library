
#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "common_cppunit_headers.h"
#	include "expose_stub_classes.h"
#	include "expose_pulls_stub_param.h"
#	include "expose_member_function_calls.h"
#	include <csetjmp>

#if OOLUA_DEBUG_CHECKS == 1
	/*This seems to be the only way of using the preprocesser and detecting luajit,
	 even when the path is pointing to luajit header directory.
	 If we include the luajit header directly it will fail to compile for Rio Lua
	 */
//#	include "lua/lua.hpp"
#endif

namespace  
{
	jmp_buf mark; 
	int OOLua_panic(lua_State* /*l*/)
	{
		longjmp(mark,1);
		return 0;
	}
	enum  SomeEnum {someEnumValue};	
}


#if OOLUA_USE_EXCEPTIONS ==  1
struct ExceptionMock
{
	void throwsStdRuntimeError()
	{
		throw std::runtime_error("member function throwing an error");
	}
};



OOLUA_CLASS_NO_BASES(ExceptionMock)
	OOLUA_TYPEDEFS 
		No_public_constructors 
		, No_public_destructor 
	OOLUA_END_TYPES
	OOLUA_MEM_FUNC_0(void, throwsStdRuntimeError)
OOLUA_CLASS_END

EXPORT_OOLUA_FUNCTIONS_1_NON_CONST(ExceptionMock,throwsStdRuntimeError)
EXPORT_OOLUA_FUNCTIONS_0_CONST(ExceptionMock)
#endif


class Error_test : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(Error_test);

		CPPUNIT_TEST(userDataCheck_constUserdataOnTopOfStackWhichOoluaDidCreate_resultIsTrue);
		CPPUNIT_TEST(userDataCheck_UserdataOnTopOfStackWhichOoluaDidCreate_resultIsTrue);
		
		CPPUNIT_TEST(userDataCheck_userdataOnTopOfStackWhichARelatedThreadCreated_resultIsTrue);
		
		CPPUNIT_TEST(userDataCheck_UserdataOnTopOfStackWhichOoluaDidNotCreate_stackIsTheSameSizeAfterCheck);
		CPPUNIT_TEST(registerClass_checkStackSize_stackIsEmpty);
		CPPUNIT_TEST(scriptConstructor_checkStackSize_stackIsEmpty);
		CPPUNIT_TEST(lua_Lopenlibs_checkStackSizeAfterCall_stackIsEmpty);
	
	
#if OOLUA_RUNTIME_CHECKS_ENABLED ==1
#	if OOLUA_CHECK_EVERY_USERDATA_IS_CREATED_BY_OOLUA == 1
		CPPUNIT_TEST(userDataCheck_UserdataOnTopOfStackWhichOoluaDidNotCreate_resultIsFalse);
		CPPUNIT_TEST(userDataCheck_lightUserDataWithNoMetaTable_resultIsFalse);
#	endif	
#	if OOLUA_USE_EXCEPTIONS == 1
		CPPUNIT_TEST(memberFunctionCall_luaCallsLikeStaticFunctionWithNoParameters_throwsOoluaRunTimeError);
#	elif OOLUA_STORE_LAST_ERROR == 1
		CPPUNIT_TEST(memberFunctionCall_luaCallsLikeStaticFunctionWithNoParameters_callRetunsFalse);
#	endif
	
#endif

	
#if OOLUA_STORE_LAST_ERROR == 1
		CPPUNIT_TEST( lastError_noError_lastErrorStringIsEmpty);
	
		CPPUNIT_TEST( lastError_callUnknownFunction_lastErrorStringIsNotEmpty);
		CPPUNIT_TEST(call_callUnknownFunction_callReturnsFalse);
		CPPUNIT_TEST(lastError_callUnknownFunction_stackIsEmpty);
		CPPUNIT_TEST( errorReset_callUnknownFunctionThenReset_lastErrorStringIsEmpty);
	
		CPPUNIT_TEST(pull_UnrelatedClassType_pullReturnsFalse);
		CPPUNIT_TEST(pull_UnrelatedClassType_ptrIsNull);
		CPPUNIT_TEST(pull_UnrelatedClassType_lastErrorStringIsNotEmpty);
	
		CPPUNIT_TEST(pull_classWhenintIsOnStack_lastErrorStringIsNotEmpty);
		CPPUNIT_TEST(pull_classWhenintIsOnStack_pullReturnsFalse);
		CPPUNIT_TEST(pull_intWhenClassIsOnStack_pullReturnsFalse);
		CPPUNIT_TEST(pull_enumWhenStringIsOnStack_callReturnsFalse);
		CPPUNIT_TEST(pull_memberFunctionPullsClassWhenintIsOnStack_callReturnsFalse);
	
		CPPUNIT_TEST(loadFile_fileDoesNotExist_returnsFalse);
		CPPUNIT_TEST(runFile_fileDoesNotExist_returnsFalse);
#endif	
	

#if OOLUA_USE_EXCEPTIONS == 1
	
		CPPUNIT_TEST(pull_ptrToconstUserDataTypeWhenStackIsNoneOoluaUserData_throwsTypeError);
	
		CPPUNIT_TEST(pull_UnrelatedClassType_throwsTypeError);

		CPPUNIT_TEST(callUnknownFunction_fromCpp_throwsOoluaRuntimeError );
	
		CPPUNIT_TEST(runChunk_chunkHasSyntaxError_throwSyntaxError);
	
		CPPUNIT_TEST(pullUnregisteredClass_fromEmptyStackInCpp_throwTypeError );
		CPPUNIT_TEST(pullUnregisteredClass_fromStackContainingAnIntInCpp_throwTypeError );
	
		CPPUNIT_TEST(pull_classWhenintIsOnStack_throwsTypeError);
	
		CPPUNIT_TEST(pull_memberFunctionPullsClassWhenintIsOnStack_throwsOoluaRuntimeError);
	
		CPPUNIT_TEST(pull_intWhenClassIsOnStack_throwsTypeError);
	
		CPPUNIT_TEST(pull_boolFromEmptyStack_throwTypeError);
		CPPUNIT_TEST(pull_pushAnIntThenPullBool_throwTypeError);
		CPPUNIT_TEST(pull_pushBoolThenPullInt_throwTypeError);
	
		CPPUNIT_TEST(pull_pushIntThenPullFloat_noException);
	
		CPPUNIT_TEST(pull_enumWhenStringIsOnStack_throwTypeError);
		
		CPPUNIT_TEST(pull_cppAcquirePtrWhenIntOnStack_throwsTypeError);
		
		CPPUNIT_TEST(exceptionSafe_memberFunctionThrowsStdRuntimeError_callThrowsOoluaRuntimeError);
		CPPUNIT_TEST(call_afterAnExceptionTheStackIsEmpty_stackCountEqualsZero);
	
		CPPUNIT_TEST(loadFile_fileDoesNotExist_callThrowsOoluaFileError);
		CPPUNIT_TEST(runFile_fileDoesNotExist_callThrowsOoluaFileError);
#endif	

#if OOLUA_DEBUG_CHECKS == 1
		CPPUNIT_TEST(push_unregisteredClass_callsLuaPanic);
#endif
	

		CPPUNIT_TEST(canXmove_vm0IsNULL_returnsFalse);
		CPPUNIT_TEST(canXmove_vm1IsNULL_returnsFalse);
		CPPUNIT_TEST(canXmove_samePointers_returnsFalse);
		CPPUNIT_TEST(canXmove_ParentAndChild_returnsTrue);
		CPPUNIT_TEST(canXmove_unrelatedStates_returnsFalse);
		CPPUNIT_TEST(canXmove_ValidParentChildBothWithAStackCountOfOne_bothHaveStackCountIsOneAfterCall);
	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script * m_lua;
public:
	Error_test():m_lua(0){}
	LVD_NOCOPY(Error_test)
	void setUp()
	{
		m_lua = new OOLUA::Script;
	}
	void tearDown()
	{
		delete m_lua;

	}
	
	void userDataCheck_runFunction()
	{
		m_lua->run_chunk("foo = function() "
						 "return Stub1:new() "
						 "end");
		m_lua->register_class<Stub1>();
		m_lua->call("foo");
		
	}
	//if the type is a userdata it will always returns true if runtine errors turned off
	void userDataCheck_UserdataOnTopOfStackWhichOoluaDidCreate_resultIsTrue()
	{
		m_lua->run_chunk("foo = function() "
						 "return Stub1:new() "
						 "end");
		m_lua->register_class<Stub1>();
		m_lua->call("foo");
		OOLUA::INTERNAL::Lua_ud* dontCare;
		bool result = OOLUA::INTERNAL::index_is_userdata(*m_lua,-1,dontCare);
		CPPUNIT_ASSERT_EQUAL(true,result );
	}
	void userDataCheck_userdataOnTopOfStackWhichARelatedThreadCreated_resultIsTrue()
	{
		m_lua->run_chunk("foo = function() "
						 "local c = coroutine.create(function() return Stub1:new() end) "
						 "local err, result = coroutine.resume(c) "
						 "if err == false then error(result) end "
						 "return result "
						 "end");
		m_lua->register_class<Stub1>();
		CPPUNIT_ASSERT(m_lua->call("foo"));
		OOLUA::INTERNAL::Lua_ud* dontCare;
		bool result = OOLUA::INTERNAL::index_is_userdata(*m_lua,-1,dontCare);
		CPPUNIT_ASSERT_EQUAL(true,result );
	}
	void userDataCheck_constUserdataOnTopOfStackWhichOoluaDidCreate_resultIsTrue()
	{
		m_lua->run_chunk("foo = function(obj) "
						 "return obj "
						 "end");
		m_lua->register_class<Stub1>();
		Stub1 s;
		Stub1 const * struct_ptr = &s;
		m_lua->call("foo",struct_ptr);
		OOLUA::INTERNAL::Lua_ud* dontCare;
		bool result = OOLUA::INTERNAL::index_is_userdata(*m_lua,-1,dontCare);
		CPPUNIT_ASSERT_EQUAL(true,result );
	}
	//if runtime checks turned off it will never effect the stack size
	void userDataCheck_UserdataOnTopOfStackWhichOoluaDidNotCreate_stackIsTheSameSizeAfterCheck()
	{
		lua_newuserdata(*m_lua,sizeof(int));
		int before = lua_gettop(*m_lua);
		OOLUA::INTERNAL::Lua_ud* dontCare;
		OOLUA::INTERNAL::index_is_userdata(*m_lua,-1,dontCare);
		int after = lua_gettop(*m_lua);
		CPPUNIT_ASSERT_EQUAL(before,after);
	}


	void scriptConstructor_checkStackSize_stackIsEmpty()
	{
		OOLUA::Script s;
		CPPUNIT_ASSERT_EQUAL(0,s.stack_count());
	}
	void registerClass_checkStackSize_stackIsEmpty()
	{
		OOLUA::Script s;
		s.register_class<Stub1>();
		CPPUNIT_ASSERT_EQUAL(0,s.stack_count());
	}
	
	void lua_Lopenlibs_checkStackSizeAfterCall_stackIsEmpty()
	{
		lua_State* L = luaL_newstate();
		luaL_openlibs(L);
		CPPUNIT_ASSERT_EQUAL(0,lua_gettop(L));
	}

	
	
#if OOLUA_RUNTIME_CHECKS_ENABLED ==1

#	if OOLUA_USE_EXCEPTIONS == 1
	void memberFunctionCall_luaCallsLikeStaticFunctionWithNoParameters_throwsOoluaRunTimeError()
	{
		::testing::NiceMock<FunctionCallsMock> mock;
		m_lua->register_class<Function_calls>();
		m_lua->run_chunk("foo = function() Function_calls:func() end"); 
		CPPUNIT_ASSERT_THROW((m_lua->call("foo")),OOLUA::Runtime_error);
	}
#	elif OOLUA_STORE_LAST_ERROR == 1
	void memberFunctionCall_luaCallsLikeStaticFunctionWithNoParameters_callRetunsFalse()
	{
		::testing::NiceMock<FunctionCallsMock> mock;
		m_lua->register_class<Function_calls>();
		m_lua->run_chunk("foo = function() Function_calls:func() end"); 
		bool result = m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}
#	endif
	
	void userDataCheck_lightUserDataWithNoMetaTable_resultIsFalse()
	{
		lua_pushlightuserdata(*m_lua,this);
		OOLUA::INTERNAL::Lua_ud* dontCare;
		bool result = OOLUA::INTERNAL::index_is_userdata(*m_lua,-1,dontCare);
		CPPUNIT_ASSERT_EQUAL(false,result );
	}
	
	void userDataCheck_UserdataOnTopOfStackWhichOoluaDidNotCreate_resultIsFalse()
	{
		lua_newuserdata(*m_lua,sizeof(int));
		OOLUA::INTERNAL::Lua_ud* dontCare;
		bool result = OOLUA::INTERNAL::index_is_userdata(*m_lua,-1,dontCare);
		CPPUNIT_ASSERT_EQUAL(false,result );
	}
	
#endif	


#if OOLUA_STORE_LAST_ERROR == 1
	
	void pull_ptrToconstUserDataTypeWhenStackIsNoneOoluaUserData_pullResultIsFalse()
	{
		lua_newuserdata(*m_lua,sizeof(int));
		Stub1 const*  cpp_type =  0;
		bool result = OOLUA::pull2cpp(*m_lua,cpp_type);
		CPPUNIT_ASSERT_EQUAL( false,result);	
	}
	
	void pull_enumWhenStringIsOnStack_callReturnsFalse()
	{
		m_lua->run_chunk("foo = function()return 'DontCareAboutStringValue' end");
		m_lua->call("foo");
		
		SomeEnum enum_value;
		bool result = OOLUA::pull2cpp(*m_lua,enum_value);
		CPPUNIT_ASSERT_EQUAL( false ,result);
	}
	
	void pull_memberFunctionPullsClassWhenintIsOnStack_callReturnsFalse()
	{
		m_lua->run_chunk("foo = function(obj)"
						 " obj:ptr(1) "
						 "end");
		m_lua->register_class<Pulls_stub>();
		::testing::NiceMock<Mock_pulls_stub> object;
		bool result = m_lua->call("foo",(Pulls_stub*)&object);
		CPPUNIT_ASSERT_EQUAL( false,result);
	}
	
	void lastError_noError_lastErrorStringIsEmpty()
	{
		CPPUNIT_ASSERT_EQUAL(true,OOLUA::get_last_error(*m_lua).empty() );
	}
	void lastError_callUnknownFunction_lastErrorStringIsNotEmpty()
	{
		m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::get_last_error(*m_lua).empty() );
	}
	void call_callUnknownFunction_callReturnsFalse()
	{
		m_lua->run_chunk("foo = function() "
						 "bar() "
						 "end");
		m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(false,m_lua->call("foo"));
	}
	void lastError_callUnknownFunction_stackIsEmpty()
	{
		m_lua->run_chunk("foo = function() "
						 "bar() "
						 "end");
		m_lua->call("foo");
		CPPUNIT_ASSERT_EQUAL(0,m_lua->stack_count() );
	}
	void errorReset_callUnknownFunctionThenReset_lastErrorStringIsEmpty()
	{
		m_lua->call("foo");
		OOLUA::reset_error_value(*m_lua);
		CPPUNIT_ASSERT_EQUAL(true,OOLUA::get_last_error(*m_lua).empty() );
	}	
	
	

	void pull_UnrelatedClassType_pullReturnsFalse()
	{
		m_lua->register_class<Stub1>();
		m_lua->register_class<InvalidStub>();
		m_lua->run_chunk("foo = function() "
						 "return Stub1:new() "
						 "end");
		m_lua->call("foo");
		InvalidStub* ptr;
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::pull2cpp(*m_lua,ptr) );
	}
	
	void pull_UnrelatedClassType_ptrIsNull()
	{
		m_lua->register_class<Stub1>();
		m_lua->register_class<InvalidStub>();
		m_lua->run_chunk("foo = function() "
						 "return Stub1:new() "
						 "end");
		m_lua->call("foo");
		InvalidStub* ptr;
		OOLUA::pull2cpp(*m_lua,ptr);
		CPPUNIT_ASSERT_EQUAL((InvalidStub*)0,ptr );
	}
	void pull_UnrelatedClassType_lastErrorStringIsNotEmpty()
	{
		m_lua->register_class<Stub1>();
		m_lua->register_class<InvalidStub>();
		m_lua->run_chunk("foo = function() "
						 "return Stub1:new() "
						 "end");
		m_lua->call("foo");
		InvalidStub* ptr;
		OOLUA::pull2cpp(*m_lua,ptr);
		CPPUNIT_ASSERT_EQUAL(false, OOLUA::get_last_error(*m_lua).empty() );
	}
	
	void pull_classWhenintIsOnStack_lastErrorStringIsNotEmpty()
	{
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("foo = function() "
						 "return 1 "
						 "end");
		m_lua->call("foo");
		Stub1* result;
		OOLUA::pull2cpp(*m_lua,result);
		CPPUNIT_ASSERT_EQUAL(false, OOLUA::get_last_error(*m_lua).empty() );

	}
	void pull_classWhenintIsOnStack_pullReturnsFalse()
	{
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("foo = function() "
						 "return 1 "
						 "end");
		m_lua->call("foo");
		Stub1* result;
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::pull2cpp(*m_lua,result));
	}

	void pull_intWhenClassIsOnStack_pullReturnsFalse()
	{
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("foo = function() "
						 "return Stub1:new() "
						 "end");
		m_lua->call("foo");
		int result;
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::pull2cpp(*m_lua,result));
	 }
				 
	void loadFile_fileDoesNotExist_returnsFalse()
	{
		CPPUNIT_ASSERT_EQUAL(false,m_lua->load_file("does_not_exist"));
	}
	void runFile_fileDoesNotExist_returnsFalse()
	{
		CPPUNIT_ASSERT_EQUAL(false,m_lua->run_file("does_not_exist"));
	}
										
#endif
	
#if OOLUA_USE_EXCEPTIONS == 1
	
	void pull_ptrToconstUserDataTypeWhenStackIsNoneOoluaUserData_throwsTypeError()
	{
		lua_newuserdata(*m_lua,sizeof(int));
		Stub1 const*  cpp_type =  0;
		CPPUNIT_ASSERT_THROW( (OOLUA::pull2cpp(*m_lua,cpp_type)),OOLUA::Type_error);	
	}
	void pull_cppAcquirePtrWhenIntOnStack_throwsTypeError()
	{
		m_lua->run_chunk("foo = function() return 1 end");
		m_lua->call("foo");
		OOLUA::cpp_acquire_ptr<Stub1*> cpp_type;
		CPPUNIT_ASSERT_THROW( (OOLUA::pull2cpp(*m_lua,cpp_type) ),OOLUA::Type_error);
		
	}
	void pull_enumWhenStringIsOnStack_throwTypeError()
	{
		m_lua->run_chunk("foo = function()return 'DontCareAboutStringValue' end");
		m_lua->call("foo");

		SomeEnum enum_value;
		CPPUNIT_ASSERT_THROW( (OOLUA::pull2cpp(*m_lua,enum_value)) ,OOLUA::Type_error);
	}
	void pull_memberFunctionPullsClassWhenintIsOnStack_throwsOoluaRuntimeError()
	{
		m_lua->run_chunk("foo = function(obj)"
						 " obj:ptr(1) "
						 "end");
		m_lua->register_class<Pulls_stub>();
		::testing::NiceMock<Mock_pulls_stub> object;
		CPPUNIT_ASSERT_THROW( (m_lua->call("foo",(Pulls_stub*)&object) ),OOLUA::Runtime_error);
	}
	
	
	void pull_UnrelatedClassType_throwsTypeError()
	{
		m_lua->register_class<Stub1>();
		m_lua->register_class<InvalidStub>();
		m_lua->run_chunk("foo = function() "
						 "return Stub1:new() "
						 "end");
		m_lua->call("foo");
		InvalidStub* ptr;
		CPPUNIT_ASSERT_THROW((OOLUA::pull2cpp(*m_lua,ptr)),OOLUA::Type_error);
	}
	
	void pull_classWhenintIsOnStack_throwsTypeError()
	{
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("foo = function() "
						 "return 1 "
						 "end");
		m_lua->call("foo");
		Stub1* result;
		CPPUNIT_ASSERT_THROW((OOLUA::pull2cpp(*m_lua,result)),OOLUA::Type_error);
	}
	
	void pull_intWhenClassIsOnStack_throwsTypeError()
	{
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("foo = function() "
						 "return Stub1:new() "
						 "end");
		m_lua->call("foo");
		int result;
		CPPUNIT_ASSERT_THROW(( OOLUA::pull2cpp(*m_lua,result) ),OOLUA::Type_error);
	}
	
	void callUnknownFunction_fromCpp_throwsOoluaRuntimeError()
	{
		CPPUNIT_ASSERT_THROW(m_lua->call("InvalidFunctionName"),OOLUA::Runtime_error);
	}
	void runChunk_chunkHasSyntaxError_throwSyntaxError()
	{
		CPPUNIT_ASSERT_THROW( ( m_lua->run_chunk("missingEnd = function() ")  ),OOLUA::Syntax_error);
	}
	void pullUnregisteredClass_fromEmptyStackInCpp_throwTypeError()
	{
		Stub1* fp(0);
		CPPUNIT_ASSERT_THROW( (OOLUA::pull2cpp(*m_lua,fp))  ,OOLUA::Type_error);
	}
	void pullUnregisteredClass_fromStackContainingAnIntInCpp_throwTypeError()
	{
		Stub1* fp(0);
		int i =1;
		OOLUA::push2lua(*m_lua,i);
		CPPUNIT_ASSERT_THROW( (OOLUA::pull2cpp(*m_lua,fp))  ,OOLUA::Type_error);
	}
	
	void pull_boolFromEmptyStack_throwTypeError()
	{
		bool stub;
		CPPUNIT_ASSERT_THROW( (OOLUA::pull2cpp(*m_lua,stub)) ,OOLUA::Type_error);
	}
	void pull_pushIntThenPullFloat_noException()
	{
		int dontCare(0);
		float pullInto(0.f);
		OOLUA::push2lua(*m_lua,dontCare);
		OOLUA::pull2cpp(*m_lua,pullInto);
	}
	
	void pull_pushAnIntThenPullBool_throwTypeError()
	{
		int dontCare(0);
		OOLUA::push2lua(*m_lua,dontCare);
		bool pullInto;
		CPPUNIT_ASSERT_THROW( (OOLUA::pull2cpp(*m_lua,pullInto)), OOLUA::Type_error);
	}
	
	void pull_pushBoolThenPullInt_throwTypeError()
	{
		//bool is a distinct type from int and float
		bool dontCare(false);
		int pullInto(0);
		OOLUA::push2lua(*m_lua,dontCare);
		CPPUNIT_ASSERT_THROW( (OOLUA::pull2cpp(*m_lua,pullInto)), OOLUA::Type_error);
	}
	void registerExceptionMockAndRunChunkCalledFoo()
	{
		m_lua->register_class<ExceptionMock>();
		m_lua->run_chunk("foo = function(obj) "
						 "obj:throwsStdRuntimeError() "
						 "end");
	}
	void exceptionSafe_memberFunctionThrowsStdRuntimeError_callThrowsOoluaRuntimeError()
	{
		ExceptionMock m;
		registerExceptionMockAndRunChunkCalledFoo();
		CPPUNIT_ASSERT_THROW(m_lua->call("foo",&m),OOLUA::Runtime_error);
	}
	
	void call_afterAnExceptionTheStackIsEmpty_stackCountEqualsZero()
	{
		ExceptionMock m;
		registerExceptionMockAndRunChunkCalledFoo();
		
		CPPUNIT_ASSERT_THROW(m_lua->call("foo",&m),OOLUA::Runtime_error);
		CPPUNIT_ASSERT_EQUAL(0, m_lua->stack_count() );
	}
	void loadFile_fileDoesNotExist_callThrowsOoluaFileError()
	{
		CPPUNIT_ASSERT_THROW(m_lua->load_file("does_not_exist"),OOLUA::File_error);
	}
	void runFile_fileDoesNotExist_callThrowsOoluaFileError()
	{
		CPPUNIT_ASSERT_THROW(m_lua->run_file("does_not_exist"),OOLUA::File_error);
	}
	
#endif
	
	
#if OOLUA_DEBUG_CHECKS == 1
#	if LUAJIT_VERSION_NUM >= 20000
		/*luajit2 will throw on some platforms */
		void push_unregisteredClass_callsLuaPanic(){}
#	else
		/*if you are using luajit2 with lua51 headers this may still fail on some platforns*/
		void push_unregisteredClass_callsLuaPanic()
		{
			Stub1 stubtmp;
			Stub1* stubptr(&stubtmp);
		
			lua_atpanic(*m_lua,&OOLua_panic);
		
			if (setjmp(mark) == 0)
			{
				OOLUA::push2lua(*m_lua,stubptr);
				CPPUNIT_ASSERT_EQUAL(false,true );//never jumped back
			}
			else
				CPPUNIT_ASSERT_EQUAL(true,true );//we hit the at panic
		}
#	endif
#endif
	
	
	void canXmove_vm0IsNULL_returnsFalse()
	{
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::can_xmove(0, *m_lua));
	}
	void canXmove_vm1IsNULL_returnsFalse()
	{
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::can_xmove(*m_lua,0));
	}
	void canXmove_samePointers_returnsFalse()
	{
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::can_xmove(*m_lua,*m_lua));
	}
	
	void canXmove_ParentAndChild_returnsTrue()
	{
		lua_State * child = lua_newthread(*m_lua);
		CPPUNIT_ASSERT_EQUAL(true,OOLUA::can_xmove(*m_lua,child));
	}
	void canXmove_unrelatedStates_returnsFalse()
	{
		lua_State * other = luaL_newstate();
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::can_xmove(*m_lua,other));
		lua_close(other);
	}
	
	void canXmove_ValidParentChildBothWithAStackCountOfOne_bothHaveStackCountIsOneAfterCall()
	{
		lua_State * child = lua_newthread(*m_lua);//thread on m_lua stack
		lua_pushnil(child);
		
		OOLUA::can_xmove(*m_lua,child);
		CPPUNIT_ASSERT( ( lua_gettop(*m_lua) ==1 && lua_gettop(child) == 1) );
	}
	
};

CPPUNIT_TEST_SUITE_REGISTRATION(Error_test);
