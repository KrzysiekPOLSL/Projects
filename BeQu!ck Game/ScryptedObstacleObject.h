#pragma once
#include "ObstacleObject.h"
class ScryptedObstacleObject :
	public ObstacleObject
{
	int velocity;
	int max_positive_x;
	int max_positive_y;
	int max_negative_x;
	int max_negative_y;
	int x_dir = 1;
	int y_dir = 1;
public:
	ScryptedObstacleObject(int x, int y, std::string name, int velocity);
	void MoveVertical();
	void MoveHorizontal();
	void DefaultInitialize();
	~ScryptedObstacleObject();
};

