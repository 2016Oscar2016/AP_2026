#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_06_4_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCreate)
        {
            int t[8];
            Create(t, 8, -5, 5, 0);
            Assert::IsTrue(t[0] >= -5 && t[0] <= 5);     // перший елемент в діапазоні
            Assert::IsTrue(t[4] >= -5 && t[4] <= 5);     // середній
            Assert::IsTrue(t[7] >= -5 && t[7] <= 5);     // останній
        }

        TEST_METHOD(TestProductEven)
        {
            int t[8] = { 2, 1, 3, 0, -4, 0, 5, -1 };
            Assert::AreEqual(-120, ProductEven(t, 8, 0));      // 2 * 3 * (-4) * 5
        }

        TEST_METHOD(TestFirstZero)
        {
            int t[8] = { 2, 1, 3, 0, -4, 0, 5, -1 };
            int b[3] = { 1, 2, 3 };
            Assert::AreEqual(3, FirstZero(t, 8, 0));
            Assert::AreEqual(-1, FirstZero(b, 3, 0));         // нулів немає
        }

        TEST_METHOD(TestLastZero)
        {
            int t[8] = { 2, 1, 3, 0, -4, 0, 5, -1 };
            Assert::AreEqual(5, LastZero(t, 7));
        }

        TEST_METHOD(TestSumBetween)
        {
            int t[8] = { 2, 1, 3, 0, -4, 0, 5, -1 };
            Assert::AreEqual(-4, SumBetween(t, 5, 4));         // між нулями на індексах 3 і 5 є тільки -4
        }

        TEST_METHOD(TestRearrange)
        {
            int t[8] = { 2, -1, 3, 0, -4, 5, -2, 1 };
            Rearrange(t, 8, 0);
            Assert::AreEqual(2, t[0]);                   // спочатку невід'ємні в тому ж порядку
            Assert::AreEqual(3, t[1]);
            Assert::AreEqual(0, t[2]);
            Assert::AreEqual(5, t[3]);
            Assert::AreEqual(1, t[4]);
            Assert::AreEqual(-1, t[5]);                  // потім від'ємні в тому ж порядку
            Assert::AreEqual(-4, t[6]);
            Assert::AreEqual(-2, t[7]);
        }
    };
}