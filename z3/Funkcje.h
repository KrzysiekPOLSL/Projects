#pragma once
#pragma once
#include <string>
template <class T>
T dziel(T a, T b)
{
	if (b == 0)
	{
		string error = "Dzielenie przez 0";
		throw error;
	}
	else
		return a / b;
}
template <class T>
void zamien(T &a, T &b)
{
	T bufor = a;
	a = b;
	b = bufor;
}

template <int i>
int isbn(int tab[])
{
	return 0;
};
template<>
int isbn<10>(int tab[])
{
	int wynik = 0;
	for (int j = 0; j < 9; j++)
	{
		wynik += (j + 1)*tab[j];
	}
	return wynik % 11;
};

template<>
int isbn<13>(int tab[])
{
	int wynik1 = 0;
	int wynik2 = 0;
	int wynik3;
	for (int j = 0; j < 12; j += 2)
		wynik1 += tab[j];
	for (int j = 1; j < 13; j += 2)
		wynik2 += tab[j];
	wynik3 = (10 - (wynik1 + 3 * wynik2) % 10);
	if (wynik3 == 10)
		return 0;
	return (10 - (wynik1 + 3 * wynik2) % 10);
};