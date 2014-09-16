#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <string.h>
#include <sys/time.h>

inline void mywrite(int fd, const void* data, size_t length) __attribute__((always_inline));
inline void mywrite(int fd, const void* data, size_t length) {
    __asm__ volatile("int $0x80"
                     : "=a" (fd)
                     : "a" (4), "b" (fd), "c" (data), "d" (length)
                     : "memory", "cc");
}

inline void mynanosleep(const struct timespec* ts, struct timespec* tsout) __attribute__((always_inline));
inline void mynanosleep(const struct timespec* ts, struct timespec* tsout) {
    __asm__ volatile("int $0x80"
                     : "=a" (ts)
                     : "a" (0xA2), "b" (ts), "c" (tsout)
                     : "memory", "cc");
}

void evil(void) {
    uint32_t seed = 0;
    char buf[80];
    struct timespec wait = {0, 0};
    while (1) {
        char* s = buf;
        for (int x = seed % 48; x > 0; --x)
            *s++ = ' ';
        *s++ = 'D';
        *s++ = 'I';
        *s++ = 'E';
        *s++ = '\n';
        mywrite(STDOUT_FILENO, buf, s - buf);
        wait.tv_nsec = 250000000;
        mynanosleep(&wait, 0);
        seed = seed * 1664525 + 1013904223;
    }
}

int main(int argc, char* argv[]) {
    if (argc == 2 && strcmp(argv[1], "-x") == 0) {
        const unsigned char* x = (const unsigned char*) evil;
        for (int i = 0; i < 256; ++i)
            putchar(x[i]);
    } else
        evil();
}
