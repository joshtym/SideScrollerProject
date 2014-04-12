#include "Player.h"
#include <iostream>
#include <stdio.h>
 
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
			if(y == floor)
			{
				setY(0-moveSpeed);
				jumpCounter = 5;
				jump = true;
			}
			break;
		case ALLEGRO_KEY_A:
			setX(0-moveSpeed);
			setFlip(true);
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
		setY(-10);
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
	imgWidth =  al_get_bitmap_width(playerBitmap);
	imgHeight = al_get_bitmap_height(playerBitmap);
	
	double position[] = {x, y};
	playerAnimation.loadContent(playerBitmap, "", position);

	
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
}

void Player::draw(ALLEGRO_DISPLAY *display)
{
	playerAnimation.draw(display, x, y);
}
