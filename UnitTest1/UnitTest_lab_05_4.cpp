#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_05_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Test_one_term)          // сума з одного доданка: K = N = 3
        {
            double e = (cos(3 / 2.) + sin(2. * 3)) / (1 + sin(cos(3)));
            Assert::AreEqual(e, S0(3, 3));
            Assert::AreEqual(e, S1(3, 3, 3));
            Assert::AreEqual(e, S2(3, 3, 3));
            Assert::AreEqual(e, S3(3, 3, 3, 0));
            Assert::AreEqual(e, S4(3, 3, 3, 0));
        }

        TEST_METHOD(Test_two_terms)         // сума з двох доданків: K = 3, N = 4
        {
            double e = (cos(3 / 2.) + sin(2. * 3)) / (1 + sin(cos(3)))
                + (cos(4 / 2.) + sin(2. * 4)) / (1 + sin(cos(4)));
            Assert::AreEqual(e, S0(3, 4));
            Assert::AreEqual(e, S1(3, 4, 3));
            Assert::AreEqual(e, S2(3, 4, 4));
            Assert::AreEqual(e, S3(3, 4, 3, 0));
            Assert::AreEqual(e, S4(3, 4, 4, 0));
        }

        TEST_METHOD(Test_empty_sum)         // K > N: доданків немає
        {
            Assert::AreEqual(0.0, S0(5, 4));
            Assert::AreEqual(0.0, S1(5, 4, 5));
            Assert::AreEqual(0.0, S2(5, 4, 4));
        }
    };
}