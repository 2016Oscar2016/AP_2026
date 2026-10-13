#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_05_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(Test_All)
        {
            // Перевірка функції g
            Assert::AreEqual(0.5, g(2, 2));
            Assert::AreEqual(0.4, g(2, 1));

            // Перевірка всього виразу при s = 1, t = 2
            double g1 = g(2, 1);
            double g2 = g(2, 1);
            double g3 = g(1, 2);
            double c = (g1 + pow(1 + g2 * g2, 3)) / sqrt(1 + g3 * g3);

            Assert::AreEqual(1.82065, c, 1e-5);
        }
    };
}