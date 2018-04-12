#pragma once
#include "Produkcja.h"
class Napoje :
	public Produkcja
{
	int produkty_wadliwe;
	int produkty_sprawne;
public:
	Napoje(std::string nazwa_towaru, int produkty_wadliwe, int produkty_sprawne);
	void Raport();
	~Napoje();
};