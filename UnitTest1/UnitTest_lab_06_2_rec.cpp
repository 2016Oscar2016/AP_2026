#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_06_2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCreate)
        {
            int a[10];
            Create(a, 10, -10, 10, 0);
            Assert::IsTrue(a[0] >= -10 && a[0] <= 10);     // перший елемент в діапазоні
            Assert::IsTrue(a[5] >= -10 && a[5] <= 10);     // середній
            Assert::IsTrue(a[9] >= -10 && a[9] <= 10);     // останній
        }

        TEST_METHOD(TestSwap)
        {
            int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            Swap(a, 5, 0);                   // n = 5, масив з 2n = 10 елементів
            Assert::AreEqual(6, a[0]);      // було 1
            Assert::AreEqual(7, a[1]);
            Assert::AreEqual(10, a[4]);     // було 5
            Assert::AreEqual(1, a[5]);      // було 6
            Assert::AreEqual(2, a[6]);
            Assert::AreEqual(5, a[9]);      // було 10
        }
    };
}