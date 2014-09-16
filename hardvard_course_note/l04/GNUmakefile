PROGRAMS = mexplore testsum testsum-file testsum-web evil \
	stacksmash stacksmash.unsafe stacksmashf stacksmashf.unsafe \
	heapsmash heapsmash.unsafe heapsmashf heapsmashf.unsafe
all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

O = 3
include ../common/rules.mk

UNSAFE_CFLAGS := $(CFLAGS) -U_FORTIFY_SOURCE -fno-stack-protector
ifeq ($(CLANG),1)
CFLAGS += -fsanitize=address
endif

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CFLAGS) $(DEPCFLAGS) -O$(O) -o $@ -c $<

%.unsafe.o: %.c $(BUILDSTAMP)
	$(CC) $(UNSAFE_CFLAGS) $(DEPCFLAGS) -O$(O) -o $@ -c $<

mexplore: mexplore.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O$(O) -o $@ $^

testsum: sum.o testsum.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O$(O) -o $@ $^

testsum-file: testsum-file.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O$(O) -o $@ $^

testsum-web: testsum-web.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O$(O) -o $@ $^

evil: evil.o
	$(CC) $(CFLAGS) -O$(O) -o $@ $^

stacksmash: stacksmash.o hexdump.o
	$(CC) $(CFLAGS) -O$(O) -o $@ $^

stacksmash.unsafe: stacksmash.unsafe.o hexdump.unsafe.o
	$(CC) $(UNSAFE_CFLAGS) -O$(O) -o $@ $^

stacksmashf: stacksmashf.o hexdump.o
	$(CC) $(CFLAGS) -O$(O) -o $@ $^

stacksmashf.unsafe: stacksmashf.unsafe.o hexdump.unsafe.o
	$(CC) $(UNSAFE_CFLAGS) -O$(O) -o $@ $^

heapsmash: heapsmash.o hexdump.o
	$(CC) $(CFLAGS) -O$(O) -o $@ $^

heapsmash.unsafe: heapsmash.unsafe.o hexdump.unsafe.o
	$(CC) $(UNSAFE_CFLAGS) -O$(O) -o $@ $^

heapsmashf: heapsmashf.o hexdump.o
	$(CC) $(CFLAGS) -O$(O) -o $@ $^

heapsmashf.unsafe: heapsmashf.unsafe.o hexdump.unsafe.o
	$(CC) $(UNSAFE_CFLAGS) -O$(O) -o $@ $^

clean:
	rm -f $(ALLPROGRAMS) *.o

hello-evil.jpg: hello.jpg evil
	head -c 72 < hello.jpg > hello-evil.jpg
	./evil -x >> hello-evil.jpg
	tail -c +328 < hello.jpg >> hello-evil.jpg

.PHONY: all clean
