#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/keyboard.h>
#include "InputManagement.h"
#include "SpriteSheet.h"
#include "ObjectDimensions.h"

class Player 
{	
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
		ObjectDimensions& getCurrentDimensions();
		
	private:
		ALLEGRO_BITMAP *playerBitmap;
		Animation playerAnimation;
		SpriteSheet ssAnimation;
		ObjectDimensions playerDimensions;
		
		int tick;
		int moveSpeed;
		int jCount;
		bool jump;
		double floor;
		double stageFloor;
		int jumpCounter;
		int lastXPosition;
};
#endif
 
