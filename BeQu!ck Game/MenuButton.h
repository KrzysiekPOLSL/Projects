#pragma once
#include "GameObject.h"
class MenuButton :
	public GameObject
{
public:
	void Draw(int x, int y);
	bool In_Area(int x, int y);
	MenuButton(int x,int y,std::string name);
	~MenuButton();
};

