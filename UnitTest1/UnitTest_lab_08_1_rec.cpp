#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_08_1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab081rec
{
	TEST_CLASS(UnitTestlab081rec)
	{
	public:

		TEST_METHOD(TestThirdComma)
		{
			char s[] = "1,22,3,4";
			int i = ThirdComma(s, 0, 0);
			Assert::AreEqual(6, i);
		}

		TEST_METHOD(TestChange)
		{
			char s[] = "1,22,3,4";
			char dest[20] = "";
			char* d = Change(dest, s, dest, 0);
			Assert::AreEqual("1**22**3**4", d);
		}
	};
}