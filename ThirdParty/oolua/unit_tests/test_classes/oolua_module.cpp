#	include "oolua_tests_pch.h"

#	include "common_cppunit_headers.h"
#	include "oolua.h"

#include "expose_stub_classes.h"

class Module : public CppUnit::TestFixture 
{
	CPPUNIT_TEST_SUITE(Module);
#if OOLUA_USE_EXCEPTIONS == 1
	CPPUNIT_TEST(require_requireFindsTheModule_doesNotThrow);
	CPPUNIT_TEST(registersStub1_luaCodeReturnsResultOfStub1New_pullPointerDoesntThrow);
#elif OOLUA_STORE_LAST_ERROR == 1
	CPPUNIT_TEST(require_requireFindsTheModule_runChunkReturnsTrue);
#endif
	CPPUNIT_TEST(require_returnsResultOfRequire_comparesEqualToTableInRegistry);
	CPPUNIT_TEST(registersStub1_luaCodeReturnsTheQueryForStub1_returnsTypeTable);

	CPPUNIT_TEST_SUITE_END();
	
	OOLUA::Script * m_lua;
public:
	Module():m_lua(0){} 
	void setUp()
	{
		m_lua = new OOLUA::Script;
	}
	void tearDown()
	{
		delete m_lua;
	}		
#if OOLUA_USE_EXCEPTIONS == 1
	void require_requireFindsTheModule_doesNotThrow()
	{
		CPPUNIT_ASSERT_NO_THROW(m_lua->run_chunk("require'OOLua'"));
	}
	void registersStub1_luaCodeReturnsResultOfStub1New_pullPointerDoesntThrow()
	{
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("return require('OOLua').Stub1:new()");
		Stub1* c;
		OOLUA::pull2cpp(*m_lua,c);
	}
#elif	OOLUA_STORE_LAST_ERROR == 1
	void require_requireFindsTheModule_runChunkReturnsTrue()
	{
		CPPUNIT_ASSERT_EQUAL(true,m_lua->run_chunk("require'OOLua'"));
	}
#endif
	void require_returnsResultOfRequire_comparesEqualToTableInRegistry()
	{
		m_lua->run_chunk("return require'OOLua'");
		lua_getfield(*m_lua, LUA_REGISTRYINDEX,"OOLua");
		CPPUNIT_ASSERT_EQUAL(lua_topointer(*m_lua, -1), lua_topointer(*m_lua, -2));
	}
	void registersStub1_luaCodeReturnsTheQueryForStub1_returnsTypeTable()
	{
		m_lua->register_class<Stub1>();
		m_lua->run_chunk("return require('OOLua').Stub1");
		CPPUNIT_ASSERT_EQUAL(LUA_TTABLE,lua_type(*m_lua, -1));
	}
};
CPPUNIT_TEST_SUITE_REGISTRATION(Module);


