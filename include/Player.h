#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include "InputManagement.h"
#include "SpriteSheet.h"
#include "ObjectDimensions.h"

enum Direction {DOWN, LEFT, RIGHT, UP};

class Player 
{
	private:
		ALLEGRO_BITMAP *playerBitmap;
		
		int tick = 0;
		int moveSpeed = 5;
		int jCount = 0;
		bool jump = false;
		double floor = -10;
		double stageFloor = 388;
		int jumpCounter = 0;
		int lastXPosition = 0;
		Direction direction;
		
		Animation playerAnimation;
		SpriteSheet ssAnimation;
		ObjectDimensions playerDimensions;
		
	public:
		Player();
		~Player();
		void loadPlayer();
		void unloadPlayer();
		void update(ALLEGRO_EVENT, InputManagement);
		void movePlayer(ALLEGRO_EVENT);
		void draw(ALLEGRO_DISPLAY*);
		void gravityTick();
		void jumpTick();
		void setFloor(double);
		void setY(double);
		void setXStatic();
		int getLastXPosition();
		ObjectDimensions getCurrentDimensions();
};
#endif
 
