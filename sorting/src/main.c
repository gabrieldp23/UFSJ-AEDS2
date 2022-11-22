#include "sorting.h"

void selectionSort(Item* array, int length, Statistics* counter);
void inserctionSort(Item* array, int length, Statistics* counter);
void shellSort(Item* array, int length, Statistics* counter);
void quickSort(Item* array, int length, Statistics* counter);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("\nERROR - CHECK INPUT FILE\n\n");
        return 1;
    }

    Data data = createArray(argv[1]);

    /*
    selectionSort(data.array, data.length, &data.counter);
    shellSort(data.array, data.length, &data.counter);
    inserctionSort(data.array, data.length, &data.counter);
    */

    quickSort(data.array, data.length, &data.counter);

    printArray(data.array, data.length);
    printStatistics(data.counter);

    return 0;
}