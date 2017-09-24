CC=g++
CFLAGS=-Wall -Wextra -std=c++11

ALL : Readfile

Readfile : Readfile.cpp AtomClass.o MoleculeClass.o SegmentClass.o AtomTable.o BranchClass.o EdgeClass.o RigidFragmentMotif.o
	$(CC) $(CFLAGS) -o Readfile Readfile.cpp AtomClass.o MoleculeClass.o SegmentClass.o AtomTable.o BranchClass.o EdgeClass.o RigidFragmentMotif.o

AtomClass.o : ../CPP_AtomClass/AtomClass.cpp
	$(CC) $(CFLAGS) -c ../CPP_AtomClass/AtomClass.cpp

MoleculeClass.o : ../CPP_MoleculeClass/MoleculeClass.cpp
	$(CC) $(CFLAGS) -c ../CPP_MoleculeClass/MoleculeClass.cpp

SegmentClass.o : ../CPP_SegmentClass/SegmentClass.cpp
	$(CC) $(CFLAGS) -c ../CPP_SegmentClass/SegmentClass.cpp

AtomTable.o : ../CPP_AtomTable/AtomTable.cpp
	$(CC) $(CFLAGS) -c ../CPP_AtomTable/AtomTable.cpp

BranchClass.o : ../CPP_BranchClass/BranchClass.cpp
	$(CC) $(CFLAGS) -c ../CPP_BranchClass/BranchClass.cpp

EdgeClass.o : ../CPP_EdgeClass/EdgeClass.cpp
	$(CC) $(CFLAGS) -c ../CPP_EdgeClass/EdgeClass.cpp

RigidFragmentMotif.o : ../CPP_RigidFragmentMotif/RigidFragmentMotif.cpp
	$(CC) $(CFLAGS) -c ../CPP_RigidFragmentMotif/RigidFragmentMotif.cpp

.PHONY : clean
clean :
	$(RM) *.o Readfile
