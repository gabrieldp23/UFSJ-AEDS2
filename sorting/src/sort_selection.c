#include "sorting.h"

void selectionSort(Item* array, int length, Statistics* counter) {
    int min;
    for (int i = 0; i < length; i++) {
        min = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j].key < array[min].key) {
                counter->comps++;

                min = j;
            }
        }

        swap(&array[min], &array[i]);
        counter->moves += 3;  // a swap represents 3 moves
    }
}