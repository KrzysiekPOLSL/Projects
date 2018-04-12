#pragma once
#include "Napoje.h"
class NapojeBezCukru :
	public Napoje
{
	int ilosc_kalorii;
	int pojemnosc_w_g;
public:
	NapojeBezCukru(std::string nazwa_towaru, int produkty_wadliwe, int produkty_sprawne,
		int ilosc_kalorii, int pojemnosc_w_g);
	void Raport2();
	~NapojeBezCukru();
};