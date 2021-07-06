# params
CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Werror -g

set: main.o Set.o
	$(CC) -o set.out $^

main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

Set.o: Set.c
	$(CC) -c $(CFLAGS) $< -o $@


# HELP:
# $^ - all the prerequisites with spaces between them
# $< - name of the first prerequisite
# $@ - file name of the target of the rule

