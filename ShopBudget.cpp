#include "ShopBudget.h"

double ShopBudget::budget = 0;

ShopBudget::ShopBudget()
	:count(1)
{
	goods = new Product[count];
	goods[0] = Product();
}

ShopBudget::~ShopBudget()
{
	free();
}
ShopBudget::ShopBudget(int sCount, Product* sGoods)
{
	if (sCount <= 0)
	{
		count = 1;
		goods = new Product[count];
		goods[0] = Product();
	}
	else
	{
		count = sCount;
		goods = new Product[count];
	
		for (size_t i = 0; i < count; i++)
		{
			goods[i] = sGoods[i];
		}
	
	}
}
ShopBudget::ShopBudget(const ShopBudget& other)
{
	copyShop(other);
}
ShopBudget& ShopBudget::operator=(const ShopBudget& other)
{
	if (this != &other)
	{
		free();
		copyShop(other);
	}

	return *this;
}

bool ShopBudget::sale(const Product& object)
{
	for (size_t i = 0; i < count; i++)
	{
		if (goods[i].isAvailable && !strcmp(goods[i].name, object.name))
		{
			budget += goods[i].price;
			goods[i].isAvailable = false;

			return 0;
		}
	}

	return 0;
}
double ShopBudget::getBudget()const
{
	return budget;
}
void ShopBudget::copyShop(const ShopBudget& obj)
{
	count = obj.count;
	goods = new Product[count];

	for (size_t i = 0; i < count; i++)
	{
		goods[i] = obj.goods[i];
	}
}
void ShopBudget::free()
{
	delete[]goods;
}

void ShopBudget::printShop()const
{
	for (size_t i = 0; i < count; i++)
	{
		goods[i].printProduct();
	}
}