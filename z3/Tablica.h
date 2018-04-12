#pragma once
#pragma once
#include <time.h>
#include "Funkcje.h"
#include <iostream>
template <class T, int i>
class Tablica
{
	T tab[i];
public:
	Tablica()
	{
		srand(time(NULL));
		for (int j = 0; j < i; j++)
		{
			this->tab[j] = (rand() % 5000) / 100.0;
		}
	};
	T Pokaz(int indeks)
	{
		return tab[indeks];
	};
	void Sortuj()
	{
		for (int j = 0; j < i - 1; j++)
			for (int k = j + 1; k < i; k++)
			{
				if (tab[j] >= tab[k])
					zamien(tab[j], tab[k]);
			}
	};

	void Wypisz()
	{
		for (int j = 0; j < i; j++)
			std::cout << " Element: " << j << " to " << tab[j] << std::endl;
	};
	void Ustaw(int indeks, T wartosc)
	{
		tab[indeks] = wartosc;
	}
	T* Dostan()
	{
		return tab;
	}
	~Tablica()
	{
	};
};