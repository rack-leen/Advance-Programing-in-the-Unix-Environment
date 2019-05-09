
CC = gcc
ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

defalut:print_limit

print_limit:print_limit.o
	$(CC) -o print_limit print_limit.o
print_limit.o:print_limit.c print_limit.h
	$(CC) $(CFLAG) -c print_limit.c
clean:
	rm -r *.o print_limit
