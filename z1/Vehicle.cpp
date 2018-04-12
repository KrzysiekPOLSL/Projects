#include "Vehicle.h"
Vehicle::Vehicle(int speed) : speed(speed)
{
}
void Vehicle::PrintSpeed()
{
	std::cout << "speed: " << this->speed << std::endl;
}
Vehicle::~Vehicle()
{
}