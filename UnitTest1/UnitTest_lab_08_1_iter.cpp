#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_08_1_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab081iter
{
	TEST_CLASS(UnitTestlab081iter)
	{
	public:

		TEST_METHOD(TestThirdComma)
		{
			char s[] = "1,22,3,4";
			int i = ThirdComma(s);
			Assert::AreEqual(6, i);
		}

		TEST_METHOD(TestChange)
		{
			char s[] = "1,22,3,4";
			char* d = Change(s);
			Assert::AreEqual("1**22**3**4", d);
		}
	};
}