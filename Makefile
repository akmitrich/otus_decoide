CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c11 -g

decoide: decoide.c
	$(CC) $(CFLAGS) -o decoide decoide.c