#include <iostream>
#include "Tablica.h"
#include <string>
using namespace std;
int main(void)
{
	Tablica <int, 5> tablica;
	tablica.Wypisz();
	cout << endl;
	tablica.Sortuj();
	tablica.Wypisz();
	cout << endl;
	for (int j = 0; j < 5; j++)
	{
		try
		{
			cout << " Dzielenie 100/" << tablica.Pokaz(j) << " = " << dziel(100, tablica.Pokaz(j)) << endl;
		}
		catch (string errorMesage)
		{
			cout << errorMesage << endl;
		}
	}
	cout << endl;
	Tablica <double, 5> tablic;
	tablic.Wypisz();
	cout << endl;
	tablic.Sortuj();
	tablic.Wypisz();
	cout << endl;
	for (int j = 0; j < 5; j++)
	{
		try
		{
			cout << " Dzielenie 100/" << tablic.Pokaz(j) << " = " << dziel(100.0, tablic.Pokaz(j)) << endl;
		}
		catch (string errorMesage)
		{
			cout << errorMesage << endl;
		}
	}
	cout << endl;
	Tablica <int, 10> isbn_10;
	Tablica <int, 13> isbn_13;
	isbn_10.Ustaw(9, isbn<10>(isbn_10.Dostan()));
	isbn_13.Ustaw(12, isbn<13>(isbn_13.Dostan()));
	cout << "numer isbn dla tablicy 10-cio elementowej: " << isbn_10.Pokaz(9) << endl;

	cout << "numer isbn dla tablicy 13-to elementowej: " << isbn_10.Pokaz(12) << endl;
	auto lambda = [](double x)->double
	{
		return x*x;
	};
	cout << "Kwadrat liczby 32: " << lambda(32) << endl;
	cout << "Kwadrat liczby 123.34: " << lambda(123.34) << endl;
	return 0;
}