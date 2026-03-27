#include <cstring>
#include "sort.h"

static int durSec(const PhoneCall* r) {
    return r->durH * 3600 + r->durM * 60 + r->durS;
}

int cmpByDurationDesc(const PhoneCall* a, const PhoneCall* b) {
    return durSec(b) - durSec(a);
}

int cmpByNumberThenCostDesc(const PhoneCall* a, const PhoneCall* b) {
    int c = strcmp(a->number, b->number);
    if (c != 0) return c;
    if (b->cost > a->cost) return 1;
    if (b->cost < a->cost) return -1;
    return 0;
}

// ?? Heap Sort ??
static void heapify(PhoneCall** arr, int n, int i, CompareFunc cmp) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && cmp(arr[l], arr[largest]) < 0) largest = l;
    if (r < n && cmp(arr[r], arr[largest]) < 0) largest = r;
    if (largest != i) {
        PhoneCall* tmp = arr[i]; arr[i] = arr[largest]; arr[largest] = tmp;
        heapify(arr, n, largest, cmp);
    }
}

void heapSort(PhoneCall** arr, int n, CompareFunc cmp) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, cmp);
    for (int i = n - 1; i > 0; i--) {
        PhoneCall* tmp = arr[0]; arr[0] = arr[i]; arr[i] = tmp;
        heapify(arr, i, 0, cmp);
    }
}

// ?? Quick Sort ??
static void qsort_(PhoneCall** arr, int lo, int hi, CompareFunc cmp) {
    if (lo >= hi) return;
    PhoneCall* pivot = arr[(lo + hi) / 2];
    int i = lo, j = hi;
    while (i <= j) {
        while (cmp(arr[i], pivot) < 0) i++;
        while (cmp(arr[j], pivot) > 0) j--;
        if (i <= j) {
            PhoneCall* tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
            i++; j--;
        }
    }
    qsort_(arr, lo, j, cmp);
    qsort_(arr, i, hi, cmp);
}

void quickSort(PhoneCall** arr, int n, CompareFunc cmp) {
    if (n > 1) qsort_(arr, 0, n - 1, cmp);
}