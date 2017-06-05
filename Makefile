CC=g++
CFLAGS=-Wall -Wextra -std=c++11

ALL : Readfile

Readfile : Readfile.cpp AtomClass.o MoleculeClass.o
	$(CC) $(CFLAGS) -o Readfile Readfile.cpp AtomClass.o MoleculeClass.o

AtomClass.o : ../CPP_AtomClass/AtomClass.cpp
	$(CC) $(CFLAGS) -c ../CPP_AtomClass/AtomClass.cpp

MoleculeClass.o : ../CPP_MoleculeClass/MoleculeClass.cpp
	$(CC) $(CFLAGS) -c ../CPP_MoleculeClass/MoleculeClass.cpp

.PHONY : clean
clean :
	$(RM) *.o Readfile
