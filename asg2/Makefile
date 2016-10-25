GPP      = g++ -g -O0 -Wall -Wextra -std=gnu++14

all: problem1 problem2 problem3

problem1: problem1.o Classroom.o
	${GPP} problem1.o Classroom.o -o problem1

problem2: problem2.o Warehouse.o
	${GPP} problem2.o Warehouse.o -o problem2

problem3: problem3.o Heap.o
	${GPP} problem3.o Heap.o -o problem3

%.o: %.cpp
	${GPP} -c $<

clean:
	- rm *.o problem1 problem2 problem3

# Dependencies

problem1.o: problem1.cpp Classroom.h
problem2.o: problem1.cpp Warehouse.h
problem3.o: problem1.cpp Heap.h
Classroom.o: Classroom.cpp Classroom.h
Warehouse.o: Warehouse.cpp Warehouse.h
Heap.o: Heap.cpp Heap.h