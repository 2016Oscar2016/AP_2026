#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_06_1_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCreate)
        {
            int t[20];
            Create(t, 20, -14, 7);
            Assert::IsTrue(t[0] >= -14 && t[0] <= 7);      // перший елемент в діапазоні
            Assert::IsTrue(t[10] >= -14 && t[10] <= 7);    // середній
            Assert::IsTrue(t[19] >= -14 && t[19] <= 7);    // останній
        }

        TEST_METHOD(TestCount)
        {
            int t[20] = { 4, 5, 0, -2, -2, 6, -7, -13, 2, -7, -13, 4, -1, 0, 3, -2, 6, -10, 1, 6 };
            Assert::AreEqual(6, Count(t, 20));
        }

        TEST_METHOD(TestSum)
        {
            int t[20] = { 4, 5, 0, -2, -2, 6, -7, -13, 2, -7, -13, 4, -1, 0, 3, -2, 6, -10, 1, 6 };
            Assert::AreEqual(25, Sum(t, 20));
        }

        TEST_METHOD(TestZero)
        {
            int t[20] = { 4, 5, 0, -2, -2, 6, -7, -13, 2, -7, -13, 4, -1, 0, 3, -2, 6, -10, 1, 6 };
            Zero(t, 20);
            Assert::AreEqual(0, t[1]);     // 5 -> 0
            Assert::AreEqual(0, t[5]);     // 6 -> 0
            Assert::AreEqual(0, t[19]);    // 6 -> 0
            Assert::AreEqual(4, t[0]);     // індекси 0, 8, 16 кратні 4 -
            Assert::AreEqual(2, t[8]);     // ці елементи не змінились
            Assert::AreEqual(6, t[16]);
            Assert::AreEqual(-2, t[3]);    // від'ємне не змінилось
        }
    };
}