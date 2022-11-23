# Internal Sorting

This repository is part of the studies of Algorithms and Data Structures II, containing the implementation of some algorithms used in internal sorting.

&nbsp;

## Description

The main ideia is to make the implementation of these codes simpler, creating a library that can be imported and do away with problems in the base of the program.

[`sorting.h`](./src/sorting.h)

- The file to sort can store any quantity of elements due the realloc() function used.

- Quantity of comparations and movements can be stored using the Statistics registry

&nbsp;

## Sorting Algorithms

### Selection Sort

It consists of looking for the smallest item in the file and replacing it with the first item, repeating the process with the remaining items until reaching the last one.

[`Click here to see the code`](./src/sort_selection.c)

#### Advantages (Selection Sort)

- Linear quantity of movements, only swaps what is needed - great for large registries

- Very insteresting for small files

#### Disadvantages (Selection Sort)

- The file already be sorted will not benefit the algorithm

- Unstable sorting

---

### Inserction

The method goes through the entire array, placing each number in the ideal place at that moment, pushing the next elements forward one position, repeating the process until the last element is placed in the correct slot.

[`Click here to see the code`](./src/sort_inserction.c)

#### Advantages (Inserction Sort)

- Great for almost sorted files

- Great for inserting elements into a sorted file - the cost is linear

- Stable sorting

#### Disadvantages (Inserction Sort)

- Large quantity of movements, very bad for large registries

- Reverse sorted files are the worst case possible

---

### Shell Sort

This algorithm uses decrescent "jumps" to sort array sections until it is equal to 1, when the algorithm transforms itself in a inserction sort, which is great for almost sorted files.

[`Click here to see the code`](./src/sort_shell.c)

The complexity is undefined due its increment sequence, making each one not a multiple of the previous one.

#### Advantages (Shell Sort)

- Great for files with moderate size

- Simple implementation with great results

#### Disadvantages (Shell Sort)

- Execution time depends on original sorting

- Unstable sorting

---

### Quick Sort

A recursive method that divides the file into two different partitions using a chosen pivot item: lower items to the left, higher items to the right. Each partition is sorted with a new recursion choosing a new pivot.

[`Click here to see the code`](./src/sort_quick.c)

#### Advantages (Quick Sort)

- One of the most efficient and used sorting algorithms.

- Needs a small stack to make the recursion calls

- Normal cases takes O(n\*log(n)) comparations

#### Disadvantages (Quick Sort)

- Worst case takes O(n²) comparations

- Not very simple implementation

- Unstable sorting
