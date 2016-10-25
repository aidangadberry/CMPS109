#include <stdio.h>

#include "Warehouse.h"

int main() {
	Warehouse *myWarehouse = new Warehouse(256);

	// add products to warehouse
	myWarehouse->addProduct(5);
	myWarehouse->addProduct(5);
	myWarehouse->addProduct(2);
	myWarehouse->addProduct(-1);
	myWarehouse->addProduct(256);
	myWarehouse->addProduct(200);
	printf("Number of products in stock: %d\n", myWarehouse->numberOfProductsInStock());

	// remove products from warehouse
	myWarehouse->removeProduct(2);
	myWarehouse->removeProduct(10);
	printf("Quantity of product 300: %d\n", myWarehouse->quantityOfProduct(300));
	printf("Quantity of product 5: %d\n", myWarehouse->quantityOfProduct(5));
	printf("Quantity of product 200: %d\n", myWarehouse->quantityOfProduct(200));
	
	printf("Number of products in stock: %d\n", myWarehouse->numberOfProductsInStock());
}