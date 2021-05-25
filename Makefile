CC=gcc
CFLAGS= -std=c99 -Werror

all: p1.o p2.o

p1.o:p1.c
	$(CC) $(CFLAGS) $< -o $@

p2.o:p2.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o*

.PHONY: all clean



