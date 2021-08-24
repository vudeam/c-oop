CC = gcc
CFLAGS = -std=c99 --pedantic -Wall -Werror -g

BINS = Point.out
OBJS = main.o new.o Point.o

all: $(BINS)


$(BINS): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

