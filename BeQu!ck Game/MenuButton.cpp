#include "MenuButton.h"



MenuButton::MenuButton(int x, int y, std::string name):GameObject(x,y,name)
{
}


MenuButton::~MenuButton()
{
}

bool MenuButton::In_Area(int x, int y)
{
	if ((x > this->x) && (x < this->x + this->bound_width))
		if ((y > this->y) && (y < this->y + this->bound_height))
			return true;

	return false;
}

void MenuButton::Draw(int x, int y)
{
	if (In_Area(x, y))
	{
		al_draw_bitmap(this->image, this->x, this->y, 0);
		al_draw_rectangle(this->x, this->y, this->x + this->bound_width, this->y + this->bound_height, al_map_rgb(255, 0, 0), 0);
	}	
	else
	{
		al_draw_bitmap(this->image, this->x, this->y,0);
	}
		
}