CC=cc
CFLAGS=-Wall -Wextra -Werror

build: main.c
	$(CC) $(CFLAGS) *.c -o rush-02

run:
	./rush-02

valgrind:
	valgrind --vgdb=yes --vgdb-error=0 ./test.o
