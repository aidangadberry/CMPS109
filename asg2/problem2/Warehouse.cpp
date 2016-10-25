#include <stdio.h>
#include <stdlib.h>

#include "Warehouse.h"

/* Constructors */

// warehouse constructor
Warehouse::Warehouse(int cap):
	capacity(cap), stocked(0), 
	warehouse((unsigned char*)calloc(cap, sizeof(unsigned char)))
{
}

/* Modifiers */

// add a product to the warehouse if its productID is allowed (0-255)
void Warehouse::addProduct(int productID) {
	if (0 <= productID && productID < capacity) {
		incrementStock(productID);
	} else {
		printf("Error: product %d is not in this warehouse of size %d.\n",
			   productID, capacity);
	}
}

// increment the stock of a given product. If the stock is at max cap,
// print an error. If the stock was at 0, increment the number of 
// products that stocked within the warehouse
void Warehouse::incrementStock(int productID) {
	if (quantityOfProduct(productID) == 0) {
		stocked++;
	}

	if (quantityOfProduct(productID) == 255) {
		printf("Error: product %d is at maximum capacity.\n", productID);
	} else {
		warehouse[productID]++;
	}
}

// remove a product from the warehouse if its productID is allowed (0-255)
void Warehouse::removeProduct(int productID) {
	if (0 <= productID && productID < capacity) {
		decrementStock(productID);
	} else {
		printf("Error: product %d is not in this warehouse of size %d.\n",
			   productID, capacity);
	}
}

// decrement the stock of a product. If the stock was at 0, print an error. If
// the stock was at 1, decrement the number of products that stocked within 
// the warehouse
void Warehouse::decrementStock(int productID) {
	if (quantityOfProduct(productID) == 1) {
		stocked--;
	}

	if (quantityOfProduct(productID) == 0) {
		printf("Error: product %d is out of stock.\n", productID);
	} else {
		warehouse[productID]--;
	}
}

/* Selectors */

// return true if there is a quantity > 0 of the given product
bool Warehouse::doesExist(int productID) {
	return (warehouse[productID] != 0);
}

// return the quantity of the given product
int Warehouse::quantityOfProduct(int productID) {
	return warehouse[productID];
}

// return the number of products within the warehouse that have
// a quantity > 0
int Warehouse::numberOfProductsInStock() {
	return stocked;
}

/* Destructors */

// warehouse destructor
Warehouse::~Warehouse() {
	free(warehouse);
}
