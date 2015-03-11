#	include "oolua_tests_pch.h"
#	include "common_cppunit_headers.h"
#	include "oolua.h"
#	include "expose_stub_classes.h"




	
namespace 
{
	struct StubNoneProxy {};
}



class Traits_test : public CPPUNIT_NS::TestFixture

{
	CPPUNIT_TEST_SUITE(Traits_test);
	CPPUNIT_TEST(isProxy_noneProxyClass_valueIsZero );
	CPPUNIT_TEST(isProxy_ProxyClass_valueIsOne);
	CPPUNIT_TEST(needsToBePushedByReference_isCurrentlyByValue_valueEqualsOne);
	CPPUNIT_TEST(needsToBePushedByReference_isCurrentlyByValue_valueEqualsZero);
	CPPUNIT_TEST(needsToBePushedByReference_isCurrentlyByReference_valueEqualsZero);

	
	CPPUNIT_TEST(luaAcquire_refToPtrUserType_pullIsPtrToUserType);
	CPPUNIT_TEST(luaAcquire_ptrToUserType_pullIsPtrToUserType);
	CPPUNIT_TEST(luaAcquire_refToPtrToConstUserType_pullIsPtrToConstUserType);
	CPPUNIT_TEST(luaAcquire_ptrToConstUserType_pullIsPtrToConstUserType);
	CPPUNIT_TEST(luaAcquire_refToConstPtrToUserType_pullIsPtrToUserType);
	CPPUNIT_TEST(luaAcquire_constPtrUserType_pullIsPtrToUserType);
	CPPUNIT_TEST(luaAcquire_constPtrToConstUserType_pullIsPtrToConstUserType);
	CPPUNIT_TEST(luaAcquire_refToConstPtrToConstUserType_pullIsPtrToConstUserType);

	
	CPPUNIT_TEST(luaOutP_refToPtrToUserType_pullIsPtrToUserType);
	CPPUNIT_TEST(luaOutP_refToPtrConstToUserType_pullIsPtrConstToUserType);
	
		
	CPPUNIT_TEST(outP_refToPtrToUserType_pullIsPtrToUserType);	
		
	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script * m_lua;
public:
    Traits_test():m_lua(0){}
    LVD_NOCOPY(Traits_test)
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<Stub1>();
	}
	void tearDown()
	{
		delete m_lua;
	}
	void isProxy_noneProxyClass_valueIsZero()
	{
		int value = OOLUA::INTERNAL::has_a_proxy_type<StubNoneProxy>::value;
		CPPUNIT_ASSERT_EQUAL(int(0),value);
	}
	void isProxy_ProxyClass_valueIsOne()
	{
		int value = OOLUA::INTERNAL::has_a_proxy_type<Stub1>::value;
		CPPUNIT_ASSERT_EQUAL(int(1),value);
	}
	void needsToBePushedByReference_isCurrentlyByValue_valueEqualsOne()
	{
		int value = OOLUA::INTERNAL::shouldPushValueByReference< Stub1,
									!LVD::by_reference<Stub1>::value 
										&& OOLUA::INTERNAL::has_a_proxy_type<Stub1>::value >::value;
		CPPUNIT_ASSERT_EQUAL(int(1),value);
	}
	void needsToBePushedByReference_isCurrentlyByValue_valueEqualsZero()
	{
		int value = OOLUA::INTERNAL::shouldPushValueByReference< StubNoneProxy,
										OOLUA::INTERNAL::is_param_by_value<StubNoneProxy>::value 
											&& OOLUA::INTERNAL::has_a_proxy_type<StubNoneProxy>::value >::value;
		CPPUNIT_ASSERT_EQUAL(int(0),value);
	}
	void needsToBePushedByReference_isCurrentlyByReference_valueEqualsZero()
	{
		int value = OOLUA::INTERNAL::shouldPushValueByReference< Stub1*,
									OOLUA::INTERNAL::is_param_by_value<Stub1*>::value 
										&& OOLUA::INTERNAL::has_a_proxy_type<OOLUA::INTERNAL::Raw_type<Stub1*>::type >::value >::value;
		CPPUNIT_ASSERT_EQUAL(int(0),value);
	}
	
	

	
	
	void luaAcquire_refToPtrUserType_pullIsPtrToUserType()
	{
		int is_same = LVD::is_same< Stub1 *,OOLUA::lua_acquire_ptr<Stub1*&>::pull_type>::value;
		CPPUNIT_ASSERT_EQUAL(1,is_same);
	}
	void luaAcquire_ptrToUserType_pullIsPtrToUserType()
	{
		int is_same = LVD::is_same< Stub1 *,OOLUA::lua_acquire_ptr<Stub1 *>::pull_type>::value;
		CPPUNIT_ASSERT_EQUAL(1,is_same);
	}
	     
	
	void luaAcquire_refToPtrToConstUserType_pullIsPtrToConstUserType()
	{
		int is_same = LVD::is_same< Stub1 const*,OOLUA::lua_acquire_ptr<Stub1 const*&>::pull_type>::value;
		CPPUNIT_ASSERT_EQUAL(1,is_same);
	}	
	void luaAcquire_ptrToConstUserType_pullIsPtrToConstUserType()
	{
		int is_same = LVD::is_same< Stub1 const*,OOLUA::lua_acquire_ptr<Stub1 const*>::pull_type>::value;
		CPPUNIT_ASSERT_EQUAL(1,is_same);
	}
	
	
	void luaAcquire_refToConstPtrToUserType_pullIsPtrToUserType()
	{
		int is_same = LVD::is_same< Stub1 *,OOLUA::lua_acquire_ptr<Stub1 *const&>::pull_type>::value;
		CPPUNIT_ASSERT_EQUAL(1,is_same);
	}	
	void luaAcquire_constPtrUserType_pullIsPtrToUserType()
	{
		int is_same = LVD::is_same< Stub1 *,OOLUA::lua_acquire_ptr<Stub1 *const>::pull_type>::value;
		CPPUNIT_ASSERT_EQUAL(1,is_same);
	}
	
	
	void luaAcquire_constPtrToConstUserType_pullIsPtrToConstUserType()
	{
		int is_same = LVD::is_same< Stub1 const*,OOLUA::lua_acquire_ptr<Stub1 const *const>::pull_type>::value;
		CPPUNIT_ASSERT_EQUAL(1,is_same);
	}
	void luaAcquire_refToConstPtrToConstUserType_pullIsPtrToConstUserType()
	{
		int is_same = LVD::is_same< Stub1 const*,OOLUA::lua_acquire_ptr<Stub1 const *const&>::pull_type>::value;
		CPPUNIT_ASSERT_EQUAL(1,is_same);
	}	
	
	
	void luaOutP_refToPtrToUserType_pullIsPtrToUserType()
	{
		int is_same = LVD::is_same< Stub1*,OOLUA::lua_out_p<Stub1*&>::pull_type>::value;
		CPPUNIT_ASSERT_EQUAL(1,is_same);
	}	
	
	void luaOutP_refToPtrConstToUserType_pullIsPtrConstToUserType()
	{
		int is_same = LVD::is_same< Stub1 const*,OOLUA::lua_out_p<Stub1 const * &>::pull_type>::value;
		CPPUNIT_ASSERT_EQUAL(1,is_same);
	}		
	
	
	/*
	Out parameter pull types
	These are created on the stack so they should be plain types
	*/
	void outP_refToPtrToUserType_pullIsPtrToUserType()
	{
		int is_same = LVD::is_same< Stub1 ,OOLUA::out_p<Stub1*&>::pull_type>::value;
		CPPUNIT_ASSERT_EQUAL(1,is_same);
	}	
	

};


