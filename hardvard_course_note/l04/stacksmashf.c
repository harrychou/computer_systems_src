#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_line(char* buffer) {
    if (gets(buffer))
        return 1;
    else
        return 0;
}

int main() {
    char buffer[100];
    if (read_line(buffer))
        printf("Read %d character(s)\n", strlen(buffer));
    else
        printf("Read nothing\n");
}
