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
    int comps, moves;
} Statistics;

typedef struct {
    Item* array;
    int length;
    Statistics counter;
} Data;

Data createArray(char* fileDir);
void printArray(Item* array, int length);
void printStatistics(Statistics counter);
void swap(Item* x, Item* y);

#endif