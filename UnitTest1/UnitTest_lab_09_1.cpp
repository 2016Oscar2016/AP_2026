#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/var.cpp"
#include "../AP_2026/dod.cpp"
#include "../AP_2026/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab91
{
	TEST_CLASS(UnitTestLab91)
	{
	public:

		TEST_METHOD(TestDod)
		{
			nsVar::x = 2;
			nsVar::n = 2;
			nsVar::a = 3;
			nsDod::dod();                       // a = 3 * 2^2 / 2
			Assert::AreEqual(6.0, nsVar::a);
		}

		TEST_METHOD(TestSumZero)
		{
			nsVar::x = 0;
			nsVar::e = 0.5;
			nsSum::sum();                       // e^0 = 1, один доданок
			Assert::AreEqual(1.0, nsVar::s);
			Assert::AreEqual(1, nsVar::n);
		}

		TEST_METHOD(TestSum)
		{
			nsVar::x = 1;
			nsVar::e = 0.5;
			nsSum::sum();                       // 1 + 1 + 0.5
			Assert::AreEqual(2.5, nsVar::s);
			Assert::AreEqual(2, nsVar::n);
		}
	};
}