#include "sorting.h"

void inserctionSort(Data* data) {
    for (int i = 1; i < data->length; i++) {
        Item aux = data->array[i];
        int j = i - 1;

        data->comps++;
        data->moves++;

        while (j >= 0 && data->array[j].key > aux.key) {
            data->array[j + 1] = data->array[j];
            j--;

            data->comps++;
            data->moves++;
        }

        data->array[j + 1] = aux;

        data->moves++;
    }
}