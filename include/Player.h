#ifndef PLAYER_H
#define PLAYER_H


#include "SpriteSheet.h"
#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>

class Player 
{
	private:
		ALLEGRO_BITMAP *playerBitmap;
		
		int tick = 0;
		int moveSpeed = 5;
		bool flip = false;
		void setX(int);
		void setY(int);
		void setFlip(bool);
		int jCount = 0;
		bool jump = false;
		double floor = 300;
		int jumpCounter = 0;
		
		//x and y are image
		int imgWidth;
		int imgHeight;
		double x;
		double y;
		double xWidth;
		double yHeight;
		
		Animation playerAnimation;
		SpriteSheet ssAnimation;
		
	public:
		Player();
		~Player();
		void loadPlayer();
		void unloadPlayer();
		void update(ALLEGRO_EVENT);
		void move(ALLEGRO_EVENT);
		void draw(ALLEGRO_DISPLAY*);
		void gravityTick();
		void jumpTick();
		double getX();
		double getY();
		void setFloor(double);
		
};
#endif
 
