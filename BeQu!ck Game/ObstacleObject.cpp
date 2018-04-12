#include "ObstacleObject.h"


ObstacleObject::ObstacleObject(int x, int y, std::string name, bool harmless):
	GameObject(x,y,name)
{
	this->delta = 4;
	this->harmless = harmless;
}

ObstacleObject::ObstacleObject()
{
	this->delta = 4;
	this->harmless = true;
}


ObstacleObject::~ObstacleObject()
{
}





