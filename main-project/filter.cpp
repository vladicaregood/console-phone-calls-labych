#include <cstring>
#include "filter.h"

int filterRecords(PhoneCall* src, int n, PhoneCall* dst,
    bool (*criterion)(const PhoneCall&)) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (criterion(src[i]))
            dst[count++] = src[i];
    return count;
}

bool isMobile(const PhoneCall& r) {
    return strcmp(r.tariff, "мобильный") == 0;
}

bool isNovember2021(const PhoneCall& r) {
    return r.month == 11 && r.year == 21;
}