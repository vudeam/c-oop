CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Werror -g

all: arithmetic.out

arithmetic.out: main.o Process.o
	$(CC) -o $@ $^


main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

Process.o: Process.c
	$(CC) -c $(CFLAGS) $< -o $@


# HELP:
# $^ - all the prerequisites with spaces between them
# $< - name of the first prerequisite
# $@ - file name of the target of the rule

