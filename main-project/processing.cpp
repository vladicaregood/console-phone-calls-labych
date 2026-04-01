#include "processing.h"

double process(PhoneCall* records, int n) {
    if (n == 0) return 0.0;

    double totalCost = 0.0;
    int totalSeconds = 0;

    for (int i = 0; i < n; i++) {
        int durSec = records[i].durH * 3600
            + records[i].durM * 60
            + records[i].durS;
        double durMin = durSec / 60.0;
        totalCost += records[i].cost * durMin;
        totalSeconds += durSec;
    }

    if (totalSeconds == 0) return 0.0;
    return totalCost / totalSeconds;
}

//Она принимает массив записей и их количество, проходит по всем записям, суммирует общую стоимость (стоимость_минуты × продолжительность_в_минутах) 
// и общую продолжительность в секундах, затем делит одно на другое и возвращает результат. Если записей нет — возвращает 0.