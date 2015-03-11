#	include "oolua_tests_pch.h"
#	include "oolua.h"

#	include "common_cppunit_headers.h"

struct Int_wrapper{int i;};

int equal(lua_State* s)
{
	Int_wrapper* i1 = static_cast<Int_wrapper *>( lua_touserdata(s, 1) );
	Int_wrapper* i2 = static_cast<Int_wrapper *>( lua_touserdata(s, 2) );
	lua_pushboolean(s, i1->i == i2->i ? 1 : 0 );
	return 1;
}
class MetatableEqual : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(MetatableEqual);
	CPPUNIT_TEST(equal_luaTablesWithDifferentMetatables_assertsTrue);
	CPPUNIT_TEST(equal_userdataWithDifferentMetatables_returnsTrue);
	CPPUNIT_TEST_SUITE_END();

	OOLUA::Script * m_lua;
public:
    MetatableEqual():m_lua(0){}
    LVD_NOCOPY(MetatableEqual)
	void setUp()
	{
		m_lua = new OOLUA::Script;
	}
	void tearDown()
	{
		delete m_lua;
	}
	void equal_luaTablesWithDifferentMetatables_assertsTrue()
	{
		std::string chunk(" mt1 = {} \
						  mt2 = {} \
						  equal = function (lhs, rhs) \
							return lhs.i == rhs.i \
						  end \
						  mt1[\"__eq\"] = equal \
						  mt2[\"__eq\"] = equal \
						  t1 = {} \
						  setmetatable(t1,mt1) \
						  t2 = {} \
						  setmetatable(t2,mt2) \
						  t1.i = 1 \
						  t2.i = 1 \
						  assert(t1 == t2) \
						  ");
		m_lua->run_chunk(chunk);
	}

	//When setting closures in Lua, metamethods are inserted in both const and none
	//constant metatables. For some operators to work the same closure needs to be set
	//as there is a raw equal called(does not call meta method __index).
	//Pushing the same function pointer to each table causes a fail, instead the closure
	//should be pushed onto the stack and its index re-pushed when it is required.
	void equal_userdataWithDifferentMetatables_returnsTrue()
	{
		lua_State* s = luaL_newstate();
		std::string chunk("equal = function (lhs, rhs) \
						  return lhs == rhs \
						  end");
		luaL_loadbuffer(s,chunk.c_str(),chunk.size(),"userChunk");
		lua_pcall(s,0,LUA_MULTRET,0);
		//lua_getfield(s, LUA_GLOBALSINDEX, "equal");
		lua_getglobal(s,"equal");

		luaL_newmetatable(s, "mt1");
		int mt1 = lua_gettop(s);
		luaL_newmetatable(s, "mt2");
		int mt2 = lua_gettop(s);

		lua_pushcfunction(s, &equal);
		int func = lua_gettop(s);
		lua_pushliteral(s, "__eq" );
		int metaname = lua_gettop(s);

		lua_pushvalue(s,metaname);
		lua_pushvalue(s,func);
		lua_settable(s, mt1);

		lua_pushvalue(s,metaname);
		lua_pushvalue(s,func);
		lua_settable(s, mt2);

		lua_remove(s,metaname);
		lua_remove(s,func);

		Int_wrapper* wrapper1 = static_cast<Int_wrapper*>(lua_newuserdata(s, sizeof(Int_wrapper)));
		int w1 = lua_gettop(s);
		lua_pushvalue(s,mt1);
		lua_setmetatable(s,w1);

		Int_wrapper* wrapper2 = static_cast<Int_wrapper*>(lua_newuserdata(s, sizeof(Int_wrapper)));
		int w2 = lua_gettop(s);
		lua_pushvalue(s,mt2);
		lua_setmetatable(s,w2);

		wrapper1->i = wrapper2->i = 1;
		lua_remove(s,mt2);
		lua_remove(s,mt1);

		lua_pcall(s,2,LUA_MULTRET,0);
		bool result = lua_toboolean(s,-1) == 1? true : false;
		CPPUNIT_ASSERT_EQUAL(true,result);
		lua_close(s);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( MetatableEqual );
