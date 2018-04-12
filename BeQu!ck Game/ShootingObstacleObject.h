#pragma once
#include "ObstacleObject.h"

class ShootingObstacleObject :
	public ObstacleObject
{
protected:
	struct bullet
	{
		int x, y;
		int velocity;
		bool visible;
	};

	static const int MAX_BULLET_NUMBER =5;
	const int max_count = 71;
	int counter = 0;

public:
	friend class PlayableObject;
	bullet bullets[MAX_BULLET_NUMBER];
	void DrawBullets();
	void CountUpdate();
	void UpdateBullets(int width);
	void ShootBullets();
	ShootingObstacleObject(int x,int y, std::string name,int velocity);
	~ShootingObstacleObject();
};

