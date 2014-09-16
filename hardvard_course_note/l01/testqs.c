#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "allowexec.h"
#include "hexdump.h"

extern void qs(int* array, int n);

static void iswap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void initialize_up(int* array, int n) {
    for (int i = 0; i < n; ++i)
        array[i] = i + 1;
}

void initialize_down(int* array, int n) {
    for (int i = 0; i < n; ++i)
        array[i] = n - i;
}

void initialize_random(int* array, int n) {
    for (int i = 0; i < n; ++i)
        array[i] = i + 1;
    for (int i = 0; i < n; ++i)
        iswap(&array[i], &array[random() % n]);
}

void initialize_magic(int* array, int n) {
    for (int i = 1; i <= n; ++i) {
        int middle = i / 2;
        array[i - 1] = array[middle];
        array[middle] = i;
    }
}

unsigned array_checksum(const int* array, int n) {
    unsigned sum = 0;
    for (int i = 0; i != n; ++i)
        sum += (unsigned) array[i];
    return sum;
}

int array_is_sorted(const int* array, int n) {
    for (int i = 0; i < n - 1; ++i)
        if (array[i] > array[i + 1])
            return 0;
    return 1;
}

void array_print(const int* array, int n) {
    for (int i = 0; i < n && i < 20; ++i)
        printf(i ? " %d" : "[%d", array[i]);
    printf("]\n");
}

int main(int argc, char* argv[]) {
    limit_stack_size(1048576);   // 1MB of stack is enough for anyone!
    int size = 6;
    int* array = malloc(sizeof(int) * size);

    // maybe get size from command line
    if (argc > 1 && strisnumber(argv[argc - 1])) {
        size = strtol(argv[argc - 1], NULL, 0);
        --argc;
    }

    // initialize based on command line argument
    if ((argc > 1 && strcmp(argv[1], "-r") == 0) || argc == 1)
        initialize_random(array, size);
    else if (argc > 1 && strcmp(argv[1], "-u") == 0)
        initialize_up(array, size);
    else if (argc > 1 && strcmp(argv[1], "-d") == 0)
        initialize_down(array, size);
    else if (argc > 1 && strcmp(argv[1], "-m") == 0)
        initialize_magic(array, size);
    else {
        fprintf(stderr, "Usage: ./testqs [-r|-u|-d|-m] [SIZE]\n");
        exit(1);
    }

    unsigned original_checksum = array_checksum(array, size);
    array_print(array, size);

    qs(array, size);

    // check that the array is sorted
    assert(array_is_sorted(array, size));
    // check that the sorted array contains the same data
    // (this can be fooled, but it's better than nothing!)
    assert(array_checksum(array, size) == original_checksum);

    array_print(array, size);
}
