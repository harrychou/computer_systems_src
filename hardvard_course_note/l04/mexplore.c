#include <stdio.h>
#include <stdlib.h>
#include "hexdump.h"

int main(void) {
    int a[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    hexdump(a, sizeof(a));
}
