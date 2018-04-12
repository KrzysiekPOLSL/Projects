#include "Napoje.h"
Napoje::Napoje(std::string nazwa_towaru, int produkty_wadliwe, int produkty_sprawne) :
	Produkcja(nazwa_towaru), produkty_wadliwe(produkty_wadliwe), produkty_sprawne(produkty_sprawne)
{
}
void Napoje::Raport()
{
	if (produkty_sprawne == 0)
	{
		int awaria_maszyny = 1;
		throw awaria_maszyny;
	}
	else
		std::cout << " Procent sprawnych butelek: "
		<< (double)produkty_wadliwe / produkty_sprawne << "%" << std::endl;
}

Napoje::~Napoje()
{
}