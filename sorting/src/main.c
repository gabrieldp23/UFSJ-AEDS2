#include "sorting.h"

void selectionSort(Data* data);
void inserctionSort(Data* data);
void shellSort(Data* data);
void quickSort(Data* data);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("\nERROR - CHECK INPUT FILE\n\n");
        return 1;
    }

    Data data = createData(argv[1]);

    /*
        selectionSort(&data);
        inserctionSort(&data);
        shellSort(&data);
    */

    quickSort(&data);

    printData(&data);
    printStatistics(&data);

    return 0;
}