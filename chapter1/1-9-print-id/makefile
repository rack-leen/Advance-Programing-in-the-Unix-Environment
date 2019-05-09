
CC = gcc
ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

defalut:print-id

print-id:print-id.o
	$(CC) -o print-id print-id.o
print-id.o:print-id.c
	$(CC) $(CFLAG) -c print-id.c
clean:
	rm -r *.o print-id
