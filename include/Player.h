#ifndef PLAYER_H
#define PLAYER_H

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
		int floor = 300;
		int jumpCounter = 0;
		
		//x and y are image
		int imgWidth;
		int imgHeight;
		int x;
		int y;
		int xWidth;
		int yHeight;
		
	public:
		Player();
		~Player();
		void loadPlayer();
		void unloadPlayer();
		void move(ALLEGRO_EVENT);
		void draw();
		void gravityTick();
		void jumpTick();
		int getX();
		int getY();
		void setFloor(int);
		
};
#endif
 
