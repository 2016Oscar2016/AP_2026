#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_07_1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCreate)
        {
            int r0[6], r1[6];
            int* a[2] = { r0, r1 };                  // матриця з 2 рядків
            CreateRows(a, 2, 6, 8, 73, 0);
            Assert::IsTrue(a[0][0] >= 8 && a[0][0] <= 73);   // перший елемент в діапазоні
            Assert::IsTrue(a[1][5] >= 8 && a[1][5] <= 73);   // останній елемент в діапазоні
        }

        TEST_METHOD(TestChange)
        {
            int r0[6] = { 1, 2, 3, 4, 5, 6 };
            int r1[6] = { 7, 8, 9, 10, 11, 12 };
            int* a[2] = { r0, r1 };
            Change(a, 0, 1, 6, 0);
            Assert::AreEqual(7, a[0][0]);            // рядки помінялись місцями
            Assert::AreEqual(12, a[0][5]);
            Assert::AreEqual(1, a[1][0]);
            Assert::AreEqual(6, a[1][5]);
        }

        TEST_METHOD(TestSort)
        {
            int r0[6] = { 5, 1, 0, 7, 0, 0 };
            int r1[6] = { 3, 2, 0, 1, 0, 0 };
            int r2[6] = { 5, 4, 0, 2, 0, 0 };
            int r3[6] = { 5, 4, 0, 9, 0, 0 };
            int* a[4] = { r0, r1, r2, r3 };
            Sort(a, 4, 6, 0);
            Assert::AreEqual(3, a[0][0]);            // найменше в 1-му стовпчику - перше
            Assert::AreEqual(5, a[1][0]);            // далі п'ятірки: 2-й стовпчик за спаданням (4, 4, 1)
            Assert::AreEqual(4, a[1][1]);
            Assert::AreEqual(9, a[1][3]);            // однакові 5 і 4: 4-й стовпчик за спаданням (9, 2)
            Assert::AreEqual(4, a[2][1]);
            Assert::AreEqual(2, a[2][3]);
            Assert::AreEqual(1, a[3][1]);
        }

        TEST_METHOD(TestCalc)
        {
            int r0[6] = { 8, 10, 16, 3, 12, 7 };
            int r1[6] = { 24, 18, 5, 14, 9, 2 };
            int* a[2] = { r0, r1 };
            int S = 0;
            int k = 0;
            CalcRows(a, 2, 6, S, k, 0);
            Assert::AreEqual(128, S);                // сума всіх заданих елементів
            Assert::AreEqual(12, k);                 // кількість заданих елементів
            Assert::AreEqual(0, a[0][1]);            // елементи замінено нулями
            Assert::AreEqual(0, a[1][5]);
        }
    };
}