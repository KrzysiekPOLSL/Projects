#include "Car.h"
Car::Car(int speed, std::string brand) :Vehicle(speed), brand(brand)
{
}
void Car::ShowBrand()
{
	std::cout << "brand: " << this->brand << std::endl;
}
Car::~Car()
{
}