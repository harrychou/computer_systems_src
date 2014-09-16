In this lecture we used a small program, mexplore.c, to start
exploring the memory representation of data. We caused some
segmentation faults (and diagnosed them) and talked about abstract
machines and real machines; about the compiler's freedom to compile a
program however the abstract machine allows; and undefined behavior.

mexplore.c now contains the programs we used in lecture. Change main()
to call one of the mainN() programs.

main0
        The initial program: print a local variable. This program has
        fixed meaning on any real machine.
main1
        Print the same local variable via a pointer. This program has
        the same fixed meaning, and, as we saw, the compiler's
        optimizers were able to remove the pointer entirely.
main2
        Print the pointer *value* rather than the pointed-to object
        (the char). This program's meaning is not fixed, since the
        address value that's printed depends on the real machine.
main3
        Print an illegal byte. This program invokes undefined behavior
        (nasal demons) and is thus meaningless.
main4
        Modify that illegal byte and print it. When compiled with
        clang, this program crashes when run, because the modification
        of ptr[8] destroys the return address to which main() returns.
        (That return address is stored on the stack.) When compiled
        with other compilers, you may need to change the offset. For
        instance, when we compile with GCC, `ptr[16] = 'B';` causes a
        crash. The location of the return address is NOT part of the
        abstract machine, so compilers can make different choices.
main5
        Introduce hexdump().
main6
        hexdump() four different characters in different locations:
        the stack (local data), the data segment (global data), the
        text segment (constant global data), and the heap
        (dynamically-allocated data).
main7
        Hexdump the VALUE of the heap_ch pointer, rather than its
        content.
main8
	Peek into a location in memory halfway between the stack and
        the heap.
