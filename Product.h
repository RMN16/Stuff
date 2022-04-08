#pragma once

#include <iostream>
#include <string.h>

class Product
{
public:
	Product();
	Product(const char* pName, double pPrice, bool pAvailable);
	Product(const Product& other);
	Product& operator=(const Product& other);
	~Product();

	friend class ShopBudget;

	void printProduct() const;

private:
	char* name;
	double price;
	bool isAvailable;


	void copyProduct(const Product& obj);
	void free();
};

