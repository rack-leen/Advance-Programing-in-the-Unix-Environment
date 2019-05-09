
CC = gcc
ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

defalut:print_fd

print_fd:print_fd.o
	$(CC) -o print_fd print_fd.o
print_fd.o:print_fd.c
	$(CC) $(CFLAG) -c print_fd.c
clean:
	rm -r *.o print_fd
