#include "Player.h"
 
Player::Player()
{
	x = 5;
	y = 300;
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
			x += moveSpeed;
			flip = false;
			break;
		case ALLEGRO_KEY_W:
			y -= moveSpeed;
			break;
		case ALLEGRO_KEY_A:
			x -= moveSpeed;
			flip = true;
			break;
		default:
			break;
	}
}
 
void Player::loadPlayer()
{
	playerBitmap = al_load_bitmap("./imgFiles/player.png");
}

void Player::unloadPlayer()
{
	al_destroy_bitmap(playerBitmap);
}

void Player::draw()
{
	if (!flip)
		al_draw_bitmap(playerBitmap, x, y, 0);
	else
		al_draw_bitmap(playerBitmap, x, y, ALLEGRO_FLIP_HORIZONTAL);

}
