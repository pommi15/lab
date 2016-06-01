# Makefile for lab
# Thomas Rauhofer and Tobias Watzek
# d[ o_0 ]b

CC=g++
CFLAGS=-g -Wall -pthread -std=c++11

all: lab

lab: lab.o bot.o import.o labyrinth.o namegen.o tremaux.o righthand.o solver.o
	${CC} ${CFLAGS} lab.o solver.o import.o bot.o labyrinth.o namegen.o tremaux.o righthand.o -o lab

lab.o: lab.cpp
	${CC} ${CFLAGS} -c lab.cpp -o lab.o

bot.o: bot.cpp
	${CC} ${CFLAGS} -c bot.cpp -o bot.o

tremaux.o: tremaux.cpp
	${CC} ${CFLAGS} -c tremaux.cpp -o tremaux.o

righthand.o: righthand.cpp
	${CC} ${CFLAGS} -c righthand.cpp -o righthand.o

import.o: import.cpp
	${CC} ${CFLAGS} -c import.cpp -o import.o

labyrinth.o: labyrinth.cpp
	${CC} ${CFLAGS} -c labyrinth.cpp -o labyrinth.o

namegen.o: namegen.cpp
	${CC} ${CFLAGS} -c namegen.cpp -o namegen.o

solver.o: solver.cpp
	${CC} ${CFLAGS} -c solver.cpp -o solver.o

.PHONY: clean
clean:
	rm -f *.o lab
