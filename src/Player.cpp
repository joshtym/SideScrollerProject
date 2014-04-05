#include "Player.h"
 #include <iostream>
 
 
Player::Player()
{
	x = 10;
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
			setFlip(false);
			break;
		case ALLEGRO_KEY_SPACE:
			setY(0-moveSpeed);
			jumpCounter = 5;
			jump = true;
			break;
		case ALLEGRO_KEY_A:
			setX(0-moveSpeed);
			setFlip(true);
			break;
		default:
			break;
	}
}


void Player::setFloor()
{
	
	
}

void Player::gravityTick()
{
	
	if(tick++ > 3)
	{ 
		setY(3);
		tick = 0;
	}

}

void Player::setFlip(bool f)
{
	flip = f;
}

void Player::jumpTick()
{
	if(jump)
	{
		jCount++;
		setY(-5);
		if(jCount > 5)
		{
			jump = false;
			jCount = 0;
		}
		
	}
}

void Player::setY(int speed)
{

	if(y <= floor && speed < 0)
		y += speed;
	else if(speed > 0 && y < floor)
	{
		y += speed;
	}
	else if (y > floor)
		y = 300;
		
	
}

void Player::setX(int speed)
{
	x += speed;
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
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
