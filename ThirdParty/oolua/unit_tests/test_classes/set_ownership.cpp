#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "lua_ownership.h"
#	include "common_cppunit_headers.h"

#	include "cpp_private_destructor.h"
#	include "expose_stub_classes.h"


#	include "lua_ownership.h"


class Ownership : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(Ownership);
		CPPUNIT_TEST(setOwnerIsRegistered_onConstantPointer_callReturnsTrue);
		CPPUNIT_TEST(setOwnerIsRegistered_onNoneConstantPointer_callReturnsTrue);
		CPPUNIT_TEST(setOwner_luaPassesOwnershipToCpp_udGcBoolIsFalse);
		CPPUNIT_TEST(setOwner_luaTakesOwnership_udGcBoolIsTrue);
		CPPUNIT_TEST(setOwner_luaTakesOwnershipAndThenPassesItToCpp_udGcBoolIsFalse);
	
#if OOLUA_STORE_LAST_ERROR	== 1
		CPPUNIT_TEST(setOwner_luaOwnsOnInstanceWithNoPublicDestructor_callSetOwnerReturnsFalse);
		CPPUNIT_TEST(setOwner_cppOwnsOnInstanceWithNoPublicDestructor_callSetOwnerReturnsFalse);
#endif

	
#if OOLUA_USE_EXCEPTIONS == 1
		CPPUNIT_TEST(setOwner_luaOwnsOnInstanceWithNoPublicDestructor_throwsRuntimeError);
		CPPUNIT_TEST(setOwner_cppOwnsOnInstanceWithNoPublicDestructor_throwsRuntimeError);
#endif	
		
		CPPUNIT_TEST(luaParamOutP_ref2Ptr_userDataPtrComparesEqualToValueSetInFunction);
		CPPUNIT_TEST(luaParamOutP_ref2Ptr_topOfStackGcIsTrue);
	
		CPPUNIT_TEST(luaParamOutP_ref2PtrConst_userDataPtrComparesEqualToValueSetInFunction);
		CPPUNIT_TEST(luaParamOutP_ref2PtrConst_topOfStackGcIsTrue);
	
		CPPUNIT_TEST(callFunction_passingPointerUsingLuaAcquirePtr_topOfStackGcIsTrue);
		CPPUNIT_TEST(callFunction_passingPointerUsingLuaAcquirePtr_topOfComparesEqualToStackPointer);
	
	/*
	 OOLUA::cpp_in_p<Stub1*======
	 OOLUA::cpp_in_p<Stub1*&======
	 
	 OOLUA::cpp_in_p<Stub1 *const
	 OOLUA::cpp_in_p<Stub1 *const&=======
	 
	 OOLUA::cpp_in_p<Stub1 const*
	 OOLUA::cpp_in_p<Stub1 const*&=========
	 
	 OOLUA::cpp_in_p<Stub1 const* const
	 OOLUA::cpp_in_p<Stub1 const* const&
	 */
		CPPUNIT_TEST(cppInP_ptr2UserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse);
		CPPUNIT_TEST(cppInP_ref2Ptr2UserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse);
		
		CPPUNIT_TEST(cppInP_constPtr2UserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse);
		CPPUNIT_TEST(cppInP_ref2ConstPtr2UserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse);
	
		CPPUNIT_TEST(cppInP_ptr2ConstUserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse);
		CPPUNIT_TEST(cppInP_ref2Ptr2ConstUserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse);

		CPPUNIT_TEST(cppInP_constPtr2ConstUserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse);
		CPPUNIT_TEST(cppInP_ref2ConstPtr2ConstUserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse);	

	CPPUNIT_TEST_SUITE_END();
	
	OOLUA::Script * m_lua;
	template<typename Type>
	bool call_set_owner(Type* stub,std::string const& owner)
	{
		bool result = m_lua->run_chunk(
			std::string("func = function(obj) obj:set_owner(") + owner + std::string(") end")
			);
		return result && m_lua->call("func",stub);
	}

