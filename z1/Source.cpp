#include <iostream>
#include <typeinfo>
#include <time.h>
#include "Vehicle.h"
#include "Car.h"
#include "RacingCar.h"
using namespace std;
Vehicle* GenerateObject(string brands[])
{
	int random_number = rand() % 3;
	switch (random_number)
	{
	case 0:
		return new Vehicle(rand() % 5);
		break;
	case 1:
		return new Car(rand() % 500, brands[rand() % 3]);
		break;
	case 2:
		return new RacingCar(rand() % 500, brands[rand() % 3], rand() % 20);
		break;
	default:
		return nullptr;
		break;
	}
}

int main()
{
	srand(time(0));
	Vehicle *v;
	Car *c;
	RacingCar *rc;
	std::string brands[] = { "ford","chevrolet", "porsche" };
	for (int i = 0; i < 10; i++)
	{
		cout << " Pojazd nr: " << i + 1 << endl << endl;
		v = GenerateObject(brands);
		if (v)
		{
			cout << "Klasa obiektu: " << typeid(*v).name() << endl;
			v->PrintSpeed();
			if (c = dynamic_cast<Car*>(v))
				c->ShowBrand();
			if (rc = dynamic_cast<RacingCar*>(v))
				rc->CheckFuel();
			delete(v);
			cout << endl << endl;
		}
	}
	return 0;
}