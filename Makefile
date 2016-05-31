# Makefile for lab
# Thomas Rauhofer and Tobias Watzek
# d[ o_0 ]b

CC=g++
CFLAGS=-g -Wall -std=c++11

all: lab

lab: lab.o bot.o import.o labyrinth.o namegen.o tremaux.o gaston.o
	${CC} ${CFLAGS} lab.o import.o bot.o labyrinth.o namegen.o tremaux.o gaston.o -o lab

lab.o: lab.cpp
	${CC} ${CFLAGS} -c lab.cpp -o lab.o

bot.o: bot.cpp
	${CC} ${CFLAGS} -c bot.cpp -o bot.o

tremaux.o: tremaux.cpp
	${CC} ${CFLAGS} -c tremaux.cpp -o tremaux.o

import.o: import.cpp
	${CC} ${CFLAGS} -c import.cpp -o import.o

labyrinth.o: labyrinth.cpp
	${CC} ${CFLAGS} -c labyrinth.cpp -o labyrinth.o

namegen.o: namegen.cpp
	${CC} ${CFLAGS} -c namegen.cpp -o namegen.o

gaston.o: gaston.cpp
	${CC} ${CFLAGS} -c gaston.cpp -o gaston.o

.PHONY: clean
clean:
	rm -f *.o lab
