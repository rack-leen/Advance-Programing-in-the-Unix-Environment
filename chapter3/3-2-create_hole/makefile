
CC = gcc
ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

defalut:create_hole

create_hole:create_hole.o
	$(CC) -o create_hole create_hole.o
create_hole.o:create_hole.c
	$(CC) $(CFLAG) -c create_hole.c
clean:
	rm -r *.o create_hole
