# Makefile for lab
# Thomas Rauhofer and Tobias Watzek
# d[ o_0 ]b

CC=g++
CFLAGS=-g -Wall -std=c++11

all: lab

lab: lab.o import.o labyrinth.o
	${CC} ${CFLAGS} import.o lab.o labyrinth.o -o lab

lab.o: lab.cpp
	${CC} ${CFLAGS} -c lab.cpp -o lab.o

impot.o: import.cpp
	${CC} ${CFLAGS} -c import.cpp -o import.o

labyrinth.o: labyrinth.cpp
	${CC} ${CFLAGS} -c labyrinth.cpp -o labyrinth.o

.PHONY: clean
clean:
	rm -f *.o lab