//OOLUA::lua_out_p<Stub1**> OOLuaDoesNotCurrentlyHandle_ptrPtr;
//OOLUA::lua_out_p<Stub1 * const * & >OOLuaDoesNotCurrentlyHandle_refPtrConstPtr;
//OOLUA::lua_out_p<Stub1 ** & >OOLuaDoesNotCurrentlyHandle_refPtrPtr;


/*
 The following are compile time tests with commented out tests being 
 ones that will fail.
*/



void luaOutp_validTraits_willCompile()
{
	OOLUA::lua_out_p<Stub1*&> pass1;(void)pass1;
	OOLUA::lua_out_p<Stub1 const * &> pass2;(void)pass2;
}
void luaOutp_invalidTraits_willNotCompile()
{
	//OOLUA::lua_out_p<Stub1 * const&>	fail1;
	//OOLUA::lua_out_p<Stub1&>			fail2;
	//OOLUA::lua_out_p<Stub1 const &>	fail3;
	//OOLUA::lua_out_p<int>				fail4;
	//OOLUA::lua_out_p<int*>			fail5;
	//OOLUA::lua_out_p<int&>			fail6;
	//OOLUA::lua_out_p<Stub1*>			fail7;
}


void inOutp_validTraits_willCompile()
{
	OOLUA::in_out_p<Stub1*>			pass1;(void)pass1;
	OOLUA::in_out_p<Stub1&>			pass2;(void)pass2;
	OOLUA::in_out_p<Stub1 const &>	pass3;(void)pass3;
	OOLUA::in_out_p<Stub1*&>		pass4;(void)pass4;
	OOLUA::in_out_p<int*>			pass5;(void)pass5;
	OOLUA::in_out_p<int&>			pass6;(void)pass6;
}


void inOutp_invalidTraits_willNotCompile()
{
	//OOLUA::in_out_p<Stub1>		fail1;
	//OOLUA::in_out_p<int>			fail2;
	
}


