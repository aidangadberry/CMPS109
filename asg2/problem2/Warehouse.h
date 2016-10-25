#ifndef __WAREHOUSE_H__
#define __WAREHOUSE_H__

class Warehouse {
	private:
		int capacity;
		int stocked;
		unsigned char *warehouse;

		void incrementStock(int productID);
		void decrementStock(int productID);

	public:
		/* Constructors */
		Warehouse(int cap);

		/* Modifiers */
		void addProduct(int productID);
		void removeProduct(int productID);

		/* Selectors */
		bool doesExist(int productID);
		int quantityOfProduct(int productID);
		int numberOfProductsInStock();
		
		/* Destructors */
		~Warehouse();
};

#endif