#include "sorting.h"

void inserctionSort(Item* array, int length, Statistics* counter) {
    for (int i = 1; i < length; i++) {
        Item aux = array[i];
        counter->moves++;

        int j = i - 1;
        while (j >= 0 && array[j].key > aux.key) {
            counter->comps++;

            array[j + 1] = array[j];
            counter->moves++;

            j--;
        }

        array[j + 1] = aux;
        counter->moves++;
    }
}