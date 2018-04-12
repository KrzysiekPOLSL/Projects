#pragma once
#include <string>
#include <iostream>
class Produkcja
{
	std::string nazwa_towaru;
public:
	Produkcja(std::string nazwa_towaru);
	virtual void Pokaz_Nazwe();
	~Produkcja();
};