#include <stdio.h>
#include <stdlib.h>
#include "hexdump.h"

void main0(void) {
    char ch = 'A';
    fprintf(stderr, "%c\n", ch);
}

void main1(void) {
    char ch = 'A';
    char* ptr = &ch;
    fprintf(stderr, "%c\n", *ptr);
}

void main2(void) {
    char ch = 'A';
    char* ptr = &ch;
    fprintf(stderr, "%p\n", ptr);
}

void main3(void) {
    char ch = 'A';
    char* ptr = &ch;
    printf("%c\n", ptr[8]);
}

void main4(void) {
    char ch = 'A';
    char* ptr = &ch;
    ptr[16] = 'B';
    printf("%c\n", ptr[8]);
}

void main5(void) {
    char ch = 'A';
    printf("%c\n", ch);
    hexdump(&ch, 1);
}

char global_ch = 'B';
const char const_global_ch = 'C';

void main6(void) {
    char ch = 'A';
    char* heap_ch = (char*) malloc(1);
    *heap_ch = 'D';

    hexdump(&ch, 1);
    hexdump(&global_ch, 1);
    hexdump(&const_global_ch, 1);
    hexdump(heap_ch, 1);
}

void main7(void) {
    char ch = 'A';
    char* heap_ch = (char*) malloc(1);
    *heap_ch = 'D';

    hexdump(&ch, 1);
    hexdump(&global_ch, 1);
    hexdump(&const_global_ch, 1);
    hexdump(heap_ch, 1);
    hexdump(&heap_ch, 4);
}

void main8(void) {
    char ch = 'A';
    char* heap_ch = (char*) malloc(1);
    *heap_ch = 'D';

    hexdump(&ch, 1);
    hexdump(&global_ch, 1);
    hexdump(&const_global_ch, 1);
    hexdump(heap_ch, 1);
    hexdump(heap_ch + (&ch - heap_ch) / 2, 1);
}

int main() {
    main0();
}