public:
    Ownership():m_lua(0){}
    LVD_NOCOPY(Ownership)
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<Stub1>();
	}
	void tearDown()
	{
		delete m_lua;
	}
	void setOwnerIsRegistered_onConstantPointer_callReturnsTrue()
	{
		Stub1 stub;
		Stub1 const* s(&stub);
		CPPUNIT_ASSERT_EQUAL(true,call_set_owner(s,"Cpp_owns"));
	}
	void setOwnerIsRegistered_onNoneConstantPointer_callReturnsTrue()
	{
		Stub1 stub;
		CPPUNIT_ASSERT_EQUAL(true,call_set_owner(&stub,"Cpp_owns"));
	}
	void setOwner_luaPassesOwnershipToCpp_udGcBoolIsFalse()
	{
		Stub1 stub;
		call_set_owner(&stub,"Cpp_owns");
		OOLUA::INTERNAL::is_there_an_entry_for_this_void_pointer(*m_lua,&stub);
		OOLUA::INTERNAL::Lua_ud* ud = static_cast<OOLUA::INTERNAL::Lua_ud *>( lua_touserdata(*m_lua, -1) );
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::INTERNAL::userdata_is_to_be_gced(ud));
	}
	void setOwner_luaTakesOwnership_udGcBoolIsTrue()
	{
		Stub1 stub;
		call_set_owner(&stub,"Lua_owns");
		OOLUA::INTERNAL::is_there_an_entry_for_this_void_pointer(*m_lua,&stub);
		OOLUA::INTERNAL::Lua_ud* ud = static_cast<OOLUA::INTERNAL::Lua_ud *>( lua_touserdata(*m_lua, -1) );
		CPPUNIT_ASSERT_EQUAL(true,OOLUA::INTERNAL::userdata_is_to_be_gced(ud));
		//we have to change back to Cpp or else delete will be called on a stack instance.
		OOLUA::INTERNAL::userdata_gc_value(ud,false);
	}
	void setOwner_luaTakesOwnershipAndThenPassesItToCpp_udGcBoolIsFalse()
	{
		Stub1 stub;
		call_set_owner(&stub,"Lua_owns");
		call_set_owner(&stub,"Cpp_owns");
		OOLUA::INTERNAL::is_there_an_entry_for_this_void_pointer(*m_lua,&stub);
		OOLUA::INTERNAL::Lua_ud* ud = static_cast<OOLUA::INTERNAL::Lua_ud *>( lua_touserdata(*m_lua, -1) );
		CPPUNIT_ASSERT_EQUAL(false,OOLUA::INTERNAL::userdata_is_to_be_gced(ud));
	}

	
#if OOLUA_STORE_LAST_ERROR	== 1
	void setOwner_luaOwnsOnInstanceWithNoPublicDestructor_callSetOwnerReturnsFalse()
	{
		m_lua->register_class<PrivateDestructor>();
		PrivateDestructor* mock = PrivateDestructor::create();
		bool result = call_set_owner(mock,"Lua_owns");
		CPPUNIT_ASSERT_EQUAL(false,result);
		mock->release();
		
	}
	void setOwner_cppOwnsOnInstanceWithNoPublicDestructor_callSetOwnerReturnsFalse()
	{
		m_lua->register_class<PrivateDestructor>();
		PrivateDestructor* mock = PrivateDestructor::create();
		bool result = call_set_owner(mock,"Cpp_owns");
		CPPUNIT_ASSERT_EQUAL(false,result);
		mock->release();
		
	}
#endif
	
	
#if OOLUA_USE_EXCEPTIONS == 1
	void setOwner_luaOwnsOnInstanceWithNoPublicDestructor_throwsRuntimeError()
	{
		m_lua->register_class<PrivateDestructor>();
		PrivateDestructor* mock = PrivateDestructor::create();
		CPPUNIT_ASSERT_THROW((call_set_owner(mock,"Lua_owns")),OOLUA::Runtime_error);
		mock->release();
		
	}
	void setOwner_cppOwnsOnInstanceWithNoPublicDestructor_throwsRuntimeError()
	{
		m_lua->register_class<PrivateDestructor>();
		PrivateDestructor* mock = PrivateDestructor::create();
		CPPUNIT_ASSERT_THROW((call_set_owner(mock,"Cpp_owns")),OOLUA::Runtime_error);
		mock->release();
		
	}
