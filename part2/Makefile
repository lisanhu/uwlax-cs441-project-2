#
# Josh Hursey
# CS 441/541: Project 2 Part 2
#
#####################################################################
#
# Type "make" to compile your code
# 
# Type "make clean" to remove the executable (and any object files)
#
#####################################################################

CC=gcc
CFLAGS=-Wall -g -O0 -I../lib
LDFLAGS=-pthread

#
# List all of the binary programs you want to build here
# Separate each program with a single space
#
all: voter

#
# Bounded buffer program
#
voter: voter.c voter.h ../lib/semaphore_support.o
	$(CC) -o voter voter.c ../lib/semaphore_support.o $(CFLAGS) $(LDFLAGS)

#
# Semaphore support library
#
../lib/semaphore_support.o: ../lib/semaphore_support.h ../lib/semaphore_support.c
	cd ../lib && make lib

#
# Cleanup the files that we have created
#
clean:
	$(RM) voter *.o
	$(RM) -rf *.dSYM
	cd ../lib && make clean