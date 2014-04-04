#include "Player.h"
 #include <iostream>
 
 
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
			//Duck or something?
			break;
		case ALLEGRO_KEY_D:
			setX(moveSpeed);
			flip = false;
			break;
		case ALLEGRO_KEY_W:
			setY(0-moveSpeed);
			break;
		case ALLEGRO_KEY_A:
			setX(0-moveSpeed);
			flip = true;
			break;
		default:
			break;
	}
}

void Player::gravityTick()
{
	if(tick++ > 3)
	{
		setY(5);
		tick = 0;
	}

}

void Player::setY(int speed)
{
	if(y <= 300 && speed < 0)
		y += speed;
	else if(speed > 0 && y < 300)
	{
		y += speed;
	}
		
	
}

void Player::setX(int speed)
{
	x += speed;
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
