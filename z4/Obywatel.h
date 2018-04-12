#pragma once
#include <string>
#include <vector>
#include <stack>
#include <time.h>
class Obywatel
{
	int dzien, miesiac, rok;
	char plec;
public:
	Obywatel();
	Obywatel(int dzien, int miesiac, int rok, char plec);
	void SprawdzDate();
	int SprawdzPlec();
	std::vector<int> ZwrocPesel();
	std::string ZwrocDate();
	std::string WypiszStos(std::stack<std::vector<int>> stos);
	~Obywatel();
};