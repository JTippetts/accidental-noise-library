#	include "oolua_tests_pch.h"
#	include <vector>
#	include "common_cppunit_headers.h"
#	include "oolua.h"
#	include "expose_vector_int.h"



class Lua_vector_int : public CPPUNIT_NS::TestFixture

{
	CPPUNIT_TEST_SUITE(Lua_vector_int);
		CPPUNIT_TEST(popBack_passedVectorWithOneEntery_vectorsSizeIsZero);
		CPPUNIT_TEST(pushBack_passedEmptyVector_sizeEqualsOne);
		CPPUNIT_TEST(size_passedEmptyVector_returnEqualsZero);
	CPPUNIT_TEST_SUITE_END();
	OOLUA::Script * m_lua;
	vector_int v;
public:
    Lua_vector_int():m_lua(0){}
    LVD_NOCOPY(Lua_vector_int)
	void setUp()
	{
		m_lua = new OOLUA::Script;
		m_lua->register_class<vector_int>();
	}
	void tearDown()
	{
		delete m_lua;
		vector_int m;
		v.swap( m );
	}

	void popBack_passedVectorWithOneEntery_vectorsSizeIsZero()
	{
		m_lua->run_chunk(
				"func = function (v)\n"
					"v:pop_back() \n"
				"end");
		v.push_back(1);
		m_lua->call("func",&v);
		CPPUNIT_ASSERT_EQUAL(vector_int::size_type(0),v.size() );
	}
	void pushBack_passedEmptyVector_sizeEqualsOne()
	{
		m_lua->run_chunk(
				"func = function (v)\n"
					"v:push_back(1) \n"
				"end");
		m_lua->call("func",&v);
		CPPUNIT_ASSERT_EQUAL(vector_int::size_type(1),v.size() );
	}
	void size_passedEmptyVector_returnEqualsZero()
	{
		m_lua->run_chunk(
				"func = function (v)\n"
					"return v:size() \n"
				"end");
		m_lua->call("func",&v);
		int res;
		OOLUA::pull2cpp(*m_lua,res);
		CPPUNIT_ASSERT_EQUAL(int(0), res );
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( Lua_vector_int );
