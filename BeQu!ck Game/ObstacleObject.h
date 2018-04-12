#pragma once
#include "GameObject.h"
class ObstacleObject :
	public GameObject
{
protected: 
	int delta;
public:
	bool harmless;
	friend class PlayableObject;
	ObstacleObject(int x, int y, std::string name, bool harmless = true);
	ObstacleObject();
	~ObstacleObject();
};

