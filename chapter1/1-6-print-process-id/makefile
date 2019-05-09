CC = gcc

ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

defalut:process-id

process-id:process-id.o
	$(CC) -o process-id process-id.o
process-id.o:process-id.c
	$(CC) $(CFLAG) -c process-id.c
clean:
	rm -r *.o process-id
