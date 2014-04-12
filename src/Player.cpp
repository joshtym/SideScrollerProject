#include "Player.h"
#include <iostream>
#include <stdio.h>
 
Player::Player()
{
	x = 10;
	y = 388;
	
	
}
 
Player::~Player()
{
}


void Player::move(ALLEGRO_EVENT e)
{
	switch(e.keyboard.keycode)
	{
		case ALLEGRO_KEY_S:
			break;
		case ALLEGRO_KEY_D:
			setX(moveSpeed);;
			break;
		case ALLEGRO_KEY_SPACE:
			if(y == floor)
			{
				setY(0-moveSpeed);
				jumpCounter = 5;
				jump = true;
			}
			break;
		case ALLEGRO_KEY_A:
			setX(0-moveSpeed);
			break;
		default:
			break;
	}
}


void Player::setFloor(double fl)
{	
	floor = fl;
}

void Player::gravityTick()
{
	setY(10);
}

void Player::jumpTick()
{
	if(jump)
	{
		jCount++;
		setY(-40);
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
		y = floor;
		
	
}

void Player::setX(int speed)
{
	x += speed;
}

double Player::getX()
{
	return x;
}

double Player::getY()
{
	return y;
}
 
void Player::loadPlayer()
{
	playerBitmap = al_load_bitmap("./imgFiles/image.png");
	//floor = 388;
	imgWidth =  al_get_bitmap_width(playerBitmap);
	imgHeight = al_get_bitmap_height(playerBitmap);
	
	double position[] = {x, y};
	playerAnimation.loadContent(playerBitmap, "", position);
	playerAnimation.getIsActive() = true;
}


void Player::unloadPlayer()
{
	al_destroy_bitmap(playerBitmap);
	playerAnimation.unloadContent();
}

void Player::update(ALLEGRO_EVENT ev)
{
	move(ev);
	jumpTick();
	gravityTick();
	ssAnimation.update(playerAnimation);
}

void Player::draw(ALLEGRO_DISPLAY *display)
{
	playerAnimation.draw(display, x, y);
}
