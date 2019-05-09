
CC = gcc
ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

defalut:process-control

process-control:process-control.o
	$(CC) -o process-control process-control.o
process-control.o:process-control.c
	$(CC) $(CFLAG) -c process-control.c
clean:
	rm -r *.o process-control
