#pragma once
#include "ObstacleObject.h"
class TrophyObject :
	public ObstacleObject
{
public:
	friend class PlayableObject;
	bool visible = true;
	TrophyObject(int x, int y, std::string name);
	void Draw();
	~TrophyObject();
};

