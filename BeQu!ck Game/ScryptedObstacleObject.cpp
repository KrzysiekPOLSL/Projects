#include "ScryptedObstacleObject.h"



ScryptedObstacleObject::ScryptedObstacleObject(int x, int y, std::string name,int velocity):
	ObstacleObject(x,y,name), velocity(velocity)
{
}


ScryptedObstacleObject::~ScryptedObstacleObject()
{
}

void ScryptedObstacleObject::MoveHorizontal()
{
	if (this->x_dir)
	{
		this->x += this->velocity;

		if (this->x >= this->max_positive_x)
			this->x_dir = 0;
	}
	else
	{
		this->x -= this->velocity;

		if (this->x <= this->max_negative_x)
			this->x_dir = 1;
	}
}

void ScryptedObstacleObject::MoveVertical()
{
	if (this->y_dir)
	{
		this->y += this->velocity;

		if (this->y >= this->max_positive_y)
			this->y_dir = 0;
	}
	else
	{
		this->y -= this->velocity;

		if (this->y <= this->max_negative_y)
			this->y_dir = 1;
	}
}

void ScryptedObstacleObject::DefaultInitialize()
{
	this->max_positive_x = this->x + 7 * this->delta;
	this->max_negative_x = this->x - 7 * this->delta;

	this->max_positive_y = this->y + 7 * this->delta;
	this->max_negative_y = this->y - 7 * this->delta;
}

