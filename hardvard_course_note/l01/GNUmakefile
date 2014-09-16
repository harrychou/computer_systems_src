PROGRAMS = $(patsubst qs%.c,testqs%,$(wildcard qs*.c))
all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

include ../common/rules.mk

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CFLAGS) -O3 -o $@ -c $<

testqs: testqs.o qs.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O3 -o $@ $^

testqs%: testqs.o qs%.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O3 -o $@ $^

clean:
	rm -f $(ALLPROGRAMS) *.o

.PHONY: all clean
