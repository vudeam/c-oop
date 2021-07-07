# params
CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Werror -g

set: main.o Set.o
	$(CC) -o set.out $^

bag: main.o Bag.o
	$(CC) -o bag.out $^


main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

Set.o: Set.c
	$(CC) -c $(CFLAGS) $< -o $@

Bag.o: Bag.c
	$(CC) -c $(CFLAGS) $< -o $@


# HELP:
# $^ - all the prerequisites with spaces between them
# $< - name of the first prerequisite
# $@ - file name of the target of the rule

