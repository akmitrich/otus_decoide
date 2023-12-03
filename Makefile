CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c11 -g

decoide: decoide.c non-ascii.h
	$(CC) $(CFLAGS) -o decoide decoide.c