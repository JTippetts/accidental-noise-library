
#	include "oolua_tests_pch.h"
#	include "oolua.h"
#	include "common_cppunit_headers.h"

#	include "expose_hierarchy.h"

template<typename Base_type,typename Derived_type>
struct BaseAndDerived
{
    typedef Derived_type Derived;
    typedef Base_type Base;
    BaseAndDerived(OOLUA::Script* l)
    :derived()
    ,derived_ptr(&derived)
    ,derived_ptr_const(&derived)
    ,base_ptr(&derived)
    ,base_ptr_const(&derived)
    {
        l->register_class<Base>();
		l->register_class<Derived>();
    }
    BaseAndDerived(BaseAndDerived const&);
    BaseAndDerived& operator = (BaseAndDerived const&);
    Derived derived;
    Derived* derived_ptr;
    Derived const* derived_ptr_const;
    Base * base_ptr ;
    Base const* base_ptr_const;
};

typedef BaseAndDerived<TwoAbstractBases,DerivedFromTwoAbstractBasesAndAbstract3 > BaseAndDerivedNoOffsets;
typedef BaseAndDerived<Abstract3,DerivedFromTwoAbstractBasesAndAbstract3 > BaseAndDerivedHaveOffsets;

template<typename Class_type>
struct Class_instance
{
    typedef Class_type Type;
    Class_instance(OOLUA::Script* l)
        :instance()
        ,instance_ptr(&instance)
        ,instance_ptr_const(&instance)
    {
        l->register_class<Type>();
    }
    Type instance;
    Type* instance_ptr;
    Type const* instance_ptr_const;
};

class ClassExchange : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(ClassExchange);
    CPPUNIT_TEST( BaseAndDerivedPointers_checkThereIsNoOffsetWhichIsRequiredForTests_addressCompareEqual);
    CPPUNIT_TEST( BaseAndDerivedPointers_checkTheyDoHaveOffsetsWhichIsRequiredForTests_addressAreNotTheSame);
	CPPUNIT_TEST( checkMetatable_pushAbstract3Pointer_pointersMetatableEqualsAbstract3Metatable);
	CPPUNIT_TEST( checkMetatable_pushConstAbstract3Pointer_pointersMetatableEqualsAbstract3ConstMetatable);


	CPPUNIT_TEST( checkMetatable_pushBaseAndThenDerived_basePointerChangesToUsingDerivedMetatable);
	CPPUNIT_TEST( checkMetatable_pushBaseWithSameAdressAndThenDerived_basePointerChangesToUsingDerivedMetatable);
	CPPUNIT_TEST( checkMetatable_pushConstBaseWithSameAdressAndThenConstDerived_basePointerChangesToUsingConstDerivedMetatable);


	CPPUNIT_TEST( checkMetatable_pushConstBaseWithSameAdressAndThenNoneConstDerived_basePointerChangesToUsingNoneConstDerivedMetatable );

	CPPUNIT_TEST( checkMetatable_pushInstanceThenSameInstanceYetAsConst_firstPushedHasNoneConstMetatable );
	CPPUNIT_TEST( checkMetatable_pushInstanceThenSameInstanceYetAsConst_secondPushedHasNoneConstMetatable );

	CPPUNIT_TEST( checkMetatable_pushConstInstanceThenSameInstanceYetAsNoneConst_firstPushedHasNoneConstMetatable);
	CPPUNIT_TEST( checkMetatable_pushConstInstanceThenSameInstanceYetAsNoneConst_secondPushedHasNoneConstMetatable);


	CPPUNIT_TEST( checkMetatable_pushConstBaseAndThenNoneConstDerived_basePointerChangesToUsingNoneConstDerivedMetatable );
	CPPUNIT_TEST( checkMetatable_pushConstBaseAndThenNoneConstDerived_derivedUsesNoneConstDerivedMetatable );

	CPPUNIT_TEST( checkMetatable_pushConstDerivedAndThenConstBase_derivedUsesConstDerivedMetatable);
	CPPUNIT_TEST( checkMetatable_pushConstDerivedAndThenConstBase_baseUsesConstDerivedMetatable);

	//This test fails and is a limitation of the library
	//CPPUNIT_TEST( differentRootsOfaTree_twoRootsPassedToLua_luaUdComparesEqual );

	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script * m_lua;
