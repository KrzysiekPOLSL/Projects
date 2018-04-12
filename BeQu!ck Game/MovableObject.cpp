#include "MovableObject.h"

PlayableObject::PlayableObject(int x, int y, std::string name, int velocity,int frames):
	GameObject(x,y,name), velocity(velocity)
{
	if (this->frames=frames)
	{
		this->bound_width = this->bound_width / frames;
		int c = this->bound_width;
		c = this->bound_height;
	}
	jumpvel = 1.3*this->velocity;
}

PlayableObject::~PlayableObject()
{
}

void PlayableObject::MoveUp()
{
	if(!this->UpLock)
	this->y -= this->velocity;
}
void PlayableObject::MoveLeft()
{
	if (!this->LeftLock&&this->x>=0)
	this->x -= this->velocity;
}
void PlayableObject::MoveRight(int width)
{
	if (!this->RightLock && (this->x + this->bound_width) < width)
	this->x += this->velocity;
}
void PlayableObject::MoveDown()
{
	if (!this->DownLock)
	this->y += this->velocity;
}
void PlayableObject::Jump()
{
	if (!this->UpLock)
		this->y -= this->jumpvel;
}
void PlayableObject::Gravity()
{
	if((!this->jump)&&(!this->DownLock))
	this->y += this->grav;
}

void PlayableObject::JumpUpdate()
{
	if (this->jump == true)
	{
			if (++this->grav_curr >= this->grav_max)
			{
				this->grav_curr = 0;
				this->jump = false;
			}
	}
}

bool PlayableObject::UpperColission(ObstacleObject* oo)
{
	if ((this->x > oo->x && this->x < oo->x + oo->bound_width) || 
		(this->x + this->bound_width > oo->x && this->x + this->bound_width < oo->x + oo->bound_width))
	{
		if ((this->y < oo->y) && (this->y + this->bound_height >= oo->y) && (this->y + this->bound_height < oo->y + oo->bound_height))
		{
			if ((!this->LeftLock) && (!this->RightLock))
				this->y = this->y - (this->y + this->bound_height - oo->y);

			if (!oo->harmless)
			{
				this->lives -= 1;
				this->hit = true;
			}

			this->jumpLock = false;

			return true;
		}	
	}
	return false;
}
bool PlayableObject::LowerColission(ObstacleObject* oo)
{
	if ((this->x > oo->x && this->x < oo->x + oo->bound_width) || 
		(this->x + this->bound_width > oo->x && this->x + this->bound_width < oo->x + oo->bound_width))
	{
		if ((this->y > oo->y) && (this->y <= oo->y + oo->bound_height) && (this->y + this->bound_height > oo->y + oo->bound_height))
		{
			if((!this->LeftLock) && (!this->RightLock))
				this->y = this->y + (oo->y + oo->bound_height -this->y);

			if (!oo->harmless)
			{
				this->lives -= 1;
				this->hit = true;
			}

			return true;
		}
			
	}
	return false;
}
bool PlayableObject::LeftColission(ObstacleObject* oo)
{
	if ((this->y > oo->y && this->y < oo->y + oo->bound_height) ||
		(this->y + this->bound_height > oo->y && this->y + this->bound_height < oo->y + oo->bound_height))
	{
		if ((this->x < oo->x) && ((this->x + this->bound_width) >= (oo->x - oo->delta)) &&
			((this->x + this->bound_width) < oo->x + oo->bound_width))
		{
			if (!this->UpLock)
				this->x = this->x - (this->x + this->bound_width - oo->x)-1;

			if (!oo->harmless)
			{
				this->lives -= 1;
				this->hit = true;
			}

			return true;
		}	
	}
	return false;
}
bool PlayableObject::RightColission(ObstacleObject* oo)
{
	if ((this->y > oo->y && this->y < oo->y + oo->bound_height) || 
		(this->y + this->bound_height > oo->y && this->y + this->bound_height < oo->y + oo->bound_height))
	{
		if ((this->x > oo->x) && (this->x <= (oo->x + oo->bound_width + oo->delta)) && ((this->x + this->bound_width) > (oo->x + oo->bound_width)))
		{
			if (!this->UpLock)
				this->x = this->x + ((oo->x + oo->bound_width)-this->x)+1;

			if (!oo->harmless)
			{
				this->lives -= 1;
				this->hit = true;
			}
			return true;
		}
	}
	return false;
}

void PlayableObject::CollisionDetection(ObstacleObject* oo)
{
	if ((UpperColission(oo)) && (!this->UpLock))
		this->DownLock = true;

	if ((LowerColission(oo)) && (!this->DownLock))
		this->UpLock = true;

	if ((LeftColission(oo))&&(!this->LeftLock))
		this->RightLock = true;
	
	if ((RightColission(oo))&&(!this->RightLock))
		this->LeftLock = true;
}

void PlayableObject::LockUpdate()
{
	this->DownLock = false;
	this->UpLock = false;
	this->LeftLock = false;
	this->RightLock = false;
}

void PlayableObject::AnimationUpdate()
{
	if (++this->frame_count >= this->frame_delay)
	{
		if (++this->current_frame >= this->max_frame)
			this->current_frame = 0;

		this->frame_count = 0;
	}
}

void PlayableObject::DrawAnimated(int left, int right)
{
	if (this->IsMoving(left, right))
	{
		if (left)
		{
			al_draw_bitmap_region(this->image, this->current_frame*this->bound_width, 0,
				this->bound_width, this->bound_height, this->x, this->y, ALLEGRO_FLIP_HORIZONTAL);
			this->facing_right = false;
		}
		else
		{
			al_draw_bitmap_region(this->image, this->current_frame*this->bound_width, 0,
				this->bound_width, this->bound_height, this->x, this->y, 0);
			this->facing_right = true;
		}	
	}	
	else if(this->facing_right)
		al_draw_bitmap_region(this->image, 0, 0, this->bound_width, this->bound_height, this->x, this->y, 0);
	else
		al_draw_bitmap_region(this->image, 0, 0, this->bound_width, this->bound_height, this->x, this->y, ALLEGRO_FLIP_HORIZONTAL);
}

void PlayableObject::UpdatePosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void PlayableObject::BulletCollision(ShootingObstacleObject* so)
{
	for (int i = 0; i < so->MAX_BULLET_NUMBER; i++)
	{
		if(so->bullets[i].x > this->x && so->bullets[i].x < this->x + this->bound_width)
			if (so->bullets[i].y > this->y && so->bullets[i].y < this->y + this->bound_height)
			{
				this->lives -= 1;
				this->hit = true;
			}
	}
}

void PlayableObject::TrophyCollision(TrophyObject* to)
{
	if (to->x > this->x && to->x < this->x + this->bound_width)
		if (to->y > this->y && to->y < this->y + this->bound_height)
		{
			if (to->visible)
			{
				to->visible = false;
				this->coins++;
			}
		}
	if (to->x + to->bound_width > this->x && to->x + to->bound_width < this->x + this->bound_width)
		if (to->y + to->bound_height > this->y && to->y + to->bound_height < this->y + this->bound_height)
		{
			if (to->visible)
			{
				to->visible = false;
				this->coins++;
			}
		}	
}

void PlayableObject::Reset()
{
	this->lives = 4;
	this->coins = 0;
}

bool PlayableObject::IsMoving(int left, int right)
{
	if (left || right)
		return true;
	else return false;
}