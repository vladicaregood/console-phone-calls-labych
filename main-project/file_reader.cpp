#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "file_reader.h"

int readData(const char* filename, PhoneCall* records) { //чтение-заполнение массива
    FILE* f = fopen(filename, "r"); //r это режим
    if (!f) return 0;
    int n = 0;
    while (n < MAX_RECORDS) {
        PhoneCall& r = records[n]; //отсюда 
        if (fscanf(f, "%s %d.%d.%d %d:%d:%d %d:%d:%d %s %lf", //прикольная штука для формата строки
            r.number,
            &r.day, &r.month, &r.year,
            &r.startH, &r.startM, &r.startS,
            &r.durH, &r.durM, &r.durS,
            r.tariff, &r.cost) != 12) break;
        n++;
    }
    fclose(f);
    return n;
}