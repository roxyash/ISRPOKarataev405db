all: db

db: main.o mainFunc.o struct.o
	gcc -o db main.c mainFunc.h struct.h

main.o: main.c
	gcc -c main.c
mainFunc.o: mainFunc.h
	gcc -c mainFunc.h
struct.o: struct.h
	gcc -c struct.h

