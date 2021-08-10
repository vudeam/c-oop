CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Werror -g

all: string

string: main.o String.o
	$(CC) -o string.out $^

atom: main.o Atom.o
	$(CC) -o atom.out $^


String.o: String.c
	$(CC) -c $(CFLAGS) $< -o $@

Atom.o: Atom.c
	$(CC) -c $(CFLAGS) $< -o $@

# HELP:
# $^ - all the prerequisites with spaces between them
# $< - name of the first prerequisite
# $@ - file name of the target of the rule

