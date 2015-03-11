#	include "oolua_tests_pch.h"
#	include "common_cppunit_headers.h"
#	include "gmock/gmock.h"

#	include "oolua.h"
#	include "cpp_hierarchy.h"
#	include "expose_hierarchy.h"

#	include <vector>
#	include <string>

//Specialise traits for a vector of strings to provide a meaningfull toString method
namespace CppUnit
{
	template<>
	struct assertion_traits<std::vector<std::string> >
	{
		static bool equal( std::vector<std::string>const & x, std::vector<std::string>const & y )
		{
			return x == y;
		}

		static std::string toString(std::vector<std::string>const &x )
		{
			OStringStream ost;
			for(std::vector<std::string>::const_iterator i = x.begin()
				;i != x.end(); ++i)
			{
				ost << *i <<" ";
			}

			return ost.str();
		}
	};
}

namespace BASE_HELPERS
{
	template<typename TL,int Index,typename T>
	struct AddName;

	template<typename TL,int Index,typename T>
	struct AddName
	{
		void add(std::vector<std::string>& v)
		{
			v.push_back(std::string(OOLUA::Proxy_class<T>::class_name));
			AddName<TL,Index+1,typename TYPELIST::At_default<TL,Index+1,TYPE::Null_type>::Result > adder;
			adder.add(v);
		}
	};

	template<typename TL,int Index>
	struct AddName<TL,Index,TYPE::Null_type>
	{
		void add(std::vector<std::string>& /*v*/)const
		{}
	};

	template<typename AllBases>
	struct AddBaseNamesToVector
	{
		void add(std::vector<std::string> & v)
		{
			AddName<AllBases,0,typename TYPELIST::At_default<AllBases,0,TYPE::Null_type>::Result > adder;
			adder.add(v);
		}
	};



	bool allStringsInRhsContainedInLhs(std::vector<std::string> const& lhs
                                    ,std::vector<std::string> const& rhs)
    {

        for(std::vector<std::string>::const_iterator i = rhs.begin();
			i != rhs.end(); ++i)
        {
            if (std::find(lhs.begin(),lhs.end(),*i) == lhs.end() ) return false;
        }
        return true;
    }

}

template<typename Derived,typename Base>
struct HierarchyPushPull
{
	HierarchyPushPull(lua_State* l):mock(),basemock(&mock),baseFromLua(0)
	{
		OOLUA::push2lua(l,&mock);
		OOLUA::pull2cpp(l,baseFromLua);
	}
	Derived mock;
	Base* basemock;
	Base* baseFromLua;
    HierarchyPushPull():mock(),basemock(0),baseFromLua(0){}
    LVD_NOCOPY(HierarchyPushPull)
};


class Hierarchy : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(Hierarchy);
		CPPUNIT_TEST(call_passedBasePointer_callsFunc1Once);
		CPPUNIT_TEST(call_passedDerivedPointer_callsFunc1Once);
		CPPUNIT_TEST(call_virtualVoidParam3Int_calledOnceWithCorrectInput);
		CPPUNIT_TEST(call_constFunctionOnBaseClass_calledOnce);
		
		CPPUNIT_TEST(pullBase_derviedCreatedInLuaOnStack_returnsNoneNullPtr);
		CPPUNIT_TEST(pullBase_derviedOnStackPullsBase_resultEqualsInputCastToBase);
		CPPUNIT_TEST(pullAbstract1_derviedFromTwoBasesOnStack_resultEqualsInputCastToAbstract1);
		CPPUNIT_TEST(pullAbstract2_derviedFromTwoBasesOnStack_resultEqualsInputCastToAbstract2);
		CPPUNIT_TEST(pullAbstract3_DerivedFromTwoAbstractBasesAndAbstract3OnStack_resultEqualsInputCastToAbstract3);
		CPPUNIT_TEST(pullAbstract2_DerivedFromTwoAbstractBasesAndAbstract3OnStack_resultEqualsInputCastToAbstract2);
		CPPUNIT_TEST(pullAbstract1_DerivedFromTwoAbstractBasesAndAbstract3OnStack_resultEqualsInputCastToAbstract1);
		CPPUNIT_TEST(pullTwoAbstractBases_DerivedFromTwoAbstractBasesAndAbstract3OnStack_resultEqualsInputCastToTwoAbstractBases);

		CPPUNIT_TEST(allBases_DerivedFromTwoAbstractBasesAndAbstract3_lengthEqualsFour);
		CPPUNIT_TEST(rootBases_DerivedFromTwoAbstractBasesAndAbstract3_lengthEqualsThree);

		CPPUNIT_TEST(rootBases_DerivedFromTwoAbstractBasesAndAbstract3_allBaseNamesContainedInVector);
		CPPUNIT_TEST(allBases_DerivedFromTwoAbstractBasesAndAbstract3_orderIsSameAsFunctionHelperReturns);
	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script * m_lua;
