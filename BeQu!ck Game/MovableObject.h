#pragma once
#include "GameObject.h"
#include "ObstacleObject.h"
#include "ShootingObstacleObject.h"
#include "TrophyObject.h"

typedef enum colision {U,D,L,R,N};

class PlayableObject :
	public GameObject
{
	//Physics parameters
	int velocity;
	int jumpvel;
	const int grav = 6;
	int grav_curr = 0;
	const int grav_max = 10;
	bool facing_right = true;

	//Collisions
	bool UpperColission(ObstacleObject* oo);
	bool LowerColission(ObstacleObject* oo);
	bool LeftColission(ObstacleObject* oo);
	bool RightColission(ObstacleObject* oo);

	//Animation
	const int max_frame = 3;
	int current_frame = 0;
	int frame_count = 0;
	int frame_delay = 5;
	int frames;
	
public:
	void CollisionDetection(ObstacleObject* oo);
	void BulletCollision(ShootingObstacleObject* so);
	void TrophyCollision(TrophyObject* to);
	int lives = 4;
	bool hit = false;
	int coins = 0;
	void LockUpdate();
	void Reset();
	bool IsMoving(int left, int right);

	bool DownLock = false;
	bool UpLock = false;
	bool LeftLock = false;
	bool RightLock = false;
	
	void MoveUp();
	void MoveLeft();
	void MoveRight(int width);
	void MoveDown();
	void Jump();
	void UpdatePosition(int x, int y);

	bool jump = false;
	bool jumpLock = false;
	void JumpUpdate();
	void Gravity();

	void AnimationUpdate();
	void DrawAnimated(int left, int right);
	
	PlayableObject(int x, int y, std::string name, int velocity,int frames=0);
	~PlayableObject();
};

