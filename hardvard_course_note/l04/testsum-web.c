#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include "hexdump.h"
#include "allowexec.h"

int main(int argc, char* argv[]) {
    if (argc <= 2) {
        fprintf(stderr, "Usage: testsum-web URL OFFSET [A B]\n");
        exit(1);
    }

    const char* url = argv[1];
    size_t offset = strtoul(argv[2], NULL, 0);
    const char* a_arg = argc >= 4 ? argv[3] : "2";
    const char* b_arg = argc >= 5 ? argv[4] : "2";

    // Create a temporary file containing the URL.
    // We do this to avoid having to quote the URL for the shell.
    char template[40];
    strncpy(template, "testsum-webtmp-XXXXXX", sizeof(template));
    int fd = mkstemp(template);
    assert(fd >= 0);
    FILE* urlf = fdopen(fd, "wb");
    fprintf(urlf, "%s\n", url);
    fclose(urlf);

    // Allocate space for the object data.
    unsigned char* data = (unsigned char*) malloc(offset + 256);
    assert(data);
    allow_execute(data, offset + 256);

    // Fetch the URL using wget.
    char popen_buf[100];
    snprintf(popen_buf, sizeof(popen_buf), "wget -i %s -O -", template);
    FILE* f = popen(popen_buf, "r");
    ssize_t n = fread(data, 1, offset + 256, f);
    assert((size_t) n >= offset + 8);
    pclose(f);
    unlink(template);

    // Print data at `offset`.
    fhexdump_at(stderr, offset, &data[offset], 16);

    // That's our `sum`!
    int (*sum)(int, int) = (int (*)(int, int)) (data + offset);

    int b = strtol(b_arg, NULL, 0);
    int a = strtol(a_arg, NULL, 0);

    printf("%d + %d = %d\n",
           a,
           b,
           sum(a, b));
}
