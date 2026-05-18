#pragma once

#include <iostream>
#include <string>
#include <fstream>
class Product
{
public:
	Product() = default;
	Product(std::string k, unsigned int l, float a) : kategoria(k), lejarat(l), ar(a) {}
	~Product() = default;

	std::string getkategoria() const {
		return this->kategoria;
	}

	unsigned int getLejarat() const {
		return this->lejarat;
	}

	float getAr() const {
		return this->ar;
	}

	void setKategoria(std::string k) {
		this->kategoria = k;
	}

	void setLejarat(unsigned int l) {
		this->lejarat = l;
	}

	void setAr(float a)
	{
		this->ar = a;
	}

	friend std::ostream& operator << (std::ostream& s, const Product& P) {
		return s << P.getkategoria() << "," << P.getLejarat() << "," << P.getAr() << std::endl;
	}

	void akcio(unsigned int datum) {
		if ((lejarat - datum) < 3)
			this->ar *= (1 - (rand() / RAND_MAX) * 0.1 + 0.05);
	}
	
private: //ez itt protected lesz, ha oroklodes lesz
	std::string kategoria;
	unsigned int lejarat;
	float ar;
};

