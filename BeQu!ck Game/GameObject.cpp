#include "GameObject.h"

GameObject::GameObject(int x, int y, std::string name)
{
	this->x = x;
	this->y = y;
	this->image = al_load_bitmap(name.c_str());
	this->bound_width = al_get_bitmap_width(this->image);
	this->bound_height = al_get_bitmap_height(this->image);
}

GameObject::GameObject()
{
	this->x = 0;
	this->y = 0;
	this->image = al_load_bitmap("plater-run.png");
	this->bound_width = 0;
	this->bound_height = 0;
}


GameObject::~GameObject()
{
	//std::cout << "Destroying GameObject"<< std::endl;
	al_destroy_bitmap(this->image);
}


void GameObject::Draw()
{
	al_draw_bitmap(this->image, this->x, this->y, NULL);
	//al_draw_rectangle(x, y, x + bound_width, y + bound_height, al_map_rgb(0, 255, 0), 1);
}