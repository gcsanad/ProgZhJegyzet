#include "Product.h"

int main()
{
	//peldanyositas
	Product P;
	Product* P2 = new Product("zoldseg", 20240524, 100.00);
	
	P.setAr(230);
	P.setKategoria("hus");
	P.setLejarat(20240520);
	delete P2;

	std::ofstream out("product.txt", std::ios::out);
	if (out.is_open())
		out << P;
	out.close();
	return 0;
}