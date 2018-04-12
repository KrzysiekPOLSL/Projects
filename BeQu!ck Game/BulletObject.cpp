#include "BulletObject.h"



BulletObject::BulletObject(int x, int y, std::string bullet_name):ObstacleObject(x,y,bullet_name)
{

}

BulletObject::BulletObject()
{
	int velocity = 0;
	bool visible = false;
}


BulletObject::~BulletObject()
{
}
