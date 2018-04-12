#include "RacingCar.h"
RacingCar::RacingCar(int speed, std::string brand, int fuel) :Car(speed, brand), fuel(fuel)
{
}
void RacingCar::CheckFuel()
{
	if (this->fuel < 5)
		std::cout << " paliwo ponizej 5, zalecana wizyta w pitstopie, stan paliwa: " << this->fuel << std::endl;
	else
		std::cout << "fuel: " << this->fuel << std::endl;
}
RacingCar::~RacingCar()
{
}