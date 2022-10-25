#include <stdio.h>
#include <string.h>

#define SLOTS 509
#define MAX_WORD_LENGTH 20

#define EMPTY "-----"

typedef struct ocurrence {
    int line, quantity;
    struct ocurrence* p_prox;
} ocurrence_t;

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    ocurrence_t* first;
} hash;

hash* createHashTable(int length) {
    hash* newHashTable = (hash*)(malloc(length * sizeof(hash)));
    for (int i = 0; i < length; i++) {
        strcpy(newHashTable[i].word, EMPTY);
    }
    return newHashTable;
}

void main() {
    hash* hashTable = createHashTable(SLOTS);
}

// hashTable[i].first = (ocurrence_t*)malloc(sizeof(ocurrence_t));