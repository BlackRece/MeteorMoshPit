#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
	};
}

namespace GivenATest
{
	TEST_CLASS(WhenATestIsExecuted)
	{
	public:

		TEST_METHOD(ThenTheTestGivesAResult)
		{
			Assert::AreEqual(1, 1);
		}
	};
}