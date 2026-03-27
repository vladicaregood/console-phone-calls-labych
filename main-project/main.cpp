#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "constants.h"
#include "phone_call.h"
#include "file_reader.h"
#include "filter.h"

void printAll(PhoneCall* records, int n) {
    for (int i = 0; i < n; i++)
        printf("%s %02d.%02d.%02d %02d:%02d:%02d %02d:%02d:%02d %s %.2f\n",
            records[i].number,
            records[i].day, records[i].month, records[i].year,
            records[i].startH, records[i].startM, records[i].startS,
            records[i].durH, records[i].durM, records[i].durS,
            records[i].tariff, records[i].cost);
}

int main() {
    std::cout << "Var 9. Phone calls" << std::endl;
    std::cout << "Vlad Sokolovsky 25ISiT1d" << std::endl;

    PhoneCall records[MAX_RECORDS];
    int n = readData("data.txt", records);
    std::cout << "Zagrusheno zapisey: " << n << std::endl;

    int choice = 0;
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1 - Mobilnye razgovory\n";
        std::cout << "2 - Razgovory v noyabre 2021\n";
        std::cout << "3 - Sortirovka\n";
        std::cout << "0 - Vyhod\n";
        std::cout << "Vybor: ";
        std::cin >> choice;
        if (choice == 0) break;

        PhoneCall filtered[MAX_RECORDS];
        int count = 0;

        if (choice == 1)
            count = filterRecords(records, n, filtered, isMobile);
        else if (choice == 2)
            count = filterRecords(records, n, filtered, isNovember2021);
        else if (choice == 3) {
            std::cout << "Sortirovka budet dobavlena pozæå\n";
            continue;
        }

        std::cout << "Naydeno: " << count << "\n";
        printAll(filtered, count);
    }
    return 0;
}