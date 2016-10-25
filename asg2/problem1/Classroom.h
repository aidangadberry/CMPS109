#ifndef __CLASSROOM_H__
#define __CLASSROOM_H__

class Classroom {
	private:
		int capacity;
		int avail;
		unsigned char *classroom;

		void reserveSeat(int seat);
		void availSeat(int seat);

	public:
		/* Constructors */
		Classroom(int cap);

		/* Modifiers */
		void enterRoom(int studentID);
		void exitRoom(int studentID);

		/* Selectors */
		bool isOccupied(int seat);
		int numberOfAvailableSeats();

		/* Destructors */
		~Classroom();
};

#endif