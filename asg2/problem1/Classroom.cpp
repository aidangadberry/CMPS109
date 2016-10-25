#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Classroom.h"

/* Constructors */

// classroom constructor
Classroom::Classroom(int cap):
	capacity(cap), avail(cap), 
	classroom((unsigned char*)calloc(cap/8, sizeof(unsigned char)))
{
}

/* Modifiers */

// enter the room as a student. If you are not a valid student, you aren't
// allowed in
void Classroom::enterRoom(int studentID) {
	if (0 <= studentID && studentID < capacity) {
		if (numberOfAvailableSeats() < 1) {
			printf("Error: no seats available.\n");
		} else {
			if (isOccupied(studentID)) {
				printf("Error: seat %d is currently occupied.\n", studentID);
			} else {
				reserveSeat(studentID);
			}
		}
	} else {
		printf("Error: student %d is not in this class of size %d.\n",
			   studentID, capacity);
	}
	return;
}

// upon entering the room, mark your assigned seat as reserved
void Classroom::reserveSeat(int seat) {
	classroom[seat/8] |= 1 << (seat%8);
	avail--;
	printf ("Seat %d has been reserved.\n", seat);
}

// leave the room. If you are not a valid student, an error is printed.
void Classroom::exitRoom(int studentID) {
	if (isOccupied(studentID)) {
		availSeat(studentID);
	} else {
		printf("Error, seat already unoccupied or does not exist\n");
	}
}		

// upon leaving the room, mark your assigned seat as available
void Classroom::availSeat(int seat) {
	classroom[seat/8] &= ~(1 << (seat%8));
	avail++;
	printf ("Seat %d is now available.\n", seat);
}


/* Selectors */

// returns true if the given seat is occupied, false if it is empty
bool Classroom::isOccupied(int seat) {
	if (0 <= seat < capacity) {
		return ((classroom[seat/8] & (1 << (seat%8))) != 0);
	}
	return false;
}

// returns the number of available seats in the classroom
int Classroom::numberOfAvailableSeats() {
	return avail;
}

/* Destructors */

// classroom destructor
Classroom::~Classroom() {
	free(classroom);
}
