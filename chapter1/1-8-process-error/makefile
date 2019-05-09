
CC = gcc
# 后面两个点表示打印了当前目录后，向前退一个步
ROOT = $(shell pwd)/..
INCLUDE = $(ROOT)/../include

CFLAG += -I$(INCLUDE)

defalut:process-error

process-error:process-error.o
	$(CC) -o process-error process-error.o
process-error.o:process-error.c
	$(CC) $(CFLAG) -c process-error.c
clean:
	rm -r *.o process-error
