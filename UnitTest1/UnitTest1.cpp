#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_05_1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t;
			t = g(2, 2);
			Assert::AreEqual(t, 0.5);
		}
	};
}
