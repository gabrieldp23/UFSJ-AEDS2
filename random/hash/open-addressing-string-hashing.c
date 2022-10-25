#include <stdio.h>
#include <string.h>

#define MAX_SIZE 6
#define SLOTS 11

#define LENGTH 50
#define EMPTY "!!!!!"
#define REMOVED "------"

typedef char hashType[LENGTH];

hashType* createHashTable(int length) {
    hashType* newHashTable = (hashType*)(malloc(length * sizeof(hashType)));
    for (int i = 0; i < length; i++) {
        strcpy(newHashTable[i], EMPTY);
    }
    return newHashTable;
}

void printHashTable(hashType* hashTable, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d = |%s|\n", i, hashTable[i]);
    }
    printf("\n");
}

int getIndexFromElement(hashType element) {
    int key;
    for (int i = 1; i <= strlen(element); i++) {
        key += i * element[i];
    }
    int index = key % SLOTS;
    return index;
}

void insertElement(hashType* hashTable, hashType element) {
    int index = getIndexFromElement(element);

    int counter = 0;
    while (strcmp(hashTable[index], EMPTY) != 0 && counter < SLOTS) {
        index = ++index % SLOTS;
        counter++;
    }

    if (counter == SLOTS) {
        // array full error
        return;
    }

    strcpy(hashTable[index], element);
}

int searchElementIndex(hashType* hashTable, hashType element) {
    int index = getIndexFromElement(element);

    int counter = 0;
    while (strcmp(hashTable[index], element) != 0 && strcmp(hashTable[index], EMPTY) != 0 && counter < SLOTS) {
        index = ++index % SLOTS;
        counter++;
    }
    printf("<<< %s <|> %s >>>>", hashTable[index], element);

    if (strcmp(hashTable[index], EMPTY) == 0) {
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

    strcpy(hashTable[index], REMOVED);
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
                setbuf(stdin, NULL);
                fflush(stdin);
                fgets(elementToInsert, LENGTH - 1, stdin);
                printf("\n");
                insertElement(hashTable, elementToInsert);
                break;
            case 2:
                printMessage("Search Element");
                printf("Element to be searched: ");
                hashType elementToSearch;
                setbuf(stdin, NULL);
                fflush(stdin);
                fgets(elementToSearch, LENGTH - 1, stdin);
                printf("\n");
                printf("Index: %d\n\n", searchElementIndex(hashTable, elementToSearch));
                break;
            case 3:
                printMessage("Remove Element");
                printf("Element to be removed: ");
                hashType elementToRemove;
                setbuf(stdin, NULL);
                fflush(stdin);
                fgets(elementToRemove, LENGTH - 1, stdin);
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