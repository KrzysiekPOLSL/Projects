#pragma once
#include "Vehicle.h"
class Car :
	public Vehicle
{
	std::string brand;
public:
	Car(int speed, std::string brand);
	virtual void ShowBrand();
	~Car();
};