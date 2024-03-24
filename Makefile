CC=g++
CFLAGS=-std=c++11 -Wall

all: vektoriai deque list

vektoriai: vektoriai.o mokinys.o
    $(CC) $(CFLAGS) vektoriai.o mokinys.o -o vektoriai

vektoriai.o: vektoriai.cpp mokinys.h
    $(CC) $(CFLAGS) -c vektoriai.cpp

mokinys.o: mokinys.cpp mokinys.h funkcijos.h
    $(CC) $(CFLAGS) -c mokinys.cpp

deque: deque.o mokinys2.o
    $(CC) $(CFLAGS) deque.o mokinys2.o -o deque

deque.o: deque.cpp mokinys2.h
    $(CC) $(CFLAGS) -c deque.cpp

mokinys2.o: mokinys2.cpp mokinys2.h funkcijos2.h
    $(CC) $(CFLAGS) -c mokinys2.cpp

list: list.o mokinys1.o
    $(CC) $(CFLAGS) list.o mokinys1.o -o list

list.o: list.cpp mokinys1.h
    $(CC) $(CFLAGS) -c list.cpp

mokinys1.o: mokinys1.cpp mokinys1.h funkcijos1.h
    $(CC) $(CFLAGS) -c mokinys1.cpp

clean:
    del -rf *.o vektoriai deque list