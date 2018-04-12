#include "Obywatel.h"
Obywatel::Obywatel() : Obywatel(0, 0, 0, 0)
{
}
Obywatel::Obywatel(int dzien, int miesiac, int rok, char plec) : dzien(dzien), miesiac(miesiac),
rok(rok), plec(plec)
{
}

void Obywatel::SprawdzDate()
{
	if (this->dzien < 1 || this->dzien > 31)
	{
		char wyjatek = 'd';
		throw wyjatek;
	}
	if (this->miesiac < 1 || this->miesiac > 12)
	{
		char wyjatek = 'm';
		throw wyjatek;
	}
	if (this->rok < 1900 || this->rok > 2099)
	{
		char wyjatek = 'r';
		throw wyjatek;
	}
}
int Obywatel::SprawdzPlec()
{
	if (toupper(this->plec) == 'M')
		return 0;
	else if (toupper(this->plec) == 'K')
		return 1;
	else
	{
		char wyjatek = 'p';
		throw wyjatek;
	}
}

std::vector<int> Obywatel::ZwrocPesel()
{
	std::vector<int> pesel;
	pesel.push_back((this->rok % 100) / 10); //rok do pesela
	pesel.push_back(this->rok % 10);
	int p_miesiac = this->miesiac;
	if (this->rok >= 2000 && this->rok <= 2099)
		p_miesiac += 20;
	pesel.push_back(p_miesiac / 10); //miesiac do pesela
	pesel.push_back(p_miesiac % 10);
	pesel.push_back(this->dzien / 10); //dzien do pesela
	pesel.push_back(this->dzien % 10);
	for (int i = 0; i < 3; i++) //trzy losowe liczby do pesela
		pesel.push_back(rand() % 10);
	if (this->SprawdzPlec()) //liczba zalezna od plci do pesela
		pesel.push_back((rand() % 5) * 2);
	else
	{
		int random = rand() % 10;
		pesel.push_back(random % 2 == 0 ? random / 2 : random);
	}
	int suma_kontrolna = 0;
	for (int i = 0; i < pesel.size(); i++)
	{
		suma_kontrolna += pesel[i] * (i + 1);
	}
	suma_kontrolna %= 10;
	if (!suma_kontrolna) //suma kontrolna do pesela
		pesel.push_back(0);
	else pesel.push_back(10 - suma_kontrolna);
	return pesel;
}

std::string Obywatel::ZwrocDate()
{
	return std::to_string(this->dzien) + "-" + std::to_string(this->miesiac) + "-" + std::to_string(this->rok);
}
std::string Obywatel::WypiszStos(std::stack<std::vector<int>> stos)
{
	std::string pesel = "";
	for (int i = 0; i < stos.top().size(); i++)
		pesel += std::to_string(stos.top()[i]);
	return pesel;
}

Obywatel::~Obywatel()
{
}