#include <stdio.h>

#include "Classroom.h"

int main() {
	Classroom *myClass = new Classroom(256);

	// enter room. Some are not valid students to demonstrate the error catching
	myClass->enterRoom(256);
	myClass->enterRoom(0);
	myClass->enterRoom(255);
	myClass->enterRoom(255);
	myClass->enterRoom(-1);

	myClass->exitRoom(0);
	myClass->enterRoom(3);
	myClass->enterRoom(5);

	// cannot exit room because they were never in it
	myClass->exitRoom(6);
	printf("Number of available seats: %d\n", myClass->numberOfAvailableSeats());
}