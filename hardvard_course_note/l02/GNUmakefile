PROGRAMS = mexplore mexplore.optimized
all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

include ../common/rules.mk

%.optimized.o %.o: %.c $(BUILDSTAMP)
	$(CC) $(CFLAGS) $(DEPCFLAGS) -O3 -o $@ -c $<

%.noopt.o: %.c $(BUILDSTAMP)
	$(CC) $(CFLAGS) -O0 -o $@ -c $<

mexplore: mexplore.noopt.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O0 -o $@ $^

mexplore.optimized: mexplore.optimized.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O3 -o $@ $^

clean:
	rm -f $(ALLPROGRAMS) *.o

.PHONY: all clean
