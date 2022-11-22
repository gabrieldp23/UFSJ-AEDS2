#include "sorting.h"

void shellSort(Item* array, int length, Statistics* counter) {
    Item aux;
    int h = 1;

    do {
        h = 3 * h + 1;
    } while (h < length);

    do {
        h /= 3;
        for (int i = h; i < length; i++) {
            counter->comps++;

            aux = array[i];
            counter->moves++;

            int j = i;
            while (j >= h && array[j - h].key > aux.key) {
                counter->comps++;

                array[j] = array[j - h];
                counter->moves++;

                j -= h;
            }

            array[j] = aux;
            counter->moves++;
        }
    } while (h > 1);
}