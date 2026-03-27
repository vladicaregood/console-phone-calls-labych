#include <iostream>
#include <cstdio>
#include "constants.h"
#include "phone_call.h"
#include "file_reader.h"

int main() {
    std::cout << "Var 9. Phone calls" << std::endl;
    std::cout << "Vlad Sokolovsky 25ISiT1d" << std::endl;

    PhoneCall records[MAX_RECORDS];
    int n = readData("data.txt", records);
    std::cout << "Zagrusheno zapisey: " << n << std::endl;

    for (int i = 0; i < n; i++) {
        printf("%s %02d.%02d.%02d %02d:%02d:%02d %02d:%02d:%02d %s %.2f\n", //+380441234567 01.11.21 09:00:00 00:05:30 мобильный 3.50
            records[i].number,
            records[i].day, records[i].month, records[i].year,
            records[i].startH, records[i].startM, records[i].startS,
            records[i].durH, records[i].durM, records[i].durS,
            records[i].tariff, records[i].cost);
    }
    return 0;
}