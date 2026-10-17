#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_2026/lab_05_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Test_Power_value)
        {
            int depth = 0;
            Assert::AreEqual(1024, Power(2, 10, 0, depth));     // p парне
            Assert::AreEqual(1594323, Power(3, 13, 0, depth));  // p непарне
            Assert::AreEqual(125, Power(5, 3, 0, depth));
            Assert::AreEqual(1, Power(7, 0, 0, depth));         // p = 0
        }

        TEST_METHOD(Test_Power_depth)
        {
            int depth = 0;
            Power(3, 13, 0, depth);     // p: 13, 6, 3, 1, 0
            Assert::AreEqual(4, depth);
            Power(5, 3, 0, depth);      // p: 3, 1, 0
            Assert::AreEqual(2, depth);
        }
    };
}