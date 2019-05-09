CC = gcc

ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

default:buf

buf:buf.o
	$(CC) -o buf buf.o

buf.o:buf.c
	$(CC) $(CFLAG) -c buf.c

clean:
	rm -r *.o buf
