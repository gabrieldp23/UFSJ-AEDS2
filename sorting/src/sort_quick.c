#include "sorting.h"

int partition(Item* array, int low, int high, Statistics* counter) {
    int i = low;
    int pivot = array[high].key;

    for (int j = low; j < high; j++) {
        if (array[j].key <= pivot) {
            counter->comps++;

            swap(&array[i], &array[j]);
            counter->moves += 3;

            i++;
        }
    }

    if (i != high) {
        swap(&array[i], &array[high]);
        counter->moves += 3;
    }

    return i;
}

void quickSortRecursion(Item* array, int low, int high, Statistics* counter) {
    if (low < high) {
        int pivot = partition(array, low, high, counter);
        quickSortRecursion(array, low, pivot - 1, counter);
        quickSortRecursion(array, pivot + 1, high, counter);
    }
}

void quickSort(Item* array, int length, Statistics* counter) {
    quickSortRecursion(array, 0, length - 1, counter);
}
