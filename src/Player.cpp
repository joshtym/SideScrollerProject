#include "Player.h"
 
 
Player::Player()
{
	 
	 
}
 
Player::~Player()
{
	 
	 
}


void Player::move(ALLEGRO_EVENT e)
{


	switch(e.keyboard.keycode)
	{
		case ALLEGRO_KEY_S:
			y += moveSpeed;
			break;
		case ALLEGRO_KEY_D:
			y -= moveSpeed;
			break;
		case ALLEGRO_KEY_R:
			x += moveSpeed;
			break;
		case ALLEGRO_KEY_A:
			x -= moveSpeed;
			break;
				
	}
	
}
 
void Player::loadPlayer()
{
	playerBitmap = al_load_bitmap("player.bmp");
}

void Player::unloadPlayer()
{
	al_destroy_bitmap(playerBitmap);
}

void Player::draw()
{
	al_draw_bitmap(playerBitmap, x, y, 0);

}
