CC = gcc
CFLAGS = -c

all: main

main: lib.o main.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -f *.o main