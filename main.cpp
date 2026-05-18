#include "Product.h"

int main()
{
	/*
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
	*/

	std::ifstream input("product.txt", std::ios::in);
	std::string fajlnev[256]; //nyugodtan csinaljanak statikus tombot
	Product* products = new Product[256];
	std::string k;
	unsigned int l=0;
	float a=0.0;
	char c;


	int iterator = 0;
	while (input) { //addig igaz lesz, amig el nem erjuk a fajl veget
		input >> fajlnev[iterator] >> c >> k >> c >> l >> c >> a; //a c-vel oldjuk meg az elvalaszto karakter beolvasast, mivel stringstream-et nem tanultunk!
		products[iterator].setKategoria(k);
		products[iterator].setLejarat(l);
		products[iterator].setAr(a);
		++iterator;
	}

	std::cout << "Milyen kategoriat valaszt? ";
	std::cin >> k;

	std::string fajlnev_txt = k + ".txt";
	std::string fajlnev_bin = k + ".dat";
	std::ofstream out_txt(fajlnev_txt, std::ios::out);
	std::ofstream out_bin(fajlnev_bin, std::ios::out|std::ios::binary);

	iterator = 0;
	unsigned int currentIndex=0;
	unsigned int indexes[256];

	//letaroljuk az indexeket egy tombben -1-re lepunk ki a beolvasasbol
	while (currentIndex != -1) {
		std::cin >> currentIndex;
		if (currentIndex !=-1)
			indexes[iterator] = currentIndex;
		++iterator;
	}

	for (int i = 0; i < iterator; i++) {
		if (products[indexes[i]].getkategoria == k) {
			if (out_txt.is_open())
				out_txt << products[indexes[i]];

			if (out_bin.is_open())
				out_bin.write((char*)&products[indexes[i]], sizeof(Product);
		}
	}

	out_txt.close();
	out_bin.close();
	delete[] products;
	return 0;
}