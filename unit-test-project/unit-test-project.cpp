#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/phone_call.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(unittestproject)
    {
    public:

        // Тест 1: один разговор, 60 секунд, стоимость 1 руб/мин = 1/60 руб/сек
        TEST_METHOD(TestOneCall)
        {
            PhoneCall records[1];
            strcpy_s(records[0].number, "+380441234567");
            records[0].durH = 0; records[0].durM = 1; records[0].durS = 0;
            records[0].cost = 1.0;

            double result = process(records, 1);
            Assert::AreEqual(1.0 / 60.0, result, 1e-9);
        }

        // Тест 2: два разговора
        // 1й: 120 сек, 2 руб/мин => стоимость = 2*2/1 = 4 руб
        // 2й: 60 сек, 3 руб/мин => стоимость = 3*1/1 = 3 руб
        // итого: 7 руб за 180 сек => 7/180 руб/сек
        TEST_METHOD(TestTwoCalls)
        {
            PhoneCall records[2];
            strcpy_s(records[0].number, "+380441234567");
            records[0].durH = 0; records[0].durM = 2; records[0].durS = 0;
            records[0].cost = 2.0;

            strcpy_s(records[1].number, "+380442345678");
            records[1].durH = 0; records[1].durM = 1; records[1].durS = 0;
            records[1].cost = 3.0;

            double result = process(records, 2);
            Assert::AreEqual(7.0 / 180.0, result, 1e-9);
        }

        // Тест 3: ноль записей — должен вернуть 0
        TEST_METHOD(TestNoCalls)
        {
            PhoneCall records[1];
            double result = process(records, 0);
            Assert::AreEqual(0.0, result, 1e-9);
        }

    };
}