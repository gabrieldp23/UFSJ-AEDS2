#include <stdio.h>

#define MAX_SIZE 6
#define SLOTS 11

#define EMPTY -1
#define REMOVED -2
typedef int hashType;

hashType* createHashTable(int length) {
    hashType* newHashTable = (hashType*)(malloc(length * sizeof(hashType)));
    for (int i = 0; i < length; i++) {
        newHashTable[i] = EMPTY;
    }
    return newHashTable;
}

void printHashTable(hashType* hashTable, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d = |%d|\n", i, hashTable[i]);
    }
    printf("\n");
}

int getIndexFromElement(hashType element) {
    int key = element;
    int index = key % SLOTS;
    return index;
}

void insertElement(hashType* hashTable, hashType element) {
    int index = getIndexFromElement(element);

    int counter = 0;
    while (hashTable[index] != EMPTY && counter < SLOTS) {
        index = ++index % SLOTS;
        counter++;
    }

    if (counter == SLOTS) {
        // array full error
        return;
    }

    hashTable[index] = element;
}

int searchElementIndex(hashType* hashTable, hashType element) {
    int index = getIndexFromElement(element);

    int counter = 0;
    while (hashTable[index] != element && hashTable[index] != EMPTY && counter < SLOTS) {
        index = ++index % SLOTS;
        counter++;
    }

    if (hashTable[index] == EMPTY) {
        // element not assigned error
        return -1;
    }
    if (counter == SLOTS) {
        // array full and element did not found error
        return -1;
    }

    return index;
}

void removeElement(hashType* hashTable, hashType element) {
    int index = searchElementIndex(hashTable, element);
    if (index == -1) {
        // element not found error
        return;
    }

    hashTable[index] = REMOVED;
}

int printMenu() {
    int input;

    printf(
        "(0) Exit Program\n"
        "(1) Insert Element\n"
        "(2) Search Element\n"
        "(3) Remove Element\n"
        "(4) Print Table\n");

    printf("Type the operation: ");
    scanf("%d", &input);
    return input;
}

void printMessage(char* message) {
    printf("\n==============================\n");
    printf("%s", message);
    printf("\n==============================\n\n");
}

void main() {
    hashType* hashTable = createHashTable(SLOTS);

    int option;
    do {
        option = printMenu();
        switch (option) {
            case 0:
                printMessage("Exit Program");
                free(hashTable);
                break;
            case 1:
                printMessage("Insert Element");
                printf("Element to be inserted: ");
                hashType elementToInsert;
                scanf("%d", &elementToInsert);
                printf("\n");
                insertElement(hashTable, elementToInsert);
                break;
            case 2:
                printMessage("Search Element");
                printf("Element to be searched: ");
                hashType elementToSearch;
                scanf("%d", &elementToSearch);
                printf("\n");
                printf("Index: %d\n\n", searchElementIndex(hashTable, elementToSearch));
                break;
            case 3:
                printMessage("Remove Element");
                printf("Element to be removed: ");
                hashType elementToRemove;
                scanf("%d", &elementToRemove);
                printf("\n");
                removeElement(hashTable, elementToRemove);
                break;
            case 4:
                printMessage("Print Table");
                printHashTable(hashTable, SLOTS);
                break;
            default:
                printMessage("Invalid Operation");
                break;
        }
    } while (option != 0);
}