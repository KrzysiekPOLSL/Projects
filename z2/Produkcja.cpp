#include "Produkcja.h"
Produkcja::Produkcja(std::string nazwa_towaru) :nazwa_towaru(nazwa_towaru)
{
}
void Produkcja::Pokaz_Nazwe()
{
	std::cout << " Nazwa: " << nazwa_towaru << std::endl;
}
Produkcja::~Produkcja()
{
}