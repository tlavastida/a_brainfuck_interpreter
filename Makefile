################################################################
## a_brainfuck_interpreter
## Makefile
## Makefile for this brainfuck interpreter project
##
## Author:
## Thomas Lavastida
## December 16, 2015
################################################################

#variables
CC=gcc
FLAGS=-Wall
INCLUDE=-I ./include/

SRC_DIR=./source/
INCLUDE_DIR=./include/


#targets
all: main test

main: main.o stack.o scan.o
	$(CC) main.o stack.o scan.o -o brainfuck $(FLAGS) $(INCLUDE) 

main.o: $(SRC_DIR)main.c
	$(CC) -c $(SRC_DIR)main.c $(FLAGS) $(INCLUDE)

test: test.o stack.o
	$(CC) test.o stack.o -o test $(FLAGS) $(INCLUDE)

test.o: $(SRC_DIR)test.c
	$(CC) -c $(SRC_DIR)test.c $(FLAGS) $(INCLUDE)

stack.o: $(SRC_DIR)stack.c $(INCLUDE_DIR)stack.h 
	$(CC) -c $(SRC_DIR)stack.c $(FLAGS) $(INCLUDE)

scan.o: $(SRC_DIR)scan.c $(INCLUDE_DIR)scan.h
	$(CC) -c $(SRC_DIR)scan.c $(FLAGS) $(INCLUDE)

clean:
	rm *.o
	rm brainfuck
	rm test
