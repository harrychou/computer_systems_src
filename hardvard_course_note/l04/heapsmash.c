#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* buffer = malloc(100);
    if (gets(buffer))
        printf("Read %d character(s)\n", strlen(buffer));
    else
        printf("Read nothing\n");
    free(buffer);
}