void cppInp_validTraits_willCompile()
{
	OOLUA::cpp_in_p<Stub1*>				pass1;(void)pass1;
	OOLUA::cpp_in_p<Stub1*&>			pass2;(void)pass2;
	
	OOLUA::cpp_in_p<Stub1 *const>		pass3;(void)pass3;
	OOLUA::cpp_in_p<Stub1 *const&>		pass4;(void)pass4;
	
	OOLUA::cpp_in_p<Stub1 const* const>	pass5;(void)pass5;
	OOLUA::cpp_in_p<Stub1 const* const&>pass6;(void)pass6;	
	
	OOLUA::cpp_in_p<Stub1 const*>		pass7;(void)pass7;
	OOLUA::cpp_in_p<Stub1 const*&>		pass8;(void)pass8;	
	
	
}


void cppInp_invalidTraits_willNotCompile()
{
	//OOLUA::cpp_in_p<Stub1&>			fail1; //should this pass, could it mean it will outlive the pointer??
	//OOLUA::cpp_in_p<int*>			fail2;
	//OOLUA::cpp_in_p<int&>			fail3;
	//OOLUA::cpp_in_p<Stub1 const &>	fail4;; //should this pass, could it mean it will outlive the pointer??
	//OOLUA::cpp_in_p<Stub1>		fail5;
	//OOLUA::cpp_in_p<int>			fail6;
	
}


void outp_validTraits_willCompile()
{
	OOLUA::out_p<Stub1*&>			pass1;(void)pass1;
	OOLUA::out_p<Stub1 const * &>	pass2;(void)pass2;
	OOLUA::out_p<int*>				pass3;(void)pass3;
	OOLUA::out_p<int&>				pass4;(void)pass4;
	OOLUA::out_p<int*&>				pass5;(void)pass5;
	
	
}
void outp_invalidTraits_willNotCompile()
{
	//OOLUA::out_p<Stub1> fail1;
	//OOLUA::out_p<int> fail2;
	
}

void cppAcquire_validTraits_willCompile()
{
	OOLUA::cpp_acquire_ptr<Stub1*>			pass1;(void)pass1;
	OOLUA::cpp_acquire_ptr<Stub1*&>			pass2;(void)pass2;
	
	OOLUA::cpp_acquire_ptr<Stub1 const*>	pass3;(void)pass3;
	OOLUA::cpp_acquire_ptr<Stub1 const*&>	pass4;(void)pass4;
	
	OOLUA::cpp_acquire_ptr<Stub1 *const>	pass5;(void)pass5;
	OOLUA::cpp_acquire_ptr<Stub1 *const&>	pass6;(void)pass6;
	
	OOLUA::cpp_acquire_ptr<Stub1 const*const>	pass7;(void)pass7;
	OOLUA::cpp_acquire_ptr<Stub1 const*const&>	pass8;(void)pass8;
}
void cppAcquire_invalidTraits_willNotCompile()
{
	//OOLUA::cpp_acquire_ptr<int> fail1;
	//OOLUA::cpp_acquire_ptr<int*> fail2;
	//OOLUA::cpp_acquire_ptr<Stub1> fail3;
	//OOLUA::cpp_acquire_ptr<Stub1&> fail4;
}


void luaAcquire_validTraits_willCompile()
{
	OOLUA::lua_acquire_ptr<Stub1*>				pass1;(void)pass1;
	OOLUA::lua_acquire_ptr<Stub1*&>				pass2;(void)pass2;
	
	OOLUA::lua_acquire_ptr<Stub1 const*>		pass3;(void)pass3;
	OOLUA::lua_acquire_ptr<Stub1 const*&>		pass4;(void)pass4;
	
	OOLUA::lua_acquire_ptr<Stub1 *const>		pass5;(void)pass5;
	OOLUA::lua_acquire_ptr<Stub1 *const&>		pass6;(void)pass6;
	
	OOLUA::lua_acquire_ptr<Stub1 const *const>	pass7;(void)pass7;
	OOLUA::lua_acquire_ptr<Stub1 const *const&>	pass8;(void)pass8;	
}

void luaAcquire_invalidTraits_willNotCompile()
{
	//OOLUA::lua_acquire_ptr<Stub1>				fail1;
	//OOLUA::lua_acquire_ptr<Stub1&>				fail2;
	
	//OOLUA::lua_acquire_ptr<int>				fail3;
	//OOLUA::lua_acquire_ptr<int&>				fail4;
	
	//OOLUA::lua_acquire_ptr<int*>				fail5;
	//OOLUA::lua_acquire_ptr<int*&>				fail6;
	
	//OOLUA::lua_acquire_ptr<int const&>		fail7;
	//OOLUA::lua_acquire_ptr<int const>			fail8;
	
	//OOLUA::lua_acquire_ptr<int *const>		fail9;
	//OOLUA::lua_acquire_ptr<int *const&>		fail10;
	
	//OOLUA::lua_acquire_ptr<int const*>		fail11;
	//OOLUA::lua_acquire_ptr<int const*&>		fail12;
	
	//OOLUA::lua_acquire_ptr<int const *const>	fail13;
	//OOLUA::lua_acquire_ptr<int const *const&>	fail14;
}



CPPUNIT_TEST_SUITE_REGISTRATION( Traits_test );
