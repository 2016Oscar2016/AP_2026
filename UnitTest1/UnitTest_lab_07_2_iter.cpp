#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_07_2_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCreate)
        {
            int r0[2], r1[2];
            int* a[2] = { r0, r1 };                  // матриця 2 x 2
            Create(a, 2, -20, 20);
            Assert::IsTrue(a[0][0] >= -20 && a[0][0] <= 20);   // перший елемент в діапазоні
            Assert::IsTrue(a[1][1] >= -20 && a[1][1] <= 20);   // останній елемент в діапазоні
        }

        // над побічною діагоналлю: 5, 3, 2 (мінімум 2);
        // під нею: 4, 1, 6 (максимум 6); на діагоналі 7, 9, 8 - не враховуються
        TEST_METHOD(TestSearchMinAbove)
        {
            int r0[3] = { 5, 3, 7 };
            int r1[3] = { 2, 9, 4 };
            int r2[3] = { 8, 1, 6 };
            int* a[3] = { r0, r1, r2 };
            int row = 0;
            int col = 0;
            SearchMinAbove(a, 3, row, col);
            Assert::AreEqual(1, row);
            Assert::AreEqual(0, col);
        }

        TEST_METHOD(TestSearchMaxBelow)
        {
            int r0[3] = { 5, 3, 7 };
            int r1[3] = { 2, 9, 4 };
            int r2[3] = { 8, 1, 6 };
            int* a[3] = { r0, r1, r2 };
            int row = 2;
            int col = 2;
            SearchMaxBelow(a, 3, row, col);
            Assert::AreEqual(2, row);
            Assert::AreEqual(2, col);
        }

        TEST_METHOD(TestSwapElements)
        {
            int r0[3] = { 5, 3, 7 };
            int r1[3] = { 2, 9, 4 };
            int r2[3] = { 8, 1, 6 };
            int* a[3] = { r0, r1, r2 };
            SwapElements(a, 1, 0, 2, 2);             // міняємо 2 і 6
            Assert::AreEqual(6, a[1][0]);
            Assert::AreEqual(2, a[2][2]);
            Assert::AreEqual(5, a[0][0]);            // решта не змінилась
        }

        TEST_METHOD(TestSumTwo)
        {
            int r0[3] = { 5, 3, 7 };
            int r1[3] = { 2, 9, 4 };
            int r2[3] = { 8, 1, 6 };
            int* a[3] = { r0, r1, r2 };
            Assert::AreEqual(8, SumTwo(a, 1, 0, 2, 2));   // 2 + 6
        }
    };
}