
CC = gcc
ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

defalut:test_lseek

test_lseek:test_lseek.o
	$(CC) -o test_lseek test_lseek.o
test_lseek.o:test_lseek.c
	$(CC) $(CFLAG) -c test_lseek.c
clean:
	rm -r *.o test_lseek
