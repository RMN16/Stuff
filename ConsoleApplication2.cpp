#include "ShopBudget.h"


int main()
{
	Product p1("beer", 2.45, 1);
	Product p2("meat", 5.40, 1);
	Product p3("oil", 6.20, 1);
	Product p4("tea", 1.50, 1);

	Product products[4];
	products[0] = p1;
	products[1] = p2;
	products[2] = p3;
	products[3] = p4;

	ShopBudget shopa(4,products);

	shopa.sale(p2);
	shopa.sale(p3);
	shopa.sale(p2);


	std::cout << shopa.getBudget() << "\n";
	

}
