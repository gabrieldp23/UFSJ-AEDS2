#include "sorting.h"

Data createArray(char* fileDir) {
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
    data.counter.comps = 0;
    data.counter.moves = 0;

    return data;
}

void printArray(Item* array, int length) {
    for (int i = 0; i < length; i++) {
        printf("\n| %d |", array[i].key);
    }
}

void printStatistics(Statistics counter) {
    printf("\n\n=========================");
    printf("\nComparations: %d", counter.comps);
    printf("\nMovements: %d", counter.moves);
    printf("\n=========================\n\n");
}

void swap(Item* x, Item* y) {
    Item temp = *x;
    *x = *y;
    *y = temp;
}