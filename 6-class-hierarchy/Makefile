CC = gcc
CFLAGS = -std=c99 --pedantic -Wall -Werror -g

BINS = any
OBJS = any.c Object.o

all: $(BINS)


$(BINS): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

