
CC = gcc
ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

defalut:capture-signal

capture-signal:capture-signal.o
	$(CC) -o capture-signal capture-signal.o
capture-signal.o:capture-signal.c
	$(CC) $(CFLAG) -c capture-signal.c
clean:
	rm -r *.o capture-signal
