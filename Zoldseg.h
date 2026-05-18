#pragma once
#include "Product.h"

class Zoldseg: public Product
{
	Zoldseg(std::string k, unsigned int l, float a, unsigned int d) : Product(k, l, a) { //a kettospont utan tudjak meghivni az ososztaly (Product) parameterezett konstruktorat!
		this->darabszam = d;
	}
private:
	unsigned int darabszam;
};

