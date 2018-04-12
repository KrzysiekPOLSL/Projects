#include "Funktor.h"
Funktor::Funktor()
{
}
bool Funktor::operator()(int a, int b)
{
	return a < b;
}
Funktor::~Funktor()
{
}