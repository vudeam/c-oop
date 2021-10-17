CC = gcc
CFLAGS = -std=c99 --pedantic -Wall -Werror -g

BINS = Table
OBJS = main.o Assign.o Name.o Var.o value.o

all: $(BINS)


$(BINS): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

