#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_05_2_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Test_A)
        {
            Assert::AreEqual(4.0, A(2, 1, 1));    // x^2 / 1! = 4
            Assert::AreEqual(8.0, A(2, 2, 4));    // x^4 / 2! = 8
            Assert::AreEqual(0.5, A(1, 2, 1));    // 1 * 1 / 2 = 0.5
        }

        TEST_METHOD(Test_S)
        {
            int n;
            Assert::AreEqual(1.0, S(0, 0.001, n));    // при x = 0 є тільки перший доданок
            Assert::AreEqual(1, n);
            Assert::AreEqual(2.5, S(1, 0.6, n));      // 1 + 1 + 0.5
            Assert::AreEqual(2, n);
        }
    };
}
