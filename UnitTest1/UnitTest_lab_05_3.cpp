#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_05_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Test_j_formula)         // гілка |x| >= 1
        {
            Assert::AreEqual((cos(1.0) + exp(-1.0)) / (cos(1.0) + 1), j(1));
            Assert::AreEqual((cos(2.0) + exp(-2.0)) / (cos(4.0) + 1), j(2));
            Assert::AreEqual(j(1), j(-1));  // функція парна
        }

        TEST_METHOD(Test_j_series)          // гілка |x| < 1
        {
            Assert::AreEqual(0.0, j(0));    // при x = 0 сума ряду нульова
            Assert::AreEqual(-j(0.5), j(-0.5));  // ряд непарний
        }
    };
}