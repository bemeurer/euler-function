CC=g++
CFLAGS=-std=c++14 -Wall -O2 -lboost_system -lboost_thread -lgmp -lprimesieve
LDFLAGS=
SOURCES=euler.cpp
all: euler.o

euler.o:euler.cpp
	$(CC) $(CFLAGS) euler.cpp -o euler.o
clean:
	rm *.o
