#include "ShootingObstacleObject.h"



ShootingObstacleObject::ShootingObstacleObject(int x, int y, std::string name, int velocity):
	ObstacleObject(x,y,name)
{
	for (int i = 0; i < this->MAX_BULLET_NUMBER; i++)
	{
		this->bullets[i].x = this->x+this->bound_width;
		this->bullets[i].y = this->y+this->delta*6;
		this->bullets[i].velocity = velocity;
		this->bullets[i].visible = false;
	}
}


ShootingObstacleObject::~ShootingObstacleObject()
{
}

void ShootingObstacleObject::DrawBullets()
{
	for (int i = 0; i < this->MAX_BULLET_NUMBER; i++)
		if (this->bullets[i].visible)
			al_draw_filled_circle(this->bullets[i].x, this->bullets[i].y, this->delta, al_map_rgb(0, 0, 0));
}


void ShootingObstacleObject::CountUpdate()
{
	if (this->counter++ >= this->max_count)
		this->counter = 0;
}

void ShootingObstacleObject::UpdateBullets(int width)
{
	for (int i = 0; i < this->MAX_BULLET_NUMBER; i++)
	{
		if (this->bullets[i].visible)
			this->bullets[i].x += this->bullets[i].velocity;

		if (this->bullets[i].x >= width)
		{
			this->bullets[i].x = this->x + this->bound_width;
			this->bullets[i].visible = false;
		}
	}
	
}

void ShootingObstacleObject::ShootBullets()
{
	if (this->counter == this->max_count - 1)
	{
		for (int i = 0; i < this->MAX_BULLET_NUMBER; i++)
		{
			if (!this->bullets[i].visible)
			{
				this->bullets[i].visible = true;
				break;
			}
		}
	}
}
