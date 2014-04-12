#include "Player.h"
#include <iostream>
#include <stdio.h>
 
Player::Player()
{
	x = 10;
	y = 388;
	tdo = new TdObject();
	playerAnimation.getIsActive() = true;
	
}
 
Player::~Player()
{
	delete tdo;
}

void Player::setXStatic()
{
	x = lastXPosition;
}



void Player::move(ALLEGRO_EVENT e)
{
	switch(e.keyboard.keycode)
	{
		case ALLEGRO_KEY_S:
			playerAnimation.getIsActive() = true;
			direction = Direction::DOWN;
			break;
		case ALLEGRO_KEY_W:
			playerAnimation.getIsActive() = true;
			direction = Direction::UP;
			break;
		case ALLEGRO_KEY_D:
			playerAnimation.getIsActive() = true;
			direction = Direction::RIGHT;
			setX(moveSpeed);;
			break;
		case ALLEGRO_KEY_SPACE:
			playerAnimation.getIsActive() = true;
			if(floor > 0 && y == floor)
			{
				setY(0-moveSpeed);
				jumpCounter = 5;
				jump = true;
			}
			if(y == stageFloor)
			{
				setY(0-moveSpeed);
				jumpCounter = 5;
				jump = true;
			}
			break;
		case ALLEGRO_KEY_A:
			playerAnimation.getIsActive() = true;
			direction = Direction::LEFT;
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

int Player::getLastXPosition()
{
	return lastXPosition;
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

	if(floor > 0)
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
	else
	{
		if(y <= stageFloor && speed < 0)
			y += speed;
		else if(speed > 0 && y < stageFloor)
		{
			y += speed;
		}
		else if (y > stageFloor)
			y = stageFloor;
	}
	
}

void Player::setX(int speed)
{
	lastXPosition = x;
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
	
	xWidth = imgWidth / 3;
	yHeight = imgHeight / 4;;
	
	double position[] = {x, y};
	playerAnimation.loadContent(playerBitmap, "", position);
	playerAnimation.getIsActive() = true;
	direction = Direction::DOWN;
	
	
	tdo->setX(x);
	tdo->setY(y);
	tdo->setYHeight(xWidth);
	tdo->setXWidth(yHeight);
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
	tdo->setX(x);
	tdo->setY(y);
	playerAnimation.modifiableCurrentFrame().second = direction;
	ssAnimation.update(playerAnimation);
}


void Player::detectFloor(TdObject* iTdo)
{
	if(!(x+xWidth < iTdo->getMinX() || x > iTdo->getMaxX() ))
	{
		setFloor(iTdo->getMinY() - yHeight -1);
	}
	else
		floor = -10;
		
}


bool Player::detectCollision(TdObject* iTdo)
{

	return tdo->isColliding(iTdo);
}


void Player::draw(ALLEGRO_DISPLAY *display)
{
	playerAnimation.draw(display, x, y);
}
