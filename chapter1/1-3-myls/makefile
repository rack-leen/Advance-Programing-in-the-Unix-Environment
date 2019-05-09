CC = gcc
# 后面两个点表示打印了当前目录后，向前退一个步
ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

defalut:myls

myls:myls.o
	$(CC) -o myls myls.o
myls.o:myls.c
	$(CC) $(CFLAG) -c myls.c
clean:
	rm -r *.o myls
