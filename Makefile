CC = g++
CFLAGS = -O3 -fpermissive -std=c++11
BINARY = LMC

all: LMC

LMC: main.o control.o instruction.o parse.o
	$(CC) $(CFLAGS) main.o control.o instruction.o parse.o -o $(BINARY)

main.o: main.cpp control.h parse.h
	$(CC) $(CFLAGS) -c main.cpp

control.o: control.cpp control.h
	$(CC) $(CFLAGS) -c control.cpp

instruction.o: instruction.cpp instruction.h
	$(CC) $(CFLAGS) -c instruction.cpp

parse.o: parse.cpp parse.h
	$(CC) $(CFLAGS) -c parse.cpp


clean:
	rm -rf *.o $(BINARY)

cleano:
	rm -rf *.o