#endif	


	
	std::string lua_out_param_helper(std::string const& functionToBeCalled)
	{
		std::string func = std::string("foo=function(obj) return obj:") + functionToBeCalled + std::string("() end"); 
		m_lua->run_chunk(func);
		m_lua->register_class<OwnershipParamsAndReturns>();
		return std::string("foo");//functions name
	}
	
	OOLUA::INTERNAL::Lua_ud * get_ud_helper()
	{
		return static_cast<OOLUA::INTERNAL::Lua_ud *>(lua_touserdata(*m_lua,-1) );
	}
	
	void luaParamOutP_ref2Ptr_userDataPtrComparesEqualToValueSetInFunction()
	{
		std::string func = lua_out_param_helper("lua_takes_ownership_of_ref_2_ptr");

		MockOwnershipParamsAndReturns object;
		Stub1 return_stub;
		
		EXPECT_CALL(object,ref_2_ptr(::testing::_))
			.Times(1)
			.WillOnce(::testing::SetArgReferee<0>(&return_stub));
		
		m_lua->call(func,(OwnershipParamsAndReturns*)&object);

		OOLUA::INTERNAL::Lua_ud * ud = get_ud_helper();
		OOLUA::INTERNAL::userdata_gc_value(ud,false);//stop delete being called on this stack pointer
		CPPUNIT_ASSERT_EQUAL((void*)&return_stub, ud->void_class_ptr);

	}
	
	
	void luaParamOutP_ref2Ptr_topOfStackGcIsTrue()
	{
		std::string func = lua_out_param_helper("lua_takes_ownership_of_ref_2_ptr");

		MockOwnershipParamsAndReturns object;
		Stub1 return_stub;
		
		EXPECT_CALL(object,ref_2_ptr(::testing::_))
			.Times(1)
			.WillOnce(::testing::SetArgReferee<0>(&return_stub));
		
		m_lua->call(func,(OwnershipParamsAndReturns*)&object);
		OOLUA::INTERNAL::Lua_ud * ud = get_ud_helper();
		bool gc_value = OOLUA::INTERNAL::userdata_is_to_be_gced(ud);
		OOLUA::INTERNAL::userdata_gc_value(ud,false);//stop delete being called on this stack pointer
		CPPUNIT_ASSERT_EQUAL(true,gc_value);

	}
	
	

	void luaParamOutP_ref2PtrConst_userDataPtrComparesEqualToValueSetInFunction()
	{
		std::string func = lua_out_param_helper("lua_takes_ownership_of_ref_2_ptr_const");
		MockOwnershipParamsAndReturns object;
		Stub1 return_stub;
		
		EXPECT_CALL(object,ref_2_ptr_const(::testing::_))
			.Times(1)
			.WillOnce(::testing::SetArgReferee<0>(&return_stub));
		
		m_lua->call(func,(OwnershipParamsAndReturns*)&object);
		OOLUA::INTERNAL::Lua_ud * ud = get_ud_helper();
		OOLUA::INTERNAL::userdata_gc_value(ud,false);//stop delete being called on this stack pointer
		CPPUNIT_ASSERT_EQUAL((void*)&return_stub, ud->void_class_ptr);

	}
	
	void luaParamOutP_ref2PtrConst_topOfStackGcIsTrue()
	{
		std::string func = lua_out_param_helper("lua_takes_ownership_of_ref_2_ptr_const");
		MockOwnershipParamsAndReturns object;
		Stub1 return_stub;
		
		EXPECT_CALL(object,ref_2_ptr_const(::testing::_))
			.Times(1)
			.WillOnce(::testing::SetArgReferee<0>(&return_stub));
		
		m_lua->call(func,(OwnershipParamsAndReturns*)&object);
		OOLUA::INTERNAL::Lua_ud * ud = get_ud_helper();
		bool gc_value = OOLUA::INTERNAL::userdata_is_to_be_gced(ud);
		OOLUA::INTERNAL::userdata_gc_value(ud,false);//stop delete being called on this stack pointer
		CPPUNIT_ASSERT_EQUAL(true,gc_value);

	}
	void callFunction_passingPointerUsingLuaAcquirePtr_topOfStackGcIsTrue()
	{
		Stub1 stub;
		m_lua->run_chunk("foo = function(param) return param end");
		m_lua->call("foo",OOLUA::lua_acquire_ptr<Stub1*>(&stub));
		OOLUA::INTERNAL::Lua_ud * ud = get_ud_helper();
		bool gc_value = OOLUA::INTERNAL::userdata_is_to_be_gced(ud);
		OOLUA::INTERNAL::userdata_gc_value(ud,false);//stop delete being called on this stack pointer
		CPPUNIT_ASSERT_EQUAL(true,gc_value);
	}
	void callFunction_passingPointerUsingLuaAcquirePtr_topOfComparesEqualToStackPointer()
	{
		Stub1 stub;
		m_lua->run_chunk("foo = function(param) return param end");
		m_lua->call("foo",OOLUA::lua_acquire_ptr<Stub1*>(&stub));
		OOLUA::INTERNAL::Lua_ud * ud = get_ud_helper();
		OOLUA::INTERNAL::userdata_gc_value(ud,false);//stop delete being called on this stack pointer
		CPPUNIT_ASSERT_EQUAL((void*)&stub,ud->void_class_ptr);
	}
	std::string generate_cpp_in_p_function(std::string func_name)
	{
		m_lua->register_class<OwnershipParamsAndReturns>();
		m_lua->run_chunk(std::string("foo = function(obj,param) ")
						 +std::string("obj:") +func_name +std::string("(param) ")
						 +std::string("return param ")
						 +std::string("end")
						 );
		return std::string("foo");
	}
	
	bool returnGarbageCollectValueAfterCppTakingOwnership(std::string func_name)
	{
		std::string generated_func_name = generate_cpp_in_p_function(func_name);
		::testing::NiceMock<MockOwnershipParamsAndReturns> object;
		Stub1 stub;
		
		m_lua->call(generated_func_name
					,(OwnershipParamsAndReturns*)&object
					,OOLUA::lua_acquire_ptr<Stub1*>(&stub));
		
		OOLUA::INTERNAL::Lua_ud * ud = get_ud_helper();
		return OOLUA::INTERNAL::userdata_is_to_be_gced(ud);
		
	}
	
	void cppInP_ptr2UserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse()
	{
		bool result = returnGarbageCollectValueAfterCppTakingOwnership(
						 "cpp_takes_ownership_of_ptr_param");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}

	void cppInP_ref2Ptr2UserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse()
	{
		bool result = returnGarbageCollectValueAfterCppTakingOwnership(
						"cpp_takes_ownership_of_ref_to_ptr_param");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}

	void cppInP_constPtr2UserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse()
	{
		bool result = returnGarbageCollectValueAfterCppTakingOwnership(
						"cpp_takes_ownership_of_const_ptr_param");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}

	void cppInP_ref2ConstPtr2UserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse()
	{
		bool result = returnGarbageCollectValueAfterCppTakingOwnership(
						"cpp_takes_ownership_of_ref_2_const_ptr_param");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}
	
	
	void cppInP_ptr2ConstUserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse()
	{
		bool result = returnGarbageCollectValueAfterCppTakingOwnership(
						"cpp_takes_ownership_of_ptr_to_const_param");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}

	void cppInP_ref2Ptr2ConstUserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse()
	{
		bool result = returnGarbageCollectValueAfterCppTakingOwnership(
						"cpp_takes_ownership_of_ref_to_ptr_to_const_param");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}
	
	
	void cppInP_constPtr2ConstUserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse()
	{
		bool result = returnGarbageCollectValueAfterCppTakingOwnership(
						"cpp_takes_ownership_of_const_ptr_to_const_param");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}
	void cppInP_ref2ConstPtr2ConstUserDataType_passingPtrThatLuaOwns_topOfStackGcIsFalse()
	{
		bool result = returnGarbageCollectValueAfterCppTakingOwnership(
						"cpp_takes_ownership_of_ref_to_const_ptr_to_const_param");
		CPPUNIT_ASSERT_EQUAL(false,result);
	}


};


CPPUNIT_TEST_SUITE_REGISTRATION( Ownership );





