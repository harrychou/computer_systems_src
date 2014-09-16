#include <stdio.h>
#include <stdlib.h>
#include "hexdump.h"

/* The `sum` function is defined in `sum.c`. */
extern int sum(int a, int b);

int main(int argc, char* argv[]) {
    int a = 2, b = 2;
    if (argc >= 2)
        a = strtol(argv[1], NULL, 0);
    if (argc >= 3)
        b = strtol(argv[2], NULL, 0);

    printf("%d + %d = %d\n",
           a,
           b,
           sum(a, b));
}
