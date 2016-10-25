#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>

class Heap {
	private:
		int *array;
		int maxSize, nel;
		void adjust(int a[], int i, int n);

	public:

		/* Constructors */
		Heap(int maxSize);

		/* Modifiers */
		bool insert(int item);
		bool delMax(int &item);

		/* Operators */

		Heap* operator+(const Heap &heap);
		Heap operator+(int a);
		int operator[](int item);
		void operator=(const Heap &heap);
		void operator+=(const Heap &heap);
		void operator+=(int a);
		friend std::ostream &operator<<(std::ostream &output, const Heap &heap);

		/* Selectors */

		/* Destructors */
		~Heap();
};

#endif