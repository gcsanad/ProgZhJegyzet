
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

class Auto {
private:
    std::string tipus;
    std::string modell;
    unsigned int evjarat;
    std::string uzemanyagTipus;
public:
    Auto() = default;
	Auto(std::string t, std::string m, unsigned int ev, std::string u) : tipus(t), modell(m), evjarat(ev), uzemanyagTipus(u) {}
	~Auto() = default;

    std::string getTipus() const { return this->tipus; }
	std::string getModell() const { return this->modell; }
	unsigned int getEvjarat() const { return this->evjarat; }
	std::string getUzemanyagTipus() const { return this->uzemanyagTipus; }

	void setTipus(std::string t) { this->tipus = t; }
	void setModell(std::string m) { this->modell = m; }
	void setEvjarat(unsigned int ev) { this->evjarat = ev; }
	void setUzemanyagTipus(std::string u) { this->uzemanyagTipus = u; }

	std::string randomRendszam() {
        // 2. Generálunk 3 betűt (az 'A' betűhöz hozzáadunk 0 és 25 közötti számot)
        char b1 = 'A' + rand() % 26;
        char b2 = 'A' + rand() % 26;
        char b3 = 'A' + rand() % 26;

        // 3. Generálunk 3 számjegyet (a '0'-hoz hozzáadunk 0 és 9 közötti számot)
        char s1 = '0' + rand() % 10;
        char s2 = '0' + rand() % 10;
        char s3 = '0' + rand() % 10;

		std::string rendszam = "aaaaaaa";
		rendszam[0] = b1;
		rendszam[1] = b2;
		rendszam[2] = b3;
		rendszam[3] = '-';
		rendszam[4] = s1;
		rendszam[5] = s2;
		rendszam[6] = s3;


		return rendszam;
	}

	
};


int main()
{
	Auto autok[3];
	int index = 0;
	std::ifstream olvas("autok_kombinalt_1.txt", std::ios::in);

	if (olvas.is_open()) {
		std::string sor;

		while (!olvas.eof())
		{
			
			std::getline(olvas, sor);

			
			if (!olvas && sor.empty()) {
				break;
			}
			if (sor.empty()) {
				continue;
			}

			std::stringstream ss(sor);

			std::string kat, mod, ev_szoveg, uzem;
			std::getline(ss, kat, '\t');
			std::getline(ss, mod, '\t');
			std::getline(ss, ev_szoveg, '\t');
			std::getline(ss, uzem, '\t');

			if (index < 3)
			{
				autok[index].setTipus(kat);
				autok[index].setModell(mod);
				autok[index].setEvjarat(std::stoi(ev_szoveg)); 
				autok[index].setUzemanyagTipus(uzem);
				index++;
			}
		}
	}
	olvas.close();

	for (int i = 0; i < 3; i++)
	{
		std::cout << autok[i].getTipus() << "\t" << autok[i].getModell() << "\t" << autok[i].getEvjarat() << "\t" << autok[i].getUzemanyagTipus() << "\t" << autok[i].randomRendszam() << std::endl;
	}

	std::ofstream ir("autok_kombinalt_szurt.txt", std::ios::out);


	int evszam;
	std::cout << "Kerem adja meg a szurt evszamot: ";
	std::cin >> evszam;
	if (ir.is_open()) {
		for (int i = 0; i < 3; i++) {
			if (autok[i].getEvjarat() > evszam) {
				ir << autok[i].getTipus() << "\t" << autok[i].getModell() << "\t" << autok[i].getEvjarat() << "\t" << autok[i].getUzemanyagTipus() << "\t" << autok[i].randomRendszam() << std::endl;
			}
		}
	}
	ir.close();
}


