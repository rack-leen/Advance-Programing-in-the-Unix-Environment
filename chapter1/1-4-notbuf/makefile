CC = gcc

ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)
defalut: notbuf

notbuf:notbuf.o
	$(CC) -o notbuf notbuf.o

notbuf.o:notbuf.c
	$(CC) $(CFLAG) -c notbuf.c

clean:
	rm -r *.o notbuf
