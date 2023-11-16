#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include <iostream>
#include "../lab_8.1(char)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;




namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountCommas)
        {
            char str1[] = "one,two,three,four";
            Assert::AreEqual(14, CountCommas(str1));

            char str2[] = "alpha,beta,gamma,delta";
            Assert::AreEqual(17, CountCommas(str2));

            char str3[] = "single";
            Assert::AreEqual(-1, CountCommas(str3));
        }
    };
}