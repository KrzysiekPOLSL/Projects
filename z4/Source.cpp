#include <iostream>
#include "Obywatel.h"
#include <map>
#include <time.h>
#include <algorithm>
#include "Funktor.h"
using namespace std;

int main()
{
	srand(time(0));
	Obywatel o1(3, 7, 1997, 'k');
	Obywatel o2(3, 5, 2003, 'm');
	Obywatel o3(3, 4, 1901, 'k');
	Obywatel o4(33, 8, 2000, 'k'); //zly dzien
	Obywatel o5(3, 14, 2001, 'k'); //zly miesiac
	Obywatel o6(3, 10, 5, 'k'); //zly rok
	Obywatel o7(3, 11, 1969, 'b'); //zla plec
	vector <Obywatel> vO;
	vO.push_back(o1);
	vO.push_back(o2);
	vO.push_back(o3);
	vO.push_back(o4);
	vO.push_back(o5);
	vO.push_back(o6);
	vO.push_back(o7);
	vector<Obywatel>::iterator it;
	for (it = vO.begin(); it != vO.end();)
	{
		try
		{
			it->SprawdzDate();
			it->SprawdzPlec();
			it++;
		}
		catch (char wyjatek)
		{
			switch (wyjatek)
			{
			case 'd':
				cout << " Niepoprawny dzien, usuwanie biezacego obywatela!" << endl;
				break;
			case 'm':
				cout << " Niepoprawny miesiac, usuwanie biezacego obywatela!" << endl;
				break;
			case 'r':
				cout << " Niepoprawny rok, usuwanie biezacego obywatela!" << endl;
				break;
			case 'p':
				cout << " Niepoprawna plec, usuwanie biezacego obywatela!" << endl;
				break;
			default:
				cout << " Nieznany blad, usuwanie biezacego obywatela!" << endl;
				break;
			}
			it = vO.erase(it);
		}
	}

	stack<vector<int>> stos;
	for (int i = vO.size() - 1; i >= 0; i--)
	{
		stos.push(vO[i].ZwrocPesel());
	}
	map<int, Obywatel> mapa;
	for (int i = vO.size() - 1; i >= 0; i--)
		mapa[i + 1] = vO[i];
	map<int, Obywatel>::iterator it_map;
	for (it_map = mapa.begin(); it_map != mapa.end(); it_map++)
	{
		cout << it_map->first << " " << it_map->second.ZwrocDate() << " " << it_map->second.WypiszStos(stos) <<
			" " << [](stack<vector<int>> stos) -> string { return to_string(count(stos.top().begin(), stos.top().end(), 9)); }(stos) << endl;
		stos.pop();
	}
	if (stos.empty())
		cout << " Stos jest pusty." << endl;
	vO.clear();
	if (vO.empty())
		cout << " Wektor jest pusty." << endl;
	vector <int> vect;
	for (int i = 0; i < 5; i++)
	{
		vect.push_back(rand() % 500);
	}
	sort(vect.begin(), vect.end(), Funktor());
	for (int i = 0; i < 5; i++)
	{
		cout << vect[i] << endl;
	}
	vect.clear();
	return 0;
}