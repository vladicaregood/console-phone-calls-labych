#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "constants.h"
#include "phone_call.h"
#include "file_reader.h"
#include "filter.h"
#include "sort.h"

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

        if (choice == 1) {
            PhoneCall filtered[MAX_RECORDS];
            int count = filterRecords(records, n, filtered, isMobile);
            std::cout << "Naydeno: " << count << "\n";
            printAll(filtered, count);
        }
        else if (choice == 2) {
            PhoneCall filtered[MAX_RECORDS];
            int count = filterRecords(records, n, filtered, isNovember2021);
            std::cout << "Naydeno: " << count << "\n";
            printAll(filtered, count);
        }
        else if (choice == 3) {
            PhoneCall* ptrs[MAX_RECORDS];
            for (int i = 0; i < n; i++) ptrs[i] = &records[i];

            SortFunc sorts[2] = { heapSort, quickSort };
            std::cout << "Metod sortirovki:\n";
            std::cout << "1 - Piramidalnaya\n";
            std::cout << "2 - Bystraya\n";
            std::cout << "Vybor: ";
            int sm; std::cin >> sm;
            if (sm < 1 || sm > 2) { std::cout << "Neverno\n"; continue; }

            CompareFunc cmps[2] = { cmpByDurationDesc, cmpByNumberThenCostDesc };
            std::cout << "Kriteriy:\n";
            std::cout << "1 - Po ubyvaniyu prodolzhitelnosti\n";
            std::cout << "2 - Po nomeru i stoimosti\n";
            std::cout << "Vybor: ";
            int cm; std::cin >> cm;
            if (cm < 1 || cm > 2) { std::cout << "Neverno\n"; continue; }

            sorts[sm - 1](ptrs, n, cmps[cm - 1]);

            for (int i = 0; i < n; i++)
                printf("%s %02d.%02d.%02d %02d:%02d:%02d %02d:%02d:%02d %s %.2f\n",
                    ptrs[i]->number,
                    ptrs[i]->day, ptrs[i]->month, ptrs[i]->year,
                    ptrs[i]->startH, ptrs[i]->startM, ptrs[i]->startS,
                    ptrs[i]->durH, ptrs[i]->durM, ptrs[i]->durS,
                    ptrs[i]->tariff, ptrs[i]->cost);
        }
    }
    return 0;
}