#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_06_3_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestSumSquares)
        {
            int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            Assert::AreEqual(385, SumSquares(a, 10));          // звичайна функція
        }

        TEST_METHOD(TestSumSquaresInt)
        {
            int a[3] = { -3, 4, 0 };
            Assert::AreEqual(25, SumSquares<int>(a, 3));       // шаблон для int: 9 + 16 + 0
        }

        TEST_METHOD(TestSumSquaresDouble)
        {
            double b[3] = { 1.5, 2.0, 0.5 };
            Assert::AreEqual(6.5, SumSquares<double>(b, 3));   // шаблон для double: 2.25 + 4 + 0.25
        }
    };
}