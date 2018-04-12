#include "TrophyObject.h"



TrophyObject::TrophyObject(int x, int y, std::string name):ObstacleObject(x,y,name)
{
}


TrophyObject::~TrophyObject()
{
}


void TrophyObject::Draw()
{
	if (this->visible)
		al_draw_bitmap(this->image, this->x, this->y,0);
}