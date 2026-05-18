// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

class Product {
private:
    std::string kategoria;
	unsigned int szavatossagi_ido;
    float ar;
public:
	Product() = default;
	Product(std::string kat, unsigned int szavatossag, float ar) : kategoria(kat), szavatossagi_ido(szavatossag), ar(ar) {}
	~Product() = default;

	std::string getKategoria() const { return this->kategoria; }
	unsigned int getSzavatossagiIdo() const { return this->szavatossagi_ido; }
	float getAr() const { return this->ar; }

	void setKategoria(const std::string& kat) { this->kategoria = kat; }
	void setSzavatossagiIdo(const unsigned int szavatossag) { this->szavatossagi_ido = szavatossag; }
	void setAr(const float a) { this->ar = a; }

	void akcio(unsigned int maiDatum) {
		if ((maiDatum - this -> szavatossagi_ido) < 3) {
			this->ar *= (1 - (rand() / RAND_MAX) * 0.01 + 0.05);
		}
	}

	friend std::ostream& operator << (std::ostream& os, const Product& p) {
		return os << p.getKategoria() << ", " << p.getSzavatossagiIdo() << ", " << p.getAr() << std::endl;
	}
};

class Muszaki : public Product {
private:
	std::string marka;
public:
	Muszaki() = default;
	~Muszaki() = default;
	Muszaki(std::string kat, unsigned int szavatossag, float ar, std::string mark) : Product(kat, szavatossag, ar){}
	
	std::string getMarka() const { return this->marka; }
	void setMarka(const std::string mark) { this->marka = mark; }
};


class Zoldseg : public Product {
private:
	int darabszam;
public:
	Zoldseg() = default;
	~Zoldseg() = default;
	Zoldseg(std::string kat, unsigned int szavatossag, float ar, int darab) : Product(kat, szavatossag, ar) {}

	int getDarabszam() const { return this->darabszam; }
	void setDarabszam(const int darab) { this->darabszam = darab; }
};



int main()
{
	Product termek("tej", 20260610, 200);
	Product termek2;
	termek2.setKategoria("hus");
	termek2.setSzavatossagiIdo(20260521);
	termek2.setAr(1500);

	std::cout << "Termek 1: " << termek.getKategoria() << ", " << termek.getSzavatossagiIdo() << ", " << termek.getAr() << std::endl;
	std::cout << "Termek 2: " << termek2.getKategoria() << ", " << termek2.getSzavatossagiIdo() << ", " << termek2.getAr() << std::endl;
	termek2.akcio(20260523);
	std::cout << "Termek 2: " << termek2.getKategoria() << ", " << termek2.getSzavatossagiIdo() << ", " << termek2.getAr() << std::endl;

	std::ofstream out("product.txt", std::ios::out); 
	if (out.is_open()) {
		out << termek;
		out << termek2;
	}
	out.close();
	
}

