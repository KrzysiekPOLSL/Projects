#pragma once
#include <string>
#include <iostream>
class Vehicle
{
	int speed;
public:
	Vehicle(int speed);
	virtual void PrintSpeed();
	~Vehicle();
};