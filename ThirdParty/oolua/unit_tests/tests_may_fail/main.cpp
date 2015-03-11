

#		include <fstream>
#		include "cppunit/CompilerOutputter.h"
#		include "cppunit/extensions/TestFactoryRegistry.h"
#		include "cppunit/ui/text/TestRunner.h"


int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

#	ifdef USING_XML_OUTPUT
		CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();
		CPPUNIT_NS::TextTestRunner runner;
		std::ofstream stream("tests.xml");
		CPPUNIT_NS::XmlOutputter* xml = new CPPUNIT_NS::XmlOutputter(&runner.result(),stream);
		xml->setStyleSheet("report.xsl");
		runner.setOutputter(xml);
		runner.addTest( suite );
		//return runner.run() ? 0 : 1;
		bool result = runner.run();
		//as they may fail lets not brake a build yet just report the error
		//return 0;
		return !result;
#	else
		CppUnit::TextUi::TestRunner runner;
		CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
		runner.addTest( registry.makeTest() );
		runner.run( "", false );
		//as they may fail lets not brake a build yet just report the error
		//return 0;
		return !runner.run( "", false );
#	endif


}

