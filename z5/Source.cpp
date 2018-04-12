#include <iostream>
#include <fstream>
#include <deque>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	ifstream plikTekst;
	ifstream plikSlownik;

	plikTekst.open("tekst.txt");
	plikSlownik.open("slownik.txt");

	if (!plikTekst.good()|| !plikSlownik.good())
		cout << " Blad pliku!" << endl;
	
	deque<string>tekst;
	deque<string>slownik;
	copy(istream_iterator<string>(plikTekst), istream_iterator<string>(), back_inserter(tekst));
	copy(istream_iterator<string>(plikSlownik), istream_iterator<string>(), back_inserter(slownik));
	ostream_iterator<string, char> wypis(cout, " ");
	copy(tekst.begin(), tekst.end(), wypis);
	cout << endl << endl;

	for (deque <string>::iterator it = tekst.begin(); it != tekst.end(); it++)
	{
		deque <string>::iterator it2 = find(slownik.begin(), slownik.end(), *it);
		if (it2 != slownik.end())
			cout << *it << " " << *++it2 << endl;
	}
	
	deque <string>::iterator it = tekst.begin();

	while (it != tekst.end())
	{
		deque <string>::iterator it2 = find(slownik.begin(), slownik.end(), *it);
		if (it2 != slownik.end())
		{
			it = tekst.insert(++it, *++it2);
		}
		it++;
	}

	cout << endl;

	copy(tekst.begin(), tekst.end(), wypis);

	cout << endl << endl;

	cout  << "ilosc osob w tekcie: " <<
		[](deque <string>::iterator beg, deque <string>::iterator end) -> int {return count(beg, end, "(osoba)"); }
		(tekst.begin(), tekst.end())<< endl;

	tekst.clear();
	slownik.clear();

	return 0;
}