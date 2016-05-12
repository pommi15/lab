# Makefile for lab
# Thomas Rauhofer and Tobias Watzek
# d[ o_0 ]b

CC=g++
CFLAGS=-g -Wall -std=c++11

all: fightclub

fightclub: lab.o
	${CC} ${CFLAGS} lab.o -o lab

lab.o: lab.cpp
	${CC} ${CFLAGS} -c lab.cpp -o lab.o

.PHONY: clean
clean:
	rm -f *.o lab
