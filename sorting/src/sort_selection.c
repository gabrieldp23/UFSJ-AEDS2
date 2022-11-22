#include "sorting.h"

void selectionSort(Data* data) {
    int min;
    for (int i = 0; i < data->length; i++) {
        min = i;
        for (int j = i + 1; j < data->length; j++) {
            if (data->array[j].key < data->array[min].key) {
                min = j;
                data->comps++;
            }
        }
        swap(&data->array[min], &data->array[i]);
        data->moves += 3;  // a swap represents 3 moves
    }
}