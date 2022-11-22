#include "sorting.h"

void shellSort(Data* data) {
    Item aux;
    int h = 1;

    do {
        h = 3 * h + 1;
    } while (h < data->length);

    do {
        h /= 3;
        for (int i = h; i < data->length; i++) {
            aux = data->array[i];

            data->comps++;
            data->moves++;

            int j = i;
            while (j >= 0 && data->array[j - h].key > aux.key) {
                data->array[j] = data->array[j - h];
                data->comps++;
                data->moves++;
                j -= h;
            }
            data->array[j] = aux;
            data->moves++;
        }
    } while (h > 1);
}