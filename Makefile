CC=g++
CFLAGS=-std=c++14 -Wall -O3 -lpthread -lgmpxx -lgmp -lprimesieve
LDFLAGS=
SOURCES=test.cpp
all: test.o

test.o:test.cpp
	$(CC) $(CFLAGS) test.cpp -o test.o
clean:
	rm *.o
