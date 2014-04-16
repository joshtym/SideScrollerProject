#include <cppunit/ui/text/TestRunner.h>
#include "SideScrollerTestFixture.h"

int main()
{
	/// Main CPP runner testing unit. As the famous GLADoS would say,
	/// "Let us begin testing, for science."
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(SideScrollerTestFixture::suite());
	runner.run();
	
	return 0;
}
