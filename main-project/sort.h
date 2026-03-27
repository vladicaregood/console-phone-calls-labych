#pragma once
#include "phone_call.h"

typedef int (*CompareFunc)(const PhoneCall*, const PhoneCall*);
typedef void (*SortFunc)(PhoneCall**, int, CompareFunc);

// Методы сортировки
void heapSort(PhoneCall** arr, int n, CompareFunc cmp);
void quickSort(PhoneCall** arr, int n, CompareFunc cmp);

// Критерии сравнения
int cmpByDurationDesc(const PhoneCall* a, const PhoneCall* b);
int cmpByNumberThenCostDesc(const PhoneCall* a, const PhoneCall* b);