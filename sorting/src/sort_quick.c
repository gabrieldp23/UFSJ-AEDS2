#include "sorting.h"

int partition(Data* data, int low, int high) {
    int pivot = data->array[high].key;

    int i = low;

    for (int j = low; j < high; j++) {
        if (data->array[j].key <= pivot) {
            swap(&data->array[i], &data->array[j]);
            i++;

            data->comps++;
            data->moves += 3;
        }
    }

    swap(&data->array[i], &data->array[high]);
    data->moves += 3;

    return i;
}

void quickSortRecursion(Data* data, int low, int high) {
    if (low < high) {
        int pivot = partition(data, low, high);
        quickSortRecursion(data, low, pivot - 1);
        quickSortRecursion(data, pivot + 1, high);
    }
}

void quickSort(Data* data) {
    quickSortRecursion(data, 0, data->length - 1);
}
