#include <stdio.h>
#include <stdlib.h>
#include "hexdump.h"

char global_ch = 'B';
const char const_global_ch = 'C';

void main0(void) {
    char ch = 'A';
    char* heap_ch = (char*) malloc(1);
    *heap_ch = 'D';

    hexdump(&ch, 1);
    hexdump(&global_ch, 1);
    hexdump(&const_global_ch, 1);
    hexdump(heap_ch, 1);
}

void main1(void) {
    char ch = 65;
    hexdump(&ch, 1);
}

void main2(void) {
    char ch = 255;
    hexdump(&ch, 1);
}

void main3(void) {
    char ch = 0x1D7;
    hexdump(&ch, 1);
}

void main4(void) {
    int i = 0x1D7;
    hexdump(&i, 1);
}

void main5(void) {
    int i = 0x1D7;
    printf("%zu\n", sizeof(i));
    hexdump(&i, sizeof(i));
}

void main6(void) {
    int i = 2147483647;
    hexdump(&i, sizeof(i));
}

void main7(void) {
    int i = 4294967295;
    hexdump(&i, sizeof(i));
}

void main8(void) {
    int i = 4294967295;
    printf("%d\n", i);
    hexdump(&i, sizeof(i));
}

void main9(void) {
    unsigned i = 4294967295;
    printf("%u\n", i);
    hexdump(&i, sizeof(i));
}

void main10(void) {
    double d = 0;
    hexdump(&d, sizeof(d));
}

void main11(void) {
    double d = 1;
    hexdump(&d, sizeof(d));
}

void main12(void) {
    char a[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    hexdump(&a[0], sizeof(a));
}

void main13(void) {
    char a[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    hexdump(&a[0], sizeof(a));

    char* ptr = &a[0];
    hexdump(&ptr, sizeof(ptr));

    char* ptr1 = &a[1];
    hexdump(&ptr1, sizeof(ptr1));

    printf("%c %c\n", *ptr, *ptr1);
}

void main14(void) {
    int a[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    hexdump(a, sizeof(a));
}

void main15(void) {
    int a[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};

    int* ptr = &a[0];
    hexdump(&ptr, sizeof(ptr));

    int* ptr1 = &a[1];
    hexdump(&ptr1, sizeof(ptr1));

    printf("%c %c\n", *ptr, *ptr1);
}

int main() {
    main0();
}
