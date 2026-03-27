#pragma once
#include "constants.h"

struct PhoneCall {
    char number[MAX_STRING];    // номер вызываемого абонента
    int day, month, year;       // дата: дд.мм.гг
    int startH, startM, startS; // время начала чч:мм:сс
    int durH, durM, durS;       // продолжительность чч:мм:сс
    char tariff[MAX_STRING];    // тариф
    double cost;                // стоимость 1 минуты
};