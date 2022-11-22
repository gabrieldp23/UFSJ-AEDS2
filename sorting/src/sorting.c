#include "sorting.h"

Data createData(char* fileDir) {
    Data data;

    Item* array = (Item*)malloc(sizeof(Item));
    int array_length = 0;

    FILE* file = fopen(fileDir, "r");
    char string[MAX_CHAR_PER_NUMBER];

    while (fgets(string, MAX_CHAR_PER_NUMBER, file) != NULL) {
        array_length++;
        array = (Item*)realloc(array, sizeof(Item) * array_length);

        int number = atoi(string);
        array[array_length - 1].key = number;
    }

    data.array = array;
    data.length = array_length;
    data.comps = 0;
    data.moves = 0;

    return data;
}

void printData(Data* data) {
    for (int i = 0; i < data->length; i++) {
        printf("\n| %d |", data->array[i].key);
    }
}

void printStatistics(Data* data) {
    printf("\n\n=========================");
    printf("\nComparations: %d", data->comps);
    printf("\nMovements: %d", data->moves);
    printf("\n=========================\n\n");
}

void swap(Item* x, Item* y) {
    Item temp = *x;
    *x = *y;
    *y = temp;
}