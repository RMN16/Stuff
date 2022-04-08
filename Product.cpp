#include "Product.h"


Product::Product()
{
	name = nullptr;
	price = 0;
	isAvailable = false;
}

Product::Product(const char* pName, double pPrice, bool pAvailable)
{
	price = pPrice;
	isAvailable = pAvailable;

	size_t length = strlen(pName);
	name = new char[length + 1];
	
	strcpy_s(name, length + 1, pName);

}

Product::Product(const Product& other)
{
	copyProduct(other);
}

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		free();
		copyProduct(other);
	}

	return *this;
}

Product::~Product()
{
	free();
}

void Product::copyProduct(const Product& obj)
{
	size_t len = strlen(obj.name);
	name = new char[len + 1];
	strcpy_s(name, len + 1, obj.name);


	price = obj.price;
	isAvailable = obj.isAvailable;
}

void Product::free()
{
	delete[] name;
}

void Product::printProduct()const
{
	std::cout << "Name: " << name;
	std::cout << "\nPrice: " << price;
	std::cout << "\nAvailability: " << isAvailable;
}