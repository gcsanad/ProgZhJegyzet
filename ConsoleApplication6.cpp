// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Auto {
    char* tipus;
    char* modell;
    int evjarat;
    char* uzemanyagTipus;
};

int main(int argc, char* argv[])
{

    Auto autok[5];
	autok[0] = { (char*)"Ford", (char*)"Focus", 2015, (char*)"Benzin" };
	autok[1] = { (char*)"Volkswagen", (char*)"Golf", 2018, (char*)"Diesel" };
	autok[2] = { (char*)"Toyota", (char*)"Corolla", 2020, (char*)"Hibrid" };
	autok[3] = { (char*)"Honda", (char*)"Civic", 2017, (char*)"Benzin" };
	autok[4] = { (char*)"Tesla", (char*)"Model 3", 2021, (char*)"Elektromos" };
    
    int evszam;
	std::cout << "Adja meg az evszamot: ";
    std::cin >> evszam;

    for (int i = 0; i < 5;i++)
    {
        if (autok[i].evjarat < evszam) {
			std::cout << autok[i].tipus << " " << autok[i].modell << " (" << autok[i].evjarat << ") - " << autok[i].uzemanyagTipus << std::endl;
        }
    }
    
    
}

