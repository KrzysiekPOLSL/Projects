#pragma once
#include "ObstacleObject.h"
#include "ShootingObstacleObject.h"
class BulletObject :
	public ObstacleObject
{

public:
	friend class ShootingObstacleObject;
	int velocity;
	bool visible;
	BulletObject(int x,int y, std::string bullet_name);
	BulletObject();
	~BulletObject();
};

