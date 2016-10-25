#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Heap.h"

/* Constructors */

// regular constructor
Heap::Heap(int maxSize):maxSize(maxSize) {
	array = (int*)calloc(maxSize+1, sizeof(int));
	nel = 0;
}

// copy constructor
Heap::Heap(const Heap &heap) {
	array = heap.array;
	maxSize = heap.maxSize;
	nel = heap.nel;
}

/* Modifiers */

// rebalance the heap
void Heap::adjust(int a[], int i, int n) {
	int j = 2*i;
	int item = a[i];

	while (j <= n) {
		if ((j < n) &&  (a[j] < a[j+1])) {
			j++;
		}
		if (item >= a[j]) {
			break;
		}
		a[j/2] = a[j];
		j *= 2;
	}
	a[j/2] = item;
}

// insert item into heap
bool Heap::insert(int item) {
	int i = ++nel;
	if (i == maxSize) {
		std::cout << "heap size exceeded" << std::endl;
		return false;
	} 
	while ((i > 1) && (array[i/2] < item)) {
		array[i] = array[i/2];
		i /= 2;
	}
	array[i] = item;
	return true;
}

// delete max of heap
bool Heap::delMax(int &item) {
	if (!nel) {
		std::cout << "heap is empty" << std::endl;
		return false;
	}
	item = array[1];
	array[1] = array[nel--];
	adjust(array, 1, nel);
	return true;
}

/* Selectors */

/* Operators */

// heap concatination operator
Heap Heap::operator+(Heap heap) {
	Heap *myHeap = new Heap(maxSize + heap.maxSize);
	int i;
	for (i = 0; i < std::max(maxSize, heap.maxSize); i++) {
		if (i < heap.maxSize) {
			myHeap->insert(heap.array[i]);
		}
		if (i < maxSize){
			myHeap->insert(array[i]);
		}
	}
	return myHeap;
}

// addition with integer operator
Heap Heap::operator+(int a) {
    insert(a);
    return *this;
}

// array indexing operator
int Heap::operator[](int item) {
	return array[item];
}

// assignment operator
void Heap::operator=(const Heap &heap) {
	array = heap.array;
	maxSize = heap.maxSize;
	nel = heap.nel;
}

// add with a heap and assign operator
void Heap::operator+=(const Heap &heap) {
	this = this + &heap;
}

// add with an integer and assign operator
void Heap::operator+=(int a) {
	this = this + a;
}

// cout<< operator for printing a heap
std::ostream &operator<<(std::ostream &output, const Heap &heap){ 
	for (int i = 0; i < heap.maxSize; i++) {
		output << heap.array[i] << " ";
	}
	return output;            
}

/* Destructors */

