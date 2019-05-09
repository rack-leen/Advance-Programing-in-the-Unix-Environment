
CC = gcc
ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

defalut:copy_file

copy_file:copy_file.o
	$(CC) -o copy_file copy_file.o
copy_file.o:copy_file.c
	$(CC) $(CFLAG) -c copy_file.c
clean:
	rm -r *.o copy_file
