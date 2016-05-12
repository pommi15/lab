# Makefile for fightclub
# Thomas Rauhofer and Tobias Watzek
# OOOO

CC=g++
CFLAGS=-g -Wall -std=c++11

all: fightclub

fightclub: fightclub.o fighter.o doctor.o warrior.o ninja.o lemming.o game.o
	${CC} ${CFLAGS} fightclub.o fighter.o  doctor.o warrior.o ninja.o lemming.o game.o -o fightclub

fightclub.o: fightclub.cpp
	${CC} ${CFLAGS} -c fightclub.cpp -o fightclub.o
fighter.o: fighter.cpp
	${CC} ${CFLAGS} -c fighter.cpp -o fighter.o
doctor.o: doctor.cpp
	${CC} ${CFLAGS} -c doctor.cpp -o doctor.o
lemming.o: lemming.cpp
	${CC} ${CFLAGS} -c lemming.cpp -o lemming.o
warrior.o: warrior.cpp
	${CC} ${CFLAGS} -c warrior.cpp -o warrior.o
ninja.o: ninja.cpp
	${CC} ${CFLAGS} -c ninja.cpp -o ninja.o
game.o: game.cpp
	${CC} ${CFLAGS} -c game.cpp -o game.o

.PHONY: clean
clean:
	rm -f *.o fightclub
