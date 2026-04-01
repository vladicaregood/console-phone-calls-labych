#include <cstring>
#include "filter.h"

int filterRecords(PhoneCall* src, int n, PhoneCall* dst, //src исход мас, dst для отфильтр
    bool (*criterion)(const PhoneCall&)) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (criterion(src[i]))
            dst[count++] = src[i];
    return count;
} //функция фильтрации записей о звонках

bool isMobile(const PhoneCall& r) {
    return strcmp(r.tariff, "mob") == 0;
}

bool isNovember2021(const PhoneCall& r) {
    return r.month == 11 && r.year == 21;
}