public:
    ClassExchange():m_lua(0){}
    LVD_NOCOPY(ClassExchange)
	void setUp()
	{
		m_lua = new OOLUA::Script;
	}
	void tearDown()
	{
		delete m_lua;

	}
	void assert_metatable_of_type_at_index_is_same_as_name(int index, char const* name)
	{
		lua_getmetatable(*m_lua,index);//ud ... metatable
		lua_getfield(*m_lua, LUA_REGISTRYINDEX,name);//ud ... metatable metatable
		int equal_result ( lua_rawequal(*m_lua,-2,-1) );
		int rawequal_returns_1_if_equal(1);
		CPPUNIT_ASSERT_EQUAL(rawequal_returns_1_if_equal , equal_result);
	}

    void BaseAndDerivedPointers_checkThereIsNoOffsetWhichIsRequiredForTests_addressCompareEqual()
    {
        BaseAndDerivedNoOffsets no_offsets(m_lua);
        CPPUNIT_ASSERT_EQUAL_MESSAGE("If this test fails please inform me of which compiler you are using "
                            ,true
                            ,(void*)no_offsets.base_ptr ==(void*)no_offsets.derived_ptr);
    }
    void BaseAndDerivedPointers_checkTheyDoHaveOffsetsWhichIsRequiredForTests_addressAreNotTheSame()
    {
        BaseAndDerivedHaveOffsets no_offsets(m_lua);
        CPPUNIT_ASSERT_EQUAL_MESSAGE("If this test fails please inform me of which compiler you are using "
                            ,false
                            ,(void*)no_offsets.base_ptr ==(void*)no_offsets.derived_ptr);
    }
	void checkMetatable_pushAbstract3Pointer_pointersMetatableEqualsAbstract3Metatable()
	{
		DerivedFromTwoAbstractBasesAndAbstract3 derived;
		Abstract3* base = &derived;
		m_lua->register_class<Abstract3>();
		OOLUA::push2lua(*m_lua,base);//ud

		assert_metatable_of_type_at_index_is_same_as_name(-1,OOLUA::Proxy_class<Abstract3>::class_name);
	}
	void checkMetatable_pushConstAbstract3Pointer_pointersMetatableEqualsAbstract3ConstMetatable()
	{
		DerivedFromTwoAbstractBasesAndAbstract3 derived;
		Abstract3 const * base = &derived;
		m_lua->register_class<Abstract3>();
		OOLUA::push2lua(*m_lua,base);//ud

		assert_metatable_of_type_at_index_is_same_as_name(-1,OOLUA::Proxy_class<Abstract3>::class_name_const);
	}



	void checkMetatable_pushBaseAndThenDerived_basePointerChangesToUsingDerivedMetatable()
	{
		BaseAndDerivedHaveOffsets have_offsets(m_lua);
		OOLUA::push2lua(*m_lua,have_offsets.base_ptr);
		OOLUA::push2lua(*m_lua,have_offsets.derived_ptr);

		assert_metatable_of_type_at_index_is_same_as_name(-2
							,OOLUA::Proxy_class<BaseAndDerivedHaveOffsets::Derived>::class_name);
	}
	void checkMetatable_pushBaseWithSameAdressAndThenDerived_basePointerChangesToUsingDerivedMetatable()
	{
        BaseAndDerivedNoOffsets no_offsets(m_lua);
		OOLUA::push2lua(*m_lua,no_offsets.base_ptr);
		OOLUA::push2lua(*m_lua,no_offsets.derived_ptr);

		assert_metatable_of_type_at_index_is_same_as_name(-2
			,OOLUA::Proxy_class<BaseAndDerivedNoOffsets::Derived>::class_name);
	}
    void checkMetatable_pushConstBaseWithSameAdressAndThenConstDerived_basePointerChangesToUsingConstDerivedMetatable()
	{
        BaseAndDerivedNoOffsets no_offsets(m_lua);
		OOLUA::push2lua(*m_lua,no_offsets.base_ptr_const);
		OOLUA::push2lua(*m_lua,no_offsets.derived_ptr_const);

		assert_metatable_of_type_at_index_is_same_as_name(-2
			,OOLUA::Proxy_class<BaseAndDerivedNoOffsets::Derived>::class_name_const);
	}
	void checkMetatable_pushConstBaseWithSameAdressAndThenNoneConstDerived_basePointerChangesToUsingNoneConstDerivedMetatable()
	{
        BaseAndDerivedNoOffsets no_offsets(m_lua);
		OOLUA::push2lua(*m_lua,no_offsets.base_ptr_const);
		OOLUA::push2lua(*m_lua,no_offsets.derived_ptr);

		assert_metatable_of_type_at_index_is_same_as_name(-2
			,OOLUA::Proxy_class<BaseAndDerivedNoOffsets::Derived>::class_name);
	}











	void checkMetatable_pushInstanceThenSameInstanceYetAsConst_firstPushedHasNoneConstMetatable()
	{
        Class_instance<DerivedFromTwoAbstractBasesAndAbstract3> helper(m_lua);
		OOLUA::push2lua(*m_lua,helper.instance_ptr);
		OOLUA::push2lua(*m_lua,helper.instance_ptr_const);

		assert_metatable_of_type_at_index_is_same_as_name(-2
			,OOLUA::Proxy_class<DerivedFromTwoAbstractBasesAndAbstract3>::class_name);
	}


	void checkMetatable_pushInstanceThenSameInstanceYetAsConst_secondPushedHasNoneConstMetatable()
	{
		Class_instance<DerivedFromTwoAbstractBasesAndAbstract3> helper(m_lua);
		OOLUA::push2lua(*m_lua,helper.instance_ptr);
		OOLUA::push2lua(*m_lua,helper.instance_ptr_const);

		assert_metatable_of_type_at_index_is_same_as_name(-1
			,OOLUA::Proxy_class<DerivedFromTwoAbstractBasesAndAbstract3>::class_name);
	}








	void checkMetatable_pushConstInstanceThenSameInstanceYetAsNoneConst_firstPushedHasNoneConstMetatable()
	{
        Class_instance<DerivedFromTwoAbstractBasesAndAbstract3> helper(m_lua);
		OOLUA::push2lua(*m_lua,helper.instance_ptr_const);
		OOLUA::push2lua(*m_lua,helper.instance_ptr);

		assert_metatable_of_type_at_index_is_same_as_name(-2
			,OOLUA::Proxy_class<DerivedFromTwoAbstractBasesAndAbstract3>::class_name);
	}
	void checkMetatable_pushConstInstanceThenSameInstanceYetAsNoneConst_secondPushedHasNoneConstMetatable()
	{
        Class_instance<DerivedFromTwoAbstractBasesAndAbstract3> helper(m_lua);
		OOLUA::push2lua(*m_lua,helper.instance_ptr_const);
		OOLUA::push2lua(*m_lua,helper.instance_ptr);

		assert_metatable_of_type_at_index_is_same_as_name(-1
			,OOLUA::Proxy_class<DerivedFromTwoAbstractBasesAndAbstract3>::class_name);
	}


	void checkMetatable_pushConstBaseAndThenNoneConstDerived_basePointerChangesToUsingNoneConstDerivedMetatable()
	{
        BaseAndDerivedHaveOffsets have_offsets(m_lua);
		OOLUA::push2lua(*m_lua,have_offsets.base_ptr_const);
		OOLUA::push2lua(*m_lua,have_offsets.derived_ptr);

		assert_metatable_of_type_at_index_is_same_as_name(-2
			,OOLUA::Proxy_class<BaseAndDerivedHaveOffsets::Derived>::class_name);
	}

	void checkMetatable_pushConstBaseAndThenNoneConstDerived_derivedUsesNoneConstDerivedMetatable()
	{
        BaseAndDerivedHaveOffsets have_offsets(m_lua);
		OOLUA::push2lua(*m_lua,have_offsets.base_ptr_const);
		OOLUA::push2lua(*m_lua,have_offsets.derived_ptr);

		assert_metatable_of_type_at_index_is_same_as_name(-1
			,OOLUA::Proxy_class<BaseAndDerivedHaveOffsets::Derived>::class_name);
	}



	void checkMetatable_pushConstDerivedAndThenConstBase_derivedUsesConstDerivedMetatable()
	{
        BaseAndDerivedHaveOffsets have_offsets(m_lua);
		OOLUA::push2lua(*m_lua,have_offsets.derived_ptr_const);
		OOLUA::push2lua(*m_lua,have_offsets.base_ptr_const);

		assert_metatable_of_type_at_index_is_same_as_name(-2
			,OOLUA::Proxy_class<BaseAndDerivedHaveOffsets::Derived>::class_name_const);
	}

	void checkMetatable_pushConstDerivedAndThenConstBase_baseUsesConstDerivedMetatable()
	{
        BaseAndDerivedHaveOffsets have_offsets(m_lua);
		OOLUA::push2lua(*m_lua,have_offsets.derived_ptr_const);
		OOLUA::push2lua(*m_lua,have_offsets.base_ptr_const);

		assert_metatable_of_type_at_index_is_same_as_name(-1
			,OOLUA::Proxy_class<BaseAndDerivedHaveOffsets::Derived>::class_name_const);
	}
	
	//This test fails and is a limitation of the library
	//void differentRootsOfaTree_twoRootsPassedToLua_luaUdComparesEqual()
	//{
	//	OOLUA::register_class_and_bases<DerivedFromTwoAbstractBasesAndAbstract3>(*m_lua);
	//	DerivedFromTwoAbstractBasesAndAbstract3 derived;
	//	Abstract2* a2 = &derived;
	//	Abstract3* a3 = &derived;
	//	OOLUA::push2lua(*m_lua,a2);
	//	OOLUA::push2lua(*m_lua,a3);
	//	OOLUA::INTERNAL::Lua_ud* ud_a2 = static_cast<OOLUA::INTERNAL::Lua_ud*>(lua_touserdata(*m_lua,-2));
	//	OOLUA::INTERNAL::Lua_ud* ud_a3 = static_cast<OOLUA::INTERNAL::Lua_ud*>(lua_touserdata(*m_lua,-1));
	//	CPPUNIT_ASSERT_EQUAL(true,ud_a2 == ud_a3);
	//}
};
CPPUNIT_TEST_SUITE_REGISTRATION(ClassExchange);
