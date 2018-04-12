#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include <iostream>
#include <string>

class GameObject
{
protected:
	//For Drawing
	int x;
	int y;
	int bound_width;
	int bound_height;

	ALLEGRO_BITMAP *image;
public:
	virtual void Draw();
	GameObject(int x, int y, std::string name);
	GameObject();
	~GameObject();
};

