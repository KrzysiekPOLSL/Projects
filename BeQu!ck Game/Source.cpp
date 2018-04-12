#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include "GameObject.h"
#include "MovableObject.h"
#include "ObstacleObject.h"
#include "Game_Items.h"
#include <vector>
#include "MenuButton.h"
#include "ScryptedObstacleObject.h"
#include "ShootingObstacleObject.h"

int main(void)
{
	//GLOBALS==============================
	const int WIDTH = 1245;
	const int HEIGHT = 729;
	int position_mouse_x = 0;
	int position_mouse_y = 0;

	enum STATE { TITLE, PLAYING, LOST, WON };
	enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };
	bool keys[5] = { false, false, false, false, false };

	//primitive variable
	bool done = false;
	bool redraw = true;
	const int FPS = 60;
	int game_state = TITLE;
	const int MAX_PLATFORMS = 390;
	const int MAX_TROPHIES = 390;
	const int MAX_SPIKES = 432;
	const int MAX_SCRYPTED_PLATFORMS = 390;
	const int MAX_SHOOTERS_NUMBER = 390;
	int platforms_number = 0;
	int spikes_number = 0;
	int scrypted_platforms_number = 0;
	int shooters_number = 0;
	int trophies_number = 0;


	//Allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *font18 = NULL;
	def_settings settings;
	
	//Initialization Functions
	if (!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(WIDTH, HEIGHT);			//create our display object

	if (!display)										//test display object
		return -1;

	al_init_primitives_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	al_install_mouse();

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	srand(time(NULL));

	PlayableObject player(settings.x, settings.y, "assets//player_run.png", 10,4);
	ObstacleObject *platforms[MAX_PLATFORMS] = { nullptr };
	TrophyObject *trophies[MAX_TROPHIES] = { nullptr };
	ShootingObstacleObject *shooters[MAX_SHOOTERS_NUMBER] = { nullptr };
	ScryptedObstacleObject *scrypted_platforms[MAX_SCRYPTED_PLATFORMS] = { nullptr };
	ObstacleObject *spikes[MAX_SPIKES] = { nullptr };
	GameObject background(0, 0, "assets//BackDrop.png");
	MenuButton start(450, 100, "assets//start.png");
	MenuButton exit(430, 400, "assets//exit.png");
	GameObject MenuBackground(0, 0, "assets//bck2.png");
	GameObject WonBackground((WIDTH / 3) + 85, (HEIGHT / 4)+40, "assets//treasure.png");
	GameObject LostBackground(-15, -85, "assets//skull.png");
	
	for (int w = 0; w < 15; w++)
		for (int k = 0; k < 26; k++)
		{
			if (Shooting_Obstacles_Array[w][k] == 1)
			{
				shooters[shooters_number] = new ShootingObstacleObject(k * 48 - 2, (w * 48) + 8, "assets//cn.png",5);
				shooters_number++;
			}
		}
	
	for(int w = 0; w < 15; w++)
		for (int k = 0; k < 26; k++)
		{
			if (Obstacles_Array[w][k] == 1)
			{
				platforms[platforms_number] = new ObstacleObject(k * 48-2, (w * 48)+8, "assets//floor-box.png");
				platforms_number++;
			}
		}

	for (int w = 0; w < 15; w++)
		for (int k = 0; k < 26; k++)
		{
			if (Trophies_Array[w][k] == 1)
			{
				trophies[trophies_number] = new TrophyObject(k * 48 - 2, (w * 48) + 8, "assets//coin.png");
				trophies_number++;
			}
		}

	for (int w = 0; w < 15; w++)
		for (int k = 0; k < 26; k++)
		{
			if (Scrypted_Obstacles_Array[w][k] == 1)
			{
				scrypted_platforms[scrypted_platforms_number] = new ScryptedObstacleObject(k * 48 - 2, (w * 48) + 8, "assets//floor-box.png", 2);
				scrypted_platforms[scrypted_platforms_number]->DefaultInitialize();
				scrypted_platforms_number++;
			}
		}

	for (int w = 0; w < 16; w++)
		for (int k = 0; k < 27; k++)
		{
			if (Spikes_Array[w][k] == 1)
			{
				spikes[spikes_number] = new ObstacleObject(k * 48, w * 48, "assets//spikes.png",false);
				spikes_number++;
			}
		}

	font18 = al_load_font("assets//arial.ttf", 18, 0);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_start_timer(timer);

	while (!done)
	{
		//------------------------------------------------------------------------------------
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			if (game_state == PLAYING)
			{
				if (player.jump)
				{
					player.Jump();
					player.JumpUpdate();
				}

				player.Gravity();
				player.LockUpdate();

				for (int i = 0; i < scrypted_platforms_number; i++)
				{
					if ((i % 2) == 0)
						scrypted_platforms[i]->MoveHorizontal();
					else
						scrypted_platforms[i]->MoveVertical();
				}

				for (int i = 0; i < platforms_number; i++)
				{
					player.CollisionDetection(platforms[i]);
				}

				for (int i = 0; i < trophies_number; i++)
				{
					player.TrophyCollision(trophies[i]);
				}

				if (player.coins == 2)
				{
					game_state = WON;
					player.Reset();
					player.UpdatePosition(settings.x, settings.y);
					for (int i = 0; i < trophies_number; i++)
						trophies[i]->visible = true;
					for (int i = 0; i < 5; i++)
						keys[i] = false;
				}
					
				for (int i = 0; i < scrypted_platforms_number; i++)
				{
					player.CollisionDetection(scrypted_platforms[i]);
				}

				for (int i = 0; i < shooters_number; i++)
				{
					shooters[i]->CountUpdate();
					shooters[i]->ShootBullets();
					shooters[i]->UpdateBullets(WIDTH);
					player.BulletCollision(shooters[i]);
				}

				for (int i = 0; i < spikes_number; i++)
				{
					player.CollisionDetection(spikes[i]);
					if (player.hit)
					{
						player.hit = false;
						player.UpdatePosition(settings.x, settings.y);
					}
					
				}
				
				if (keys[LEFT])
					player.MoveLeft();
				else if (keys[RIGHT])
					player.MoveRight(WIDTH);

				player.AnimationUpdate();
					
				if (player.lives <= 0)
				{
					game_state = LOST;
					player.Reset();
					for (int i = 0; i < 5; i++)
						keys[i] = false;
					for (int i = 0; i < trophies_number; i++)
						trophies[i]->visible = true;
				}	

			}

		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			if (game_state == TITLE)
			{
				position_mouse_x = ev.mouse.x;
				position_mouse_y = ev.mouse.y;
			}	
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (game_state == TITLE)
			{
				if (exit.In_Area(position_mouse_x, position_mouse_y))
					done = true;
				else if (start.In_Area(position_mouse_x, position_mouse_y))
					game_state = PLAYING;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (game_state == PLAYING)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_UP:
					keys[UP] = true;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN] = true;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = true;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = true;
					if (!player.jumpLock)
					{
						player.jump = true;
						player.jumpLock = true;
					}	
					break;
				}
			}
			else if (game_state == LOST || game_state == WON)
				if (ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
				{
					game_state = TITLE;
				}
					
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (game_state == PLAYING)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_UP:
					keys[UP] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = false;
					break;
				}
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			if (game_state == PLAYING)
			{
				background.Draw();
				al_draw_textf(font18, al_map_rgb(255, 255, 255), 5, 5, 0, "Lives: %d", player.lives);
				al_draw_textf(font18, al_map_rgb(255, 255, 255), WIDTH-100, 5, 0, "Coins: %d", player.coins);
				for (int i = 0; i < platforms_number; i++)
				{
					platforms[i]->Draw();
				}

				for (int i = 0; i < trophies_number; i++)
				{
					trophies[i]->Draw();
				}

				for (int i = 0; i < scrypted_platforms_number; i++)
				{
					scrypted_platforms[i]->Draw();
				}

				for (int i = 0; i < shooters_number; i++)
				{
					shooters[i]->Draw();
					shooters[i]->DrawBullets();
				}

				for (int i = 0; i < spikes_number; i++)
				{
					spikes[i]->Draw();
				}

				//if (player.LeftLock)
					//al_draw_text(font18, al_map_rgb(255, 255, 255), 10, 10, 0, "LEFT");
				//if (player.RightLock)
					//al_draw_text(font18, al_map_rgb(255, 255, 255), 10, 30, 0, "RIGHT");
				//if (player.UpLock)
					//al_draw_text(font18, al_map_rgb(255, 255, 255), 10, 50, 0, "UP");
				//if (player.DownLock)
					//al_draw_text(font18, al_map_rgb(255, 255, 255), 10, 70, 0, "DOWN");

				player.DrawAnimated(keys[LEFT],keys[RIGHT]);

			}
			else if (game_state == TITLE)
			{
				MenuBackground.Draw();
				start.Draw(position_mouse_x,position_mouse_y);
				exit.Draw(position_mouse_x,position_mouse_y);
			}
			else if (game_state == LOST)
			{
				LostBackground.Draw();
				al_draw_text(font18,al_map_rgb(255,255,255), WIDTH / 2, (HEIGHT / 2) + 115,ALLEGRO_ALIGN_CENTRE ,"You lost, press SPACE to go to menu screen.");
			}
			else if (game_state == WON)
			{
				al_draw_text(font18, al_map_rgb(255, 255, 255), WIDTH / 2, (HEIGHT / 2) +100, ALLEGRO_ALIGN_CENTRE, "You won, press SPACE to go to menu screen.");
				WonBackground.Draw();
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
		//------------------------------------------------------------------------------------
	}

	for (int i = 0; i < platforms_number; i++)
	{
		delete platforms[i];
	}
	for (int i = 0; i < scrypted_platforms_number; i++)
	{
		delete scrypted_platforms[i];
	}
	for (int i = 0; i < spikes_number; i++)
	{
		delete spikes[i];
	}
	for (int i = 0; i < trophies_number; i++)
	{
		delete trophies[i];
	}
	for (int i = 0; i < shooters_number; i++)
	{
		delete shooters[i];
	}
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);	//destroy our display object

	return 0;
}