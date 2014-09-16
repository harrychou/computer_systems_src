#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include "hexdump.h"
#include "allowexec.h"

int main(int argc, char* argv[]) {
    if (argc <= 2) {
        fprintf(stderr, "Usage: testsum-file FILE OFFSET [A B]\n");
        exit(1);
    }

    const char* file = argv[1];
    size_t offset = strtoul(argv[2], NULL, 0);
    const char* a_arg = argc >= 4 ? argv[3] : "2";
    const char* b_arg = argc >= 5 ? argv[4] : "2";

    // Allocate space for the object data.
    unsigned char* data = (unsigned char*) malloc(offset + 256);
    assert(data);
    allow_execute(data, offset + 256);

    // Read data.
    FILE* f = fopen(file, "rb");
    if (!f) {
        fprintf(stderr, "%s: %s\n", file, strerror(errno));
        exit(1);
    }
    ssize_t n = fread(data, 1, offset + 256, f);
    assert((size_t) n >= offset + 8);
    fclose(f);

    // Call `sum`!
    int (*sum)(int, int) = (int (*)(int, int))
        (data + offset);

    int b = strtol(b_arg, NULL, 0);
    int a = strtol(a_arg, NULL, 0);

    printf("%d + %d = %d\n",
           a,
           b,
           sum(a, b));
}
