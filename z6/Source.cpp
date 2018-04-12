#include <iostream>
#include <fstream>
#include <deque>
#include <iterator>
#include <algorithm>
#include <string>
#include <memory>
#include <vector>

using namespace std;

struct Miasto
{
	string nazwa;
	vector < shared_ptr <Miasto>> listaMiast;

	void pokazInfo()
	{
		if (this)
			cout << " Wskaznik niepusty, nazwa miasta: " << this->nazwa << endl;
		else
			cout << " Wskaznik pusty" << endl;
	}

	void Wypisz()
	{
		vector <shared_ptr <Miasto>>::iterator it;

		for (it = listaMiast.begin();it != listaMiast.end(); it++)
		{
			(*it)->pokazInfo();
		}
	}

	void Dodaj(shared_ptr <Miasto> m)
	{
		listaMiast.push_back(m);
	}

	~Miasto()
	{
		cout << " Usuwam strukture Miasto" << endl;
	}
};

void Sprawdz(int i)
{
	if (i > 2)
		cout << " Liczba referencji wieksza od 2, dokladna liczba: " << i << endl;
	else
		cout << " Liczba referencji mniejsza od 2, dokladna liczba: " << i << endl;
}


int main(void)
{
	unique_ptr <Miasto> m1(new Miasto);
	m1->nazwa = "Katowice";

	cout << m1.get() << " ";
	m1->pokazInfo();

	unique_ptr <Miasto> m2(new Miasto);
	m2->nazwa = "Opole";

	cout << m2.get() << " ";
	m2->pokazInfo();

	unique_ptr <Miasto> m3(new Miasto);
	m3->nazwa = "Wroclaw";

	cout << m3.get() << " ";
	m3->pokazInfo();

	unique_ptr <Miasto> m4(new Miasto);
	m4->nazwa = "Krakow";

	cout << m4.get() << " ";
	m4->pokazInfo();

	unique_ptr <Miasto> m5(new Miasto);
	m5->nazwa = "Warszawa";

	cout << m5.get() << " ";
	m5->pokazInfo();

	cout << " uzycie move()" << endl;

	shared_ptr <Miasto> shr1;

	shr1 = move(m1);

	cout << shr1.get() << " ";
	shr1->pokazInfo();

	cout << m1.get() << " ";
	m1->pokazInfo();

	Sprawdz(shr1.use_count());

	shared_ptr <Miasto> shr2 = shr1;

	Sprawdz(shr1.use_count());

	weak_ptr <Miasto> w1 = shr2;

	w1.lock()->pokazInfo();

	Sprawdz(shr1.use_count());

	shared_ptr <Miasto> shr3(new Miasto);
	shr3->nazwa = "Rzeszow";

	shared_ptr <Miasto> shr4(new Miasto);
	shr4->nazwa = "Plock";

	shr2->Dodaj(shr3);
	shr2->Dodaj(shr4);
	shr2->Dodaj(shr1);

	Sprawdz(shr1.use_count());
	shr2->Wypisz();
	Sprawdz(shr3.use_count());
	Sprawdz(shr4.use_count());

	return 0;
}