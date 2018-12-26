CC = gcc
CFLAGS = -O2 -Wall -I ..

all: adder

adder: adder.c
	$(CC) $(CFLAGS) -o adder adder.c
	movie.c	
clean:
	rm -f adder *~
