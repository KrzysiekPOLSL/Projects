#include "Napoje_bez_cukru.h"
NapojeBezCukru::NapojeBezCukru(std::string nazwa_towaru, int produkty_wadliwe, int produkty_sprawne,
	int ilosc_kalorii, int pojemnosc_w_g) :Napoje(nazwa_towaru, produkty_wadliwe, produkty_sprawne),
	ilosc_kalorii(ilosc_kalorii), pojemnosc_w_g(pojemnosc_w_g)
{
}
void NapojeBezCukru::Raport2()
{
	if (pojemnosc_w_g == 0)
	{
		int brak_pojemnosci = 2;
		throw brak_pojemnosci;
	}
	else
		std::cout << " Ilosc kalorii na 100g: " << (double)pojemnosc_w_g / 100 << std::endl;
}
NapojeBezCukru::~NapojeBezCukru()
{
}