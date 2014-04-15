#include "Player.h"
#include <iostream>

Player::Player()
{
	playerDimensions.setMinX(-100);
	playerDimensions.setMinY(388);
	
	tick = 0;
	moveSpeed = 15;
	jCount = 0;
	jump = false;
	floor = -10;
	stageFloor = 388;
	jumpCounter = 0;
	lastXPosition = 0;
	momentium = 0;
	otherTick = false;

}
 
Player::~Player()
{
}

void Player::setXStatic()
{
	playerDimensions.setMinX(lastXPosition);
}


double Player::setStageSpeed(double x)
{
	stageSpeed = x;
}



void Player::movePlayer(ALLEGRO_EVENT e)
{
	switch(e.keyboard.keycode)
	{
		case ALLEGRO_KEY_S:
			playerAnimation.getIsActive() = true;
			playerDimensions.setDirection(Direction::DOWN);
			break;
		case ALLEGRO_KEY_W:
			playerAnimation.getIsActive() = true;
			playerDimensions.setDirection(Direction::UP);
			break;
		case ALLEGRO_KEY_D:
			playerAnimation.getIsActive() = true;
			playerDimensions.setDirection(Direction::RIGHT);
			addMomentium(+20);
			break;
		case ALLEGRO_KEY_SPACE:
			playerAnimation.getIsActive() = true;
			std::cout << "space " << onPlatform << std::endl;
			if(onPlatform)
			{
				setY(0-moveSpeed);
				jumpCounter = 5;
				jump = true;
			}
			else if(playerDimensions.getMinY() == stageFloor)
			{
				setY(0-moveSpeed);
				jumpCounter = 5;
				jump = true;
				onPlatform = false;
			}
			break;
		case ALLEGRO_KEY_A:
			playerAnimation.getIsActive() = true;
			playerDimensions.setDirection(Direction::LEFT);
			addMomentium(-20);
			break;
		default:
			//playerAnimation.getIsActive() = false;
			if(otherTick) addMomentium(-1);
			break;
	}
}

void Player::addMomentium(int m)
{
	if(momentium < 45 && momentium > -45)
		momentium += m;
}




void Player::applyMomentium()
{
	if(momentium > 0)
	{
		playerDimensions.setMinX(playerDimensions.getMinX() + 4);
		momentium--;
	}
	else if(momentium < 0)
	{
		playerDimensions.setMinX(playerDimensions.getMinX() - 4);
		momentium++;
	}
}

void Player::setIsOnPlatform(bool b)
{
	onPlatform = b;
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

void Player::setY(double speed)
{
	std::cout << "set " << onPlatform << std::endl;
	if(onPlatform && jump)
	{
		if(speed < 0)
			playerDimensions.setMinY(playerDimensions.getMinY() + speed);
		else if(speed > 0 && playerDimensions.getMinY() < floor)
			playerDimensions.setMinY(playerDimensions.getMinY() + speed);
		else if (playerDimensions.getMinY() > floor)
			playerDimensions.setMinY(floor);
		onPlatform = false;
	}
	else
	{
		if(playerDimensions.getMinY() <= stageFloor && speed < 0)
			playerDimensions.setMinY(playerDimensions.getMinY() + speed);
		else if(speed > 0 && playerDimensions.getMinY() < stageFloor)
			playerDimensions.setMinY(playerDimensions.getMinY() + speed);
		else if (playerDimensions.getMinY() > stageFloor)
			playerDimensions.setMinY(stageFloor);
	}
}
 
void Player::loadPlayer()
{
	playerBitmap = al_load_bitmap("./assets/imgFiles/image.png");
	playerDimensions.setImgWidth(al_get_bitmap_width(playerBitmap) / 3);
	playerDimensions.setImgHeight(al_get_bitmap_height(playerBitmap) / 4);
	playerDimensions.updateValues();
	playerDimensions.setDirection(Direction::DOWN);
	
	double position[] = {playerDimensions.getMinX(), playerDimensions.getMinY()};
	playerAnimation.loadContent(playerBitmap, position);
	
	playerAnimation.getIsActive() = true;
}


void Player::unloadPlayer()
{
	al_destroy_bitmap(playerBitmap);
	playerAnimation.unloadContent();
}

void Player::update(ALLEGRO_EVENT ev, InputManagement input)
{
	if(otherTick) otherTick = false;
	else otherTick = true;
	
	input.update();
	applyMomentium();
	movePlayer(ev);
	jumpTick();
	gravityTick();
	playerDimensions.updateValues();
	
	playerAnimation.modifiableCurrentFrame().second = playerDimensions.getCurrentDirection();
	ssAnimation.update(playerAnimation);
}

void Player::draw(ALLEGRO_DISPLAY *display)
{
	playerAnimation.draw(display, playerDimensions.getMinX(),
						 playerDimensions.getMinY());
}

ObjectDimensions& Player::getCurrentDimensions()
{
	return playerDimensions;
}

void Player::setFloorLevel(double userGivenFloorLevel)
{
	stageFloor = userGivenFloorLevel;
}
