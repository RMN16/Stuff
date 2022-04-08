#pragma once

#include "Product.h"


class ShopBudget
{
public:
	ShopBudget();
	~ShopBudget();
	ShopBudget(int sCount, Product* sGoods);
	ShopBudget(const ShopBudget& other);
	ShopBudget& operator=(const ShopBudget& other);

	bool sale(const Product& object);
	double getBudget()const;
	void printShop()const;


private:
	
	static double budget;
	int count;
	Product* goods;

	void copyShop(const ShopBudget& obj);
	void free();


};

