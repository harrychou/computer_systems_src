PROGRAMS = mexplore testsum
all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

O = 3
include ../common/rules.mk

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CFLAGS) $(DEPCFLAGS) -O$(O) -o $@ -c $<

mexplore: mexplore.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O$(O) -o $@ $^

testsum: sum.o testsum.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O$(O) -o $@ $^

clean:
	rm -f $(ALLPROGRAMS) *.o

.PHONY: all clean
