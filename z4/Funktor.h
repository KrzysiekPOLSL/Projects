#pragma once
class Funktor
{
public:
	Funktor();
	bool operator ()(int a, int b);
	~Funktor();
};