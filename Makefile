# Makefile for lab
# Thomas Rauhofer and Tobias Watzek
# d[ o_0 ]b

CC=g++
CFLAGS=-g -Wall -std=c++11

all: lab

lab: lab.o bot.o import.o labyrinth.o
	${CC} ${CFLAGS} lab.o import.o bot.o labyrinth.o -o lab

lab.o: lab.cpp
	${CC} ${CFLAGS} -c lab.cpp -o lab.o

bot.o: bot.cpp
	${CC} ${CFLAGS} -c bot.cpp -o bot.o

impot.o: import.cpp
	${CC} ${CFLAGS} -c import.cpp -o import.o

labyrinth.o: labyrinth.cpp
	${CC} ${CFLAGS} -c labyrinth.cpp -o labyrinth.o

.PHONY: clean
clean:
	rm -f *.o lab
