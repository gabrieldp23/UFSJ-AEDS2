#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_PER_NUMBER 20

typedef int KeyType;
typedef struct Item {
    KeyType key;
} Item;

typedef struct {
    Item* array;
    int length;
    int comps, moves;
} Data;

Data createData(char* fileDir);
void printData(Data* data);
void printStatistics(Data* data);
void swap(Item* x, Item* y);

#endif