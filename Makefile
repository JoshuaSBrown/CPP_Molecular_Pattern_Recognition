CC=g++
CFLAGS=-Wall -Wextra -std=c++11

ALL : Readfile

Readfile : Readfile.cpp AtomClass.o
	$(CC) $(CFLAGS) -o Readfile Readfile.cpp AtomClass.o

AtomClass.o : ../CPP_AtomClass/AtomClass.cpp
	$(CC) $(CFLAGS) -c ../CPP_AtomClass/AtomClass.cpp

.PHONY : clean
clean :
	$(RM) *.o Readfile
