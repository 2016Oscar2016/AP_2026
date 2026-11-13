#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_08_1_string/lab_08_1_string.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab081string
{
	TEST_CLASS(UnitTestlab081string)
	{
	public:

		TEST_METHOD(TestThirdComma)
		{
			string s = "1,22,3,4";
			int i = ThirdComma(s);
			Assert::AreEqual(6, i);
		}

		TEST_METHOD(TestChange)
		{
			string s = "1,22,3,4";
			string d = Change(s);
			Assert::AreEqual("1**22**3**4", d.c_str());
		}
	};
}