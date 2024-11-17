#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4 it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMinAbsElement)
        {
            std::vector<int> testArray = { -3, 0, 5, 8, -2 };
            int result = findMinAbsElement(testArray);
            Assert::AreEqual(0, result); // Мінімальний за модулем елемент має бути 0
        }

        TEST_METHOD(TestSumAfterFirstZero)
        {
            std::vector<int> testArray = { -3, 0, 5, 8, -2 };
            int result = sumAfterFirstZero(testArray);
            Assert::AreEqual(15, result); // Сума після першого 0 має бути 15
        }

        TEST_METHOD(TestTransformArray)
        {
            std::vector<int> testArray = { 24, 2, 12, 5, 4 };
            transformArray(testArray);

            std::vector<int> expectedArray = { 24, 12, 4, 2, 5 }; // Очікуваний результат
            for (int i = 0; i < testArray.size(); ++i) {
                Assert::AreEqual(expectedArray[i], testArray[i]);
            }
        }

    };
}