#pragma once
#include "phone_call.h"

int filterRecords(PhoneCall* src, int n, PhoneCall* dst, bool (*criterion)(const PhoneCall&));
//функция фильтрации записей о звонках
bool isMobile(const PhoneCall& r);
bool isNovember2021(const PhoneCall& r);