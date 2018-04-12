#include <iostream>
#include <typeinfo>
#include <vector>
#include "Produkcja.h"
#include "Napoje.h"
#include "Napoje_bez_cukru.h"
using namespace std;

int main(void)
{
	vector<Produkcja*> v;
	Napoje *n = nullptr;
	NapojeBezCukru *nb = nullptr;
	Produkcja p1("Nazwa1");
	v.push_back(&p1);
	Produkcja p2("Nazwa2");
	v.push_back(&p2);
	Napoje n1("Nazwa3", 23, 12);
	v.push_back(&n1);
	Napoje n2("Nazwa3", 23, 0);
	v.push_back(&n2);
	NapojeBezCukru nb1("Nazwa4", 34, 23, 34, 344);
	v.push_back(&nb1);
	NapojeBezCukru nb2("Nazwa5", 34, 0, 23, 1000);
	v.push_back(&nb2);
	NapojeBezCukru nb3("Nazwa6", 34, 0, 324, 0);
	v.push_back(&nb3);

	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << " Obiekt " << typeid(*i).name() << endl << endl;
		try
		{
			(*i)->Pokaz_Nazwe();
			if (n = dynamic_cast<Napoje*>(*i))
			{
				n->Raport();
			}
			else
				cout << " Brak produkcji napoju!" << endl;
			if (nb = dynamic_cast<NapojeBezCukru*>(*i))
			{
				nb->Raport2();
			}
		}
		catch (int i)
		{
			switch (i)
			{
			case 1:
				cout << " Awaria maszyny!" << endl;
				break;
			case 2:
				cout << " Brak pojemnosci!" << endl;
				break;
			default:
				cout << " Nieznany blad typu integer!";
				break;
			}
		}
		catch (bad_alloc& ba)
		{
			cout << " Blad alokacji!" << endl;
		}
		catch (bad_cast& bc)
		{
			cout << " Blad rzutowania!" << endl;
		}
		cout << endl << endl;
	}
	v.clear();
	return 0;
}