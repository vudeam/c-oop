CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Werror -g

all: set bag list

set: main.o Set.o
	$(CC) -o set.out $^

bag: main.o Bag.o
	$(CC) -o bag.out $^

list: main.o List.o list.o
	$(CC) -o list.out $^

main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

Set.o: Set.c
	$(CC) -c $(CFLAGS) $< -o $@

Bag.o: Bag.c
	$(CC) -c $(CFLAGS) $< -o $@

List.o: List.c
	$(CC) -c $(CFLAGS) $< -o $@

list.o: list.c
	$(CC) -c $(CFLAGS) $< -o $@


# HELP:
# $^ - all the prerequisites with spaces between them
# $< - name of the first prerequisite
# $@ - file name of the target of the rule

