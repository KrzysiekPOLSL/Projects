#pragma once
#include "Car.h"
class RacingCar :
	public Car
{
	int fuel;
public:
	RacingCar(int speed, std::string brand, int fuel);
	void CheckFuel();
	~RacingCar();
};