public:
    Hierarchy():m_lua(0){}
    LVD_NOCOPY(Hierarchy)
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<Abstract1>();
		m_lua->register_class<Abstract2>();
		m_lua->register_class<Abstract3>();
		m_lua->register_class<Derived1Abstract1>();
		m_lua->register_class<TwoAbstractBases>();
		m_lua->register_class<DerivedFromTwoAbstractBasesAndAbstract3>();

	}
	void tearDown()
	{
		delete m_lua;
	}
	void call_passedBasePointer_callsFunc1Once()
	{
		Derived1Abstract1 mock;
		Abstract1* base = &mock;

		EXPECT_CALL(mock,func1())
			.Times(1);
		m_lua->run_chunk("func = function(obj) obj:func1() end");
		m_lua->call("func",base);
	}

	void call_passedDerivedPointer_callsFunc1Once()
	{
		Derived1Abstract1 mock;
		EXPECT_CALL(mock,func1())
			.Times(1);
		m_lua->run_chunk("func = function(obj) obj:func1() end");
		m_lua->call("func",&mock);
	}
	void call_virtualVoidParam3Int_calledOnceWithCorrectInput()
	{
		Derived1Abstract1 mock;
		int i1(1);int i2(2);int i3(3);
		EXPECT_CALL(mock,
					virtualVoidParam3Int(::testing::Eq(i1)
										,::testing::Eq(i2)
										,::testing::Eq(i3)))
					.Times(1);

		m_lua->run_chunk(
				"func = function(obj,i1,i2,i3) \n"
					"obj:virtualVoidParam3Int(i1,i2,i3) \n"
				"end");
		m_lua->call("func",&mock,i1,i2,i3);
	}

	void call_constFunctionOnBaseClass_calledOnce()
	{
		TwoAbstractBases mock;
		EXPECT_CALL(mock,constVirtualFunction()).Times(1);
		
		m_lua->run_chunk("foo=function(obj) "
							"obj:constVirtualFunction() "
						 "end");
		m_lua->call("foo",(Abstract2*)&mock);
	}

	void pullBase_derviedCreatedInLuaOnStack_returnsNoneNullPtr()
	{
		m_lua->run_chunk(
				"func = function() \n"
					"return Derived1Abstract1:new() \n"
				"end");
		m_lua->call("func");
		OOLUA::cpp_acquire_ptr<Abstract1*> base;
		OOLUA::pull2cpp(*m_lua,base);
		std::auto_ptr<Abstract1> deletePtr(base.m_ptr);
		CPPUNIT_ASSERT_EQUAL(false,base.m_ptr == static_cast<Abstract1*>(0));
	}
	void pullBase_derviedOnStackPullsBase_resultEqualsInputCastToBase()
	{
		HierarchyPushPull<Derived1Abstract1,Abstract1> helper(*m_lua);
		CPPUNIT_ASSERT_EQUAL(helper.basemock, helper.baseFromLua );
	}
	void pullAbstract1_derviedFromTwoBasesOnStack_resultEqualsInputCastToAbstract1()
	{
		HierarchyPushPull<TwoAbstractBases,Abstract1> helper(*m_lua);
		CPPUNIT_ASSERT_EQUAL(helper.basemock, helper.baseFromLua );
	}
	void pullAbstract2_derviedFromTwoBasesOnStack_resultEqualsInputCastToAbstract2()
	{
		HierarchyPushPull<TwoAbstractBases,Abstract2> helper(*m_lua);
		CPPUNIT_ASSERT_EQUAL(helper.basemock, helper.baseFromLua );
	}
	void pullTwoAbstractBases_DerivedFromTwoAbstractBasesAndAbstract3OnStack_resultEqualsInputCastToTwoAbstractBases()
	{
		HierarchyPushPull<DerivedFromTwoAbstractBasesAndAbstract3,TwoAbstractBases> helper(*m_lua);
		CPPUNIT_ASSERT_EQUAL(helper.basemock, helper.baseFromLua );
	}
	void pullAbstract3_DerivedFromTwoAbstractBasesAndAbstract3OnStack_resultEqualsInputCastToAbstract3()
	{
		HierarchyPushPull<DerivedFromTwoAbstractBasesAndAbstract3,Abstract3> helper(*m_lua);
		CPPUNIT_ASSERT_EQUAL(helper.basemock, helper.baseFromLua );
	}
	void pullAbstract2_DerivedFromTwoAbstractBasesAndAbstract3OnStack_resultEqualsInputCastToAbstract2()
	{
		HierarchyPushPull<DerivedFromTwoAbstractBasesAndAbstract3,Abstract2> helper(*m_lua);
		CPPUNIT_ASSERT_EQUAL(helper.basemock, helper.baseFromLua );
	}
	void pullAbstract1_DerivedFromTwoAbstractBasesAndAbstract3OnStack_resultEqualsInputCastToAbstract1()
	{
		HierarchyPushPull<DerivedFromTwoAbstractBasesAndAbstract3,Abstract1> helper(*m_lua);
		CPPUNIT_ASSERT_EQUAL(helper.basemock, helper.baseFromLua );
	}

	void allBases_DerivedFromTwoAbstractBasesAndAbstract3_lengthEqualsFour()
	{
		int result_length(TYPELIST::Length<OOLUA::Proxy_class<DerivedFromTwoAbstractBasesAndAbstract3>::AllBases>::value);
		CPPUNIT_ASSERT_EQUAL(int(4),result_length);
	}
	void rootBases_DerivedFromTwoAbstractBasesAndAbstract3_lengthEqualsThree()
	{
        int result_length(TYPELIST::Length<OOLUA::INTERNAL::FindRootBases<DerivedFromTwoAbstractBasesAndAbstract3>::Result>::value);
        CPPUNIT_ASSERT_EQUAL(int(3),result_length);
	}

    void rootBases_DerivedFromTwoAbstractBasesAndAbstract3_allBaseNamesContainedInVector()
	{
		std::vector<std::string> roots;
		BASE_HELPERS::AddBaseNamesToVector<OOLUA::INTERNAL::FindRootBases<DerivedFromTwoAbstractBasesAndAbstract3>::Result> adder;
		adder.add(roots);
		std::vector<std::string> shouldContain = BASE_HELPERS::rootBasesOfDerivedFromTwoAbstractBasesAndAbstract3();
		CPPUNIT_ASSERT_EQUAL(true, BASE_HELPERS::allStringsInRhsContainedInLhs(roots,shouldContain));
	}
    void allBases_DerivedFromTwoAbstractBasesAndAbstract3_orderIsSameAsFunctionHelperReturns()
	{
		std::vector<std::string> bases;
		BASE_HELPERS::AddBaseNamesToVector<OOLUA::Proxy_class<DerivedFromTwoAbstractBasesAndAbstract3>::AllBases> adder;
		adder.add(bases);
		std::vector<std::string> shouldContain = BASE_HELPERS::allBasesOfDerivedFromTwoAbstractBasesAndAbstract3();
		//assert_vectors_are_equal(bases, shouldContain);
		CPPUNIT_ASSERT_EQUAL(shouldContain, bases);
	}

};



CPPUNIT_TEST_SUITE_REGISTRATION( Hierarchy );

