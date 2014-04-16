#include "Player.h"
#include <iostream>

Player::Player()
{
	// Set player dimensions
	playerDimensions.setMinX(-100);
	playerDimensions.setMinY(388);
	
	// Assign default values
	tick = 0;
	moveSpeed = 15;
	jCount = 0;
	floor = -10;
	stageFloor = 388;
	jumpCounter = 0;
	lastXPosition = 0;
	momentum = 0;
	stageSpeed = 0;
	otherTick = false;
	jump = false;
}
 
Player::~Player()
{
}

void Player::loadPlayer()
{
	// Load bitmap
	playerBitmap = al_load_bitmap("./assets/imgFiles/image.png");
	
	// Set imgWidth and height. Note that the full player file is actually
	// a collection of images to simulate animation, so we have to get one
	// specific player img/height
	playerDimensions.setImgWidth(al_get_bitmap_width(playerBitmap) / 3);
	playerDimensions.setImgHeight(al_get_bitmap_height(playerBitmap) / 4);
	
	// Update values and set the default direction to down
	playerDimensions.updateValues();
	playerDimensions.setDirection(Direction::DOWN);
	
	// Load animation content with player position and set animation to true
	double position[] = {playerDimensions.getMinX(), playerDimensions.getMinY()};
	playerAnimation.loadContent(playerBitmap, position);
	
	playerAnimation.getIsActive() = true;
}

void Player::unloadPlayer()
{
	// Destroy bitmap and unload animation content
	al_destroy_bitmap(playerBitmap);
	playerAnimation.unloadContent();
}

void Player::update(ALLEGRO_EVENT ev, InputManagement input)
{
	// Update the current player based on input, momentum, whether
	// jumping is currently happening, and whether gravity is
	// currently pulling the player down
	if(otherTick) 
		otherTick = false;
	else 
		otherTick = true;
	
	input.update();
	applyMomentum();
	movePlayer(ev);
	jumpTick();
	gravityTick();
	
	// Update values accordingly
	playerDimensions.updateValues();
	
	// Set the currentFrame to the direction and animate
	playerAnimation.modifiableCurrentFrame().second = playerDimensions.getCurrentDirection();
	ssAnimation.update(playerAnimation);
}

void Player::movePlayer(ALLEGRO_EVENT e)
{
	// Deal with the different inputs based on what the player
	// pressed
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
			addMomentum(+20);
			break;
		case ALLEGRO_KEY_SPACE:
			playerAnimation.getIsActive() = true;
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
			addMomentum(-20);
			break;
		default:
			//playerAnimation.getIsActive() = false;
			if(otherTick) addMomentum(-1);
			break;
	}
}

void Player::draw(ALLEGRO_DISPLAY *display)
{
	// Draw the animation
	playerAnimation.draw(display, playerDimensions.getMinX(),
						 playerDimensions.getMinY());
}

void Player::gravityTick()
{
	// When in a gravity tick, set the player to fall down
	setY(10);
}

void Player::jumpTick()
{
	// Determine the jump tick
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
	// Depending on jumping and if the player is on a platform, allows
	// the player to jump, essentially
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

void Player::setXStatic()
{
	playerDimensions.setMinX(lastXPosition);
}

void Player::setIsOnPlatform(bool b)
{
	onPlatform = b;
}

void Player::setFloorLevel(double userGivenFloorLevel)
{
	stageFloor = userGivenFloorLevel;
}

void Player::addMomentum(int m)
{
	if(momentum < 60 && momentum > -60)
		momentum += m;
}

void Player::applyMomentum()
{
	if(momentum > 0)
	{
		playerDimensions.setMinX(playerDimensions.getMinX() + 5);
		momentum--;
	}
	else if(momentum < 0)
	{
		playerDimensions.setMinX(playerDimensions.getMinX() - 5);
		momentum++;
	}
}

int Player::getLastXPosition()
{
	return lastXPosition;
}

double Player::setStageSpeed(double x)
{
	stageSpeed = x;
}

ObjectDimensions& Player::getCurrentDimensions()
{
	return playerDimensions;
}
